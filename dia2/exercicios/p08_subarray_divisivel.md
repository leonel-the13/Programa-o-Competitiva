# 📝 Problema 8: Subarray com Soma Divisível por K

## 📌 Enunciado

Dado um array de inteiros e um valor K, determine **quantos subarrays** têm soma **divisível por K**.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros
- **Linha 3**: Inteiro K (K > 0)

---

## 📤 Saída

Um único inteiro: número de subarrays com soma divisível por K.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4
4 5 0 -2
5
```

**Saída**:

```
7
```

**Explicação**:  
Subarrays com soma ≡ 0 (mod 5):

- [4,5], [5], [0], [0,-2], [4,5,0], [4,5,0,-2], [-2]

---

### Exemplo 2

**Entrada**:

```
3
3 1 2
3
```

**Saída**:

```
2
```

**Explicação**:

- [3] tem soma 3 ≡ 0 (mod 3)
- [3,1,2] tem soma 6 ≡ 0 (mod 3)

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- -10^9 ≤ arr[i] ≤ 10^9
- 1 ≤ K ≤ 10^9

---

## 💡 Dicas

- Use Prefix Sum + HashMap
- Armazene (prefix % K) e conte quantas vezes aparece
- Cuidado com mód negativo em C++

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(k)
