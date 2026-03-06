# 📝 Problema 3: Detectar Ciclo

## 📌 Enunciado

Dado um grafo não direcionado, determine se **há ciclo**.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros V e E
- **Próximas E linhas**: Dois inteiros u e v

---

## 📤 Saída

"SIM" se há ciclo, "NAO" caso contrário.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3 3
0 1
1 2
2 0
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

- Use DFS com tracking de parent
- Se visita vértice que não é parent e já foi visitado, há ciclo

---

## 🎯 Complexidade Esperada

- **Tempo**: O(V + E)
- **Espaço**: O(V)
