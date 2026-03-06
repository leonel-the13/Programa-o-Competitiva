# 📝 Problema 3: Coin Change

## 📌 Enunciado

Dado um array de moedas e um valor alvo, encontre o **número mínimo de moedas necessário** para fazer o valor alvo.

Você tem infinitas moedas de cada tipo.

---

## 📥 Entrada

- **Linha 1**: Inteiro N (número de tipos de moedas)
- **Linha 2**: N inteiros (valores das moedas)
- **Linha 3**: Inteiro amount (valor alvo)

---

## 📤 Saída

Um único inteiro: número mínimo de moedas, ou -1 se impossível.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3
1 2 5
5
```

**Saída**:

```
1
```

**Explicação**: Uma moeda de 5.

---

### Exemplo 2

**Entrada**:

```
3
2 3 5
5
```

**Saída**:

```
1
```

**Explicação**: Uma moeda de 5.

---

### Exemplo 3

**Entrada**:

```
2
10 1
31
```

**Saída**:

```
4
```

**Explicação**: 10 + 10 + 10 + 1 = 31 (4 moedas).

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- 1 ≤ coins[i] ≤ 10^6
- 0 ≤ amount ≤ 10^6

---

## 💡 Dicas

- **DP**: dp[i] = número mínimo de moedas para fazer valor i
- **Base**: dp[0] = 0
- **Transição**: Para cada moeda, dp[i] = min(dp[i], dp[i-moeda] + 1)
- Valores não alcançáveis ficam com dp[i] = infinity

---

## 🎯 Complexidade Esperada

- **Tempo**: O(amount × N)
- **Espaço**: O(amount)
