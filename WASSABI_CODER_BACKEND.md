# 🍣 WASSABI CODER - DOCUMENTO BACKEND

> **Plataforma de Programação Competitiva**  
> Desenvolvido por **vleonel**

---

## 📋 VISÃO GERAL

Este documento descreve a arquitetura completa do backend da plataforma **Wassabi Coder**, incluindo API REST, sistema de Judge, autenticação, e infraestrutura containerizada.

### Stack Backend

- **Framework**: NestJS (Node.js + TypeScript)
- **Database**: PostgreSQL
- **ORM**: Prisma
- **Cache**: Redis
- **Queue**: Bull (Redis-based)
- **Judge System**: Docker containers isolados
- **Email**: Nodemailer + SMTP
- **Auth**: JWT + Bcrypt
- **Validation**: class-validator + class-transformer
- **Documentation**: Swagger/OpenAPI

---

## 🏗️ ARQUITETURA GERAL

```
┌─────────────────────────────────────────────────────────────────┐
│                         FRONTEND (React)                        │
└────────────────────────────────┬────────────────────────────────┘
                                 │ HTTPS
                                 ▼
┌─────────────────────────────────────────────────────────────────┐
│                      API GATEWAY (NestJS)                       │
│  ┌──────────┐ ┌──────────┐ ┌──────────┐ ┌──────────────────┐   │
│  │   Auth   │ │ Problems │ │Submissions│ │ Admin Module     │   │
│  │  Module  │ │  Module  │ │  Module  │ │                  │   │
│  └──────────┘ └──────────┘ └──────────┘ └──────────────────┘   │
└────────────────────────────────┬────────────────────────────────┘
                                 │
         ┌───────────────────────┼───────────────────────┐
         │                       │                       │
         ▼                       ▼                       ▼
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   PostgreSQL    │    │      Redis      │    │  Judge Workers  │
│   (Database)    │    │  (Cache/Queue)  │    │   (Docker)      │
└─────────────────┘    └─────────────────┘    └─────────────────┘
```

---

## 🔒 SEGURANÇA

### Critérios Implementados

| Critério          | Implementação                           |
| ----------------- | --------------------------------------- |
| **Autenticação**  | JWT com refresh tokens                  |
| **Senhas**        | Bcrypt (salt rounds: 12)                |
| **Rate Limiting** | 100 req/min por IP, 10 req/min em /auth |
| **CORS**          | Configurável por ambiente               |
| **Helmet**        | Headers de segurança HTTP               |
| **Validação**     | class-validator em todas as rotas       |
| **SQL Injection** | Prisma ORM (queries parametrizadas)     |
| **XSS**           | Sanitização de inputs                   |
| **Sandbox**       | Código executa em containers isolados   |
| **Timeout**       | Max 10s por execução de código          |
| **Recursos**      | Memory limit 256MB por container        |

### Configuração CORS

```typescript
// src/main.ts
app.enableCors({
  origin: process.env.FRONTEND_URL || "http://localhost:5173",
  methods: ["GET", "POST", "PUT", "DELETE", "PATCH"],
  allowedHeaders: ["Content-Type", "Authorization"],
  credentials: true,
  maxAge: 86400, // 24 hours
});
```

### Headers de Segurança (Helmet)

```typescript
// src/main.ts
import helmet from "helmet";

app.use(
  helmet({
    contentSecurityPolicy: {
      directives: {
        defaultSrc: ["'self'"],
        styleSrc: ["'self'", "'unsafe-inline'"],
        scriptSrc: ["'self'"],
        imgSrc: ["'self'", "data:", "https:"],
      },
    },
    crossOriginEmbedderPolicy: false,
  }),
);
```

### Rate Limiting

```typescript
// src/app.module.ts
import { ThrottlerModule } from '@nestjs/throttler';

@Module({
  imports: [
    ThrottlerModule.forRoot({
      ttl: 60,
      limit: 100,
    }),
  ],
})
```

---

## 📊 MODELO DE DADOS

### Schema Prisma

