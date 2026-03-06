# 📝 Problema 6: Buscar em Array Rotacionado

## 📌 Enunciado

Um array foi **rotacionado** um número desconhecido de vezes.

Exemplo: [0,1,2,4,5,6,7] rotacionado 3 vezes → [4,5,6,7,0,1,2]

Dado um alvo, **encontre sua posição ou retorne -1** se não encontrado.

---

## 📥 Entrada

- **Linha 1**: Inteiro N (tamanho do array)
- **Linha 2**: N inteiros separados por espaço (array rotacionado)
- **Linha 3**: Inteiro target

---

## 📤 Saída

Um único inteiro: índice do target ou -1 se não encontrado.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
7
4 5 6 7 0 1 2
0
```

**Saída**:

```
4
```

---

### Exemplo 2

**Entrada**:

```
7
4 5 6 7 0 1 2
3
```

**Saída**:

```
-1
```

---

### Exemplo 3

**Entrada**:

```
1
1
1
```

**Saída**:

```
0
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- Array contém elementos únicos
- -10^9 ≤ arr[i] ≤ 10^9
- -10^9 ≤ target ≤ 10^9

---

## 💡 Dicas

- Use Binary Search modificado
- Identifique qual lado está ordenado
- Se target está no lado ordenado, busque lá; senão, vá pro outro lado

---

## 🎯 Complexidade Esperada

- **Tempo**: O(log n)
- **Espaço**: O(1)
