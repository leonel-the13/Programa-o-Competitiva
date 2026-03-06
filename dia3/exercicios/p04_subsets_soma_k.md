# 📝 Problema 4: Subsets com Soma K

## 📌 Enunciado

Dado um array e um valor K, encontre **todos os subsets** cuja **soma seja exatamente K**.

Cada elemento pode ser usado **no máximo uma vez**.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros
- **Linha 3**: Inteiro K

---

## 📤 Saída

Todos os subsets com soma K. Cada subset em ordem crescente, e depois subsets em ordem lexicográfica. Se não houver, imprima "NENHUM".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4
3 1 4 1
5
```

**Saída**:

```
1 4
3 1 1
```

---

### Exemplo 2

**Entrada**:

```
3
1 2 3
10
```

**Saída**:

```
NENHUM
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 20
- -10^6 ≤ arr[i] ≤ 10^6
- 1 ≤ K ≤ 10^9

---

## 💡 Dicas

- Backtracking: escolher elemento ou não
- Poda: se soma > K, pode parar
- Importante: Passar índice para evitar reutilizar elemento

---

## 🎯 Complexidade Esperada

- **Tempo**: O(2^n × n)
- **Espaço**: O(n)
