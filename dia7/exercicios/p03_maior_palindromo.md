# 📝 Problema 3: Maior Palíndromo

## 📌 Enunciado

Dado uma string, encontre o **maior substring que é palíndromo**.

---

## 📥 Entrada

Uma string S.

---

## 📤 Saída

O maior palíndromo.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
babad
```

**Saída**:

```
bab
```

ou

```
aba
```

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 1000

---

## 💡 Dicas

- **Expansão ao redor do centro**: O(n²) e fácil
- **DP Manacher**: O(n)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n²)
- **Espaço**: O(1)
