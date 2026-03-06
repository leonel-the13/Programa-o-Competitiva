# 📝 Problema 4: Número Perfeito

## 📌 Enunciado

Um número perfeito é aquele cuja soma de seus divisores próprios (excluindo ele mesmo) é igual a ele próprio.

Exemplo: 6 = 1 + 2 + 3

Dado N, verifique se é perfeito.

---

## 📥 Entrada

Um único inteiro N.

---

## 📤 Saída

"SIM" ou "NAO".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
6
```

**Saída**:

```
SIM
```

---

### Exemplo 2

**Entrada**:

```
28
```

**Saída**:

```
SIM
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^9

---

## 💡 Dicas

- Encontre todos divisores: O(√n)
- Some seus divisores (exceto N)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(√n)
- **Espaço**: O(1)
