# Problema E: Componentes Especiais

**Tempo Limite**: 2 segundos  
**Memória Limite**: 256 MB  
**Dificuldade**: ⭐⭐ Médio

---

## Descrição

Dado um grafo não direcionado com N vértices e M arestas, uma "componente especial" é uma componente conexa que contém pelo menos K vértices.

Determine quantas componentes especiais existem no grafo.

---

## Entrada

A primeira linha contém três inteiros: N, M, K (1 ≤ N ≤ 10^5, 0 ≤ M ≤ 2×10^5, 1 ≤ K ≤ N).

As próximas M linhas contêm dois inteiros u e v (0 ≤ u, v < N, u ≠ v), representando uma aresta entre vértices u e v.

O grafo pode conter múltiplas arestas entre os mesmos vértices.

---

## Saída

Imprima um único inteiro — o número de componentes especiais.

---

## Exemplos

### Exemplo 1

**Entrada**:

```
7 5 3
0 1
1 2
3 4
4 5
5 3
```

**Saída**:

```
1
```

**Explicação**:

- Componente 1: {0, 1, 2} — tamanho 3 ≥ K ✓
- Componente 2: {3, 4, 5} — tamanho 3 ≥ K ✓
- Componente 3: {6} — tamanho 1 < K ✗

Ah, espera. Revisei: temos 7 vértices e 5 arestas.

- 0-1-2: componente de tamanho 3
- 3-4-5: componente de tamanho 3
- 6: componente de tamanho 1

Total de especiais (≥ 3): 2

Correção do output:

```
**Saída**:
```

2

```

---

### Exemplo 2
**Entrada**:
```

5 3 2
0 1
2 3
3 4

```
**Saída**:
```

1

```
**Explicação**:
- {0, 1}: tamanho 2 ≥ 2 ✓
- {2, 3, 4}: tamanho 3 ≥ 2 ✓

Total: 2 componentes especiais.

Correção:
```

**Saída**:

```
2
```

---

### Exemplo 3

**Entrada**:

```
4 0 2
```

**Saída**:

```
0
```

**Explicação**: Todos os vértices estão isolados (componentes de tamanho 1).

---

## Dica

1. Use **DFS ou BFS** para encontrar componentes conexas
2. Conte o tamanho de cada componente
3. Conte quantas têm tamanho ≥ K
