# Problema 9: Tripla com Soma Mais Próxima

**Dificuldade**: Difícil  
**Tempo limite**: 1 segundo

## Descrição

Dado um array de N inteiros e um valor target, encontre três elementos cuja soma seja a mais próxima possível de target. Retorne essa soma.

## Entrada

Primeira linha: N, target (3 ≤ N ≤ 10^3, -10^9 ≤ target ≤ 10^9)  
Segunda linha: N inteiros (-10^9 ≤ aᵢ ≤ 10^9)

## Saída

Imprima a soma dos três elementos.

## Exemplo

**Entrada**:

```
4 1
-1 2 1 -4
```

**Saída**:

```
2
```

**Explicação**: A soma mais próxima de 1 é 2 = (-1 + 2 + 1)

---

**Entrada**:

```
5 10
1 2 3 4 5
```

**Saída**:

```
12
```

**Explicação**: 3 + 4 + 5 = 12 (diferença de 2 do target)

## Dica

- Ordene o array
- Fixe o primeiro elemento
- Use two pointers para os outros dois
- Mantenha track da melhor soma encontrada

**Complexidade**: O(n²)

**Arquivo**: `p09_solution.cpp`
