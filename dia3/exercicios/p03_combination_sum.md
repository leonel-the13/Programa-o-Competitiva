# 📝 Problema 3: Combination Sum

## 📌 Enunciado

Dado um array de inteiros (pode ter repetições) e um alvo, encontre **todas as combinações** que somem ao alvo. **Cada número pode ser usado unlimited vezes**.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros
- **Linha 3**: Inteiro target

---

## 📤 Saída

Todas as combinações únicas. Cada combinação em ordem crescente, e depois combinações em ordem lexicográfica.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3
2 3 6
7
```

**Saída**:

```
2 2 3
```

**Explicação**: Única forma de fazer 7 com esses números.

---

### Exemplo 2

**Entrada**:

```
2
2 3
8
```

**Saída**:

```
2 2 2 2
2 3 3
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- 1 ≤ arr[i] ≤ 100
- 1 ≤ target ≤ 500
- Todos elementos são positivos

---

## 💡 Dicas

- (Remova duplicatas do array primeiro)
- Use backtracking
- Importante: Passe índice (pode reutilizar)
- Poda: Se soma > target, retorne

---

## 🎯 Complexidade Esperada

- **Tempo**: Exponencial (depende da saída)
- **Espaço**: O(target) para recursão
