# 🔥 DIA 4 – PROGRAMAÇÃO DINÂMICA (BASE)

**Tempo estimado**: 5 horas  
**Meta**: 10 problemas (5 médios + 5 difíceis)

---

## 🎯 OBJETIVOS DO DIA

1. 🧩 **DP 1D**: Fibonacci, Climbing Stairs, House Robber
2. 💰 **Knapsack**: Mochila 0/1
3. 📊 **Subsequências**: LIS, LCS
4. 🎯 **Memoization**: Top-down vs Bottom-up

---

## 📚 TEORIA ESSENCIAL

### 1️⃣ O QUE É DP?

**Dynamic Programming** = Recursão + Memoization  
**Ideia**: Guardar resultados de subproblemas para não recalcular

**Quando usar DP?**

1. **Sobreposição de subproblemas**: mesmos subproblemas aparecem várias vezes
2. **Subestrutura ótima**: solução ótima depende de soluções ótimas de subproblemas

---

### 2️⃣ FIBONACCI – Primeiro Exemplo

**Recursão ingênua**: O(2^n)

```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

**Top-Down (Recursão + Memoization)**: O(n)

```cpp
vector<int> memo(n+1, -1);

int fib(int n) {
    if(n <= 1) return n;
    if(memo[n] != -1) return memo[n];

    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}
```

**Bottom-Up (Iterativo)**: O(n) tempo, O(n) espaço

```cpp
int fib(int n) {
    if(n <= 1) return n;

    vector<int> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}
```

**Otimizado**: O(n) tempo, O(1) espaço

```cpp
int fib(int n) {
    if(n <= 1) return n;
    int prev2 = 0, prev1 = 1;
    for(int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

---

### 3️⃣ CLIMBING STAIRS

**Problema**: N degraus, pode subir 1 ou 2 por vez. Quantas formas?

**Relação**: `dp[i] = dp[i-1] + dp[i-2]`

```cpp
int climbStairs(int n) {
    if(n <= 2) return n;

    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}
```

---

### 4️⃣ KNAPSACK 0/1 (MOCHILA)

**Problema**: N itens com peso wᵢ e valor vᵢ. Capacidade W. Maximizar valor.

**Relação**:

```
dp[i][w] = valor máximo usando itens 0..i com capacidade w

dp[i][w] = max(
    dp[i-1][w],              // não pega item i
    dp[i-1][w - weight[i]] + value[i]  // pega item i
)
```

**Código**:

```cpp
int knapsack(vector<int>& weight, vector<int>& value, int W) {
    int n = weight.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            // Não pega item i-1
            dp[i][w] = dp[i-1][w];

            // Pega item i-1 (se cabe)
            if(w >= weight[i-1])
                dp[i][w] = max(dp[i][w], dp[i-1][w - weight[i-1]] + value[i-1]);
        }
    }

    return dp[n][W];
}
```

**Complexidade**: O(n × W)

---

### 5️⃣ LONGEST INCREASING SUBSEQUENCE (LIS)

**Problema**: Maior subsequência crescente

**DP O(n²)**:

```cpp
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // dp[i] = LIS terminando em arr[i]

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}
```

**DP O(n log n)** com binary search:

```cpp
int lis(vector<int>& arr) {
    vector<int> tails; // tails[i] = menor final de LIS de tamanho i+1

    for(int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if(it == tails.end())
            tails.push_back(x);
        else
            *it = x;
    }

    return tails.size();
}
```

---

### 6️⃣ LONGEST COMMON SUBSEQUENCE (LCS)

**Problema**: Maior subsequência comum entre duas strings

```cpp
int lcs(string& s1, string& s2) {
    int m = s1.size(), n = s2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}
```

---

## 🧠 PADRÕES DESTE DIA

### Padrão A: "Contar formas de chegar em N"

→ DP 1D: `dp[i] = soma(dp[i - opções])`

### Padrão B: "Maximizar/Minimizar com escolhas"

→ DP com decisão: pegar ou não pegar

### Padrão C: "Subsequência ótima"

→ LIS, LCS: comparar elementos e decidir

---

## 📝 EXERCÍCIOS DO DIA

### Nível Médio (5 problemas)

1. [Climbing Stairs com K passos](exercicios/p01_climb_k.md)
2. [House Robber](exercicios/p02_house_robber.md)
3. [Coin Change](exercicios/p03_coin_change.md)
4. [Minimum Path Sum](exercicios/p04_min_path_sum.md)
5. [Unique Paths](exercicios/p05_unique_paths.md)

### Nível Difícil (5 problemas)

6. [Knapsack 0/1](exercicios/p06_knapsack.md)
7. [Longest Increasing Subsequence](exercicios/p07_lis.md)
8. [Edit Distance](exercicios/p08_edit_distance.md)
9. [Maximum Product Subarray](exercicios/p09_max_product.md)
10. [Partition Equal Subset Sum](exercicios/p10_partition.md)

---

## 🔥 MENTALIDADE

> "DP não é difícil. É encontrar a recorrência e implementar com cuidado."

**Processo**:

1. Encontre a relação de recorrência
2. Identifique o caso base
3. Implemente (top-down ou bottom-up)
4. Otimize espaço se possível

---

## ✅ CHECKLIST DO DIA

- [ ] Entendi diferença entre top-down e bottom-up
- [ ] Implementei Fibonacci com DP
- [ ] Implementei Knapsack 0/1
- [ ] Resolvi problema de subsequência
- [ ] Tentei otimizar espaço em pelo menos 1 problema
- [ ] Anotei padrões no [NOTAS.md](NOTAS.md)

---

**Próximo**: [DIA 5 - Grafos (CRÍTICO!)](../dia5/README.md)
