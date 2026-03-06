# 📝 Problema 4: Soma de Intervalo

## 📌 Enunciado

Você receberá um array e deve responder Q consultas. Cada consulta pede a **soma dos elementos no intervalo [L, R]** (0-indexado, inclusivo em ambos os lados).

**Dica**: Use Prefix Sum para responder cada consulta em O(1).

---

## 📥 Entrada

- **Linha 1**: Inteiro N (tamanho do array)
- **Linha 2**: N inteiros separados por espaço (elementos do array)
- **Linha 3**: Inteiro Q (número de consultas)
- **Próximas Q linhas**: Dois inteiros L e R

---

## 📤 Saída

Q linhas, cada uma com a soma do intervalo consultado.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
5
1 2 3 4 5
3
0 2
1 3
0 4
```

**Saída**:

```
6
9
15
```

**Explicação**:

- [0,2]: 1+2+3 = 6
- [1,3]: 2+3+4 = 9
- [0,4]: 1+2+3+4+5 = 15

---

### Exemplo 2

**Entrada**:

```
4
10 20 30 40
2
0 0
3 3
```

**Saída**:

```
10
40
```

**Explicação**:

- [0,0]: 10
- [3,3]: 40

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10^5
- -10^9 ≤ arr[i] ≤ 10^9
- 1 ≤ Q ≤ 10^5
- 0 ≤ L ≤ R < N

---

## 💡 Dicas

- Pré-compute Prefix Sum em O(n)
- Responda cada consulta em O(1)
- Cuidado com overflow: use `long long`

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n + q)
- **Espaço**: O(n)
