# 📝 Problema 1: Contar Primos até N

## 📌 Enunciado

Dado N, conte **quantos números primos existem** entre 2 e N (inclusive).

---

## 📥 Entrada

Um único inteiro N.

---

## 📤 Saída

Número de primos até N.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
10
```

**Saída**:

```
4
```

**Explicação**: Primos: 2, 3, 5, 7

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^7

---

## 💡 Dicas

- Use Crivo de Eratóstenes: O(n log log n)
- Simples teste de primalidade: O(n√n)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n log log n)
- **Espaço**: O(n)
