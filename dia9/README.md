# 🎯 DIA 9 – REVISÃO ESTRATÉGICA

**Tempo estimado**: 5 horas  
**Meta**: Consolidar conhecimento + 5 problemas difíceis + descanso

---

## 🎯 OBJETIVO DO DIA

**Este é o dia de refinamento final.**

Você já treinou 8 dias. Hoje é para:

1. 🔄 Revisar erros do Dia 8
2. 📝 Consolidar templates
3. 🧠 Resolver problemas difíceis com calma
4. 😌 Descansar mentalmente para a prova

---

## 📋 CRONOGRAMA DO DIA

### ⏰ 08:00 - 09:30 (1h30min): ANÁLISE DO DIA 8

1. **Revise sua [ANALISE.md do Dia 8](../dia8/ANALISE.md)**
2. **Para cada problema que errou**:
   - Leia a solução oficial
   - Entenda o padrão
   - Implemente do zero (sem copiar)
3. **Anote padrões que você não reconheceu**

---

### ⏰ 09:30 - 11:00 (1h30min): REVISÃO DE TEMPLATES

**Abra seus cadernos de NOTAS.md de cada dia e crie seu CADERNO FINAL.**

#### Templates que você DEVE ter decorados:

**📌 Fundamentos**:

```cpp
// I/O rápido
ios_base::sync_with_stdio(false);
cin.tie(NULL);

// Prefix sum
vector<long long> prefix(n+1, 0);
for(int i = 0; i < n; i++)
    prefix[i+1] = prefix[i] + arr[i];
// soma[L, R] = prefix[R+1] - prefix[L]
```

**📌 Two Pointers**:

```cpp
// Par com soma target
int left = 0, right = n-1;
while(left < right) {
    int sum = arr[left] + arr[right];
    if(sum == target) break;
    else if(sum < target) left++;
    else right--;
}
```

**📌 Binary Search**:

```cpp
int left = 0, right = n-1;
while(left <= right) {
    int mid = left + (right-left)/2;
    if(arr[mid] == target) return mid;
    if(arr[mid] < target) left = mid+1;
    else right = mid-1;
}
```

**📌 Backtracking**:

```cpp
void backtrack(estado, &resultado) {
    if(eh_solucao(estado)) {
        resultado.push_back(estado);
        return;
    }
    for(escolha : escolhas) {
        estado.push_back(escolha); // escolher
        backtrack(estado, resultado); // recursão
        estado.pop_back(); // desfazer
    }
}
```

**📌 BFS**:

```cpp
queue<int> q;
vector<bool> visited(n, false);
q.push(start);
visited[start] = true;

while(!q.empty()) {
    int u = q.front();
    q.pop();

    for(int v : adj[u]) {
        if(!visited[v]) {
            visited[v] = true;
            q.push(v);
        }
    }
}
```

