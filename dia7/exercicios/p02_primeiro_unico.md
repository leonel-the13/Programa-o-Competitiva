# 📝 Problema 2: Primeiro Caractere Único

## 📌 Enunciado

Dado uma string, encontre o **índice do primeiro caractere que aparece apenas uma vez**.

Se não houver, retorne -1.

---

## 📥 Entrada

Uma string S.

---

## 📤 Saída

Índice ou -1.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
leetcode
```

**Saída**:

```
0
```

**Explicação**: 'l' aparece apenas uma vez.

---

### Exemplo 2

**Entrada**:

```
loveleetcode
```

**Saída**:

```
2
```

**Explicação**: 'v' é o primeiro único em posição 2.

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 10^5

---

## 💡 Dicas

- Use frequência
- Iterate segunda vez para encontrar primeiro

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(1) (fixed alphabet)
