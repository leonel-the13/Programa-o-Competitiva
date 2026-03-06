# 📝 Problema 7: Longest Increasing Subsequence

## 📌 Enunciado

Dado um array, encontre o **comprimento da maior subsequência estritamente crescente**.

Uma subsequência não precisa ser contígua.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros

---

## 📤 Saída

Um único inteiro: comprimento da LIS.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
10
10 9 2 5 3 7 101 18
```

**Saída**:

```
4
```

**Explicação**: LIS = [2, 3, 7, 101] ou [2, 3, 7, 18] (comprimento 4)

---

### Exemplo 2

**Entrada**:

```
5
0 1 0 4 4
```

**Saída**:

```
2
```

**Explicação**: LIS = [0, 1] ou [0, 4] (comprimento 2)

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- -10^9 ≤ arr[i] ≤ 10^9

---

## 💡 Dicas

- **DP O(n²)**: dp[i] = comprimento da LIS terminando em arr[i]
- **DP O(n log n)**: Use binary search com array de "menores finais"
- Melhor é implementar a O(n log n) se N for grande

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n log n)
- **Espaço**: O(n)
