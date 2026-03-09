# 🍣 WASSABI CODER - DOCUMENTO FRONTEND

> **Plataforma de Programação Competitiva**  
> Desenvolvido por **vleonel**

---

## 📋 VISÃO GERAL

**Wassabi Coder** é uma plataforma minimalista de programação competitiva onde usuários podem resolver exercícios de código, submeter soluções em múltiplas linguagens (C, C++, Python, Java) e acompanhar seu progresso.

### Stack Frontend

- **Framework**: React 18+
- **Build Tool**: Vite
- **Estilização**: Tailwind CSS
- **HTTP Client**: Axios
- **Routing**: React Router v6
- **State Management**: Zustand (leve e simples)
- **Notificações/Toasts**: React Hot Toast
- **Editor de Código**: Monaco Editor (VS Code no browser)

---

## 🎨 DESIGN SYSTEM

### Filosofia

- **Minimalista**: Menos é mais. Sem elementos desnecessários.
- **Moderno**: Bordas suaves, espaçamento generoso, tipografia limpa.
- **Funcional**: Cada elemento tem propósito claro.
- **Sem Dark Mode**: Apenas tema claro, consistente.

### Paleta de Cores

```css
/* Cores Principais */
--primary: #10b981; /* Verde Wassabi - Ações principais */
--primary-hover: #059669; /* Verde escuro - Hover */
--secondary: #6366f1; /* Indigo - Elementos secundários */

/* Vereditos */
--accepted: #22c55e; /* Verde - AC */
--wrong-answer: #ef4444; /* Vermelho - WA */
--time-limit: #f59e0b; /* Amarelo - TLE */
--runtime-error: #8b5cf6; /* Roxo - RE */
--compile-error: #ec4899; /* Rosa - CE */
--pending: #6b7280; /* Cinza - Em fila */

/* Neutros */
--background: #fafafa; /* Fundo geral */
--surface: #ffffff; /* Cards e containers */
--border: #e5e7eb; /* Bordas */
--text-primary: #111827; /* Texto principal */
--text-secondary: #6b7280; /* Texto secundário */
--text-muted: #9ca3af; /* Texto desabilitado */
```

### Tipografia

```css
/* Font Family */
font-family:
  "Inter",
  -apple-system,
  BlinkMacSystemFont,
  sans-serif;

/* Font para código */
font-family: "JetBrains Mono", "Fira Code", monospace;

/* Tamanhos */
--text-xs: 0.75rem; /* 12px */
--text-sm: 0.875rem; /* 14px */
--text-base: 1rem; /* 16px */
--text-lg: 1.125rem; /* 18px */
--text-xl: 1.25rem; /* 20px */
--text-2xl: 1.5rem; /* 24px */
--text-3xl: 1.875rem; /* 30px */
```

### Espaçamento

```css
/* Sistema de 4px */
--space-1: 0.25rem; /* 4px */
--space-2: 0.5rem; /* 8px */
--space-3: 0.75rem; /* 12px */
--space-4: 1rem; /* 16px */
--space-6: 1.5rem; /* 24px */
--space-8: 2rem; /* 32px */
--space-12: 3rem; /* 48px */
```

### Componentes Base

#### Botões

```jsx
// Primário
<button className="bg-primary hover:bg-primary-hover text-white px-6 py-2.5 rounded-lg font-medium transition-colors">
  Submeter
</button>

// Secundário
<button className="bg-white border border-border hover:bg-gray-50 text-text-primary px-6 py-2.5 rounded-lg font-medium transition-colors">
  Cancelar
</button>

// Ghost
<button className="text-text-secondary hover:text-text-primary hover:bg-gray-100 px-4 py-2 rounded-lg transition-colors">
  Ver mais
</button>
```

#### Inputs

```jsx
<input
  type="text"
  className="w-full px-4 py-2.5 border border-border rounded-lg focus:outline-none focus:ring-2 focus:ring-primary/20 focus:border-primary transition-all"
  placeholder="Digite aqui..."
/>
```

#### Cards

```jsx
<div className="bg-surface border border-border rounded-xl p-6 shadow-sm">
  {/* Conteúdo */}
</div>
```

---

## 🗺️ ESTRUTURA DE PÁGINAS

### Páginas Públicas (Não autenticado)

```
/                    → Landing Page
/login               → Login
/register            → Cadastro
/verify-email/:token → Verificação de email
/forgot-password     → Recuperar senha
/reset-password/:token → Redefinir senha
```

### Páginas Autenticadas (Contestant)

```
/dashboard           → Dashboard principal
/problems            → Lista de exercícios
/problems/:id        → Detalhe + Submissão
/submissions         → Minhas submissões
/submissions/:id     → Detalhe da submissão
/profile             → Meu perfil
/profile/edit        → Editar perfil
/leaderboard         → Placar geral
/clarifications      → Minhas clarificações
```

### Páginas Admin

```
/admin               → Dashboard admin
/admin/problems      → Gerenciar exercícios
/admin/problems/new  → Criar exercício
/admin/problems/:id  → Editar exercício
/admin/users         → Gerenciar usuários
/admin/users/:id     → Editar usuário
/admin/submissions   → Todas as submissões
/admin/clarifications → Clarificações pendentes
```

