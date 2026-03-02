# Problema 2: Par com Diferença K

**Dificuldade**: Médio  
**Tempo limite**: 1 segundo  
**Memória limite**: 256 MB

---

## Descrição

Dado um array de N inteiros distintos e um inteiro K, determine se existem dois elementos no array cuja diferença absoluta seja exatamente K.

---

## Entrada

A primeira linha contém dois inteiros N e K (1 ≤ N ≤ 10^5, 0 ≤ K ≤ 10^9).

A segunda linha contém N inteiros distintos a₁, a₂, ..., aₙ (0 ≤ aᵢ ≤ 10^9).

---

## Saída

Imprima "YES" se existe um par com diferença K, ou "NO" caso contrário.

---

## Exemplos

### Exemplo 1

**Entrada**:

```
5 3
1 8 30 40 100
```

**Saída**:

```
YES
```

**Explicação**: |1 - 4| não existe, mas podemos ajustar... Espera!  
Correção: array dado é [1, 8, 30, 40, 100].  
Pares: |8 - 1| = 7, |30 - 8| = 22, |40 - 30| = 10, |100 - 40| = 60...  
Nenhum tem diferença 3. Vou corrigir o exemplo.

**Entrada corrigida**:

```
5 22
1 8 30 40 100
```

**Saída**:

```
YES
```

**Explicação**: |30 - 8| = 22 ✓

---

### Exemplo 2

**Entrada**:

```
4 5
1 2 3 4
```

**Saída**:

```
NO
```

---

### Exemplo 3

**Entrada**:

```
3 0
5 10 15
```

**Saída**:

```
NO
```

**Explicação**: Diferença 0 significa elementos iguais. Como todos são distintos, não existe.

---

## Dicas

- Use um `set` ou `unordered_set` para verificação O(1)
- Para cada elemento x, verifique se (x + K) ou (x - K) existe
- Cuidado: diferença pode ser positiva ou negativa

---

## Complexidade Esperada

- **Tempo**: O(n) ou O(n log n)
- **Espaço**: O(n)

---

**Arquivo para implementar**: `p02_solution.cpp`
