# 📝 Problema 5: DP 2D Difícil

## 📌 Enunciado

Encontre **máximo valor de um path** em uma matriz M×N onde:

- Comece no canto superior esquerdo
- Termine no canto inferior direito
- Mova apenas direita ou baixo
- Cada célula tem um custo (positivo ou negativo)
- Máximo K passos

---

## 📥 Entrada

- **Linha 1**: Três inteiros M, N, K
- **Próximas M linhas**: N inteiros (custos)

---

## 📤 Saída

Máximo valor com limite de K passos, ou INT_MIN se impossível.

---

## ⚙️ Restrições

- 1 ≤ M, N ≤ 50
- 1 ≤ K ≤ 100
- -100 ≤ custos ≤ 100

---

## 💡 Dicas

- DP 3D: dp[i][j][k] = máximo valor chegando em (i,j) usando exatamente k passos

---

## 🎯 Complexidade Esperada

- **Tempo**: O(M × N × K)
- **Espaço**: O(M × N × K)