---

## 📱 TELAS DETALHADAS

### 1. Landing Page (`/`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi Coder                    [Login] [Cadastro] │
├─────────────────────────────────────────────────────────┤
│                                                         │
│           Aprimore suas habilidades de                  │
│              programação competitiva                    │
│                                                         │
│     [Começar Agora]                                     │
│                                                         │
│  ┌──────────┐  ┌──────────┐  ┌──────────┐              │
│  │ 150+     │  │ 1.2k     │  │ 4        │              │
│  │Exercícios│  │ Usuários │  │Linguagens│              │
│  └──────────┘  └──────────┘  └──────────┘              │
│                                                         │
│─────────────────────────────────────────────────────────│
│  Desenvolvido com 💚 por vleonel                        │
└─────────────────────────────────────────────────────────┘
```

**Elementos:**

- Header fixo com logo e botões de ação
- Hero section com título e CTA
- Estatísticas dinâmicas (total de exercícios, usuários, linguagens)
- Footer simples com créditos

---

### 2. Login (`/login`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│                    🍣 Wassabi Coder                     │
├─────────────────────────────────────────────────────────┤
│                                                         │
│              ┌─────────────────────────┐                │
│              │                         │                │
│              │     Entrar na conta     │                │
│              │                         │                │
│              │  Email                  │                │
│              │  ┌───────────────────┐  │                │
│              │  │                   │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  Senha                  │                │
│              │  ┌───────────────────┐  │                │
│              │  │                   │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  [Esqueci minha senha]  │                │
│              │                         │                │
│              │  ┌───────────────────┐  │                │
│              │  │      Entrar       │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  Não tem conta?         │                │
│              │  Cadastre-se            │                │
│              │                         │                │
│              └─────────────────────────┘                │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Validações:**

- Email: formato válido, obrigatório
- Senha: mínimo 6 caracteres, obrigatório
- Mostrar erro inline se credenciais inválidas
- Loading state no botão durante requisição

**API Consumida:**

```
POST /api/auth/login
```

---

### 3. Cadastro (`/register`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│                    🍣 Wassabi Coder                     │
├─────────────────────────────────────────────────────────┤
│                                                         │
│              ┌─────────────────────────┐                │
│              │                         │                │
│              │     Criar conta         │                │
│              │                         │                │
│              │  Nome completo          │                │
│              │  ┌───────────────────┐  │                │
│              │  │                   │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  Tagname (@usuario)     │                │
│              │  ┌───────────────────┐  │                │
│              │  │ @                 │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  Email                  │                │
│              │  ┌───────────────────┐  │                │
│              │  │                   │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  Senha                  │                │
│              │  ┌───────────────────┐  │                │
│              │  │                   │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  Confirmar senha        │                │
│              │  ┌───────────────────┐  │                │
│              │  │                   │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  ┌───────────────────┐  │                │
│              │  │   Criar conta     │  │                │
│              │  └───────────────────┘  │                │
│              │                         │                │
│              │  Já tem conta? Entre    │                │
│              │                         │                │
│              └─────────────────────────┘                │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Validações:**

- Nome: mínimo 2 caracteres
- Tagname: alfanumérico, underscore, 3-20 chars, único
- Email: formato válido, único
- Senha: mínimo 8 caracteres, 1 número, 1 letra
- Confirmar senha: deve coincidir

**Após cadastro:**

- Exibir mensagem: "Verifique seu email para ativar a conta"
- Redirecionar para /login

**API Consumida:**

```
POST /api/auth/register
```

---

### 4. Dashboard (`/dashboard`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]  👤   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Olá, João! 👋                                          │
│                                                         │
│  ┌────────────┐ ┌────────────┐ ┌────────────┐          │
│  │ Resolvidos │ │  Tentados  │ │  Posição   │          │
│  │    42      │ │     58     │ │   #127     │          │
│  │ exercícios │ │ exercícios │ │  no placar │          │
│  └────────────┘ └────────────┘ └────────────┘          │
│                                                         │
│  ─────────────────────────────────────────────────────  │
│                                                         │
│  📊 Últimas Submissões                                  │
│  ┌─────────────────────────────────────────────────┐   │
│  │ #1234  Two Sum           C++    ✅ AC    2min   │   │
│  │ #1233  Binary Search     Python ❌ WA    5min   │   │
│  │ #1232  Merge Sort        Java   ✅ AC    8min   │   │
│  └─────────────────────────────────────────────────┘   │
│                           [Ver todas →]                 │
│                                                         │
│  ─────────────────────────────────────────────────────  │
│                                                         │
│  🎯 Exercícios Recomendados                             │
│  ┌─────────────┐ ┌─────────────┐ ┌─────────────┐       │
│  │ Prefix Sum  │ │ Kadane      │ │ Two Pointer │       │
│  │ ⭐ Médio    │ │ ⭐ Médio    │ │ ⭐⭐ Difícil │       │
│  │ 234 pessoas │ │ 189 pessoas │ │ 87 pessoas  │       │
│  └─────────────┘ └─────────────┘ └─────────────┘       │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**APIs Consumidas:**

```
GET /api/users/me/stats
GET /api/submissions/me?limit=5
GET /api/problems/recommended
```

---

### 5. Lista de Exercícios (`/problems`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]  👤   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Exercícios                                             │
│                                                         │
│  ┌─────────────────────────────────────────────────┐   │
│  │ 🔍 Buscar exercício...                          │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
│  Filtros:                                               │
│  [Todas] [Arrays] [Strings] [DP] [Grafos] [Math]       │
│  [Todos] [Fácil] [Médio] [Difícil]                     │
│  [Todos] [Resolvidos] [Não resolvidos]                 │
│                                                         │
│  ┌─────────────────────────────────────────────────┐   │
│  │ #  │ Título          │ Categoria │ Dif. │ Resol │   │
│  ├─────────────────────────────────────────────────┤   │
│  │ ✅ │ Two Sum         │ Arrays    │ ⭐   │  342  │   │
│  │ ✅ │ Valid Parens    │ Strings   │ ⭐   │  289  │   │
│  │ ❌ │ Longest Substr  │ Strings   │ ⭐⭐ │  156  │   │
│  │ ❌ │ Merge Intervals │ Arrays    │ ⭐⭐ │  134  │   │
│  │ ⬜ │ LRU Cache       │ Design    │ ⭐⭐⭐│   67  │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
│  [← Anterior]  Página 1 de 15  [Próxima →]             │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Legenda de Status:**

- ✅ Verde: Resolvido pelo usuário (AC)
- ❌ Vermelho: Tentou mas não resolveu
- ⬜ Cinza: Nunca tentou

**APIs Consumidas:**

```
GET /api/problems?page=1&limit=20&category=&difficulty=&status=
GET /api/categories
```

---

### 6. Detalhe do Exercício (`/problems/:id`)

**Layout Split-View:**

````
┌─────────────────────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]                   👤  │
├────────────────────────────────┬────────────────────────────────────────┤
│                                │                                        │
│  Two Sum                       │  Linguagem: [C++  ▼]                   │
│  ⭐ Fácil  •  Arrays  •  342   │                                        │
│                                │  ┌────────────────────────────────┐   │
│  ─────────────────────────     │  │ #include <bits/stdc++.h>       │   │
│                                │  │ using namespace std;           │   │
│  Dado um array de inteiros     │  │                                │   │
│  nums e um inteiro target,     │  │ int main() {                   │   │
│  retorne os índices dos dois   │  │     // Seu código aqui         │   │
│  números que somam target.     │  │                                │   │
│                                │  │     return 0;                  │   │
│  **Exemplo 1:**                │  │ }                              │   │
│  ```                           │  │                                │   │
│  Input: nums = [2,7,11,15]     │  │                                │   │
│         target = 9             │  │                                │   │
│  Output: [0,1]                 │  │                                │   │
│  ```                           │  │                                │   │
│                                │  │                                │   │
│  **Restrições:**               │  │                                │   │
│  - 2 <= nums.length <= 10^4    │  │                                │   │
│  - -10^9 <= nums[i] <= 10^9    │  │                                │   │
│                                │  └────────────────────────────────┘   │
│  ─────────────────────────     │                                        │
│                                │  ┌────────────────────────────────┐   │
│  👥 Quem resolveu (342)        │  │         Submeter Código        │   │
│  @joao, @maria, @pedro...      │  └────────────────────────────────┘   │
│  [Ver todos]                   │                                        │
│                                │  [Pedir Clarificação]                  │
│  ─────────────────────────     │                                        │
│                                │  ─────────────────────────────────     │
│  📝 Minhas Submissões          │                                        │
│  #1234 ✅ AC C++ 2min          │  Minhas Submissões Recentes:           │
│  #1230 ❌ WA C++ 5min          │  • #1234 ✅ AC - 12/03 14:30          │
│  [Ver todas]                   │  • #1230 ❌ WA - 12/03 14:25          │
│                                │                                        │
└────────────────────────────────┴────────────────────────────────────────┘
````

**Funcionalidades:**

- Editor Monaco com syntax highlighting
- Dropdown de linguagem (C, C++, Python, Java)
- Templates padrão por linguagem
- Lista de quem resolveu (clicável para ver perfil)
- Histórico de submissões do usuário neste problema

**APIs Consumidas:**

```
GET /api/problems/:id
GET /api/problems/:id/solvers?limit=10
GET /api/submissions/me?problemId=:id
POST /api/submissions
POST /api/clarifications
```

---

### 7. Popup de Submissão (Pending/Result)

**Estado: Em Fila (Pending)**

```
┌──────────────────────────────────────┐
│                                      │
│     ⏳ Processando submissão...      │
│                                      │
│     ████████░░░░░░░░  Compilando     │
│                                      │
│     Aguarde enquanto testamos        │
│     seu código.                      │
│                                      │
└──────────────────────────────────────┘
```

**Estado: Aceito (AC)**

```
┌──────────────────────────────────────┐
│                                      │
│     ✅ ACEITO                        │
│                                      │
│     Parabéns! Sua solução passou     │
│     em todos os casos de teste.      │
│                                      │
│     ⏱️ Tempo: 45ms                   │
│     💾 Memória: 2.1 MB               │
│                                      │
│     [Ver Submissão]  [Continuar]     │
│                                      │
└──────────────────────────────────────┘
```

**Estado: Wrong Answer (WA)**

```
┌──────────────────────────────────────┐
│                                      │
│     ❌ RESPOSTA INCORRETA            │
│                                      │
│     Seu código não passou em         │
│     todos os casos de teste.         │
│                                      │
│     Passou: 7/10 casos               │
│                                      │
│     [Ver Detalhes]  [Tentar Novamente]│
│                                      │
└──────────────────────────────────────┘
```

**Estado: Compile Error (CE)**

```
┌──────────────────────────────────────┐
│                                      │
│     🔴 ERRO DE COMPILAÇÃO            │
│                                      │
│     ┌──────────────────────────┐     │
│     │ error: expected ';'      │     │
│     │ at line 15, column 23    │     │
│     │                          │     │
│     │ int x = 5                │     │
│     │               ^          │     │
│     └──────────────────────────┘     │
│                                      │
│     [Fechar]                         │
│                                      │
└──────────────────────────────────────┘
```

**Implementação técnica:**

- Polling a cada 2 segundos enquanto status = "pending"
- Ou usar WebSocket para real-time updates
- Animação suave de transição entre estados

---

### 8. Minhas Submissões (`/submissions`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]  👤   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Minhas Submissões                                      │
│                                                         │
│  Filtros:                                               │
│  [Todos] [AC] [WA] [TLE] [RE] [CE]                     │
│  Linguagem: [Todas ▼]                                   │
│                                                         │
│  ┌─────────────────────────────────────────────────┐   │
│  │ ID    │ Problema        │ Status │ Lang │ Data  │   │
│  ├─────────────────────────────────────────────────┤   │
│  │ #1234 │ Two Sum         │ ✅ AC  │ C++  │ Hoje  │   │
│  │ #1233 │ Two Sum         │ ❌ WA  │ C++  │ Hoje  │   │
│  │ #1232 │ Binary Search   │ ✅ AC  │ Py   │ Ontem │   │
│  │ #1231 │ Merge Sort      │ ⏱️ TLE │ Java │ Ontem │   │
│  │ #1230 │ Valid Parens    │ 🔴 CE  │ C    │ 2d    │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
│  [← Anterior]  Página 1 de 8  [Próxima →]              │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Clique na linha:** Abre detalhe da submissão

**API Consumida:**

```
GET /api/submissions/me?page=1&limit=20&status=&language=
```

---

### 9. Detalhe da Submissão (`/submissions/:id`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]  👤   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  Submissão #1234                                        │
│                                                         │
│  ┌───────────────────────────────────────────────────┐ │
│  │ Problema:    Two Sum                              │ │
│  │ Status:      ✅ Aceito                            │ │
│  │ Linguagem:   C++                                  │ │
│  │ Tempo:       45ms                                 │ │
│  │ Memória:     2.1 MB                               │ │
│  │ Submetido:   12/03/2026 14:30:45                  │ │
│  └───────────────────────────────────────────────────┘ │
│                                                         │
│  Código Submetido:                                      │
│  ┌───────────────────────────────────────────────────┐ │
│  │  1 │ #include <bits/stdc++.h>                     │ │
│  │  2 │ using namespace std;                         │ │
│  │  3 │                                              │ │
│  │  4 │ int main() {                                 │ │
│  │  5 │     int n, target;                           │ │
│  │  6 │     cin >> n >> target;                      │ │
│  │  7 │     vector<int> nums(n);                     │ │
│  │  8 │     for(int i = 0; i < n; i++)               │ │
│  │  9 │         cin >> nums[i];                      │ │
│  │ 10 │     // ... resto do código                   │ │
│  └───────────────────────────────────────────────────┘ │
│                                                         │
│  Casos de Teste:                                        │
│  ┌───────────────────────────────────────────────────┐ │
│  │ Caso 1: ✅ Passou (12ms)                          │ │
│  │ Caso 2: ✅ Passou (8ms)                           │ │
│  │ Caso 3: ✅ Passou (15ms)                          │ │
│  │ ... 7 casos ocultos ✅                            │ │
│  └───────────────────────────────────────────────────┘ │
│                                                         │
│  [← Voltar para Submissões]  [Ir para o Problema →]    │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Se houver erro de compilação, mostrar:**

```
Erro de Compilação:
┌───────────────────────────────────────────────────────┐
│ main.cpp:15:23: error: expected ';' before 'return'   │
│    15 |     int x = 5                                 │
│       |                       ^                       │
│       |                       ;                       │
│    16 |     return 0;                                 │
└───────────────────────────────────────────────────────┘
```

**API Consumida:**

```
GET /api/submissions/:id
```

---

### 10. Perfil (`/profile` e `/profile/:tagname`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]  👤   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  ┌─────────────────────────────────────────────────┐   │
│  │                                                   │   │
│  │  ┌────┐                                          │   │
│  │  │ JD │  João da Silva                           │   │
│  │  └────┘  @joaodev                                │   │
│  │          joao@email.com                          │   │
│  │                                                   │   │
│  │          Membro desde: 01/01/2026                │   │
│  │                                                   │   │
│  │  [Editar Perfil]                                 │   │
│  │                                                   │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
│  ┌────────────┐ ┌────────────┐ ┌────────────┐          │
│  │ Resolvidos │ │  Posição   │ │ Submissões │          │
│  │    42      │ │   #127     │ │    156     │          │
│  └────────────┘ └────────────┘ └────────────┘          │
│                                                         │
│  ─────────────────────────────────────────────────────  │
│                                                         │
│  Exercícios Resolvidos:                                 │
│  ┌─────────────────────────────────────────────────┐   │
│  │ ✅ Two Sum              ⭐     Arrays           │   │
│  │ ✅ Valid Parentheses    ⭐     Strings          │   │
│  │ ✅ Merge Intervals      ⭐⭐   Arrays           │   │
│  │ ✅ LRU Cache            ⭐⭐⭐  Design          │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Avatar:**

- Não há upload de avatar
- Usar iniciais do nome em círculo colorido (cor gerada a partir do tagname)

**APIs Consumidas:**

```
GET /api/users/me           (próprio perfil)
GET /api/users/:tagname     (perfil de outro usuário)
GET /api/users/:id/solved   (exercícios resolvidos)
```

---

### 11. Leaderboard (`/leaderboard`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]  👤   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  🏆 Placar Geral                                        │
│                                                         │
│  ┌─────────────────────────────────────────────────┐   │
│  │ #   │ Usuário         │ Resolvidos │ Submissões│   │
│  ├─────────────────────────────────────────────────┤   │
│  │ 🥇  │ @maria          │    87      │    234    │   │
│  │ 🥈  │ @pedro          │    82      │    198    │   │
│  │ 🥉  │ @ana            │    79      │    210    │   │
│  │  4  │ @carlos         │    71      │    189    │   │
│  │  5  │ @julia          │    68      │    156    │   │
│  │ ... │                 │            │           │   │
│  │ 127 │ @joaodev  ← Você│    42      │    156    │   │
│  │ ... │                 │            │           │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
│  [← Anterior]  Página 1 de 50  [Próxima →]             │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**Funcionalidades:**

- Destaque na linha do usuário logado
- Medalhas para top 3
- Clique no usuário abre perfil
- Ordenação por exercícios resolvidos

**API Consumida:**

```
GET /api/leaderboard?page=1&limit=50
```

---

### 12. Clarificações (`/clarifications`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi    [Exercícios] [Submissões] [Placar]  👤   │
├─────────────────────────────────────────────────────────┤
│                                                         │
│  💬 Minhas Clarificações                                │
│                                                         │
│  ┌─────────────────────────────────────────────────┐   │
│  │ Two Sum • 12/03/2026 14:30                       │   │
│  │                                                   │   │
│  │ Você: O array pode ter números repetidos?        │   │
│  │                                                   │   │
│  │ Admin: Sim, pode haver números repetidos no      │   │
│  │ array, mas a solução será sempre única.          │   │
│  │                                              ✅   │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
│  ┌─────────────────────────────────────────────────┐   │
│  │ Binary Search • 11/03/2026 10:15                 │   │
│  │                                                   │   │
│  │ Você: O array já vem ordenado?                   │   │
│  │                                                   │   │
│  │ ⏳ Aguardando resposta...                        │   │
│  └─────────────────────────────────────────────────┘   │
│                                                         │
└─────────────────────────────────────────────────────────┘
```

