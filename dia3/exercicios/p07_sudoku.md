# 📝 Problema 7: Sudoku Solver

## 📌 Enunciado

Dado um tabuleiro Sudoku 9×9 **incompleto**, resolva-o usando backtracking.

Regras do Sudoku:

- Cada linha deve conter 1-9 uma vez
- Cada coluna deve conter 1-9 uma vez
- Cada bloco 3×3 deve conter 1-9 uma vez

Células vazias são representadas por 0.

---

## 📥 Entrada

9 linhas, cada uma com 9 números (0 = vazio, 1-9 = preenchidos).

---

## 📤 Saída

O tabuleiro resolvido, 9 linhas com 9 números.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

**Saída**:

```
5 3 4 6 7 8 9 1 2
6 7 2 1 9 5 3 4 8
1 9 8 3 4 2 5 6 7
8 5 9 7 6 1 4 2 3
4 2 6 8 5 3 7 9 1
7 1 3 9 2 4 8 5 6
9 6 1 5 3 7 2 8 4
2 8 7 4 1 9 6 3 5
3 4 5 2 8 6 1 7 9
```

---

## ⚙️ Restrições

- Tabuleiro sempre tem solução única

---

## 💡 Dicas

- Backtracking: tente preencher cada célula vazia
- Para cada célula, tente valores 1-9
- Verifique se é válido (linha, coluna, bloco)
- Se válido, recursione; se não, desfaça

---

## 🎯 Complexidade Esperada

- **Tempo**: Exponencial, mas com poda é aceitável
- **Espaço**: O(1) além do input
