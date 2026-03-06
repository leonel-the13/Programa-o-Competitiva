# 📝 Problema 2: Contar Inversões

## 📌 Enunciado

Uma **inversão** em um array é um par de índices (i, j) onde i < j mas arr[i] > arr[j].

Dado um array de inteiros, **conte quantas inversões existem**.

---

## 📥 Entrada

- **Linha 1**: Inteiro N (tamanho do array)
- **Linha 2**: N inteiros separados por espaço (elementos do array)

---

## 📤 Saída

Um único inteiro: o número total de inversões.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
5
4 3 2 1 5
```

**Saída**:

```
5
```

**Explicação**:  
Inversões: (4,3), (4,2), (4,1), (3,2), (3,1)

---

### Exemplo 2

**Entrada**:

```
3
1 2 3
```

**Saída**:

```
0
```

**Explicação**:  
Array já está ordenado, nenhuma inversão.

---

### Exemplo 3

**Entrada**:

```
4
2 1 3 1
```

**Saída**:

```
3
```

**Explicação**:  
Inversões: (2,1) índices 0-1, (2,1) índices 0-3, (3,1) índices 2-3

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 0 ≤ arr[i] ≤ 10^9

---

## 💡 Dicas

- **Força Bruta**: O(n²) - dois loops para cada par
- **Otimizado**: Merge Sort para O(n log n)
- Considere: modulo 10^9+7 se o resultado for muito grande

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n log n)
- **Espaço**: O(n)
