# 📝 Problema J: Ordenação Topológica

## 📌 Enunciado

Dado um DAG, retorne uma ordenação topológica. Se houver ciclo, retorne "CICLO".

---

## 📥 Entrada

- **Linha 1**: Dois inteiros V e E
- **Próximas E linhas**: Dois inteiros (u, v)

---

## 📤 Saída

Ordenação topológica ou "CICLO".

---

## ⚙️ Restrições

- 1 ≤ V ≤ 10^5
- 0 ≤ E ≤ 10^5

---

## 💡 Dicas

- Kahn's algorithm ou DFS

---

## 🎯 Complexidade Esperada

- **Tempo**: O(V + E)
- **Espaço**: O(V)
