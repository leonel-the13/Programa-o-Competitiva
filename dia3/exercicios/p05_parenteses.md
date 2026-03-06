# 📝 Problema 5: Gerar Parênteses Válidos

## 📌 Enunciado

Dado N, gere **todas as strings com N pares de parênteses que sejam válidas**.

Um string de parênteses é válido se:

- Cada parêntese aberto tem um correspondente fechado
- Em qualquer prefixo, nunca há mais fechados que abertos

---

## 📥 Entrada

- Um único inteiro N (número de pares)

---

## 📤 Saída

Todas as strings válidas, uma por linha, em ordem lexicográfica.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
1
```

**Saída**:

```
()
```

---

### Exemplo 2

**Entrada**:

```
2
```

**Saída**:

```
(())
()()
```

---

### Exemplo 3

**Entrada**:

```
3
```

**Saída**:

```
((()))
(()())
(())()
()(())
()()()
```

---

## ⚙️ Restrições

- 1 ≤ N ≤ 10

---

## 💡 Dicas

- Use backtracking
- Mantenha contadores: parênteses abertos e fechados usados
- Se abertos < N, pode adicionar "("
- Se fechados < abertos, pode adicionar ")"

---

## 🎯 Complexidade Esperada

- **Tempo**: O(Catalan(n) × n) onde Catalan(n) ≈ 4^n/n^1.5
- **Espaço**: O(n) para recursão
