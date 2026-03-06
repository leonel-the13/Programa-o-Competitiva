# 📝 Problema 6: É Bipartido?

## 📌 Enunciado

Dado um grafo não direcionado, determine se é **bipartido**.

Um grafo é bipartido se pode ser colorido com 2 cores tal que nenhuma aresta liga vértices de mesma cor.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros V e E
- **Próximas E linhas**: Dois inteiros u e v

---

## 📤 Saída

"SIM" ou "NAO".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4 4
0 1
1 2
2 3
3 0
```

**Saída**:

```
SIM
```

---

## ⚙️ Restrições

- 1 ≤ V ≤ 10^5
- 0 ≤ E ≤ 10^5

---

## 💡 Dicas

- Use BFS/DFS com 2-coloração
- Se conseguir colorir todo grafo com 2 cores, é bipartido

---

## 🎯 Complexidade Esperada

- **Tempo**: O(V + E)
- **Espaço**: O(V)