**API Consumida:**

```
GET /api/clarifications/me
```

---

## 👨‍💼 PAINEL ADMIN

### 13. Dashboard Admin (`/admin`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi Admin            [Sair do Admin] [Perfil]   │
├────────────────┬────────────────────────────────────────┤
│                │                                        │
│  📊 Dashboard  │  Dashboard Administrativo              │
│  📝 Exercícios │                                        │
│  👥 Usuários   │  ┌──────────┐ ┌──────────┐ ┌──────────┐│
│  📤 Submissões │  │ Usuários │ │Exercícios│ │Submissões││
│  💬 Clarific.  │  │   1.234  │ │   156    │ │  8.901   ││
│                │  │  +12 hoje│ │  +3 hoje │ │ +234 hoje││
│  ──────────    │  └──────────┘ └──────────┘ └──────────┘│
│                │                                        │
│  🏠 Ir para    │  ┌──────────────────────────────────┐ │
│     Site       │  │ 📊 Submissões Últimas 24h         │ │
│                │  │                                    │ │
│                │  │  ████████████████░░░░  156 AC     │ │
│                │  │  ████████░░░░░░░░░░░░   67 WA     │ │
│                │  │  ██░░░░░░░░░░░░░░░░░░   11 TLE    │ │
│                │  └──────────────────────────────────┘ │
│                │                                        │
│                │  ⚠️ Clarificações Pendentes: 3         │
│                │  [Ver Clarificações →]                 │
│                │                                        │
└────────────────┴────────────────────────────────────────┘
```

**APIs Consumidas:**

```
GET /api/admin/stats
GET /api/admin/clarifications/pending/count
```

---

### 14. Gerenciar Exercícios (`/admin/problems`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi Admin            [Sair do Admin] [Perfil]   │
├────────────────┬────────────────────────────────────────┤
│                │                                        │
│  📊 Dashboard  │  Exercícios         [+ Novo Exercício] │
│  📝 Exercícios │                                        │
│  👥 Usuários   │  🔍 Buscar...                          │
│  📤 Submissões │                                        │
│  💬 Clarific.  │  ┌─────────────────────────────────┐   │
│                │  │ ID │ Título      │ Cat.  │ Ações│   │
│                │  ├─────────────────────────────────┤   │
│                │  │ 1  │ Two Sum     │ Array │ ✏️ 🗑️│   │
│                │  │ 2  │ Valid Paren │ String│ ✏️ 🗑️│   │
│                │  │ 3  │ Merge Inter │ Array │ ✏️ 🗑️│   │
│                │  └─────────────────────────────────┘   │
│                │                                        │
└────────────────┴────────────────────────────────────────┘
```

