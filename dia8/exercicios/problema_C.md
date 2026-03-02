# Problema C: Caminhos no Grid

**Tempo Limite**: 2 segundos  
**Memória Limite**: 256 MB  
**Dificuldade**: ⭐⭐ Médio

---

## Descrição

Você está em um grid M×N. Você começa na célula (0, 0) e quer chegar na célula (M-1, N-1).

Você pode se mover apenas para a direita ou para baixo. Algumas células contêm obstáculos (valor 1) e não podem ser atravessadas. Células vazias têm valor 0.

Determine o número de caminhos diferentes para chegar ao destino. Como o resultado pode ser grande, imprima o resultado módulo 10^9 + 7.

---

## Entrada

A primeira linha contém M e N (1 ≤ M, N ≤ 1000).

As próximas M linhas contêm N inteiros cada (0 ou 1), representando o grid.

---

## Saída

Imprima o número de caminhos módulo 10^9 + 7.

---

## Exemplos

### Exemplo 1

**Entrada**:

```
3 3
0 0 0
0 1 0
0 0 0
```

**Saída**:

```
2
```

**Explicação**:
Caminhos:

1. Direita → Direita → Baixo → Baixo
2. Baixo → Baixo → Direita → Direita

---

### Exemplo 2

**Entrada**:

```
2 2
0 0
0 0
```

**Saída**:

```
2
```

---

### Exemplo 3

**Entrada**:

```
3 3
0 0 0
0 1 0
1 0 0
```

**Saída**:

```
0
```

**Explicação**: Impossível chegar ao destino devido aos obstáculos.

---

## Dica

Use **Programação Dinâmica**!

`dp[i][j]` = número de caminhos para chegar em (i, j)

Relação:

- Se grid[i][j] == 1: dp[i][j] = 0
- Senão: dp[i][j] = dp[i-1][j] + dp[i][j-1]

Caso base: dp[0][0] = 1 (se não for obstáculo)
