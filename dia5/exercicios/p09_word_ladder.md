# 📝 Problema 9: Word Ladder

## 📌 Enunciado

Dado uma palavra init, uma palavra final e uma lista de palavras, encontre o **caminho mais curto** transformando init em final mudando uma letra por vez.

Cada passo deve ser uma palavra na lista.

---

## 📥 Entrada

- **Linha 1**: String beginWord
- **Linha 2**: String endWord
- **Linha 3**: Inteiro N (número de palavras)
- **Próximas N linhas**: Palavras

---

## 📤 Saída

Comprimento do caminho curto (incluindo init e end), ou 0 se impossível.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
hit
cog
4
hot
dot
dog
lot
log
cog
```

**Saída**:

```
5
```

**Explicação**: hit -> hot -> dot -> dog -> cog

---

## ⚙️ Restrições

- Todas palavras têm mesmo tamanho
- 1 ≤ tamanho ≤ 10
- Diferença é de 1 letra apenas

---

## 💡 Dicas

- Use BFS
- Encontre palavras que diferem por 1 letra

---

## 🎯 Complexidade Esperada

- **Tempo**: O(N × L² × 26) onde L = tamanho palavra
- **Espaço**: O(N)
