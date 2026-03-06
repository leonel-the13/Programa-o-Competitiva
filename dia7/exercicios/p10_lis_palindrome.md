# 📝 Problema 10: Longest Palindromic Substring (DP)

## 📌 Enunciado

Encontre o **maior substring palindromic** usando DP.

(Mesma problema do p03 mas resolva com DP!)

---

## 📥 Entrada

Uma string S.

---

## 📤 Saída

O maior palíndromo.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
racecar
```

**Saída**:

```
racecar
```

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 1000

---

## 💡 Dicas

- **DP**: dp[i][j] = true se S[i..j] é palíndromo
- **Base**: dp[i][i] = true, dp[i][i+1] = (S[i] == S[i+1])
- **Transição**: dp[i][j] = (S[i] == S[j]) && dp[i+1][j-1]

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n²)
- **Espaço**: O(n²)