---

### 15. Criar/Editar Exercício (`/admin/problems/new` ou `/admin/problems/:id`)

**Layout:**

````
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi Admin            [Sair do Admin] [Perfil]   │
├────────────────┬────────────────────────────────────────┤
│                │                                        │
│  📊 Dashboard  │  Novo Exercício                        │
│  📝 Exercícios │                                        │
│  👥 Usuários   │  Título *                              │
│  📤 Submissões │  ┌────────────────────────────────┐   │
│  💬 Clarific.  │  │ Two Sum                        │   │
│                │  └────────────────────────────────┘   │
│                │                                        │
│                │  Categoria *        Dificuldade *      │
│                │  [Arrays    ▼]      [Fácil     ▼]     │
│                │                                        │
│                │  Descrição (Markdown) *                │
│                │  ┌────────────────────────────────┐   │
│                │  │ Dado um array de inteiros...   │   │
│                │  │                                │   │
│                │  │ **Exemplo:**                   │   │
│                │  │ ```                            │   │
│                │  │ Input: [2,7,11,15], target=9  │   │
│                │  │ Output: [0,1]                  │   │
│                │  │ ```                            │   │
│                │  └────────────────────────────────┘   │
│                │                                        │
│                │  Time Limit (ms) *   Memory Limit (MB)*│
│                │  ┌──────────────┐   ┌──────────────┐  │
│                │  │ 1000         │   │ 256          │  │
│                │  └──────────────┘   └──────────────┘  │
│                │                                        │
│                │  ───────────────────────────────────   │
│                │                                        │
│                │  Casos de Teste                        │
│                │  ┌────────────────────────────────┐   │
│                │  │ Caso 1:                        │   │
│                │  │ Input:    Output:   [Oculto?]  │   │
│                │  │ ┌──────┐  ┌──────┐   ☐        │   │
│                │  │ │4 9   │  │0 1   │            │   │
│                │  │ │2 7...│  │      │            │   │
│                │  │ └──────┘  └──────┘            │   │
│                │  └────────────────────────────────┘   │
│                │  [+ Adicionar Caso de Teste]          │
│                │                                        │
│                │  ┌────────────────────────────────┐   │
│                │  │         Salvar Exercício       │   │
│                │  └────────────────────────────────┘   │
│                │                                        │
└────────────────┴────────────────────────────────────────┘
````

