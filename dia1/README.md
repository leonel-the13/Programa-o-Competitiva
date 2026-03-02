# 🔥 DIA 1 – FUNDAMENTOS DE COMPETIÇÃO

**Tempo estimado**: 5 horas  
**Meta**: 10 problemas (7 médios + 3 difíceis)

---

## 🎯 OBJETIVOS DO DIA

Hoje você vai dominar os fundamentos que separam competidores rápidos dos lentos:

1. ⚡ **Complexidade**: Saber instantaneamente se O(n²) vai passar
2. 🚀 **I/O Rápido**: Ler 1 milhão de números em segundos
3. 🧩 **Arrays**: Manipulação eficiente, subarray, frequências
4. 🛡️ **Casos Limite**: Zero, negativo, overflow, limites extremos

---

## 📚 TEORIA ESSENCIAL

### 1️⃣ COMPLEXIDADE DE TEMPO

| Complexidade | Max N | Exemplo          |
| ------------ | ----- | ---------------- |
| O(1)         | ∞     | Acesso direto    |
| O(log n)     | 10^18 | Binary search    |
| O(n)         | 10^8  | Loop simples     |
| O(n log n)   | 10^6  | Sort, merge sort |
| O(n²)        | 10^4  | Loop duplo       |
| O(n³)        | 500   | Loop triplo      |
| O(2^n)       | 20    | Backtracking     |
| O(n!)        | 11    | Permutações      |

**REGRA DE OURO**: Se N ≤ 10^5 e você fizer O(n²), vai dar TLE (Time Limit Exceeded)

#### Como calcular rápido:

- 10^8 operações ≈ 1 segundo
- Se N = 2×10^5 e você faz O(n²) = 4×10^10 → TLE garantido
- Sempre calcule: "Quantas operações no pior caso?"

---

### 2️⃣ INPUT/OUTPUT RÁPIDO

Em C++, SEMPRE use no início do `main()`:

```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
```

**Por quê?**

- Desativa sincronização entre C e C++ (ganha velocidade)
- Remove flush automático do cin

**⚠️ NUNCA misture `printf/scanf` com `cin/cout` depois disso!**

#### Leitura até EOF (End Of File):

```cpp
int x;
while(cin >> x) {
    // processa x
}
```

#### Múltiplos casos de teste:

```cpp
int t;
cin >> t;
while(t--) {
    // resolve caso
}
```

---

### 3️⃣ MANIPULAÇÃO DE ARRAYS

#### Padrão 1: Frequência de Elementos

```cpp
map<int, int> freq;
for(int x : arr) freq[x]++;
```

Ou use `unordered_map` para O(1) médio.

#### Padrão 2: Subarray com Soma K (Prefix Sum)

```cpp
// Problema: existe subarray com soma = k?
unordered_map<long long, int> prefix;
prefix[0] = 1;
long long sum = 0;
for(int x : arr) {
    sum += x;
    if(prefix[sum - k]) {
        // encontrou!
    }
    prefix[sum]++;
}
```

#### Padrão 3: Maximum Subarray Sum (Kadane)

```cpp
long long maxSum = LLONG_MIN, current = 0;
for(int x : arr) {
    current = max((long long)x, current + x);
    maxSum = max(maxSum, current);
}
```

#### Padrão 4: Sliding Window (Janela Deslizante)

```cpp
// Soma de janela de tamanho k
int sum = 0;
for(int i = 0; i < k; i++) sum += arr[i];
int maxSum = sum;

for(int i = k; i < n; i++) {
    sum += arr[i] - arr[i-k];
    maxSum = max(maxSum, sum);
}
```

---

### 4️⃣ CASOS LIMITE (SEMPRE TESTAR)

✅ **Checklist obrigatória**:

- [ ] N = 0 ou N = 1
- [ ] Todos elementos iguais
- [ ] Elementos negativos
- [ ] Overflow (usar `long long`)
- [ ] Array vazio
- [ ] Resposta pode ser zero?
- [ ] Limites máximos (N = 10^5, valor = 10^9)

**Exemplo clássico de erro:**

```cpp
int sum = 0;
for(int i = 0; i < n; i++) {
    sum += arr[i]; // Se arr[i] ~ 10^9 e n ~ 10^5 → OVERFLOW!
}
```

**Correção:**

```cpp
long long sum = 0; // SEMPRE long long para somas
```

---

