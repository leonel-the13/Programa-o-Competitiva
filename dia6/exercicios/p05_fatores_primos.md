# 📝 Problema 5: Fatores Primos

## 📌 Enunciado

Dado N, encontre sua **decomposição em fatores primos**.

Retorne os primos e seus expoentes.

---

## 📥 Entrada

Um único inteiro N.

---

## 📤 Saída

Primos e expoentes: p1^e1 p2^e2 ...

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
60
```

**Saída**:

```
2^2 3^1 5^1
```

**Explicação**: 60 = 2² × 3 × 5

---

## ⚙️ Restrições

- 2 ≤ N ≤ 10^9

---

## 💡 Dicas

- Divide por 2 enquanto possível
- Depois tenta divisores ímpares até √n

---

## 🎯 Complexidade Esperada

- **Tempo**: O(√n)
- **Espaço**: O(log n)
