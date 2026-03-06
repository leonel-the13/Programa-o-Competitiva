# 📝 Problema H: Maior Caminho

## 📌 Enunciado

Dado um DAG (grafo direcionado acíclico), encontre o **caminho com maior soma de pesos**.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros V e E
- **Linha 2**: V inteiros (pesos dos vértices)
- **Próximas E linhas**: Três inteiros (u, v, peso da aresta)

---

## 📤 Saída

Maior soma de caminho.

---

## 🧪 Exemplos (Conceitual)

---

## ⚙️ Restrições

- 1 ≤ V ≤ 100
- 0 ≤ E ≤ 10000

---

## 💡 Dicas

- Use DP + Topological Sort
- dp[u] = máximo caminho terminando em u

---

## 🎯 Complexidade Esperada

- **Tempo**: O(V + E)
- **Espaço**: O(V)