### 5️⃣ ORDENAÇÃO EFICIENTE

```cpp
vector<int> arr(n);
sort(arr.begin(), arr.end()); // O(n log n)

// Ordem decrescente
sort(arr.begin(), arr.end(), greater<int>());

// Ordenar por critério customizado
sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b); // ordena por valor absoluto
});
```

---

## 🧠 PADRÕES QUE SEMPRE CAEM

### Padrão A: "Existe subarray com propriedade X?"

→ Use **Prefix Sum** ou **Two Pointers**

### Padrão B: "Qual o máximo/mínimo em janela?"

→ Use **Sliding Window**

### Padrão C: "Conte frequência de elementos"

→ Use **HashMap** (`unordered_map`)

### Padrão D: "Ordene e processe"

→ Depois de ordenar, muitos problemas ficam O(n)

---

## ⚡ TEMPLATES PRONTOS

Veja a pasta [templates/](templates/) para copiar e colar:

- `input_rapido.cpp` → Template base
- `prefix_sum.cpp` → Soma de subarray
- `kadane.cpp` → Maximum subarray
- `sliding_window.cpp` → Janela deslizante
- `frequency.cpp` → Contador de elementos

---

## 📝 EXERCÍCIOS DO DIA

**⏱️ Tempo limite por exercício: 45 minutos**

Acesse [exercicios/](exercicios/) para ver os enunciados completos.

### Nível Médio (7 problemas)

1. [Problema 1: Subarray com Soma Zero](exercicios/p01_subarray_soma_zero.md)
2. [Problema 2: Par com Diferença K](exercicios/p02_par_diferenca_k.md)
3. [Problema 3: Frequência Máxima](exercicios/p03_frequencia_maxima.md)
4. [Problema 4: Reorganizar Array](exercicios/p04_reorganizar_array.md)
5. [Problema 5: Soma Máxima Janela K](exercicios/p05_soma_maxima_janela.md)
6. [Problema 6: Elemento que Aparece Uma Vez](exercicios/p06_elemento_unico.md)
7. [Problema 7: Merge Intervals](exercicios/p07_merge_intervals.md)

### Nível Difícil (3 problemas)

8. [Problema 8: Maior Subarray com 0s e 1s Iguais](exercicios/p08_subarray_0s_1s.md)
9. [Problema 9: Tripla com Soma Mais Próxima](exercicios/p09_tripla_soma_proxima.md)
10. [Problema 10: Sliding Window Maximum](exercicios/p10_sliding_window_max.md)

---

## 🎯 ESTRATÉGIA DE RESOLUÇÃO

Para cada problema:

1. **Leia atento** → Identifique as restrições (N ≤ ?, valor ≤ ?)
2. **Calcule complexidade necessária** → Se N=10^5, preciso O(n) ou O(n log n)
3. **Reconheça o padrão** → É subarray? É frequência? É janela?
4. **Implemente** → Use os templates
5. **Teste casos limite** → N=1, negativos, overflow
6. **Se travar 45 min** → Veja a solução em [solucoes/](solucoes/)

---

## 📊 PROGRESSO ESPERADO

- **Primeiros 3 problemas**: ~20 min cada (aquecimento)
- **Próximos 4**: ~30-40 min cada (desafiadores)
- **Últimos 3**: ~45+ min (difíceis, pode ver dica)

**NORMAL** travar nos difíceis. O importante é entender a solução depois.

---

## 🔥 MENTALIDADE

> "Não existe problema difícil, existe padrão que você ainda não reconhece."

Hoje é o dia de construir sua biblioteca mental. Cada problema que você resolve adiciona um padrão no seu cérebro.

**No Dia 8, quando você estiver na simulação, vai olhar um problema e pensar:**  
_"Ah, isso é igual ao Problema 2 do Dia 1, é só usar prefix sum!"_

Esse é o objetivo. Vamos! 💪

---

## ✅ CHECKLIST DO DIA

- [ ] Li toda a teoria
- [ ] Testei os templates
- [ ] Resolvi os 7 médios
- [ ] Tentei os 3 difíceis (mesmo sem terminar)
- [ ] Anotei padrões no NOTAS.md
- [ ] Revisei erros

Quando terminar, abra [NOTAS.md](NOTAS.md) e anote os padrões aprendidos.

---

**Próximo**: [DIA 2 - Ordenação + Dois Ponteiros](../dia2/README.md)
