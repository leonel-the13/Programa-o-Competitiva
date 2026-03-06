# 📝 Problema 2: Segment Tree Básico

## 📌 Enunciado

Implemente uma Segment Tree para:

- **Update**: Mude o valor de um índice
- **Query**: Encontre a soma de um intervalo

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros (array inicial)
- **Linha 3**: Inteiro Q (número de queries)
- **Próximas Q linhas**: "UPDATE i v" ou "QUERY l r"

---

## 📤 Saída

Para cada QUERY, imprima a soma do intervalo [l, r].

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 1 ≤ Q ≤ 10^5
- 0 ≤ arr[i] ≤ 10^9

---

## 💡 Dicas

- Segment Tree com update O(log n) e query O(log n)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n + q log n)
- **Espaço**: O(n)
