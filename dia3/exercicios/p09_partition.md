# 📝 Problema 9: Partition Equal Subset Sum

## 📌 Enunciado

Dado um array de inteiros, determine se é **possível particionar** em dois subsets com **soma igual**.

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros

---

## 📤 Saída

"SIM" se possível particionar em duas somas iguais, "NAO" caso contrário.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4
1 5 11 5
```

**Saída**:

```
SIM
```

**Explicação**: [11] e [5,5,1] ambas com soma 11.

---

### Exemplo 2

**Entrada**:

```
2
2 2
```

**Saída**:

```
SIM
```

**Explicação**: [2] e [2], ambas soma 2.

---

### Exemplo 3

**Entrada**:

```
3
1 2 5
```

**Saída**:

```
NAO
```

**Explicação**: Soma total = 8, não é par. Impossível.

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- 0 ≤ arr[i] ≤ 200

---

## 💡 Dicas

- Se soma total é ímpar, retorna false
- Se soma total é par, procure subset com soma = total/2
- **DP**: dp[i] = true se suma i é alcançável
- **Backtracking**: Tente todos os subsets

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n × sum/2) com DP
- **Espaço**: O(sum/2)