```prisma
// prisma/schema.prisma

generator client {
  provider = "prisma-client-js"
}

datasource db {
  provider = "postgresql"
  url      = env("DATABASE_URL")
}

enum Role {
  USER
  ADMIN
}

enum SubmissionStatus {
  PENDING
  COMPILING
  RUNNING
  ACCEPTED
  WRONG_ANSWER
  TIME_LIMIT
  MEMORY_LIMIT
  RUNTIME_ERROR
  COMPILE_ERROR
}

enum Difficulty {
  EASY
  MEDIUM
  HARD
}

enum Language {
  C
  CPP
  PYTHON
  JAVA
}

model User {
  id            String    @id @default(uuid())
  name          String
  email         String    @unique
  tagname       String    @unique
  password      String
  role          Role      @default(USER)
  emailVerified Boolean   @default(false)
  createdAt     DateTime  @default(now())
  updatedAt     DateTime  @updatedAt

  submissions     Submission[]
  clarifications  Clarification[]

  @@index([email])
  @@index([tagname])
}

model Category {
  id        String    @id @default(uuid())
  name      String    @unique
  slug      String    @unique
  createdAt DateTime  @default(now())

  problems  Problem[]
}

model Problem {
  id          String     @id @default(uuid())
  title       String
  slug        String     @unique
  description String     @db.Text
  difficulty  Difficulty
  timeLimit   Int        @default(1000) // ms
  memoryLimit Int        @default(256)  // MB
  isPublished Boolean    @default(false)
  createdAt   DateTime   @default(now())
  updatedAt   DateTime   @updatedAt

  categoryId  String
  category    Category   @relation(fields: [categoryId], references: [id])

  testCases      TestCase[]
  submissions    Submission[]
  clarifications Clarification[]

  @@index([slug])
  @@index([categoryId])
}

model TestCase {
  id        String  @id @default(uuid())
  input     String  @db.Text
  output    String  @db.Text
  isHidden  Boolean @default(true)
  order     Int

  problemId String
  problem   Problem @relation(fields: [problemId], references: [id], onDelete: Cascade)

  @@index([problemId])
}

model Submission {
  id         String           @id @default(uuid())
  code       String           @db.Text
  language   Language
  status     SubmissionStatus @default(PENDING)
  runtime    Int?             // ms
  memory     Int?             // KB
  errorMsg   String?          @db.Text
  testsPassed Int             @default(0)
  testsTotal  Int             @default(0)
  createdAt  DateTime         @default(now())

  userId    String
  user      User    @relation(fields: [userId], references: [id])

  problemId String
  problem   Problem @relation(fields: [problemId], references: [id])

  @@index([userId])
  @@index([problemId])
  @@index([status])
  @@index([createdAt])
}

model Clarification {
  id        String   @id @default(uuid())
  question  String   @db.Text
  answer    String?  @db.Text
  isAnswered Boolean @default(false)
  createdAt DateTime @default(now())
  answeredAt DateTime?

  userId    String
  user      User    @relation(fields: [userId], references: [id])

  problemId String
  problem   Problem @relation(fields: [problemId], references: [id])

  @@index([userId])
  @@index([problemId])
  @@index([isAnswered])
}

model VerificationToken {
  id        String   @id @default(uuid())
  token     String   @unique
  email     String
  type      String   // 'email_verification' | 'password_reset'
  expiresAt DateTime
  createdAt DateTime @default(now())

  @@index([token])
  @@index([email])
}
```

---

## 📡 API ENDPOINTS

### Padrão de Respostas

**Sucesso:**

```json
{
  "success": true,
  "data": { ... },
  "message": "Operação realizada com sucesso"
}
```

**Erro:**

```json
{
  "success": false,
  "error": {
    "code": "VALIDATION_ERROR",
    "message": "Email já está em uso",
    "details": { ... }
  }
}
```

**Paginação:**

```json
{
  "success": true,
  "data": {
    "items": [...],
    "meta": {
      "page": 1,
      "limit": 20,
      "total": 156,
      "totalPages": 8
    }
  }
}
```

---

## 🔐 AUTH MODULE

### POST `/api/auth/register`

Cadastro de novo usuário.

**Request:**

```json
{
  "name": "João da Silva",
  "tagname": "joaodev",
  "email": "joao@email.com",
  "password": "SenhaForte123"
}
```

**Validações:**

- `name`: string, min 2, max 100 caracteres
- `tagname`: string, alfanumérico + underscore, min 3, max 20, único
- `email`: email válido, único
- `password`: min 8 caracteres, 1 letra, 1 número

**Response (201):**

```json
{
  "success": true,
  "data": {
    "id": "uuid",
    "name": "João da Silva",
    "tagname": "joaodev",
    "email": "joao@email.com"
  },
  "message": "Cadastro realizado. Verifique seu email para ativar a conta."
}
```

**Ações:**

- Salva usuário com emailVerified = false
- Gera token de verificação (expira em 24h)
- Envia email com link de verificação

---

### POST `/api/auth/login`

Login de usuário.

**Request:**

```json
{
  "email": "joao@email.com",
  "password": "SenhaForte123"
}
```

**Response (200):**

```json
{
  "success": true,
  "data": {
    "user": {
      "id": "uuid",
      "name": "João da Silva",
      "tagname": "joaodev",
      "email": "joao@email.com",
      "role": "USER"
    },
    "accessToken": "jwt_token",
    "refreshToken": "refresh_token"
  }
}
```

**Erros:**

- 401: Credenciais inválidas
- 403: Email não verificado

---

### POST `/api/auth/logout`

Logout (invalida refresh token).

**Headers:** `Authorization: Bearer {accessToken}`

**Response (200):**

```json
{
  "success": true,
  "message": "Logout realizado com sucesso"
}
```

---

### POST `/api/auth/refresh`

Renova access token.

**Request:**

```json
{
  "refreshToken": "refresh_token"
}
```

**Response (200):**

