# 📝 Problema 5: Três Números com Soma Zero

## 📌 Enunciado

Dado um array de inteiros, encontre **todos os triplets únicos** cuja soma seja **exatamente 0**.

⚠️ Não repita triplets na resposta (cada triplet uma única vez).

---

## 📥 Entrada

- **Linha 1**: Inteiro N (tamanho do array)
- **Linha 2**: N inteiros separados por espaço

---

## 📤 Saída

Cada linha contém um triplet (a, b, c) em ordem crescente, com triplets também em ordem lexicográfica. Se não houver solução, imprima "NENHUM".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
6
-1 0 1 2 -1 -4
```

**Saída**:

```
-1 -1 2
-1 0 1
```

**Explicação**:  
Único triplet com soma 0: (-1, -1, 2) e (-1, 0, 1)

---

### Exemplo 2

**Entrada**:

```
3
0 0 0
```

**Saída**:

```
0 0 0
```

---

### Exemplo 3

**Entrada**:

```
2
1 2
```

**Saída**:

```
NENHUM
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 3000
- -10^5 ≤ arr[i] ≤ 10^5

---

## 💡 Dicas

- Ordene o array primeiro: O(n log n)
- Para cada elemento, use two pointers para encontrar pares que completem soma 0
- Cuidado para não adicionar duplicatas

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n²)
- **Espaço**: O(1) (ignorando output)
