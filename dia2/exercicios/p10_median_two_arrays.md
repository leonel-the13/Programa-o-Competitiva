# 📝 Problema 10: Median of Two Sorted Arrays

## 📌 Enunciado

Dados dois arrays **já ordenados**, encontre a **mediana combinada** de todos os elementos.

A mediana é o elemento do meio quando o array tem tamanho ímpar, ou a média dos dois elementos do meio quando par.

---

## 📥 Entrada

- **Linha 1**: Inteiro M (tamanho primeiro array)
- **Linha 2**: M inteiros em ordem crescente
- **Linha 3**: Inteiro N (tamanho segundo array)
- **Linha 4**: N inteiros em ordem crescente

---

## 📤 Saída

Um único número: a mediana (com até 5 casas decimais se for float).

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
2
1 3
1
2
```

**Saída**:

```
2.0
```

**Explicação**:  
Array combinado: [1, 2, 3]. Mediana = 2

---

### Exemplo 2

**Entrada**:

```
2
1 2
2
3 4
```

**Saída**:

```
2.5
```

**Explicação**:  
Array combinado: [1, 2, 3, 4]. Mediana = (2+3)/2 = 2.5

---

## ⚙️ Restrições

- 0 ≤ M, N ≤ 10^5
- M + N > 0
- -10^6 ≤ arr[i] ≤ 10^6

---

## 💡 Dicas

- **Simples**: Merge arrays e encontre mediana - O((m+n) log (m+n))
- **Otimizado**: Binary search on partition - O(log(min(m,n)))
- Cuidado: Um dos arrays pode estar vazio

---

## 🎯 Complexidade Esperada

- **Tempo**: O(log(min(m,n)))
- **Espaço**: O(1)