```json
{
  "success": true,
  "data": {
    "accessToken": "new_jwt_token",
    "refreshToken": "new_refresh_token"
  }
}
```

---

### POST `/api/auth/verify-email`

Verifica email via token.

**Request:**

```json
{
  "token": "verification_token"
}
```

**Response (200):**

```json
{
  "success": true,
  "message": "Email verificado com sucesso"
}
```

---

### POST `/api/auth/forgot-password`

Solicita reset de senha.

**Request:**

```json
{
  "email": "joao@email.com"
}
```

**Response (200):**

```json
{
  "success": true,
  "message": "Se o email existir, você receberá instruções para redefinir sua senha"
}
```

_Nota: Sempre retorna sucesso para não confirmar existência de email._

---

### POST `/api/auth/reset-password`

Redefine senha via token.

**Request:**

```json
{
  "token": "reset_token",
  "password": "NovaSenha123"
}
```

**Response (200):**

```json
{
  "success": true,
  "message": "Senha redefinida com sucesso"
}
```

---

### GET `/api/auth/me`

Retorna usuário atual logado.

**Headers:** `Authorization: Bearer {accessToken}`

**Response (200):**

```json
{
  "success": true,
  "data": {
    "id": "uuid",
    "name": "João da Silva",
    "tagname": "joaodev",
    "email": "joao@email.com",
    "role": "USER",
    "emailVerified": true,
    "createdAt": "2026-01-01T00:00:00.000Z"
  }
}
```

---

## 👤 USERS MODULE

### GET `/api/users/me`

Retorna perfil do usuário logado.

**Headers:** `Authorization: Bearer {accessToken}`

**Response (200):**

```json
{
  "success": true,
  "data": {
    "id": "uuid",
    "name": "João da Silva",
    "tagname": "joaodev",
    "email": "joao@email.com",
    "createdAt": "2026-01-01T00:00:00.000Z"
  }
}
```

---

### PUT `/api/users/me`

Atualiza perfil do usuário logado.

**Headers:** `Authorization: Bearer {accessToken}`

**Request:**

```json
{
  "name": "João Silva Updated",
  "tagname": "joaodev_new"
}
```

**Response (200):**

```json
{
  "success": true,
  "data": {
    "id": "uuid",
    "name": "João Silva Updated",
    "tagname": "joaodev_new",
    "email": "joao@email.com"
  },
  "message": "Perfil atualizado com sucesso"
}
```

---

### GET `/api/users/me/stats`

Retorna estatísticas do usuário logado.

**Headers:** `Authorization: Bearer {accessToken}`

**Response (200):**

```json
{
  "success": true,
  "data": {
    "solved": 42,
    "attempted": 58,
    "totalSubmissions": 156,
    "rank": 127,
    "acceptanceRate": 72.4
  }
}
```

---

### GET `/api/users/:tagname`

Retorna perfil público de um usuário.

**Response (200):**

```json
{
  "success": true,
  "data": {
    "name": "João da Silva",
    "tagname": "joaodev",
    "createdAt": "2026-01-01T00:00:00.000Z",
    "stats": {
      "solved": 42,
      "rank": 127
    }
  }
}
```

---

### GET `/api/users/:id/solved`

Retorna exercícios resolvidos pelo usuário.

**Query Params:**

- `page`: número da página (default: 1)
- `limit`: itens por página (default: 20)

**Response (200):**

```json
{
  "success": true,
  "data": {
    "items": [
      {
        "id": "uuid",
        "title": "Two Sum",
        "slug": "two-sum",
        "difficulty": "EASY",
        "category": "Arrays",
        "solvedAt": "2026-03-01T14:30:00.000Z"
      }
    ],
    "meta": {
      "page": 1,
      "limit": 20,
      "total": 42,
      "totalPages": 3
    }
  }
}
```

---

## 📝 PROBLEMS MODULE

### GET `/api/problems`

Lista exercícios com filtros e paginação.

**Query Params:**

- `page`: número da página (default: 1)
- `limit`: itens por página (default: 20, max: 100)
- `category`: slug da categoria (opcional)
- `difficulty`: EASY | MEDIUM | HARD (opcional)
- `status`: solved | unsolved | attempted (opcional, requer auth)
- `search`: busca por título (opcional)

**Headers:** `Authorization: Bearer {accessToken}` (opcional, para filtro por status)

**Response (200):**

```json
{
  "success": true,
  "data": {
    "items": [
      {
        "id": "uuid",
        "title": "Two Sum",
        "slug": "two-sum",
        "difficulty": "EASY",
        "category": {
          "id": "uuid",
          "name": "Arrays",
          "slug": "arrays"
        },
        "solvedCount": 342,
        "userStatus": "solved" // null | "solved" | "attempted"
      }
    ],
    "meta": {
      "page": 1,
      "limit": 20,
      "total": 156,
      "totalPages": 8
    }
  }
}
```

---

### GET `/api/problems/:id`

Retorna detalhe de um exercício.

**Headers:** `Authorization: Bearer {accessToken}` (opcional)

