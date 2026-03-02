# Problema 1: Subarray com Soma Zero

**Dificuldade**: Médio  
**Tempo limite**: 1 segundo  
**Memória limite**: 256 MB

---

## Descrição

Dado um array de N inteiros, determine se existe um subarray contíguo cuja soma seja exatamente zero.

Um subarray é uma sequência contígua de elementos do array. Se existir, imprima "YES", caso contrário "NO".

---

## Entrada

A primeira linha contém um inteiro N (1 ≤ N ≤ 2×10^5) — o tamanho do array.

A segunda linha contém N inteiros a₁, a₂, ..., aₙ (-10^9 ≤ aᵢ ≤ 10^9) — os elementos do array.

---

## Saída

Imprima "YES" se existe um subarray com soma zero, ou "NO" caso contrário.

---

## Exemplos

### Exemplo 1

**Entrada**:

```
5
4 2 -3 1 6
```

**Saída**:

```
YES
```

**Explicação**: O subarray [2, -3, 1] tem soma = 0.

---

### Exemplo 2

**Entrada**:

```
3
1 2 3
```

**Saída**:

```
NO
```

**Explicação**: Nenhum subarray tem soma zero.

---

### Exemplo 3

**Entrada**:

```
4
-1 4 -3 5
```

**Saída**:

```
YES
```

**Explicação**: O subarray [4, -3] tem soma = 1... aguarde, erro!  
Correto: subarray [-1, 4, -3] tem soma = 0.

---

### Exemplo 4

**Entrada**:

```
1
0
```

**Saída**:

```
YES
```

**Explicação**: O próprio elemento é zero.

---

## Dicas

- Pense em **prefix sum** (soma acumulada)
- Se duas posições têm a mesma soma acumulada, o que isso significa?
- Não esqueça: se somaAcumulada = 0 em algum ponto, já temos resposta
- Cuidado com overflow: use `long long`

---

## Complexidade Esperada

- **Tempo**: O(n)
- **Espaço**: O(n)

Uma solução O(n²) com dois loops vai dar TLE (Time Limit Exceeded).

---

**Arquivo para implementar**: `p01_solution.cpp`  
**Quando terminar**: Compare com [solucoes/p01_solution.cpp](../solucoes/p01_solution.cpp)
