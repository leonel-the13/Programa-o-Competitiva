# 📝 Problema 8: Rotting Oranges

## 📌 Enunciado

Dado um grid com laranja fresca (1), laranja podre (2) e vaza (0), as laranjas podres propagam para fresca em 1 minuto (4 direções).

Encontre o **tempo mínimo** para todas as laranjas ficarem podres, ou -1 se impossível.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros M e N
- **Próximas M linhas**: N dígitos (0, 1, 2)

---

## 📤 Saída

Tempo mínimo ou -1.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3 3
2 1 1
1 1 0
0 1 1
```

**Saída**:

```
4
```

---

## ⚙️ Restrições

- 1 ≤ M, N ≤ 100

---

## 💡 Dicas

- Use multi-source BFS
- Começar com todas as laranjas podres na fila

---

## 🎯 Complexidade Esperada

- **Tempo**: O(M × N)
- **Espaço**: O(M × N)
