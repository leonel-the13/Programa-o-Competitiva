# Problema 7: Merge Intervals

**Dificuldade**: Médio  
**Tempo limite**: 1 segundo

## Descrição

Dado N intervalos [início, fim], mescle todos os intervalos sobrepostos.

## Entrada

Primeira linha: N (1 ≤ N ≤ 10^5)  
Próximas N linhas: dois inteiros sᵢ, eᵢ (1 ≤ sᵢ ≤ eᵢ ≤ 10^9)

## Saída

Imprima o número de intervalos após mesclar.  
Depois imprima cada intervalo em uma linha.

## Exemplo

**Entrada**:

```
4
1 3
2 6
8 10
15 18
```

**Saída**:

```
3
1 6
8 10
15 18
```

**Explicação**: [1,3] e [2,6] se sobrepõem → [1,6]

## Dica

Ordene os intervalos pelo início. Depois percorra e mescle quando necessário.

**Arquivo**: `p07_solution.cpp`