**Response (200):**

````json
{
  "success": true,
  "data": {
    "id": "uuid",
    "title": "Two Sum",
    "slug": "two-sum",
    "description": "Dado um array de inteiros...\n\n**Exemplo:**\n```\nInput: [2,7,11,15], target=9\nOutput: [0,1]\n```",
    "difficulty": "EASY",
    "timeLimit": 1000,
    "memoryLimit": 256,
    "category": {
      "id": "uuid",
      "name": "Arrays",
      "slug": "arrays"
    },
    "solvedCount": 342,
    "testCases": [
      {
        "input": "4 9\n2 7 11 15",
        "output": "0 1"
      }
    ],
    "userStatus": "solved",
    "userSubmissionCount": 3
  }
}
````

_Nota: testCases retorna apenas os não ocultos (isHidden = false)_

---

### GET `/api/problems/:id/solvers`

Lista usuários que resolveram o exercício.

**Query Params:**

- `page`: número da página (default: 1)
- `limit`: itens por página (default: 20)

**Response (200):**

```json
{
  "success": true,
  "data": {
    "items": [
      {
        "tagname": "joaodev",
        "name": "João da Silva",
        "solvedAt": "2026-03-01T14:30:00.000Z"
      }
    ],
    "meta": {
      "page": 1,
      "limit": 20,
      "total": 342,
      "totalPages": 18
    }
  }
}
```

---

### GET `/api/problems/recommended`

Retorna exercícios recomendados para o usuário.

**Headers:** `Authorization: Bearer {accessToken}`

**Response (200):**

```json
{
  "success": true,
  "data": [
    {
      "id": "uuid",
      "title": "Prefix Sum",
      "slug": "prefix-sum",
      "difficulty": "MEDIUM",
      "category": "Arrays",
      "solvedCount": 234
    }
  ]
}
```

_Lógica: Retorna 3-5 exercícios que o usuário ainda não resolveu, baseado em dificuldade apropriada._

---

### GET `/api/categories`

Lista todas as categorias.

**Response (200):**

```json
{
  "success": true,
  "data": [
    { "id": "uuid", "name": "Arrays", "slug": "arrays", "problemCount": 45 },
    { "id": "uuid", "name": "Strings", "slug": "strings", "problemCount": 38 },
    {
      "id": "uuid",
      "name": "Dynamic Programming",
      "slug": "dp",
      "problemCount": 32
    }
  ]
}
```

---

## 📤 SUBMISSIONS MODULE

### POST `/api/submissions`

Submete código para julgamento.

**Headers:** `Authorization: Bearer {accessToken}`

**Request:**

```json
{
  "problemId": "uuid",
  "language": "CPP",
  "code": "#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    // código\n    return 0;\n}"
}
```

**Validações:**

- `problemId`: deve existir
- `language`: C | CPP | PYTHON | JAVA
- `code`: não vazio, max 50KB

**Response (201):**

```json
{
  "success": true,
  "data": {
    "id": "uuid",
    "status": "PENDING",
    "language": "CPP",
    "createdAt": "2026-03-12T14:30:00.000Z"
  },
  "message": "Submissão recebida. Aguarde o resultado."
}
```

**Ações:**

- Cria registro no banco com status PENDING
- Envia para fila de processamento (Bull)

---

### GET `/api/submissions/:id`

Retorna detalhe de uma submissão.

**Headers:** `Authorization: Bearer {accessToken}`

**Response (200):**

```json
{
  "success": true,
  "data": {
    "id": "uuid",
    "status": "ACCEPTED",
    "language": "CPP",
    "runtime": 45,
    "memory": 2100,
    "testsPassed": 10,
    "testsTotal": 10,
    "code": "#include <bits/stdc++.h>...",
    "errorMsg": null,
    "createdAt": "2026-03-12T14:30:00.000Z",
    "problem": {
      "id": "uuid",
      "title": "Two Sum",
      "slug": "two-sum"
    }
  }
}
```

_Nota: Usuário só pode ver suas próprias submissões (exceto admin)._

---

### GET `/api/submissions/me`

Lista submissões do usuário logado.

**Headers:** `Authorization: Bearer {accessToken}`

**Query Params:**

- `page`: número da página (default: 1)
- `limit`: itens por página (default: 20)
- `problemId`: filtrar por problema (opcional)
- `status`: ACCEPTED | WRONG_ANSWER | ... (opcional)
- `language`: C | CPP | PYTHON | JAVA (opcional)

**Response (200):**

```json
{
  "success": true,
  "data": {
    "items": [
      {
        "id": "uuid",
        "status": "ACCEPTED",
        "language": "CPP",
        "runtime": 45,
        "createdAt": "2026-03-12T14:30:00.000Z",
        "problem": {
          "id": "uuid",
          "title": "Two Sum",
          "slug": "two-sum"
        }
      }
    ],
    "meta": {
      "page": 1,
      "limit": 20,
      "total": 156,
      "totalPages": 8
    }
  }
}
```

