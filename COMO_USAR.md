# 🎯 COMO USAR ESTE MATERIAL

**Guia rápido para aproveitar ao máximo sua preparação de 9 dias.**

---

## 📅 ROTINA DIÁRIA (5 HORAS)

### ⏰ Sessão da Manhã (3h):

1. **00:00 - 00:45**: Leia o README.md do dia
   - Entenda a teoria
   - Rode os exemplos de código
   - Teste os templates

2. **00:45 - 02:30**: Resolva exercícios (primeiros 5)
   - Máximo 30 min por problema
   - Se travar → veja dica → tente mais 15 min → veja solução
   - **NÃO copie soluções**: veja, entenda, implemente sozinho

3. **02:30 - 03:00**: Análise e correção
   - Teste suas soluções com casos limites
   - Se errou, entenda POR QUÊ
   - Anote padrões no NOTAS.md

---

### ☕ Intervalo (30min)

---

### ⏰ Sessão da Tarde (2h):

1. **00:00 - 01:30**: Resolva exercícios restantes
   - Agora os mais difíceis
   - É NORMAL travar nos difíceis
   - Veja soluções sem culpa, mas ENTENDA

2. **01:30 - 02:00**: Consolidação
   - Preencha seu NOTAS.md completamente
   - Liste padrões aprendidos
   - Liste erros cometidos
   - Marque problemas para refazer

---

## 📂 ESTRUTURA DOS ARQUIVOS

```
maratona/
├── README.md                 ← Leia PRIMEIRO (overview geral)
├── GUIA_RAPIDO.md           ← Reconhecimento de padrões (estude muito!)
│
├── dia1/ (Fundamentos)
│   ├── README.md            ← Teoria do dia
│   ├── templates/           ← Códigos prontos para copiar
│   ├── exercicios/          ← Enunciados dos problemas
│   ├── solucoes/            ← Soluções (veja DEPOIS de tentar)
│   └── NOTAS.md             ← SEU caderno (preencha!)
│
├── dia2/ até dia7/ (mesmo formato)
│
├── dia8/ (Simulação)
│   ├── README.md            ← Regras da simulação
│   ├── exercicios/          ← 12 problemas
│   └── ANALISE.md           ← Preencha DEPOIS da simulação
│
└── dia9/ (Revisão)
    ├── README.md
    ├── TEMPLATES_FINAIS.md  ← Copie tudo para a prova
    └── exercicios/
```

---

## ✅ CHECKLIST ANTES DE CADA DIA

- [ ] Dormi bem (mínimo 7 horas)
- [ ] Tenho 5 horas livres à frente
- [ ] Ambiente de trabalho preparado (editor, compilador)
- [ ] Cronômetro pronto
- [ ] Caderno e caneta para rascunhos
- [ ] SEM distrações (celular no silencioso, redes sociais fechadas)

---

## 🎯 COMO RESOLVER CADA PROBLEMA

### Passo 1: LEIA COM ATENÇÃO

- Leia 2x se necessário
- Anote: N ≤ ?, limites dos valores, casos especiais

### Passo 2: RECONHEÇA O PADRÃO

- Parece com qual tipo de problema?
- Consulte [GUIA_RAPIDO.md](GUIA_RAPIDO.md)
- Este é o passo MAIS IMPORTANTE

### Passo 3: CALCULE A COMPLEXIDADE

- Qual complexidade é necessária?
- Minha solução passa nos limites?
- Se N = 10^5 e você fez O(n²) → TLE garantido

### Passo 4: IMPLEMENTE

- Use os templates quando possível
- Escreva com calma, sem pressa
- Comente partes complexas

### Passo 5: TESTE

- **Caso do enunciado**: deve passar
- **N = 1**: caso mínimo
- **N = máximo**: caso extremo
- **Todos iguais**: caso uniforme
- **Negativos**: se aplicável
- **Resposta zero**: se possível

### Passo 6: SE TRAVAR

- 30 min sem progresso? → Veja dica no enunciado
- 45 min total? → Veja solução completa
- **NÃO fique preso em um problema**

---

## 📝 COMO USAR O NOTAS.md

Preencha diariamente:

1. **Padrões aprendidos**: "Aprendi que problema X usa two pointers"
2. **Templates importantes**: Copie os que mais usou
3. **Erros comuns**: "Esqueci long long em...", "Não testei N=1 em..."
4. **Insights**: "Descobri que grid é grafo disfarçado"
5. **Problemas para refazer**: Os que errou ou não terminou

**Este caderno vai ser OURO no Dia 9 e na véspera da prova.**

---

## 🚨 ERROS COMUNS (EVITE!)

❌ **Pular a teoria**: Não vá direto pros exercícios. Leia a teoria primeiro.

❌ **Copiar soluções sem entender**: Você NÃO vai aprender assim.

❌ **Não testar casos limites**: N=1, N=max, todos iguais, negativos.

❌ **Ficar 2h em um problema**: Se travou 45 min, veja a solução.

❌ **Não anotar padrões**: NOTAS.md não é opcional!

❌ **Estudar quando cansado**: Se está sonolento, descanse. 5h com foco > 8h cansado.

---

## 💪 DIA 8: SIMULAÇÃO (ESPECIAL)

**Este dia é DIFERENTE.**

- Não consulte soluções (simule condição real)
- Cronômetro de 5h REAIS
- Preencha [dia8/ANALISE.md](dia8/ANALISE.md) depois
- Este dia mostra onde você realmente está

---

## 🎓 DIA 9: REVISÃO (PREPARAÇÃO FINAL)

- Revise erros do Dia 8
- Compile seus templates finais
- Resolva 5 problemas difíceis (sem pressa, para aprender)
- DESCANSE no final do dia

**NÃO estude até tarde na véspera da prova!**

---

## 📊 ACOMPANHE SEU PROGRESSO

Crie uma planilha ou use papel:

| Dia | Problemas Resolvidos | Tempo Gasto | Sensação    |
| --- | -------------------- | ----------- | ----------- |
| 1   | \_\_\_ / 10          | \_\_\_ h    | 😤/😐/😊/🔥 |
| 2   | \_\_\_ / 10          | \_\_\_ h    | 😤/😐/😊/🔥 |
| ... |                      |             |             |

---

## 🏆 MENTALIDADE VENCEDORA

> "Eu não falhei. Apenas encontrei 10.000 maneiras que não funcionam." — Edison

- **Errar é APRENDER**: Cada erro te aproxima da solução
- **Comparação é armadilha**: Compare com você de ontem, não com outros
- **Consistência > Intensidade**: 5h/dia por 9 dias > 20h em um dia
- **Descanso é treino**: Seu cérebro consolida conhecimento enquanto descansa

---

## 🎯 OBJETIVO FINAL

**Após 9 dias você terá**:

- ✅ Resolvido 80+ problemas
- ✅ Dominado os padrões principais
- ✅ Simulado condição real de competição
- ✅ Criado seu próprio caderno de templates

**Você estará entre os MAIS PREPARADOS da competição.**

---

## 💬 MENSAGEM FINAL

Este material foi criado para transformar você em uma **máquina de resolver problemas**.

Não é sobre ser gênio. É sobre:

1. **Reconhecer padrões** (80% da competição)
2. **Implementar com cuidado** (15%)
3. **Gerenciar tempo e calma** (5%)

**Você tem tudo que precisa aqui.**

Agora é só executar com disciplina e foco.

---

# 🔥 COMECE AGORA! DIA 1 TE ESPERA! 🔥

**Abra** [dia1/README.md](dia1/README.md) **e comece sua jornada para o mundial.**

Boa sorte, campeão! 💪🏆
