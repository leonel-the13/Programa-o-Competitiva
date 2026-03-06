# 📝 Problema 6: Knapsack 0/1

## 📌 Enunciado

Clássico problema da mochila. Você tem uma mochila com capacidade W e N itens, cada um com peso wᵢ e valor vᵢ.

**Qual é o máximo valor que você pode carregar?** (Cada item pode ser incluído no máximo uma vez)

---

## 📥 Entrada

- **Linha 1**: Inteiro N (número de itens)
- **Linha 2**: Inteiro W (capacidade da mochila)
- **Próximas N linhas**: Dois inteiros wᵢ e vᵢ (peso e valor)

---

## 📤 Saída

Um único inteiro: máximo valor possível.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4
5
1 2
3 4
4 5
2 3
```

**Saída**:

```
8
```

**Explicação**: Pega itens com pesos (1,3) ou (2,4), ambos cabem e têm valor 4+3=7 ou 3+5=8.

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- 1 ≤ W ≤ 1000
- 1 ≤ weight[i], value[i] ≤ 1000

---

## 💡 Dicas

- **DP 2D**: dp[i][w] = máximo valor usando itens 0..i-1 com capacidade w
- **Base**: dp[0][w] = 0, dp[i][0] = 0
- **Transição**: dp[i][w] = max(dp[i-1][w], dp[i-1]w-weight[i]] + value[i])
- **Espaço**: Pode usar array 1D rolante

---

## 🎯 Complexidade Esperada

- **Tempo**: O(N × W)
- **Espaço**: O(W) com otimização