---

## 💬 CLARIFICATIONS MODULE

### POST `/api/clarifications`

Cria uma clarificação.

**Headers:** `Authorization: Bearer {accessToken}`

**Request:**

```json
{
  "problemId": "uuid",
  "question": "O array pode ter números repetidos?"
}
```

**Response (201):**

```json
{
  "success": true,
  "data": {
    "id": "uuid",
    "question": "O array pode ter números repetidos?",
    "isAnswered": false,
    "createdAt": "2026-03-12T14:30:00.000Z"
  },
  "message": "Clarificação enviada. Aguarde a resposta."
}
```

---

### GET `/api/clarifications/me`

Lista clarificações do usuário.

**Headers:** `Authorization: Bearer {accessToken}`

**Response (200):**

```json
{
  "success": true,
  "data": [
    {
      "id": "uuid",
      "question": "O array pode ter números repetidos?",
      "answer": "Sim, pode haver números repetidos.",
      "isAnswered": true,
      "createdAt": "2026-03-12T14:30:00.000Z",
      "answeredAt": "2026-03-12T15:00:00.000Z",
      "problem": {
        "id": "uuid",
        "title": "Two Sum"
      }
    }
  ]
}
```

---

## 🏆 LEADERBOARD MODULE

### GET `/api/leaderboard`

Retorna placar geral.

**Query Params:**

- `page`: número da página (default: 1)
- `limit`: itens por página (default: 50, max: 100)

**Response (200):**

```json
{
  "success": true,
  "data": {
    "items": [
      {
        "rank": 1,
        "tagname": "maria",
        "name": "Maria Lima",
        "solved": 87,
        "submissions": 234
      },
      {
        "rank": 2,
        "tagname": "pedro",
        "name": "Pedro Santos",
        "solved": 82,
        "submissions": 198
      }
    ],
    "meta": {
      "page": 1,
      "limit": 50,
      "total": 1234,
      "totalPages": 25
    },
    "currentUser": {
      "rank": 127,
      "solved": 42
    }
  }
}
```

---

## 👨‍💼 ADMIN MODULE

Todas as rotas admin requerem role = ADMIN.

### GET `/api/admin/stats`

Estatísticas gerais.

**Response (200):**

```json
{
  "success": true,
  "data": {
    "totalUsers": 1234,
    "newUsersToday": 12,
    "totalProblems": 156,
    "totalSubmissions": 8901,
    "submissionsToday": 234,
    "pendingClarifications": 3,
    "submissionsByStatus": {
      "ACCEPTED": 5600,
      "WRONG_ANSWER": 2100,
      "TIME_LIMIT": 450,
      "RUNTIME_ERROR": 320,
      "COMPILE_ERROR": 431
    }
  }
}
```

---

### GET `/api/admin/problems`

Lista todos os exercícios (admin view).

**Query Params:**

- `page`, `limit`, `search`, `category`, `published`

**Response (200):**

```json
{
  "success": true,
  "data": {
    "items": [
      {
        "id": "uuid",
        "title": "Two Sum",
        "slug": "two-sum",
        "difficulty": "EASY",
        "category": "Arrays",
        "isPublished": true,
        "testCasesCount": 10,
        "submissionsCount": 1234,
        "createdAt": "2026-01-01T00:00:00.000Z"
      }
    ],
    "meta": { ... }
  }
}
```

---

### POST `/api/admin/problems`

Cria novo exercício.

**Request:**

```json
{
  "title": "Two Sum",
  "slug": "two-sum",
  "description": "Dado um array de inteiros...",
  "difficulty": "EASY",
  "categoryId": "uuid",
  "timeLimit": 1000,
  "memoryLimit": 256,
  "isPublished": true,
  "testCases": [
    {
      "input": "4 9\n2 7 11 15",
      "output": "0 1",
      "isHidden": false,
      "order": 1
    },
    {
      "input": "...",
      "output": "...",
      "isHidden": true,
      "order": 2
    }
  ]
}
```

**Response (201):**

```json
{
  "success": true,
  "data": { ... },
  "message": "Exercício criado com sucesso"
}
```

---

### PUT `/api/admin/problems/:id`

Atualiza exercício.

**Request:** (campos opcionais)

```json
{
  "title": "Two Sum Updated",
  "description": "...",
  "testCases": [ ... ]
}
```

---

### DELETE `/api/admin/problems/:id`

Exclui exercício.

**Response (200):**

```json
{
  "success": true,
  "message": "Exercício excluído com sucesso"
}
```

---

### GET `/api/admin/users`

Lista usuários.

**Query Params:**

- `page`, `limit`, `search`, `role`

---

### POST `/api/admin/users`

Cria usuário (bypass de verificação de email).

**Request:**

```json
{
  "name": "Novo Usuário",
  "email": "novo@email.com",
  "tagname": "novouser",
  "password": "SenhaTemporaria123",
  "role": "USER",
  "emailVerified": true
}
```

---

### PUT `/api/admin/users/:id`