**APIs Consumidas:**

```
POST /api/admin/problems          (criar)
PUT /api/admin/problems/:id       (editar)
DELETE /api/admin/problems/:id    (excluir)
```

---

### 16. Gerenciar Usuários (`/admin/users`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi Admin            [Sair do Admin] [Perfil]   │
├────────────────┬────────────────────────────────────────┤
│                │                                        │
│  📊 Dashboard  │  Usuários              [+ Novo Usuário]│
│  📝 Exercícios │                                        │
│  👥 Usuários   │  🔍 Buscar por nome, email ou tagname  │
│  📤 Submissões │                                        │
│  💬 Clarific.  │  ┌───────────────────────────────────┐ │
│                │  │ Nome       │ Tag    │ Role │Ações │ │
│                │  ├───────────────────────────────────┤ │
│                │  │ João Silva │ @joao  │ user │ ✏️   │ │
│                │  │ Maria Lima │ @maria │ user │ ✏️   │ │
│                │  │ Admin      │ @admin │ admin│ ✏️   │ │
│                │  └───────────────────────────────────┘ │
│                │                                        │
└────────────────┴────────────────────────────────────────┘
```

**Editar usuário permite:**

- Alterar nome, email, tagname
- Alterar role (user/admin)
- Verificar email manualmente
- Resetar senha

**APIs Consumidas:**

```
GET /api/admin/users?search=&page=1&limit=20
POST /api/admin/users                       (criar)
PUT /api/admin/users/:id                    (editar)
POST /api/admin/users/:id/verify-email      (verificar manualmente)
POST /api/admin/users/:id/reset-password    (enviar email de reset)
```

---

### 17. Gerenciar Submissões (`/admin/submissions`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi Admin            [Sair do Admin] [Perfil]   │
├────────────────┬────────────────────────────────────────┤
│                │                                        │
│  📊 Dashboard  │  Submissões                            │
│  📝 Exercícios │                                        │
│  👥 Usuários   │  Filtros:                              │
│  📤 Submissões │  [Todos ▼] [Todas Linguagens ▼]       │
│  💬 Clarific.  │                                        │
│                │  ┌───────────────────────────────────┐ │
│                │  │ ID   │ User  │Problema│Status│Açõe│ │
│                │  ├───────────────────────────────────┤ │
│                │  │ 1234 │ @joao │Two Sum │ ✅AC │ 👁️ 🔧│ │
│                │  │ 1233 │ @maria│Valid P │ ❌WA │ 👁️ 🔧│ │
│                │  └───────────────────────────────────┘ │
│                │                                        │
│                │  🔧 = Forçar status (para bugs)        │
│                │                                        │
└────────────────┴────────────────────────────────────────┘
```

