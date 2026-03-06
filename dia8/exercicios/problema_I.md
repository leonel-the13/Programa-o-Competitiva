# 📝 Problema I: Knapsack Modificado

## 📌 Enunciado

Variante de Knapsack: Dado N itens e capacidade W, maximize o valor com a restrição de que número de itens ≤ K.

---

## 📥 Entrada

- **Linha 1**: Três inteiros N, W, K
- **Próximas N linhas**: Peso e valor

---

## 📤 Saída

Máximo valor.

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- 1 ≤ W ≤ 1000
- 1 ≤ K ≤ 50

---

## 💡 Dicas

- DP 3D: dp[i][j][k] = max valor usando i itens, capacidade j, usando no máximo k itens

---

## 🎯 Complexidade Esperada

- **Tempo**: O(N × W × K)
- **Espaço**: O(W × K)
