# 📝 Problema F: Triplas com Condição

## 📌 Enunciado

Dado um array, encontre **quantas triplas (i,j,k)** satisfazem: i < j < k **e** arr[i] < arr[k] < arr[j].

---

## 📥 Entrada

- **Linha 1**: Inteiro N
- **Linha 2**: N inteiros

---

## 📤 Saída

Número de triplas.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4
1 4 0 2
```

**Saída**:

```
1
```

**Explicação**: (0,1,2): arr[0]=1, arr[1]=4, arr[2]=0. 0 < 1? Não... Verifique problema.

Procuram triplas onde arr[i] < arr[k] < arr[j]:

- i=0, j=1, k=2: 1 < 0 < 4? Não
- i=0, j=1, k=3: 1 < 2 < 4? Sim! (1)
- i=0, j=3, k=2: índices fora de ordem

Total: 1

---

## ⚙️ Restrições

- 1 ≤ N ≤ 400
- 0 ≤ arr[i] ≤ 10^9

---

## 💡 Dicas

- Triple loop O(n³) passa pois N é pequeno
- Ou otimize com estruturas

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n²) ou O(n³)
- **Espaço**: O(1)
