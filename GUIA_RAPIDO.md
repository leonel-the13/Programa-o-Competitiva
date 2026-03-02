# ⚡ GUIA RÁPIDO DE RECONHECIMENTO DE PADRÕES

**Cole isso na parede. Decore. Use na prova.**

---

## 🎯 SE O PROBLEMA PEDE...

### 📊 ARRAYS

| O que pede                              | Use                          | Complexidade |
| --------------------------------------- | ---------------------------- | ------------ |
| Existe subarray com soma K              | Prefix sum + hashmap         | O(n)         |
| Maior subarray com soma X               | Kadane ou prefix sum         | O(n)         |
| Soma máxima de K elementos consecutivos | Sliding window               | O(n)         |
| Par com soma/diferença K                | Two pointers (ordenar antes) | O(n log n)   |
| Tripla com soma K                       | Ordenar + two pointers       | O(n²)        |
| Kth maior elemento                      | Quickselect ou heap          | O(n) médio   |
| Remover duplicatas                      | Two pointers                 | O(n)         |
| Merge intervals                         | Ordenar + processar          | O(n log n)   |

---

### 🔍 BUSCA E ORDENAÇÃO

| O que pede                        | Use                       | Complexidade |
| --------------------------------- | ------------------------- | ------------ |
| Buscar elemento em array ordenado | Binary search             | O(log n)     |
| Primeira/última ocorrência        | lower_bound / upper_bound | O(log n)     |
| Buscar em array rotacionado       | Binary search modificado  | O(log n)     |
| Buscar em matriz ordenada         | Binary search 2D          | O(log mn)    |
| Ordenar com critério especial     | sort() com comparador     | O(n log n)   |

---

### 🔄 RECURSÃO E BACKTRACKING

| O que pede                 | Use                      | Complexidade |
| -------------------------- | ------------------------ | ------------ |
| Gerar todos os subsets     | Backtracking             | O(2^n)       |
| Gerar todas as permutações | Backtracking com usado[] | O(n!)        |
| Combination sum            | Backtracking             | O(2^n)       |
| N-Queens                   | Backtracking com poda    | O(n!)        |
| Sudoku solver              | Backtracking             | O(9^(n²))    |
| Todas as possibilidades    | Backtracking             | Exponencial  |

---

### 💎 PROGRAMAÇÃO DINÂMICA

| O que pede                    | Use          | Complexidade        |
| ----------------------------- | ------------ | ------------------- |
| Contar formas de fazer X      | DP 1D        | O(n) ou O(nk)       |
| Mochila / escolher itens      | Knapsack 0/1 | O(nW)               |
| Subsequência crescente máxima | LIS          | O(n²) ou O(n log n) |
| Subsequência comum máxima     | LCS          | O(nm)               |
| Edit distance                 | DP 2D        | O(nm)               |
| Coin change                   | DP           | O(nk)               |
| Caminho mínimo em grid        | DP 2D        | O(nm)               |
| Subarray com propriedade X    | DP + hash    | O(n)                |

---

### 🌐 GRAFOS

| O que pede                       | Use                           | Complexidade |
| -------------------------------- | ----------------------------- | ------------ |
| Menor caminho sem peso           | BFS                           | O(V+E)       |
| Explorar todas as possibilidades | DFS                           | O(V+E)       |
| Quantos grupos isolados          | Componentes conexas (DFS/BFS) | O(V+E)       |
| Grid com obstáculos              | BFS em matriz                 | O(nm)        |
| Detectar ciclo não direcionado   | DFS com parent                | O(V+E)       |
| Detectar ciclo direcionado       | DFS com color                 | O(V+E)       |
| Ordem de dependências            | Ordenação topológica          | O(V+E)       |
| Labirinto / menor caminho        | BFS                           | O(nm)        |
| É bipartido?                     | BFS/DFS com 2 cores           | O(V+E)       |
| Número de ilhas                  | DFS/BFS                       | O(nm)        |

---

### 🔢 TEORIA DOS NÚMEROS

| O que pede             | Use                          | Complexidade    |
| ---------------------- | ---------------------------- | --------------- |
| Verificar se N é primo | Teste de primalidade         | O(√n)           |
| Todos os primos até N  | Crivo de Eratóstenes         | O(n log log n)  |
| MDC de dois números    | Algoritmo de Euclides        | O(log min(a,b)) |
| a^n mod m              | Exponenciação rápida modular | O(log n)        |
| Fatorar N              | Fatoração prima              | O(√n)           |
| Número de divisores    | Iterar até √n                | O(√n)           |
| Fibonacci grande       | Exponenciação de matriz      | O(log n)        |

---

### 🔤 STRINGS

| O que pede                            | Use                   | Complexidade        |
| ------------------------------------- | --------------------- | ------------------- |
| Anagramas                             | Ordenar ou frequência | O(n log n) ou O(n)  |
| Pattern matching                      | KMP ou Z-algorithm    | O(n+m)              |
| Palíndromo                            | Expansão ou DP        | O(n²) ou O(n)       |
| Primeira/última ocorrência            | find() ou KMP         | O(nm) ou O(n+m)     |
| Substring mais longa com X caracteres | Sliding window        | O(n)                |
| Distinct substrings                   | Suffix array ou hash  | O(n²) ou O(n log n) |
| Maior palíndromo                      | Manacher ou expansão  | O(n) ou O(n²)       |

---

## 🚨 CASOS LIMITE (SEMPRE TESTAR!)

✅ **N = 0 ou N = 1**  
✅ **Todos elementos iguais**  
✅ **Array já ordenado (crescente/decrescente)**  
✅ **Elementos negativos**  
✅ **Valores máximos**: N = 10^5, valor = 10^9  
✅ **Overflow**: use `long long`  
✅ **Resposta pode ser zero ou negativa?**  
✅ **String vazia**  
✅ **Grafo desconexo**  
✅ **Ciclos**

---

## ⏱️ COMPLEXIDADE E CONSTRAINTS

| N        | Complexidade Aceitável |
| -------- | ---------------------- |
| N ≤ 10   | O(n!), O(2^n)          |
| N ≤ 20   | O(2^n), O(n²2^n)       |
| N ≤ 100  | O(n⁴)                  |
| N ≤ 500  | O(n³)                  |
| N ≤ 10⁴  | O(n²)                  |
| N ≤ 10^5 | O(n log n)             |
| N ≤ 10^6 | O(n)                   |
| N ≤ 10^9 | O(log n), O(1)         |

**Regra geral**: 10^8 operações ≈ 1 segundo

---

## 🎯 ESTRATÉGIA NA PROVA (5 PASSOS)

1. **LER todos os problemas** (15 min)
2. **IDENTIFICAR o padrão** (mais importante!)
3. **CALCULAR complexidade** (vai passar?)
4. **IMPLEMENTAR com cuidado**
5. **TESTAR casos limite**

---

## 💡 DICAS DE OURO

🔥 **Se não reconhecer o padrão em 10 min, pule**  
🔥 **Comece SEMPRE pelo mais fácil**  
🔥 **Use long long quando em dúvida**  
🔥 **Teste N=1 SEMPRE**  
🔥 **Desenhe exemplos pequenos**  
🔥 **Não complique: solução simples geralmente está certa**

---

## 🏆 VOCÊ ESTÁ PRONTO!

Se consegue reconhecer 80% dos padrões acima, você está entre os **TOP 10%** da competição.

**Confia no treino. VAI DOMINAR! 🔥**
