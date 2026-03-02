# Problema 10: Sliding Window Maximum

**Dificuldade**: Difícil  
**Tempo limite**: 2 segundos

## Descrição

Dado um array de N inteiros e um inteiro K, para cada janela consecutiva de tamanho K, encontre o elemento máximo.

## Entrada

Primeira linha: N, K (1 ≤ K ≤ N ≤ 10^5)  
Segunda linha: N inteiros (-10^9 ≤ aᵢ ≤ 10^9)

## Saída

Imprima N - K + 1 inteiros: o máximo de cada janela.

## Exemplo

**Entrada**:

```
8 3
1 3 -1 -3 5 3 6 7
```

**Saída**:

```
3 3 5 5 6 7
```

**Explicação**:

- Janela [1, 3, -1]: max = 3
- Janela [3, -1, -3]: max = 3
- Janela [-1, -3, 5]: max = 5
- Janela [-3, 5, 3]: max = 5
- Janela [5, 3, 6]: max = 6
- Janela [3, 6, 7]: max = 7

## Dica

Solução ingênua O(nk) vai dar TLE.

**Solução eficiente**: Use um `deque` (fila de duas pontas)

- Mantenha índices em ordem decrescente de valores
- Remova índices fora da janela
- Remova elementos menores que o atual (nunca serão máximo)

**Complexidade**: O(n)

**Arquivo**: `p10_solution.cpp`
