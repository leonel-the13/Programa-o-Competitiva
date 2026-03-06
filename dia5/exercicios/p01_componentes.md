# 📝 Problema 1: Componentes Conexas

## 📌 Enunciado

Dado um grafo não direcionado, determine o **número de componentes conexas**.

Uma componente conexa é um conjunto máximo de vértices onde há caminho entre qualquer par.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros V e E (vértices e arestas)
- **Próximas E linhas**: Dois inteiros u e v (aresta entre u e v)

---

## 📤 Saída

Um único inteiro: número de componentes conexas.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
5 2
0 1
1 2
```

**Saída**:

```
3
```

**Explicação**: Componentes: {0,1,2}, {3}, {4}

---

## ⚙️ Restrições

- 1 ≤ V ≤ 10^5
- 0 ≤ E ≤ 10^5

---

## 💡 Dicas

- Use BFS ou DFS
- Para cada vértice não visitado, faça BFS/DFS e incremente contador

---

## 🎯 Complexidade Esperada

- **Tempo**: O(V + E)
- **Espaço**: O(V)
