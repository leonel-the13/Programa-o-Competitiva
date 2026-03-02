# Problema 4: Reorganizar Array

**Dificuldade**: Médio  
**Tempo limite**: 1 segundo

## Descrição

Dado um array, reorganize-o de forma que arr[i] ≠ arr[i+1] para todo i. Se for impossível, imprima "-1".

## Entrada

Primeira linha: N (1 ≤ N ≤ 10^5)  
Segunda linha: N inteiros (1 ≤ aᵢ ≤ 10^9)

## Saída

Imprima o array reorganizado ou "-1".

## Exemplos

**Entrada**:

```
5
1 1 2 2 3
```

**Saída**:

```
1 2 1 2 3
```

**Entrada**:

```
4
1 1 1 1
```

**Saída**:

```
-1
```

## Dica

Se algum elemento aparece mais de (N+1)/2 vezes, é impossível.

**Arquivo**: `p04_solution.cpp`