**Ação especial:** Admin pode forçar status de submissão (AC/WA) em caso de bugs do judge.

**APIs Consumidas:**

```
GET /api/admin/submissions?status=&language=&page=1&limit=20
PUT /api/admin/submissions/:id/force-status
```

---

### 18. Clarificações Admin (`/admin/clarifications`)

**Layout:**

```
┌─────────────────────────────────────────────────────────┐
│  🍣 Wassabi Admin            [Sair do Admin] [Perfil]   │
├────────────────┬────────────────────────────────────────┤
│                │                                        │
│  📊 Dashboard  │  Clarificações                         │
│  📝 Exercícios │                                        │
│  👥 Usuários   │  [Pendentes (3)] [Respondidas]         │
│  📤 Submissões │                                        │
│  💬 Clarific.  │  ┌───────────────────────────────────┐ │
│                │  │ Two Sum • @joao • 12/03 14:30     │ │
│                │  │                                   │ │
│                │  │ "O array pode ter números         │ │
│                │  │  repetidos?"                      │ │
│                │  │                                   │ │
│                │  │ Resposta:                         │ │
│                │  │ ┌─────────────────────────────┐   │ │
│                │  │ │ Sim, pode haver números...  │   │ │
│                │  │ └─────────────────────────────┘   │ │
│                │  │                                   │ │
│                │  │ [Responder]                       │ │
│                │  └───────────────────────────────────┘ │
│                │                                        │
└────────────────┴────────────────────────────────────────┘
```

