# 📝 Problema 8: Edit Distance

## 📌 Enunciado

Dadas duas strings s1 e s2, encontre o **número mínimo de operações** necessário para transformar s1 em s2.

Operações permitidas:

- Inserir um caractere
- Deletar um caractere
- Substituir um caractere

---

## 📥 Entrada

- **Linha 1**: String s1
- **Linha 2**: String s2

---

## 📤 Saída

Um único inteiro: distância mínima (edit distance ou Levenshtein distance).

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
horse
ros
```

**Saída**:

```
3
```

**Explicação**:

- Deletar 'h': "horse" → "orse"
- Deletar 'o': "orse" → "rse"
- Substituir 'e' por 'o': "rse" → "ros"

---

### Exemplo 2

**Entrada**:

```
intention
execution
```

**Saída**:

```
5
```

---

## ⚙️ Restrições

- 0 ≤ len(s1), len(s2) ≤ 500

---

## 💡 Dicas

- **DP 2D**: dp[i][j] = edit distance entre s1[0..i-1] e s2[0..j-1]
- **Base**: dp[0][j] = j (inserir j), dp[i][0] = i (deletar i)
- **Transição**:
  - Se s1[i-1] == s2[j-1]: dp[i][j] = dp[i-1][j-1]
  - Senão: dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

---

## 🎯 Complexidade Esperada

- **Tempo**: O(m × n)
- **Espaço**: O(m × n) ou O(n)
