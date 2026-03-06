# 📝 Problema 1: Graph + DP Combinado

## 📌 Enunciado

Dado um grafo ponderado, encontreuma ordem de vértices tal que a **soma das diferenças de pesos** entre vértices consecutivos seja mínima.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros V e E
- **Linha 2**: V inteiros (pesos dos vértices)
- **Próximas E linhas**: Dois inteiros (u, v)

---

## 📤 Saída

Mínima soma de diferenças.

---

## ⚙️ Restrições

- 1 ≤ V ≤ 15
- 0 ≤ E ≤ V\*(V-1)/2
- 0 ≤ peso ≤ 10^9

---

## 💡 Dicas

- TSP (Traveling Salesman Problem) variante
- DP + bitmask se V é pequeno

---

## 🎯 Complexidade Esperada

- **Tempo**: O(2^V × V²)
- **Espaço**: O(2^V × V)
