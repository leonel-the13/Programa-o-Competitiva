# 📝 Problema 10: Partition Equal Subset Sum (DP)

## 📌 Enunciado

Dado um array de inteiros, determine se é **possível particionar** em dois subsets com **soma igual**.

(Mesmo problema do Dia 3, mas resolva com DP!)

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros

---

## 📤 Saída

"SIM" ou "NAO".

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

---

### Exemplo 2

**Entrada**:

```
3
1 2 5
```

**Saída**:

```
NAO
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 100
- 0 ≤ arr[i] ≤ 200

---

## 💡 Dicas

- **DP**: dp[i] = true se soma i é alcançável
- **Base**: dp[0] = true
- **Transição**: Para cada elemento, atualizar dp em ordem reversa
- Se sum total é ímpar, resposta é não
- Procure subset com soma = total/2

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n × sum/2)
- **Espaço**: O(sum/2)
