# 📝 Problema 6: N-Queens

## 📌 Enunciado

O **problema clássico das N Rainhas**: Coloque N rainhas em um tabuleiro N×N tal que **nenhuma rainha se ataque**.

Duas rainhas se atacam se estiverem na mesma linha, coluna ou diagonal.

---

## 📥 Entrada

Um único inteiro N (tamanho do tabuleiro).

---

## 📤 Saída

Número de formas diferentes de colocar N rainhas sem que se ataquem.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
1
```

**Saída**:

```
1
```

---

### Exemplo 2

**Entrada**:

```
4
```

**Saída**:

```
2
```

---

### Exemplo 3

**Entrada**:

```
8
```

**Saída**:

```
92
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 13

---

## 💡 Dicas

- Backtracking: coloque rainha linha por linha
- Para cada coluna na linha atual, verifique se é seguro
- Verifique: coluna, diagonal \\ e diagonal //
- Poda: se alguma posição for impossível, retorne

---

## 🎯 Complexidade Esperada

- **Tempo**: O(N!)
- **Espaço**: O(N) para recursão
