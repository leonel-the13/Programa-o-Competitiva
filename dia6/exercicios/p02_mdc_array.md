# 📝 Problema 2: MDC de Array

## 📌 Enunciado

Dado um array de inteiros, encontre o **MDC (Máximo Divisor Comum)** de todos elementos.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros

---

## 📤 Saída

Um único inteiro: MDC de todos elementos.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3
12 8 16
```

**Saída**:

```
4
```

**Explicação**: MDC(12, 8, 16) = 4

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 1 ≤ arr[i] ≤ 10^9

---

## 💡 Dicas

- Use Algoritmo de Euclides
- MDC(a, MDC(b, c)) = MDC(MDC(a, b), c)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n log max)
- **Espaço**: O(1)
