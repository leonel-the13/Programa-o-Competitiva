# 📝 Problema 10: Números Coprimos em Range

## 📌 Enunciado

Dados dois inteiros A e B, conte **quantos números no range [A, B]** são coprimos com N (MDC(número, N) = 1).

---

## 📥 Entrada

- **Linha 1**: Três inteiros N, A, B

---

## 📤 Saída

Um único inteiro: count.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
6 1 10
```

**Saída**:

```
3
```

**Explicação**: Números coprimos com 6: 1, 5, 7 (MDC com 6 = 1)

---

## ⚙️ Restrições

- 1 ≤ N, A, B ≤ 10^9
- A ≤ B

---

## 💡 Dicas

- Use Princípio de Inclusão-Exclusão
- Count[1, B] - Count[1, A-1]
- Para plano, use fatores primos de N

---

## 🎯 Complexidade Esperada

- **Tempo**: O(√N + 2^k) onde k = número de fatores primos
- **Espaço**: O(k)
