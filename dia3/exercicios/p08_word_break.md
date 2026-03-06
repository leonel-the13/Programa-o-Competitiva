# 📝 Problema 8: Word Break II

## 📌 Enunciado

Dado uma string S e uma lista de palavras, encontre **todas as formas de quebrar S** usando palavras da lista.

Cada palavra pode ser usada multiple vezes.

---

## 📥 Entrada

- **Linha 1**: String S
- **Linha 2**: Inteiro N (número de palavras)
- **Próximas N linhas**: Palavras do dicionário

---

## 📤 Saída

Todas as formas de quebrar S, uma por linha, com palavras separadas por espaço em ordem de formação.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
catsandcatsdog
3
cat
cats
and
sand
dog
```

**Saída**:

```
cats and cat dog
cats and cats dog
cat sand cats dog
```

**Explicação**: Válidos: "cats and cat dog", "cats and cats dog", "cat sand cats dog"

---

### Exemplo 2

**Entrada**:

```
pineapplepenapple
2
apple
pen
```

**Saída**:

```
pine apple pen apple
pine apple pena pple
```

---

## ⚙️ Restrições

- 1 ≤ |S| ≤ 20
- 1 ≤ N ≤ 20
- 1 ≤ |palavra| ≤ 20

---

## 💡 Dicas

- Use backtracking
- Para cada posição, tente todas as palavras do dicionário
- Se palavra matches prefixo, recursione no resto
- Memoization pode acelerar

---

## 🎯 Complexidade Esperada

- **Tempo**: Exponencial
- **Espaço**: O(|S|) para recursão
