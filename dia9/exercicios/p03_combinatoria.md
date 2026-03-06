# 📝 Problema 3: Combinatória Avançada

## 📌 Enunciado

Calcule nCr (n escolhe r) modulo 10^9+7 para resolver problem combinatório.

Número de formas de selecionar r objetos de n.

---

## 📥 Entrada

- **Linha 1**: Inteiro T (casos de teste)
- **Próximas T linhas**: Dois inteiros N e R

---

## 📤 Saída

nCr mod 10^9+7 para cada caso.

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
2
5 2
10 5
```

**Saída**:

```
10
252
```

---

## ⚙️ Restrições

- 1 ≤ T ≤ 1000
- 0 ≤ R ≤ N ≤ 10^5

---

## 💡 Dicas

- Pré-compute factoriais e inversos
- nCr = n! / (r! × (n-r)!)

---

## 🎯 Complexidade Esperada

- **Tempo**: O(n + t)
- **Espaço**: O(n)
