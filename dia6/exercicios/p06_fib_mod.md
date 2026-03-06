# 📝 Problema 6: Fibonacci Modular

## 📌 Enunciado

Compute o N-ésimo número de Fibonacci modulo M.

F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: Inteiro M

---

## 📤 Saída

F(N) mod M.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
10
1000000007
```

**Saída**:

```
55
```

---

## ⚙️ Restrições

- 0 ≤ N ≤ 10^18
- 1 ≤ M ≤ 10^9

---

## 💡 Dicas

- Para N, muito grande, use exponenciação de matriz
- Ou use memoization com mod

---

## 🎯 Complexidade Esperada

- **Tempo**: O(log n)
- **Espaço**: O(log n)
