# 📝 Problema 3: Potência Modular

## 📌 Enunciado

Compute (a^b) mod m de forma eficiente.

---

## 📥 Entrada

- **Linha 1**: Três inteiros a, b, m

---

## 📤 Saída

(a^b) mod m.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
2 10 1000
```

**Saída**:

```
24
```

**Explicação**: 2^10 = 1024, 1024 mod 1000 = 24

---

## ⚙️ Restrições

- 1 ≤ a, b, m ≤ 10^9

---

## 💡 Dicas

- Use exponenciação rápida: O(log b)
- Tomar mod a cada multiplicação para evitar overflow

---

## 🎯 Complexidade Esperada

- **Tempo**: O(log b)
- **Espaço**: O(1)
