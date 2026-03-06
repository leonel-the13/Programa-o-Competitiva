# 📝 Problema 9: Maximum Product Subarray

## 📌 Enunciado

Dado um array de inteiros, encontre o **subarray contíguo com o maior produto**.

⚠️ Cuidado com números negativos!

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros

---

## 📤 Saída

Um único inteiro: máximo produto.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4
2 3 -2 4
```

**Saída**:

```
6
```

**Explicação**: Subarray [2, 3] tem produto 6.

---

### Exemplo 2

**Entrada**:

```
5
-2 0 -1 3 2
```

**Saída**:

```
3
```

**Explicação**: Subarray [3] tem produto 3.

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- -10 ≤ arr[i] ≤ 10

---

## 💡 Dicas

- Problema é tricky por causa de negativos
- Manter track de máximo produto e mínimo produto até cada posição
- **Relação**:
  - maxProd[i] = max(arr[i], arr[i] × maxProd[i-1], arr[i] × minProd[i-1])
  - minProd[i] = min(arr[i], arr[i] × maxProd[i-1], arr[i] × minProd[i-1])

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(1)
