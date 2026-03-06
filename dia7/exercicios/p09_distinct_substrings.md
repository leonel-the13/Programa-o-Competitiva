# 📝 Problema 9: Distinct Substrings

## 📌 Enunciado

Dado uma string, conte o **número de distinct substrings**.

---

## 📥 Entrada

Uma string S.

---

## 📤 Saída

Número de distinct substrings.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
ababa
```

**Saída**:

```
9
```

**Explicação**: "", "a", "b", "ab", "ba", "aba", "bab", "abab", "baba", "ababa" (contando vazio também, 10 no total, mas sem vazio = 9?) Verifique...

Substrings: a, ab, aba, abab, ababa, b, ba, bab, baba = 9

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 10^5

---

## 💡 Dicas

- Use HashSet
- Ou suffix array com LCP

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n²) com set, O(n) com suffix array
- **Espaço**: O(n²)
