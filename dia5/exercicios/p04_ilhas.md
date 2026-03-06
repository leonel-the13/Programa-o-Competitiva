# 📝 Problema 4: Número de Ilhas

## 📌 Enunciado

Dado um grid com 0s (água) e 1s (terra), conte **quantas ilhas** existem.

Uma ilha é um grupo de 1s conectados horizontalmente ou verticalmente (não diagonalmente).

---

## 📥 Entrada

- **Linha 1**: Dois inteiros M e N
- **Próximas M linhas**: String de 0s e 1s

---

## 📤 Saída

Um único inteiro: número de ilhas.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
4 5
11010
11010
10101
00100
```

**Saída**:

```
3
```

---

## ⚙️ Restrições

- 1 ≤ M, N ≤ 500

---

## 💡 Dicas

- Use DFS ou BFS
- Para cada célula 1 não visitada, faça DFS/BFS e incremente contador

---

## 🎯 Complexidade Esperada

- **Tempo**: O(M × N)
- **Espaço**: O(M × N)
