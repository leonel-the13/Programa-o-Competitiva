# 📝 Problema 1: Gerar Todos os Subsets

## 📌 Enunciado

Dado um array de inteiros **distintos**, gere **todos os possíveis subsets** (também chamados de power set).

Um subset é qualquer combinação de elementos, incluindo o conjunto vazio.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros distintos

---

## 📤 Saída

Todos os subsets em ordem. Cada subset em uma linha, elementos separados por espaço.

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

1
2
1 2
```

**Explicação**: 2² = 4 subsets

---

### Exemplo 2

**Entrada**:

```
3
1 2 3
```

**Saída**:

```

1
2
1 2
3
1 3
2 3
1 2 3
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 20
- -10^6 ≤ arr[i] ≤ 10^6

---

## 💡 Dicas

- **Recursão**: Incluir ou não incluir cada elemento
- **Iterativo**: Usar bits - cada número de 0 a 2^n-1 representa um subset
- **Backtracking**: Template padrão

---

## 🎯 Complexidade Esperada

- **Tempo**: O(2^n × n)
- **Espaço**: O(2^n × n) para armazenar output
