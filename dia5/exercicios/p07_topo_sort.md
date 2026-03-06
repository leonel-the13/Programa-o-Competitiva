# 📝 Problema 7: Ordenação Topológica

## 📌 Enunciado

Dado um DAG (grafo direcionado acíclico), encontre uma **ordenação topológica válida**.

Uma ordenação topológica é uma ordem de vértices tal que para toda aresta (u,v), u vem antes de v.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros V e E
- **Próximas E linhas**: Dois inteiros u e v

---

## 📤 Saída

Uma ordenação topológica válida (espaço separado). Se houver ciclo, imprima "CICLO".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4 4
1 0
0 2
2 3
1 3
```

**Saída**:

```
1 0 2 3
```

---

## ⚙️ Restrições

- 1 ≤ V ≤ 10^5
- 0 ≤ E ≤ 10^5

---

## 💡 Dicas

- Use Kahn's algorithm (BFS com indegree)
- Ou DFS com pilha

---

## 🎯 Complexidade Esperada

- **Tempo**: O(V + E)
- **Espaço**: O(V)
