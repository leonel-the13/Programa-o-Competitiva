# 📝 Problema 7: KMP Pattern Matching

## 📌 Enunciado

Dado um texto T e padrão P, encontre **todas as ocorrências** de P em T usando KMP.

---

## 📥 Entrada

- **Linha 1**: String T (texto)
- **Linha 2**: String P (padrão)

---

## 📤 Saída

Índices onde P começa em T, espaço separado. Se não houver, imprima "NENHUM".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
ababcababa
aba
```

**Saída**:

```
0 5 7
```

---

## ⚙️ Restrições

- 1 ≤ |T|, |P| ≤ 10^6

---

## 💡 Dicas

- Implemente LPS array
- Iterar T procurando P

---

## 🎯 Complexidade Esperada

- **Tempo**: O(|T| + |P|)
- **Espaço**: O(|P|)
