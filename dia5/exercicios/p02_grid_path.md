# 📝 Problema 2: Menor Caminho em Grid

## 📌 Enunciado

Dado um grid M×N com 0s (livre) e 1s (obstáculo), encontre o **menor caminho** de (0,0) até (M-1,N-1).

Você pode se mover apenas em 4 direções (cima, baixo, esquerda, direita).

---

## 📥 Entrada

- **Linha 1**: Dois inteiros M e N
- **Próximas M linhas**: N dígitos (0 ou 1)

---

## 📤 Saída

Um único inteiro: comprimento do menor caminho, ou -1 se impossível.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3 3
0 0 0
0 1 0
0 0 0
```

**Saída**:

```
5
```

---

## ⚙️ Restrições

- 1 ≤ M, N ≤ 500
- grid[0][0] = 0 e grid[M-1][N-1] = 0

---

## 💡 Dicas

- Use BFS (sem peso)
- Mantenha distância junto com cada posição

---

## 🎯 Complexidade Esperada

- **Tempo**: O(M × N)
- **Espaço**: O(M × N)
