# 📝 Problema 4: É Subsequência

## 📌 Enunciado

Dado duas strings S e T, verifique se S é uma **subsequência de T**.

Uma subsequência não precisa ser contígua.

---

## 📥 Entrada

- **Linha 1**: String S
- **Linha 2**: String T

---

## 📤 Saída

"SIM" ou "NAO".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
abc
ahbgdc
```

**Saída**:

```
SIM
```

**Explicação**: a, b, c aparecem em ordem em T.

---

## ⚙️ Restrições

- 0 ≤ |S|, |T| ≤ 10^5

---

## 💡 Dicas

- Two pointers: iterar T e procurar caracteres de S

---

## 🎯 Complexidade Esperada

- **Tempo**: O(|T|)
- **Espaço**: O(1)
