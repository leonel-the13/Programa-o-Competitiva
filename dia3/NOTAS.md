# 📝 NOTAS DO DIA 3

## 🎯 Padrões Aprendidos Hoje

### 1. Backtracking Base

**Template**:

```cpp
void backtrack(estado, &resultado) {
    if(eh_solucao) {
        resultado.push_back(estado);
        return;
    }
    for(escolha : escolhas) {
        estado.push_back(escolha);  // escolher
        backtrack(estado, resultado); // recursão
        estado.pop_back();           // desfazer
    }
}
```

### 2. Gerar Subsets

- Para cada elemento: incluir OU não incluir
- Complexidade: O(2^n)

### 3. Gerar Permutações

- Array usado[] para rastrear elementos já escolhidos
- Complexidade: O(n!)

### 4. Poda

- Cortar branches que não podem levar à solução
- Exemplo: se soma > target, não continua

---

## ⚠️ Erros Comuns

- [ ] Esqueci de fazer pop_back() (desfazer escolha)
- [ ] Não coloquei caso base correto
- [ ] Não passei parâmetros por referência quando necessário

---

## 📊 Progresso

| Problema | Tempo | Status |
| -------- | ----- | ------ |
| P01      |       |        |
| P02      |       |        |

---

**Data**: **_/_**/\_\_\_
