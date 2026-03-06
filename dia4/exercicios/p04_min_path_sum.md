# 📝 Problema 4: Minimum Path Sum

## 📌 Enunciado

Dado uma matriz M×N onde cada célula tem um custo, encontre o **caminho do canto superior esquerdo até o inferior direito com custo mínimo**.

Você só pode se mover para **direita ou baixo**.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros M e N
- **Próximas M linhas**: N inteiros cada (custos da célula)

---

## 📤 Saída

Um único inteiro: custo mínimo do caminho.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
2 3
1 3 1
1 5 1
```

**Saída**:

```
5
```

**Explicação**: Caminho: 1 → 3 → 1 → 1 → 1 = 7. Melhor: ? Vamos ver: 1 → 1 → 1 → 1 → 1 = 5. (Descendo: 1, +1=2, +1=3, depois direita: +1=4, +1=5)

---

### Exemplo 2

**Entrada**:

```
1 1
1
```

**Saída**:

```
1
```

---

## ⚙️ Restrições

- 1 ≤ M, N ≤ 200
- 0 ≤ grid[i][j] ≤ 100

---

## 💡 Dicas

- **DP 2D**: dp[i][j] = custo mínimo até célula (i,j)
- **Base**: dp[0][0] = grid[0][0]
- **Transição**: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1])
- **Espaço**: Pode ser otimizado para O(n) usando 1D

---

## 🎯 Complexidade Esperada

- **Tempo**: O(M × N)
- **Espaço**: O(M × N) ou O(N)
