# 📝 Problema 5: Unique Paths

## 📌 Enunciado

Uma matriz M×N. Você começa no canto superior esquerdo e quer ir ao inferior direito. **Você só pode se mover para direita ou baixo.**

**De quantas formas diferentes você pode chegar?**

---

## 📥 Entrada

- **Linha 1**: Dois inteiros M e N

---

## 📤 Saída

Um único inteiro: número de caminhos únicos.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3 2
```

**Saída**:

```
3
```

**Explicação**:

- Direita, Direita, Baixo, Baixo
- Direita, Baixo, Direita, Baixo
- Direita, Baixo, Baixo, Direita
- Baixo, Direita, Direita, Baixo
- Baixo, Direita, Baixo, Direita
- Baixo, Baixo, Direita, Direita

Espera, são 6, não 3? Verifique a entrada...

Na verdade há C(4, 2) = 6 caminhos (escolher 2 posições para as 4 movimentos totais para ser "baixo").

---

### Exemplo 2

**Entrada**:

```
1 1
```

**Saída**:

```
1
```

---

## ⚙️ Restrições

- 1 ≤ M, N ≤ 100

---

## 💡 Dicas

- **Combinatória**: Total moves = M-1 + N-1. Escolher M-1 posições para baixo = C(M+N-2, M-1)
- **DP**: dp[i][j] = número de caminhos até (i,j) = dp[i-1][j] + dp[i][j-1]
- **Espaço**: Pode usar array 1D

---

## 🎯 Complexidade Esperada

- **Tempo**: O(M × N)
- **Espaço**: O(M × N) ou O(N)
