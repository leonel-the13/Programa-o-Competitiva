# Problema A: Soma Especial

**Tempo Limite**: 1 segundo  
**Memória Limite**: 256 MB  
**Dificuldade**: ⭐ Fácil

---

## Descrição

Dada uma sequência de N inteiros, calcule a soma de todos os elementos que são maiores que a média aritmética da sequência.

---

## Entrada

A primeira linha contém um inteiro N (1 ≤ N ≤ 10^5) — o tamanho da sequência.

A segunda linha contém N inteiros a₁, a₂, ..., aₙ (-10^9 ≤ aᵢ ≤ 10^9) — os elementos da sequência.

---

## Saída

Imprima um único número — a soma dos elementos maiores que a média. Se não existir nenhum, imprima 0.

---

## Exemplos

### Exemplo 1

**Entrada**:

```
5
1 2 3 4 5
```

**Saída**:

```
9
```

**Explicação**: Média = (1+2+3+4+5)/5 = 3.0. Elementos > 3.0: 4 e 5. Soma = 9.

---

### Exemplo 2

**Entrada**:

```
4
10 10 10 10
```

**Saída**:

```
0
```

**Explicação**: Média = 10.0. Nenhum elemento > 10.0.

---

### Exemplo 3

**Entrada**:

```
3
-5 0 5
```

**Saída**:

```
5
```

**Explicação**: Média = 0.0. Elemento > 0: 5.

---

## Notas

- A média pode ser um número decimal
- Use comparação estrita (>), não (≥)
- Cuidado com overflow: use `long long` para somas

---

## Dica

1. Calcule a soma de todos os elementos
2. Calcule a média: soma / n
3. Percorra novamente e some os que são maiores que a média