**APIs Consumidas:**

```
GET /api/admin/clarifications?status=pending
POST /api/admin/clarifications/:id/reply
```

---

## 🔌 ROTAS DE API CONSUMIDAS (RESUMO)

### Autenticação

| Método | Endpoint                    | Descrição                 |
| ------ | --------------------------- | ------------------------- |
| POST   | `/api/auth/register`        | Cadastro de usuário       |
| POST   | `/api/auth/login`           | Login                     |
| POST   | `/api/auth/logout`          | Logout                    |
| POST   | `/api/auth/verify-email`    | Verificar email via token |
| POST   | `/api/auth/forgot-password` | Solicitar reset de senha  |
| POST   | `/api/auth/reset-password`  | Redefinir senha           |
| GET    | `/api/auth/me`              | Usuário atual logado      |

### Usuários

| Método | Endpoint                | Descrição                          |
| ------ | ----------------------- | ---------------------------------- |
| GET    | `/api/users/me`         | Meu perfil                         |
| PUT    | `/api/users/me`         | Atualizar meu perfil               |
| GET    | `/api/users/me/stats`   | Minhas estatísticas                |
| GET    | `/api/users/:tagname`   | Perfil de outro usuário            |
| GET    | `/api/users/:id/solved` | Exercícios resolvidos pelo usuário |

### Problemas

| Método | Endpoint                    | Descrição                             |
| ------ | --------------------------- | ------------------------------------- |
| GET    | `/api/problems`             | Listar exercícios (paginado, filtros) |
| GET    | `/api/problems/:id`         | Detalhe do exercício                  |
| GET    | `/api/problems/:id/solvers` | Quem resolveu este exercício          |
| GET    | `/api/problems/recommended` | Exercícios recomendados               |
| GET    | `/api/categories`           | Lista de categorias                   |

### Submissões

| Método | Endpoint               | Descrição            |
| ------ | ---------------------- | -------------------- |
| POST   | `/api/submissions`     | Submeter código      |
| GET    | `/api/submissions/:id` | Detalhe da submissão |
| GET    | `/api/submissions/me`  | Minhas submissões    |

### Clarificações

| Método | Endpoint                 | Descrição            |
| ------ | ------------------------ | -------------------- |
| POST   | `/api/clarifications`    | Criar clarificação   |
| GET    | `/api/clarifications/me` | Minhas clarificações |

### Leaderboard

| Método | Endpoint           | Descrição    |
| ------ | ------------------ | ------------ |
| GET    | `/api/leaderboard` | Placar geral |

### Admin - Problemas

