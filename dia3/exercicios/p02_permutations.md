# 📝 Problema 2: Gerar Permutações

## 📌 Enunciado

Dado um array de inteiros **distintos**, gere **todas as permutações** possíveis.

Uma permutação é um arranjo de todos os elementos em qualquer ordem.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros distintos

---

## 📤 Saída

Todas as permutações em ordem. Cada permutação em uma linha, elementos separados por espaço.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
2
1 2
```

**Saída**:

```
1 2
2 1
```

---

### Exemplo 2

**Entrada**:

```
3
1 2 3
```

**Saída**:

```
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 8
- -10^6 ≤ arr[i] ≤ 10^6

---

## 💡 Dicas

- Use backtracking com array de visited
- **Padrão**: Escolher cada elemento não usado, recursão, depois desfazer
- Cuidado: N! cresce muito rápido (8! = 40320)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n! × n)
- **Espaço**: O(n!)
