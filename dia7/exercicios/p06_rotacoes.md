# 📝 Problema 6: Rotações de String

## 📌 Enunciado

Dada uma string S e número K, retorne a string rotacionada K vezes para a direita.

Exemplo: "abcde" rotacionada 2 vezes = "deabc"

---

## 📥 Entrada

- **Linha 1**: String S
- **Linha 2**: Inteiro K

---

## 📤 Saída

String rotacionada.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
abcde
2
```

**Saída**:

```
deabc
```

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 10^5
- 0 ≤ K ≤ 10^9

---

## 💡 Dicas

- K pode ser > N, então tome K % N
- Use substr ou rotate

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(n)
