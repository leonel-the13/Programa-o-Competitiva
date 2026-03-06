# 📝 Problema 10: Shortest Bridge

## 📌 Enunciado

Dado um grid com dois grupos de 1s (ilhas), encontre a **distância mínima** entre elas.

Distância é o número mínimo de 0s que precisa cruzar.

---

## 📥 Entrada

- **Linha 1**: Inteiro N (grid N×N)
- **Próximas N linhas**: String de 0s e 1s

---

## 📤 Saída

Distância mínima.

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- Exatamente 2 ilhas

---

## 💡 Dicas

- Use DFS para marcar a primeira ilha
- Use BFS multi-source partindo de todos 1s da primeira ilha

---

## 🎯 Complexidade Esperada

- **Tempo**: O(N²)
- **Espaço**: O(N²)
