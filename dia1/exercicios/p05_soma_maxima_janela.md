# Problema 5: Soma Máxima em Janela de Tamanho K

**Dificuldade**: Médio  
**Tempo limite**: 1 segundo

## Descrição

Dado um array de N inteiros e um inteiro K, encontre a soma máxima de K elementos consecutivos.

## Entrada

Primeira linha: N, K (1 ≤ K ≤ N ≤ 10^5)  
Segunda linha: N inteiros (-10^9 ≤ aᵢ ≤ 10^9)

## Saída

Imprima a soma máxima.

## Exemplo

**Entrada**:

```
6 3
1 4 2 10 2 3
```

**Saída**:

```
16
```

**Explicação**: [4, 2, 10] = 16

## Dica

Use sliding window: mantenha soma da janela, deslize removendo um e adicionando outro.

**Arquivo**: `p05_solution.cpp`
