# 📝 NOTAS DO DIA 4

## 🎯 Padrões Aprendidos Hoje

### 1. DP = Recursão + Memoization

- Top-down: recursão com cache
- Bottom-up: iterativo preenchendo tabela

### 2. Knapsack Template

```cpp
dp[i][w] = max(
    dp[i-1][w],                           // não pega
    dp[i-1][w-weight[i-1]] + value[i-1]  // pega
)
```

### 3. LIS (Longest Increasing Subsequence)

- O(n²): para cada i, olha todos j < i
- O(n log n): binary search com tails array

### 4. LCS (Longest Common Subsequence)

- Se s1[i] == s2[j]: dp[i][j] = dp[i-1][j-1] + 1
- Senão: dp[i][j] = max(dp[i-1][j], dp[i][j-1])

---

## ⚠️ Erros Comuns

- [ ] Índices errados (off-by-one)
- [ ] Esqueci de inicializar caso base
- [ ] Overflow (não usei long long)
- [ ] Ordem de preenchimento errada

---

## 💡 Insights

- DP é sobre QUEBRAR em subproblemas menores
- Sempre identifique: "Qual é a recorrência?"
- Desenhe a tabela DP no papel antes de codificar

---

**Data**: **_/_**/\_\_\_
