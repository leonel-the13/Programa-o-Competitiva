# Problema 8: Maior Subarray com 0s e 1s Iguais

**Dificuldade**: Difícil  
**Tempo limite**: 1 segundo

## Descrição

Dado um array binário (apenas 0s e 1s), encontre o comprimento do maior subarray contíguo que tenha o mesmo número de 0s e 1s.

## Entrada

Primeira linha: N (1 ≤ N ≤ 2×10^5)  
Segunda linha: N inteiros (cada um 0 ou 1)

## Saída

Imprima o comprimento do maior subarray.

## Exemplos

**Entrada**:

```
6
1 0 1 1 0 0
```

**Saída**:

```
6
```

**Explicação**: O array inteiro tem três 1s e três 0s.

---

**Entrada**:

```
4
0 0 1 0
```

**Saída**:

```
2
```

**Explicação**: [0, 1] ou [1, 0] (índices 1-2)

## Dica

Transforme o problema:

- Troque 0 por -1
- Agora o problema vira: "maior subarray com soma 0"
- Use prefix sum com HashMap

**Arquivo**: `p08_solution.cpp`