| Método | Endpoint                  | Descrição         |
| ------ | ------------------------- | ----------------- |
| POST   | `/api/admin/problems`     | Criar exercício   |
| PUT    | `/api/admin/problems/:id` | Editar exercício  |
| DELETE | `/api/admin/problems/:id` | Excluir exercício |

### Admin - Usuários

| Método | Endpoint                              | Descrição                   |
| ------ | ------------------------------------- | --------------------------- |
| GET    | `/api/admin/users`                    | Listar usuários             |
| POST   | `/api/admin/users`                    | Criar usuário               |
| PUT    | `/api/admin/users/:id`                | Editar usuário              |
| POST   | `/api/admin/users/:id/verify-email`   | Verificar email manualmente |
| POST   | `/api/admin/users/:id/reset-password` | Enviar email de reset       |

### Admin - Submissões

| Método | Endpoint                                  | Descrição           |
| ------ | ----------------------------------------- | ------------------- |
| GET    | `/api/admin/submissions`                  | Todas as submissões |
| PUT    | `/api/admin/submissions/:id/force-status` | Forçar status       |

### Admin - Clarificações

| Método | Endpoint                              | Descrição              |
| ------ | ------------------------------------- | ---------------------- |
| GET    | `/api/admin/clarifications`           | Listar clarificações   |
| POST   | `/api/admin/clarifications/:id/reply` | Responder clarificação |

### Admin - Stats

| Método | Endpoint           | Descrição           |
| ------ | ------------------ | ------------------- |
| GET    | `/api/admin/stats` | Estatísticas gerais |

---

## 📁 ESTRUTURA DE PASTAS SUGERIDA

```
wassabi-coder-frontend/
├── public/
│   └── favicon.ico
├── src/
│   ├── assets/
│   │   └── logo.svg
│   ├── components/
│   │   ├── ui/
│   │   │   ├── Button.jsx
│   │   │   ├── Input.jsx
│   │   │   ├── Card.jsx
│   │   │   ├── Modal.jsx
│   │   │   ├── Toast.jsx
│   │   │   ├── Pagination.jsx
│   │   │   ├── Badge.jsx
│   │   │   ├── Avatar.jsx
│   │   │   └── Spinner.jsx
│   │   ├── layout/
│   │   │   ├── Header.jsx
│   │   │   ├── Footer.jsx
│   │   │   ├── Sidebar.jsx
│   │   │   └── AdminLayout.jsx
│   │   ├── CodeEditor.jsx
│   │   ├── SubmissionPopup.jsx
│   │   ├── ProblemCard.jsx
│   │   ├── SubmissionRow.jsx
│   │   └── TestCaseForm.jsx
│   ├── pages/
│   │   ├── public/
│   │   │   ├── Landing.jsx
│   │   │   ├── Login.jsx
│   │   │   ├── Register.jsx
│   │   │   ├── VerifyEmail.jsx
│   │   │   ├── ForgotPassword.jsx
│   │   │   └── ResetPassword.jsx
│   │   ├── app/
│   │   │   ├── Dashboard.jsx
│   │   │   ├── Problems.jsx
│   │   │   ├── ProblemDetail.jsx
│   │   │   ├── Submissions.jsx
│   │   │   ├── SubmissionDetail.jsx
│   │   │   ├── Profile.jsx
│   │   │   ├── EditProfile.jsx
│   │   │   ├── Leaderboard.jsx
│   │   │   └── Clarifications.jsx
│   │   └── admin/
│   │       ├── AdminDashboard.jsx
│   │       ├── AdminProblems.jsx
│   │       ├── AdminProblemForm.jsx
│   │       ├── AdminUsers.jsx
│   │       ├── AdminUserForm.jsx
│   │       ├── AdminSubmissions.jsx
│   │       └── AdminClarifications.jsx
│   ├── hooks/
│   │   ├── useAuth.js
│   │   ├── useProblems.js
│   │   ├── useSubmissions.js
│   │   └── useToast.js
│   ├── services/
│   │   ├── api.js
│   │   ├── auth.service.js
│   │   ├── problems.service.js
│   │   ├── submissions.service.js
│   │   ├── users.service.js
│   │   └── admin.service.js
│   ├── store/
│   │   └── authStore.js
│   ├── utils/
│   │   ├── constants.js
│   │   ├── formatters.js
│   │   └── validators.js
│   ├── App.jsx
│   ├── main.jsx
│   └── index.css
├── .env.example
├── tailwind.config.js
├── vite.config.js
├── package.json
└── README.md
```

---

## 🚀 COMANDOS DE SETUP

```bash
# Criar projeto
npm create vite@latest wassabi-coder-frontend -- --template react

# Instalar dependências
cd wassabi-coder-frontend
npm install

# Tailwind CSS
npm install -D tailwindcss postcss autoprefixer
npx tailwindcss init -p

# Dependências do projeto
npm install axios react-router-dom zustand react-hot-toast @monaco-editor/react

# Rodar desenvolvimento
npm run dev
```

---

## 📝 CRÉDITOS

**Wassabi Coder** - Plataforma de Programação Competitiva

Desenvolvido por **vleonel** © 2026

---

_Este documento serve como prompt completo para implementação do frontend da plataforma Wassabi Coder._
