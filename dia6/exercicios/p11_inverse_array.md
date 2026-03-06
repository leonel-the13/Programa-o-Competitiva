# 📝 Problema 11: Modular Inverse Array

## 📌 Enunciado

Dado um array de inteiros e um módulo primo P, compute o inverso modular de cada elemento modulo P.

O inverso modular de A modulo P é um número X tal que (A × X) ≡ 1 (mod P).

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros
- **Linha 3**: Inteiro P (primo)

---

## 📤 Saída

N inteiros: inverso modular de cada elemento.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3
2 3 5
7
```

**Saída**:

```
4 5 3
```

**Explicação**:

- 2×4 ≡ 8 ≡ 1 (mod 7) ✓
- 3×5 ≡ 15 ≡ 1 (mod 7) ✓
- 5×3 ≡ 15 ≡ 1 (mod 7) ✓

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 1 ≤ arr[i] < P
- P é primo
- P ≤ 10^9

---

## 💡 Dicas

- Use Fermat's Little Theorem: a^(p-1) ≡ 1 (mod p)
- Logo: a^(-1) ≡ a^(p-2) (mod p)
- Use exponenciação rápida

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n log p)
- **Espaço**: O(n)
