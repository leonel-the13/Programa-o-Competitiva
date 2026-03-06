# 📝 Problema 9: Agressivos Cows (Binary Search em Resposta)

## 📌 Enunciado

Há N cochos em posições conhecidas em uma linha. Você tem C vacas para colocar nos cochos, com a condição de que **qualquer duas vacas devem estar a pelo menos D unidades de distância**.

Determine a **máxima distância mínima** possível entre quaisquer duas vacas.

---

## 📥 Entrada

- **Linha 1**: Dois inteiros N e C
- **Próximas N linhas**: Um inteiro representando a posição de cada cocho

---

## 📤 Saída

Um único inteiro: máxima distância mínima.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
5 3
1
2
8
4
9
```

**Saída**:

```
3
```

**Explicação**:  
Posições: [1, 2, 4, 8, 9]. Com 3 vacas, melhor colocação: [1, 4, 8] ou [1, 4, 9].  
Distância mínima entre pares: min(4-1, 8-4) = 3

---

### Exemplo 2

**Entrada**:

```
3 2
1
2
3
```

**Saída**:

```
2
```

---

## ⚙️ Restrições

- 2 ≤ N ≤ 10^5
- 2 ≤ C ≤ N
- 1 ≤ posição ≤ 10^9

---

## 💡 Dicas

- Ordene as posições
- Use Binary Search na resposta (distância)
- Para cada distância D, verifique se é possível colocar C vacas
- Greedy: Coloque primeira vaca no primeiro cocho, depois coloque próxima no primeiro cocho que está >= D unidades

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n log n + n log(max_dist))
- **Espaço**: O(n)
