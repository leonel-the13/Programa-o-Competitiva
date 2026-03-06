# 📝 Problema 7: Contar Divisores de Fatorial

## 📌 Enunciado

Dado N, compute o número de divisores de N! (fatorial).

---

## 📥 Entrada

Um único inteiro N.

---

## 📤 Saída

Número de divisores de N!.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
5
```

**Saída**:

```
16
```

**Explicação**: 5! = 120 = 2³×3×5. Divisores: (3+1)×(1+1)×(1+1) = 16

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5

---

## 💡 Dicas

- Se n = p1^a1 × p2^a2 × ... então divisores = (a1+1) × (a2+1) × ...
- Encontre expoente de cada primo em N!

---

## 🎯 Complexidade Esperada

- **Tempo**: O(√n + n)
- **Espaço**: O(n)