**📌 DFS**:

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v])
            dfs(v, adj, visited);
}
```

**📌 Crivo de Eratóstenes**:

```cpp
vector<bool> crivo(int n) {
    vector<bool> primo(n+1, true);
    primo[0] = primo[1] = false;
    for(int i = 2; i*i <= n; i++)
        if(primo[i])
            for(int j = i*i; j <= n; j += i)
                primo[j] = false;
    return primo;
}
```

**📌 Exponenciação Rápida Modular**:

```cpp
long long potenciaMod(long long a, long long n, long long m) {
    long long res = 1;
    a %= m;
    while(n > 0) {
        if(n % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}
```

**📌 Knapsack 0/1**:

```cpp
vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
for(int i = 1; i <= n; i++) {
    for(int w = 0; w <= W; w++) {
        dp[i][w] = dp[i-1][w];
        if(w >= weight[i-1])
            dp[i][w] = max(dp[i][w], dp[i-1][w-weight[i-1]] + value[i-1]);
    }
}
```

**Anote todos no** [TEMPLATES_FINAIS.md](TEMPLATES_FINAIS.md)

---

### ⏰ 11:00 - 11:15 (15min): DESCANSO ☕

---

### ⏰ 11:15 - 13:00 (1h45min): 5 PROBLEMAS DIFÍCEIS

Resolva com calma, SEM pressão de tempo. O objetivo é ENTENDER.

1. [Problema 1: Graph + DP Combinado](exercicios/p01_graph_dp.md) ⭐⭐⭐⭐
2. [Problema 2: Segment Tree Básico](exercicios/p02_seg_tree.md) ⭐⭐⭐⭐
3. [Problema 3: Combinatória Avançada](exercicios/p03_combinatoria.md) ⭐⭐⭐⭐
4. [Problema 4: String Hashing](exercicios/p04_string_hash.md) ⭐⭐⭐⭐
5. [Problema 5: DP 2D Difícil](exercicios/p05_dp_2d.md) ⭐⭐⭐⭐⭐

**Importante**: Não se desespere se não conseguir todos. O objetivo é APRENDER.

---

### ⏰ 13:00 - 13:30 (30min): ALMOÇO 🍽️

---

### ⏰ 13:30 - 14:30 (1h): CHECKLIST FINAL

Preencha o checklist abaixo. Seja HONESTO.

#### ✅ Complexidade

- [ ] Sei calcular complexidade de um código
- [ ] Sei quando usar O(n) vs O(n log n) vs O(n²)
- [ ] Sei estimar se meu código vai dar TLE

#### ✅ Arrays

- [ ] Prefix sum
- [ ] Sliding window
- [ ] Two pointers
- [ ] Kadane's algorithm

#### ✅ Ordenação e Busca

- [ ] sort() e comparadores customizados
- [ ] Binary search
- [ ] lower_bound / upper_bound

#### ✅ Recursão e Backtracking

- [ ] Gerar subsets
- [ ] Gerar permutações
- [ ] Backtracking com poda

#### ✅ DP

- [ ] DP 1D (Fibonacci, Climbing Stairs)
- [ ] Knapsack 0/1
- [ ] LIS / LCS

#### ✅ Grafos

- [ ] BFS
- [ ] DFS
- [ ] Componentes conexas
- [ ] BFS em grid
- [ ] Detectar ciclo
- [ ] Ordenação topológica

#### ✅ Teoria dos Números

- [ ] Crivo de Eratóstenes
- [ ] MDC / MMC
- [ ] Exponenciação rápida modular
- [ ] Fatoração prima

#### ✅ Strings

- [ ] Frequência de caracteres
- [ ] Anagramas
- [ ] Palíndromos
- [ ] KMP (pelo menos entender)

---

### ⏰ 14:30 - 17:00: DESCANSO E REVISÃO LEVE

**PARE DE PROGRAMAR.**

Neste momento:

- 📖 Releia seus NOTAS.md
- 🧘 Relaxe a mente
- 💤 Se puder, tire um cochilo
- 🎮 Faça algo relaxante

**NÃO resolva mais problemas difíceis.**  
Seu cérebro precisa consolidar o conhecimento.

---

## 🧠 RECONHECIMENTO DE PADRÕES

Esta tabela é OURO. Decore ela.

| Se o problema pede...         | Use...                        |
| ----------------------------- | ----------------------------- |
| Existe subarray com soma X    | Prefix sum + hashmap          |
| Par/tripla com soma X         | Two pointers (ordenar antes)  |
| Kth maior elemento            | Quickselect ou heap           |
| Menor caminho sem peso        | BFS                           |
| Explorar todas possibilidades | DFS / Backtracking            |
| Contar formas de fazer X      | DP (bottom-up ou top-down)    |
| Mochila / escolher itens      | Knapsack DP                   |
| Grid com obstáculos           | BFS em grid                   |
| Quantos grupos isolados       | Componentes conexas (DFS/BFS) |
| Ordem de dependências         | Ordenação topológica          |
| Contar primos até N           | Crivo de Eratóstenes          |
| a^n mod m                     | Exponenciação rápida modular  |
| Anagramas                     | Ordenar string ou frequência  |
| Pattern matching              | KMP ou Z-algorithm            |
| Palíndromo                    | Expansão ao centro ou DP      |

---

## 📊 ANÁLISE DOS 9 DIAS

| Dia | Tema                     | Problemas | Status |
| --- | ------------------------ | --------- | ------ |
| 1   | Fundamentos              | 10        | ✅     |
| 2   | Ordenação + Two Pointers | 10        | ✅     |
| 3   | Recursão + Backtracking  | 9         | ✅     |
| 4   | DP Base                  | 10        | ✅     |
| 5   | Grafos                   | 11        | ✅     |
| 6   | Teoria dos Números       | 11        | ✅     |
| 7   | Strings                  | 10        | ✅     |
| 8   | Simulação                | 12        | ✅     |
| 9   | Revisão                  | 5         | ✅     |

**Total**: ~88 problemas resolvidos  
**Tempo total**: 45 horas

---

## 🏆 VOCÊ ESTÁ PRONTO!

Se você seguiu este cronograma com seriedade:

- ✅ Resolveu ~88 problemas
- ✅ Treinou 45 horas
- ✅ Dominou os padrões principais
- ✅ Simulou condição real de competição

**Você está entre os MELHORES preparados da sua universidade.**

---

## 🔥 ÚLTIMAS DICAS PARA A PROVA

### Na Véspera:

- ❌ NÃO estude até tarde
- ❌ NÃO tente aprender coisa nova
- ✅ Durma BEM (8 horas)
- ✅ Revise templates rapidamente

### No Dia:

- ✅ Chegue cedo, relaxado
- ✅ Leia TODOS os problemas primeiro (15 min)
- ✅ Comece pelo mais fácil
- ✅ Se travar 45 min → mude de problema
- ✅ Teste casos limites: N=1, N=max, todos iguais
- ✅ Use `long long` quando em dúvida
- ✅ Mantenha CALMA

### Durante a Prova:

1. **Identifique o padrão** (este é o passo mais importante)
2. **Verifique complexidade** (vai passar no tempo?)
3. **Implemente com cuidado**
4. **Teste casos limites**
5. **Submeta**

---

## 💪 MENSAGEM FINAL

> **"Você treinou como um campeão. Agora compete como um."**

Competição é sobre:

- 30% conhecimento técnico → ✅ VOCÊ TEM
- 40% reconhecimento de padrão → ✅ VOCÊ TREINOU
- 30% gerenciamento de tempo + calma → ✅ VOCÊ PRATICOU

**Confie no seu treino. Você vai DOMINAR.**

---

## ✅ CHECKLIST FINAL DO DIA 9

- [ ] Revisei erros do Dia 8
- [ ] Compilei todos os templates importantes
- [ ] Resolvi (ou tentei seriamente) os 5 problemas difíceis
- [ ] Preenchi o checklist de tópicos
- [ ] Descansei a mente
- [ ] Estou CONFIANTE

---

# 🏆 AMANHÃ É O DIA. VOCÊ ESTÁ PRONTO! 🔥

**Vá buscar aquela vaga no mundial!** 🌍
