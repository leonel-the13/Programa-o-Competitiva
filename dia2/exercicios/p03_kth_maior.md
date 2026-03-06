# 📝 Problema 3: Kth Maior Elemento

## 📌 Enunciado

Dado um array não ordenado, encontre o **k-ésimo maior elemento**.

⚠️ Considera-se que K é válido (1 ≤ K ≤ N)

---

## 📥 Entrada

- **Linha 1**: Inteiro N (tamanho do array)
- **Linha 2**: N inteiros separados por espaço
- **Linha 3**: Inteiro K

---

## 📤 Saída

Um único inteiro: o K-ésimo maior elemento.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
5
3 2 1 4 5
1
```

**Saída**:

```
5
```

**Explicação**:  
Ordenado: [5, 4, 3, 2, 1]. O 1º maior é 5.

---

### Exemplo 2

**Entrada**:

```
5
3 2 1 4 5
3
```

**Saída**:

```
3
```

**Explicação**:  
Ordenado: [5, 4, 3, 2, 1]. O 3º maior é 3.

---

### Exemplo 3

**Entrada**:

```
4
1 1 1 1
2
```

**Saída**:

```
1
```

**Explicação**:  
Todos elementos iguais, 2º maior também é 1.

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 1 ≤ arr[i] ≤ 10^9
- 1 ≤ K ≤ N

---

## 💡 Dicas

- **Simples**: Ordenar e retornar arr[k-1]
- **Otimizado**: Usar Heap (priority_queue)
- **Avançado**: Quickselect em O(n) médio

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n log n) ou O(n) com Quickselect
- **Espaço**: O(1)