Atualiza qualquer campo do usuário.

**Request:**

```json
{
  "name": "Nome Atualizado",
  "email": "novo@email.com",
  "tagname": "novotag",
  "role": "ADMIN",
  "emailVerified": true
}
```

---

### POST `/api/admin/users/:id/verify-email`

Verifica email manualmente.

---

### POST `/api/admin/users/:id/reset-password`

Envia email de reset ou define nova senha diretamente.

**Request:**

```json
{
  "sendEmail": true
}
```

ou

```json
{
  "newPassword": "NovaSenha123"
}
```

---

### GET `/api/admin/submissions`

Lista todas as submissões.

**Query Params:**

- `page`, `limit`, `status`, `language`, `userId`, `problemId`

---

### PUT `/api/admin/submissions/:id/force-status`

Força status de uma submissão (para corrigir bugs do judge).

**Request:**

```json
{
  "status": "ACCEPTED",
  "reason": "Bug no judge corrigido manualmente"
}
```

---

### GET `/api/admin/clarifications`

Lista clarificações.

**Query Params:**

- `status`: pending | answered

---

### POST `/api/admin/clarifications/:id/reply`

Responde clarificação.

**Request:**

```json
{
  "answer": "Sim, pode haver números repetidos no array."
}
```

---

## ⚙️ JUDGE SYSTEM

### Arquitetura

```
┌─────────────────────────────────────────────────────────┐
│                    SUBMISSION                           │
└─────────────────────────────────────────────────────────┘
                          │
                          ▼
┌─────────────────────────────────────────────────────────┐
│                   BULL QUEUE (Redis)                    │
└─────────────────────────────────────────────────────────┘
                          │
                          ▼
┌─────────────────────────────────────────────────────────┐
│                    JUDGE WORKER                         │
│                                                         │
│  1. Pull submission from queue                          │
│  2. Create Docker container                             │
│  3. Copy code to container                              │
│  4. Compile (if needed)                                 │
│  5. Run against each test case                          │
│  6. Compare output                                      │
│  7. Update submission status                            │
│  8. Destroy container                                   │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

### Docker Images por Linguagem

```dockerfile
# images/cpp/Dockerfile
FROM gcc:12
WORKDIR /app
RUN useradd -m judge
USER judge

# images/python/Dockerfile
FROM python:3.11-slim
WORKDIR /app
RUN useradd -m judge
USER judge

# images/java/Dockerfile
FROM openjdk:17-slim
WORKDIR /app
RUN useradd -m judge
USER judge

# images/c/Dockerfile
FROM gcc:12
WORKDIR /app
RUN useradd -m judge
USER judge
```

### Comandos de Execução

```typescript
// src/judge/judge.service.ts

const LANGUAGE_CONFIG = {
  C: {
    image: "wassabi-judge-c",
    compile: "gcc -o main main.c -lm",
    run: "./main",
    sourceFile: "main.c",
  },
  CPP: {
    image: "wassabi-judge-cpp",
    compile: "g++ -O2 -o main main.cpp -lm",
    run: "./main",
    sourceFile: "main.cpp",
  },
  PYTHON: {
    image: "wassabi-judge-python",
    compile: null, // interpreted
    run: "python3 main.py",
    sourceFile: "main.py",
  },
  JAVA: {
    image: "wassabi-judge-java",
    compile: "javac Main.java",
    run: "java Main",
    sourceFile: "Main.java",
  },
};
```

### Limites de Recursos

```typescript
const CONTAINER_LIMITS = {
  memory: "256m", // 256 MB
  cpus: "0.5", // 50% de 1 CPU
  timeout: 10000, // 10 segundos max
  networkDisabled: true,
  readOnlyRootfs: true,
};
```

### Fluxo de Julgamento

```typescript
async judgeSubmission(submissionId: string): Promise<void> {
  const submission = await this.getSubmission(submissionId);
  const problem = await this.getProblem(submission.problemId);
  const testCases = await this.getTestCases(problem.id);

  // 1. Update status to COMPILING
  await this.updateStatus(submissionId, 'COMPILING');

  // 2. Create container
  const container = await this.createContainer(submission.language);

  try {
    // 3. Copy code
    await this.copyCode(container, submission.code, submission.language);

    // 4. Compile (if needed)
    if (LANGUAGE_CONFIG[submission.language].compile) {
      const compileResult = await this.compile(container, submission.language);
      if (!compileResult.success) {
        await this.updateStatus(submissionId, 'COMPILE_ERROR', {
          errorMsg: compileResult.error,
        });
        return;
      }
    }

    // 5. Update status to RUNNING
    await this.updateStatus(submissionId, 'RUNNING');

    // 6. Run against test cases
    let passed = 0;
    let totalRuntime = 0;
    let maxMemory = 0;

    for (const testCase of testCases) {
      const result = await this.runTestCase(
        container,
        testCase,
        problem.timeLimit,
        problem.memoryLimit,
      );

      if (result.status === 'TLE') {
        await this.updateStatus(submissionId, 'TIME_LIMIT', {
          testsPassed: passed,
          testsTotal: testCases.length,
        });
        return;
      }

      if (result.status === 'MLE') {
        await this.updateStatus(submissionId, 'MEMORY_LIMIT', {
          testsPassed: passed,
          testsTotal: testCases.length,
        });
        return;
      }

      if (result.status === 'RE') {
        await this.updateStatus(submissionId, 'RUNTIME_ERROR', {
          testsPassed: passed,
          testsTotal: testCases.length,
          errorMsg: result.error,
        });
        return;
      }

      if (!this.compareOutput(result.output, testCase.output)) {
        await this.updateStatus(submissionId, 'WRONG_ANSWER', {
          testsPassed: passed,
          testsTotal: testCases.length,
        });
        return;
      }

      passed++;
      totalRuntime += result.runtime;
      maxMemory = Math.max(maxMemory, result.memory);
    }

    // 7. All passed!
    await this.updateStatus(submissionId, 'ACCEPTED', {
      testsPassed: passed,
      testsTotal: testCases.length,
      runtime: Math.round(totalRuntime / testCases.length),
      memory: maxMemory,
    });

  } finally {
    // 8. Cleanup
    await this.destroyContainer(container);
  }
}
```

---

## 🐳 INFRAESTRUTURA DOCKER

### docker-compose.yml

```yaml
version: "3.8"

