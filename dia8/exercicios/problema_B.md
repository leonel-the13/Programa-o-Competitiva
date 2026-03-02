# Problema B: Array Mágico

**Tempo Limite**: 1 segundo  
**Memória Limite**: 256 MB  
**Dificuldade**: ⭐ Fácil-Médio

---

## Descrição

Um array é chamado de "mágico" se pode ser dividido em duas partes não vazias onde a soma da parte esquerda é igual à soma da parte direita.

Dado um array de N inteiros, determine se ele é mágico. Se for, imprima o índice de divisão. Se houver múltiplas respostas, imprima qualquer uma. Se não for mágico, imprima -1.

O índice de divisão i significa que os elementos de índice 0 a i-1 formam a parte esquerda, e os elementos de índice i a N-1 formam a parte direita.

---

## Entrada

A primeira linha contém N (2 ≤ N ≤ 10^5).

A segunda linha contém N inteiros a₀, a₁, ..., aₙ₋₁ (-10^9 ≤ aᵢ ≤ 10^9).

---

## Saída

Imprima o índice de divisão (1-indexado) se o array é mágico, ou -1 caso contrário.

---

## Exemplos

### Exemplo 1

**Entrada**:

```
4
1 2 2 1
```

**Saída**:

```
2
```

**Explicação**: Divisão no índice 2 → [1, 2] soma 3, [2, 1] soma 3.

---

### Exemplo 2

**Entrada**:

```
6
1 2 3 4 5 15
```

**Saída**:

```
5
```

**Explicação**: [1,2,3,4,5] soma 15, [15] soma 15.

---

### Exemplo 3

**Entrada**:

```
3
1 1 1
```

**Saída**:

```
-1
```

**Explicação**: Nenhuma divisão válida.

---

## Dica

Use **prefix sum**! Se a soma total é S, então procure um ponto onde prefix[i] = S - prefix[i].
