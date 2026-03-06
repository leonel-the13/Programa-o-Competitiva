# 📝 Problema 9: Exponenciação de Matrizes

## 📌 Enunciado

Compute A^N (matriz A elevada a potência N) modulo M usando exponenciação rápida.

---

## 📥 Entrada

- **Linha 1**: Inteiro N (tamanho matriz) e expoente K
- **Próximas N linhas**: Matriz N×N
- **Última linha**: Inteiro M (módulo)

---

## 📤 Saída

Matriz A^K mod M.

---

## 🧪 Exemplos (Conceitual)

Seu array A:

```
[1 1]
[1 0]
```

Compute A^3:
A² = [[2,1],[1,1]]
A³ = [[3,2],[2,1]]

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- 1 ≤ K ≤ 10^18
- 1 ≤ M ≤ 10^9

---

## 💡 Dicas

- Implemente multiplicação de matrizes com mod
- Use exponenciação rápida (binary exponentiation)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(log K × N³)
- **Espaço**: O(N²)