services:
  # API Principal
  api:
    build:
      context: .
      dockerfile: Dockerfile
    ports:
      - "3000:3000"
    environment:
      - NODE_ENV=production
      - DATABASE_URL=postgresql://postgres:postgres@db:5432/wassabi
      - REDIS_URL=redis://redis:6379
      - JWT_SECRET=${JWT_SECRET}
      - SMTP_HOST=${SMTP_HOST}
      - SMTP_USER=${SMTP_USER}
      - SMTP_PASS=${SMTP_PASS}
      - FRONTEND_URL=${FRONTEND_URL}
    depends_on:
      - db
      - redis
    volumes:
      - /var/run/docker.sock:/var/run/docker.sock
    restart: unless-stopped

  # Judge Worker
  judge-worker:
    build:
      context: .
      dockerfile: Dockerfile.worker
    environment:
      - DATABASE_URL=postgresql://postgres:postgres@db:5432/wassabi
      - REDIS_URL=redis://redis:6379
    depends_on:
      - db
      - redis
    volumes:
      - /var/run/docker.sock:/var/run/docker.sock
    restart: unless-stopped

  # PostgreSQL
  db:
    image: postgres:15-alpine
    environment:
      - POSTGRES_USER=postgres
      - POSTGRES_PASSWORD=postgres
      - POSTGRES_DB=wassabi
    volumes:
      - postgres_data:/var/lib/postgresql/data
    restart: unless-stopped

  # Redis
  redis:
    image: redis:7-alpine
    volumes:
      - redis_data:/data
    restart: unless-stopped

volumes:
  postgres_data:
  redis_data:
```

### Dockerfile (API)

```dockerfile
# Dockerfile
FROM node:20-alpine AS builder

WORKDIR /app

COPY package*.json ./
RUN npm ci

COPY . .
RUN npm run build

# Production
FROM node:20-alpine

WORKDIR /app

# Install docker CLI for judge
RUN apk add --no-cache docker-cli

COPY --from=builder /app/dist ./dist
COPY --from=builder /app/node_modules ./node_modules
COPY --from=builder /app/package*.json ./
COPY --from=builder /app/prisma ./prisma

RUN npx prisma generate

EXPOSE 3000

CMD ["npm", "run", "start:prod"]
```

### Build Judge Images

```bash
#!/bin/bash
# scripts/build-judge-images.sh

