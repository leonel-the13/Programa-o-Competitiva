# 📝 Problema 7: Quatro Números com Soma Alvo

## 📌 Enunciado

Dado um array de inteiros e um alvo, encontre **todos os quadruplets únicos** cuja soma seja igual ao alvo.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros
- **Linha 3**: Inteiro target

---

## 📤 Saída

Quadruplets em ordem crescente (elementos e entre quadruplets). Se não houver, imprima "NENHUM".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
6
1000000000 1000000000 1000000000 1000000000
-294967296
```

**Saída**:

```
1000000000 1000000000 1000000000 1000000000
```

---

### Exemplo 2

**Entrada**:

```
5
1 0 -1 0 -2 2
0
```

**Saída**:

```
-2 -1 1 2
-2 0 0 2
-1 0 0 1
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 200
- -10^9 ≤ arr[i] ≤ 10^9
- -10^9 ≤ target ≤ 10^9

---

## 💡 Dicas

- Ordene o array
- Use loop duplo + two pointers para buscar pares
- Cuidado com duplicatas e overflow

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n³) se usar ingênuo, O(n² log n) bom
- **Espaço**: O(1)
