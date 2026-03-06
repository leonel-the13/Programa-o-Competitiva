# 📝 Problema 8: Menor Janela com Todos Caracteres

## 📌 Enunciado

Dados uma string S e string T, encontre a **menor substring de S** que contém **todos os caracteres de T**.

---

## 📥 Entrada

- **Linha 1**: String S
- **Linha 2**: String T

---

## 📤 Saída

A menor substring. Se não houver, imprima "NENHUM".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
ADOBECODEBANC
ABC
```

**Saída**:

```
BANC
```

---

## ⚙️ Restrições

- 1 ≤ |S|, |T| ≤ 10^5

---

## 💡 Dicas

- Use sliding window com 2 pointers
- Frequência de caracteres

---

## 🎯 Complexidade Esperada

- **Tempo**: O(|S| + |T|)
- **Espaço**: O(1) (fixed alphabet)
