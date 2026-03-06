# 📝 Problema 8: Equação Diofantina

## 📌 Enunciado

Resolva a equação linear Diofantina: ax + by = c

---

## 📥 Entrada

- **Linha 1**: Três inteiros a, b, c

---

## 📤 Saída

Uma solução (x, y) se existir, ou "IMPOSSIVEL" caso contrário.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
2 3 5
```

**Saída**:

```
1 1
```

**Explicação**: 2×1 + 3×1 = 5 ✓

---

## ⚙️ Restrições

- -10^9 ≤ a, b, c ≤ 10^9

---

## 💡 Dicas

- Existe solução se MDC(a,b) divide c
- Use Extended Euclidean Algorithm para encontrar solução particular

---

## 🎯 Complexidade Esperada

- **Tempo**: O(log(min(a,b)))
- **Espaço**: O(1)
