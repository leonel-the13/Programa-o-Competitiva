# Problema 3: Frequência Máxima

**Dificuldade**: Médio  
**Tempo limite**: 1 segundo  
**Memória limite**: 256 MB

---

## Descrição

Dado um array de N inteiros, encontre o elemento que aparece mais vezes. Se houver empate, imprima o menor valor.

---

## Entrada

A primeira linha contém N (1 ≤ N ≤ 10^5).

A segunda linha contém N inteiros (1 ≤ aᵢ ≤ 10^9).

---

## Saída

Imprima dois inteiros: o elemento mais frequente e quantas vezes ele aparece.

---

## Exemplos

### Exemplo 1

**Entrada**:

```
7
1 2 2 3 3 3 1
```

**Saída**:

```
3 3
```

---

### Exemplo 2

**Entrada**:

```
5
5 5 2 2 1
```

**Saída**:

```
2 2
```

**Explicação**: 5 e 2 aparecem 2 vezes. Imprimimos o menor (2).

---

## Dicas

- Use `map<int, int>` para manter ordem
- Ou use `unordered_map` + vector para ordenar depois

---

**Arquivo para implementar**: `p03_solution.cpp`
