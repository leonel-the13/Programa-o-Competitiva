# 📝 NOTAS DO DIA 7

## 🎯 Padrões Aprendidos Hoje

### 1. Frequência de Caracteres

```cpp
// Letras minúsculas
int freq[26] = {0};
for(char c : s) freq[c - 'a']++;

// Geral
unordered_map<char,int> freq;
for(char c : s) freq[c]++;
```

### 2. Anagramas

- Ordenar ambas strings e comparar
- OU comparar frequências

### 3. Palíndromo

- Two pointers: left e right
- OU reverter e comparar

### 4. KMP (entender conceito)

- LPS array: longest proper prefix which is also suffix
- Permite pattern matching em O(n + m)

---

## ⚠️ Erros Comuns

- [ ] Índice errado em freq[c - 'a'] (assumiu minúsculas mas tinha maiúsculas)
- [ ] Não considerou espaços/caracteres especiais
- [ ] String vazia não tratada

---

## 💡 Insights

- String é array de chars
- Use frequência para a maioria dos problemas
- KMP/Z-algo só quando realmente necessário (raramente)

---

**Data**: **_/_**/\_\_\_
