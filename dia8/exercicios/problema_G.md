# 📝 Problema G: Números Primos no Range

## 📌 Enunciado

Dados L e R, liste **todos os primos no range [L, R]**.

---

## 📥 Entrada

- **Linha 1**: Inteiro L
- **Linha 2**: Inteiro R

---

## 📤 Saída

Primos encontrados, um por linha. Se nenhum, imprima "NENHUM".

---

## 🧪 Exemplos

### Exemplo 1

**Entrada**:

```
10
30
```

**Saída**:

```
11
13
17
19
23
29
```

---

## ⚙️ Restrições

- 1 ≤ L ≤ R ≤ 10^6

---

## 💡 Dicas

- Crivo de Eratóstenes se range é grande
- Teste de primalidade se range é pequeno

---

## 🎯 Complexidade Esperada

- **Tempo**: O((R-L)√R) ou O(R log log R)
- **Espaço**: O(R-L)
