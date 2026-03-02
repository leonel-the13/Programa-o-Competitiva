# Problema 6: Elemento que Aparece Uma Vez

**Dificuldade**: Médio  
**Tempo limite**: 1 segundo

## Descrição

Em um array onde cada elemento aparece duas vezes, exceto um que aparece uma vez, encontre esse elemento único.

**Restrição especial**: Use complexidade O(n) tempo e O(1) espaço.

## Entrada

Primeira linha: N (1 ≤ N ≤ 10^5, N é ímpar)  
Segunda linha: N inteiros (1 ≤ aᵢ ≤ 10^9)

## Saída

Imprima o elemento único.

## Exemplo

**Entrada**:

```
5
4 1 2 1 2
```

**Saída**:

```
4
```

## Dica

Pense em operações bit a bit. O que acontece quando você faz XOR de um número com ele mesmo?

**Propriedade**: a ⊕ a = 0, a ⊕ 0 = a

**Arquivo**: `p06_solution.cpp`
