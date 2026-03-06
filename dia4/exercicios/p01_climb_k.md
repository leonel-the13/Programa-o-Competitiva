# 📝 Problema 1: Climbing Stairs com K passos

## 📌 Enunciado

Você está em um degrau 0 e precisa chegar ao degrau N. Você pode **subir 1 a K degraus por vez**.

**De quantas formas diferentes você pode atingir o degrau N?**

---

## 📥 Entrada

- **Linha 1**: Inteiro N (degrau alvo)
- **Linha 2**: Inteiro K (máximo de degraus por vez)

---

## 📤 Saída

Um único inteiro: número de formas de alcançar o degrau N modulo 10^9+7.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
3
2
```

**Saída**:

```
3
```

**Explicação**: Formas: (1+1+1), (1+2), (2+1) - 3 formas

---

### Exemplo 2

**Entrada**:

```
4
2
```

**Saída**:

```
5
```

**Explicação**: (1+1+1+1), (1+1+2), (1+2+1), (2+1+1), (2+2) - 5 formas

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- 1 ≤ K ≤ 100

---

## 💡 Dicas

- **Recorrência**: dp[i] = sum(dp[i-1], dp[i-2], ..., dp[i-k]) para i >= k
- **DP bottom-up**: Iterar de 0 a N
- **Otimização**: Use sliding window sum para O(n)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n × k) ou O(n) otimizado
- **Espaço**: O(n)