docker build -t wassabi-judge-c ./judge-images/c
docker build -t wassabi-judge-cpp ./judge-images/cpp
docker build -t wassabi-judge-python ./judge-images/python
docker build -t wassabi-judge-java ./judge-images/java
```

---

## 📁 ESTRUTURA DE PASTAS

```
wassabi-coder-backend/
├── prisma/
│   ├── schema.prisma
│   ├── migrations/
│   └── seed.ts
├── judge-images/
│   ├── c/
│   │   └── Dockerfile
│   ├── cpp/
│   │   └── Dockerfile
│   ├── python/
│   │   └── Dockerfile
│   └── java/
│       └── Dockerfile
├── scripts/
│   ├── build-judge-images.sh
│   └── seed.sh
├── src/
│   ├── auth/
│   │   ├── auth.controller.ts
│   │   ├── auth.service.ts
│   │   ├── auth.module.ts
│   │   ├── dto/
│   │   │   ├── login.dto.ts
│   │   │   ├── register.dto.ts
│   │   │   └── reset-password.dto.ts
│   │   ├── guards/
│   │   │   ├── jwt-auth.guard.ts
│   │   │   └── roles.guard.ts
│   │   └── strategies/
│   │       └── jwt.strategy.ts
│   ├── users/
│   │   ├── users.controller.ts
│   │   ├── users.service.ts
│   │   ├── users.module.ts
│   │   └── dto/
│   │       └── update-user.dto.ts
│   ├── problems/
│   │   ├── problems.controller.ts
│   │   ├── problems.service.ts
│   │   ├── problems.module.ts
│   │   └── dto/
│   │       ├── create-problem.dto.ts
│   │       └── problem-filters.dto.ts
│   ├── submissions/
│   │   ├── submissions.controller.ts
│   │   ├── submissions.service.ts
│   │   ├── submissions.module.ts
│   │   └── dto/
│   │       └── create-submission.dto.ts
│   ├── clarifications/
│   │   ├── clarifications.controller.ts
│   │   ├── clarifications.service.ts
│   │   └── clarifications.module.ts
│   ├── leaderboard/
│   │   ├── leaderboard.controller.ts
│   │   ├── leaderboard.service.ts
│   │   └── leaderboard.module.ts
│   ├── admin/
│   │   ├── admin.controller.ts
│   │   ├── admin.service.ts
│   │   └── admin.module.ts
│   ├── judge/
│   │   ├── judge.service.ts
│   │   ├── judge.processor.ts
│   │   ├── judge.module.ts
│   │   └── language.config.ts
│   ├── mail/
│   │   ├── mail.service.ts
│   │   ├── mail.module.ts
│   │   └── templates/
│   │       ├── verification.hbs
│   │       └── password-reset.hbs
│   ├── common/
│   │   ├── decorators/
│   │   │   ├── roles.decorator.ts
│   │   │   └── current-user.decorator.ts
│   │   ├── filters/
│   │   │   └── http-exception.filter.ts
│   │   ├── interceptors/
│   │   │   └── transform.interceptor.ts
│   │   └── dto/
│   │       └── pagination.dto.ts
│   ├── prisma/
│   │   ├── prisma.service.ts
│   │   └── prisma.module.ts
│   ├── app.module.ts
│   └── main.ts
├── test/
│   └── ...
├── .env.example
├── docker-compose.yml
├── Dockerfile
├── Dockerfile.worker
├── nest-cli.json
├── package.json
├── tsconfig.json
└── README.md
```

---

## 🚀 COMANDOS DE SETUP

```bash
# Criar projeto
npx @nestjs/cli new wassabi-coder-backend

# Instalar dependências
cd wassabi-coder-backend

npm install @nestjs/config @nestjs/jwt @nestjs/passport passport passport-jwt bcrypt
npm install @prisma/client
npm install @nestjs/bull bull
npm install @nestjs/swagger swagger-ui-express
npm install @nestjs/throttler
npm install helmet
npm install class-validator class-transformer
npm install nodemailer @nestjs-modules/mailer handlebars
npm install ioredis
npm install -D prisma @types/bcrypt @types/passport-jwt @types/nodemailer

# Setup Prisma
npx prisma init

# Após configurar schema.prisma
npx prisma migrate dev --name init
npx prisma generate

# Build judge images
chmod +x scripts/build-judge-images.sh
./scripts/build-judge-images.sh

# Rodar desenvolvimento
npm run start:dev

# Rodar produção
docker-compose up -d
```

---

## 🔧 VARIÁVEIS DE AMBIENTE

```env
# .env.example

# App
NODE_ENV=development
PORT=3000

# Database
DATABASE_URL=postgresql://postgres:postgres@localhost:5432/wassabi

# Redis
REDIS_URL=redis://localhost:6379

# JWT
JWT_SECRET=your-super-secret-jwt-key-here
JWT_EXPIRES_IN=15m
JWT_REFRESH_EXPIRES_IN=7d

# SMTP (Email)
SMTP_HOST=smtp.gmail.com
SMTP_PORT=587
SMTP_USER=your-email@gmail.com
SMTP_PASS=your-app-password
SMTP_FROM="Wassabi Coder <noreply@wassabicoder.com>"

# Frontend
FRONTEND_URL=http://localhost:5173

# Judge
JUDGE_TIMEOUT_MS=10000
JUDGE_MEMORY_LIMIT_MB=256
```

---

## 📚 DOCUMENTAÇÃO SWAGGER

Acessível em `/api/docs` quando a aplicação estiver rodando.

```typescript
// src/main.ts
import { DocumentBuilder, SwaggerModule } from "@nestjs/swagger";

const config = new DocumentBuilder()
  .setTitle("Wassabi Coder API")
  .setDescription("API da plataforma de programação competitiva Wassabi Coder")
  .setVersion("1.0")
  .addBearerAuth()
  .build();

const document = SwaggerModule.createDocument(app, config);
SwaggerModule.setup("api/docs", app, document);
```

---

## 📝 CRÉDITOS

**Wassabi Coder** - Plataforma de Programação Competitiva

Desenvolvido por **vleonel** © 2026

---

_Este documento serve como prompt completo para implementação do backend da plataforma Wassabi Coder._
