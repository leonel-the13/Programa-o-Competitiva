# 📝 Problema D: Substring Palindrômica

## 📌 Enunciado

Dado uma string, encontre o **número de substrings que são palíndromos**.

---

## 📥 Entrada

Uma string S.

---

## 📤 Saída

Número de substrings palindrômicos.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
abc
```

**Saída**:

```
3
```

**Explicação**: "a", "b", "c" (substrings simples são palíndromos)

---

### Exemplo 2

**Entrada**:

```
aab
```

**Saída**:

```
4
```

**Explicação**: "a"(x2), "a", "b", "aa"

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 500

---

## 💡 Dicas

- Expansão ao redor do centro
- Ou DP O(n²)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n²)
- **Espaço**: O(1)
