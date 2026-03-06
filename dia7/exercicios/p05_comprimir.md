# 📝 Problema 5: Comprimir String

## 📌 Enunciado

Comprime uma string usando contagem de caracteres consecutivos.

Exemplo: "aabbbcccc" → "a2b3c4"

Se comprimido não é menor, retorna string original.

---

## 📥 Entrada

Uma string S.

---

## 📤 Saída

String comprimida ou original.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
abcccccde
```

**Saída**:

```
a1b1c5d1e1
```

---

### Exemplo 2

**Entrada**:

```
abc
```

**Saída**:

```
abc
```

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 100

---

## 💡 Dicas

- Iterate e conte consecutivos

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(n)
