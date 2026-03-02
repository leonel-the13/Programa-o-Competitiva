# 📝 NOTAS DO DIA 1

## 🎯 Padrões Aprendidos Hoje

### 1. Prefix Sum + HashMap

**Quando usar**: Problemas de subarray com soma específica  
**Tempo**: O(n)  
**Código**:

```cpp
unordered_map<long long, int> prefix;
prefix[0] = 1;
long long sum = 0;
for(int x : arr) {
    sum += x;
    if(prefix[sum - target]) // encontrou!
    prefix[sum]++;
}
```

---

### 2. Two Pointers com HashSet

**Quando usar**: Encontrar pares/triplas com condição  
**Tempo**: O(n)  
**Padrão**: Para cada x, verificar se (x ± k) existe

---

### 3. Sliding Window

**Quando usar**: Máximo/mínimo em janela de tamanho fixo  
**Tempo**: O(n)  
**Chave**: Remove elemento que saiu, adiciona que entrou

---

### 4. Frequência com Map

**Quando usar**: Contar ocorrências, anagramas  
**map vs unordered_map**:

- map: ordenado, O(log n)
- unordered_map: não ordenado, O(1) médio

---

### 5. XOR para Elemento Único

**Quando usar**: Todos aparecem 2x exceto 1  
**Propriedade**: a ⊕ a = 0, a ⊕ 0 = a  
**Código**: `int result = 0; for(int x : arr) result ^= x;`

---

## ⚠️ Erros Comuns que Cometi

- [ ] Esqueci `long long` e deu overflow em **\_\_**
- [ ] Não testei caso N = 1 em **\_\_**
- [ ] Complexidade errada: esperava O(n) mas fiz O(n²) em **\_\_**
- [ ] Não considerei elementos negativos em **\_\_**

---

## 💡 Insights

(Anote aqui seus aprendizados específicos)

---

## 🔄 Problemas para Refazer

- [ ] Problema **: Não entendi bem \_\_\_\_**
- [ ] Problema **: Errei a implementação de \_\_\_\_**

---

## ⏱️ Tempos de Resolução

| Problema | Tempo Gasto | Acertou? | Dificuldade Sentida |
| -------- | ----------- | -------- | ------------------- |
| P01      |             |          |                     |
| P02      |             |          |                     |
| P03      |             |          |                     |
| P04      |             |          |                     |
| P05      |             |          |                     |
| P06      |             |          |                     |
| P07      |             |          |                     |
| P08      |             |          |                     |
| P09      |             |          |                     |
| P10      |             |          |                     |

---

## 🎓 Conceitos para Revisar Amanhã

- [ ] ***
- [ ] ***
- [ ] ***

---

**Data**: **_/_**/**\_  
**Horas estudadas**: \_\_\_**  
**Sensação geral**: 😤 / 😐 / 😊 / 🔥
