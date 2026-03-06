# 📝 Problema 2: House Robber

## 📌 Enunciado

Você é um ladrão que entra em uma rua com N casas. Cada casa tem um certo valor.

Se você rouba duas casas adjacentes, um alarme dispara. **Qual é o máximo valor que você pode roubar?**

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros (valor de cada casa)

---

## 📤 Saída

Um único inteiro: máximo valor que pode roubar.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4
1 2 3 4
```

**Saída**:

```
6
```

**Explicação**: Rouba casas 0 e 2 (1 + 3 = 4) ou casas 1 e 3 (2 + 4 = 6). Máximo = 6.

---

### Exemplo 2

**Entrada**:

```
3
2 7 9
```

**Saída**:

```
11
```

**Explicação**: Rouba casas 1 e 0 (7 + 2 = 9) ou somente casa 1 (7) ou somente casa 2 (9). Melhor: Apenas casa 2 (9) ou apenas casa 1 (7)... Espera: 2+9 = 11! Casas 0 e 2.

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 0 ≤ arr[i] ≤ 10^5

---

## 💡 Dicas

- **DP**: dp[i] = max valor até casa i
- Para cada casa, você rouba ou não rouba
- Se rouba: dp[i] = dp[i-2] + arr[i]
- Se não rouba: dp[i] = dp[i-1]
- Resultado: dp[i] = max(dp[i-1], dp[i-2] + arr[i])

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(1)
