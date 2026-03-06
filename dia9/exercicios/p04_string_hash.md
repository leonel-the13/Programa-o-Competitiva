# 📝 Problema 4: String Hashing

## 📌 Enunciado

Implemente String Hashing para encontrar **quantas substrings únicas** existem usando polynomial rolling hash.

---

## 📥 Entrada

Uma string S.

---

## 📤 Saída

Número de substrings únicos.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
ababa
```

**Saída**:

```
9
```

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 10^5

---

## 💡 Dicas

- Use polynomial hashing: hash = (c0 × p^0 + c1 × p^1 + ...) mod mod
- p e mod devem ser primos grandes

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(n)
