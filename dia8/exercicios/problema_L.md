# 📝 Problema L: Combinatória Avançada

## 📌 Enunciado

Calcule o **número de caminhos**em um grid M×N com alguns obstáculos, usando apenas movimentos para cima e para esquerda.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros M e N
- **Próximas M linhas**: N valores (0=livre, 1=obstáculo)

---

## 📤 Saída

Número de caminhos do canto superior esquerdo para inferior direito.

---

## ⚙️ Restrições

- 1 ≤ M, N ≤ 100

---

## 💡 Dicas

- DP 2D: dp[i][j] = número de formas de chegar

---

## 🎯 Complexidade Esperada

- **Tempo**: O(M × N)
- **Espaço**: O(M × N)
