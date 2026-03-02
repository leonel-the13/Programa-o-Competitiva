# 📚 TEMPLATES FINAIS - COPIE E COLE NA PROVA

**Este arquivo contém TODOS os templates essenciais.**  
Revise antes da competição. Decore os mais importantes.

---

## 🔧 SETUP BÁSICO

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Seu código aqui

    return 0;
}
```

---

## 1️⃣ FUNDAMENTOS

### Prefix Sum (Soma Acumulada)

```cpp
vector<long long> prefix(n+1, 0);
for(int i = 0; i < n; i++)
    prefix[i+1] = prefix[i] + arr[i];

// Soma de índices [L, R]
long long soma = prefix[R+1] - prefix[L];
```

### Kadane (Maximum Subarray Sum)

```cpp
long long maxSum = LLONG_MIN, currentSum = 0;
for(int x : arr) {
    currentSum = max((long long)x, currentSum + x);
    maxSum = max(maxSum, currentSum);
}
```

### Sliding Window (Janela Deslizante)

```cpp
long long windowSum = 0;
for(int i = 0; i < k; i++)
    windowSum += arr[i];

long long maxSum = windowSum;
for(int i = k; i < n; i++) {
    windowSum = windowSum - arr[i-k] + arr[i];
    maxSum = max(maxSum, windowSum);
}
```

---

## 2️⃣ ORDENAÇÃO E BUSCA

### Ordenação Customizada

```cpp
// Decrescente
sort(arr.begin(), arr.end(), greater<int>());

// Critério customizado
sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b); // ordena por valor absoluto
});

// Pares
vector<pair<int,int>> pairs;
sort(pairs.begin(), pairs.end()); // ordena por .first, depois .second
```

### Binary Search

```cpp
int left = 0, right = n-1;
while(left <= right) {
    int mid = left + (right - left) / 2; // evita overflow
    if(arr[mid] == target) return mid;
    if(arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
return -1; // não encontrado
```

### Two Pointers (Par com Soma)

```cpp
sort(arr.begin(), arr.end()); // ORDENAR ANTES

int left = 0, right = n-1;
while(left < right) {
    int sum = arr[left] + arr[right];
    if(sum == target) {
        // encontrou!
        break;
    } else if(sum < target) {
        left++;
    } else {
        right--;
    }
}
```

---

## 3️⃣ RECURSÃO E BACKTRACKING

### Gerar Subsets

```cpp
void gerarSubsets(vector<int>& nums, int idx, vector<int>& atual,
                  vector<vector<int>>& resultado) {
    resultado.push_back(atual);

    for(int i = idx; i < nums.size(); i++) {
        atual.push_back(nums[i]);
        gerarSubsets(nums, i+1, atual, resultado);
        atual.pop_back();
    }
}
```

### Gerar Permutações

```cpp
void gerarPermutacoes(vector<int>& nums, vector<bool>& usado,
                      vector<int>& atual, vector<vector<int>>& resultado) {
    if(atual.size() == nums.size()) {
        resultado.push_back(atual);
        return;
    }

    for(int i = 0; i < nums.size(); i++) {
        if(usado[i]) continue;

        usado[i] = true;
        atual.push_back(nums[i]);
        gerarPermutacoes(nums, usado, atual, resultado);
        atual.pop_back();
        usado[i] = false;
    }
}
```

---

## 4️⃣ PROGRAMAÇÃO DINÂMICA

### Knapsack 0/1

```cpp
int knapsack(vector<int>& weight, vector<int>& value, int W) {
    int n = weight.size();
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i = 1; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w]; // não pega
            if(w >= weight[i-1])
                dp[i][w] = max(dp[i][w], dp[i-1][w-weight[i-1]] + value[i-1]);
        }
    }

    return dp[n][W];
}
```

### Longest Increasing Subsequence (LIS) - O(n²)

```cpp
int lis(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}
```

### Longest Common Subsequence (LCS)

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

## 5️⃣ GRAFOS

### BFS (Busca em Largura)

```cpp
vector<int> bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return dist;
}
```

### DFS (Busca em Profundidade)

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;

    for(int v : adj[u]) {
        if(!visited[v])
            dfs(v, adj, visited);
    }
}
```

### BFS em Grid (4 direções)

```cpp
int bfs_grid(vector<vector<int>>& grid, int sx, int sy, int ex, int ey) {
    int m = grid.size(), n = grid[0].size();
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<tuple<int,int,int>> q; // {x, y, dist}

    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    while(!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();

        if(x == ex && y == ey) return dist;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
               !visited[nx][ny] && grid[nx][ny] != 1) {
                visited[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
    }

    return -1;
}
```

### Componentes Conexas

```cpp
int contarComponentes(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            count++;
            dfs(i, adj, visited);
        }
    }

    return count;
}
```

### Ordenação Topológica (Kahn)

```cpp
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for(int u = 0; u < n; u++)
        for(int v : adj[u])
            indegree[v]++;

    queue<int> q;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0)
            q.push(i);

    vector<int> resultado;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        resultado.push_back(u);

        for(int v : adj[u]) {
            indegree[v]--;
            if(indegree[v] == 0)
                q.push(v);
        }
    }

    return (resultado.size() == n) ? resultado : vector<int>();
}
```

---

## 6️⃣ TEORIA DOS NÚMEROS

### Teste de Primalidade

```cpp
bool ehPrimo(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i*i <= n; i += 6)
        if(n % i == 0 || n % (i+2) == 0)
            return false;

    return true;
}
```

### Crivo de Eratóstenes

```cpp
vector<bool> crivo(int n) {
    vector<bool> primo(n+1, true);
    primo[0] = primo[1] = false;

    for(int i = 2; i*i <= n; i++) {
        if(primo[i]) {
            for(int j = i*i; j <= n; j += i)
                primo[j] = false;
        }
    }

    return primo;
}
```

### MDC (Algoritmo de Euclides)

```cpp
int mdc(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
```

### MMC

```cpp
long long mmc(int a, int b) {
    return (long long)a / mdc(a, b) * b;
}
```

### Exponenciação Rápida Modular

```cpp
long long potenciaMod(long long a, long long n, long long m) {
    long long res = 1;
    a %= m;

    while(n > 0) {
        if(n % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        n /= 2;
    }

    return res;
}
```

### Fatoração Prima

```cpp
vector<pair<int,int>> fatorar(int n) {
    vector<pair<int,int>> fatores;

    for(int i = 2; i*i <= n; i++) {
        int count = 0;
        while(n % i == 0) {
            count++;
            n /= i;
        }
        if(count > 0)
            fatores.push_back({i, count});
    }

    if(n > 1)
        fatores.push_back({n, 1});

    return fatores;
}
```

---

## 7️⃣ STRINGS

### Frequência de Caracteres

```cpp
// Para letras minúsculas
int freq[26] = {0};
for(char c : s)
    freq[c - 'a']++;

// Para todos ASCII
unordered_map<char, int> freq;
for(char c : s)
    freq[c]++;
```

### Verificar Palíndromo

```cpp
bool ehPalindromo(string s) {
    int left = 0, right = s.size() - 1;
    while(left < right) {
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}
```

### Verificar Anagramas

```cpp
bool saoAnagramas(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}
```

---

## 🎯 DICAS RÁPIDAS

### Quando usar cada estrutura:

- **vector**: array dinâmico, O(1) acesso
- **set**: elementos únicos ordenados, O(log n)
- **unordered_set**: elementos únicos, O(1) médio
- **map**: pares chave-valor ordenados, O(log n)
- **unordered_map**: pares chave-valor, O(1) médio
- **priority_queue**: heap, O(log n) inserção/remoção

### Evite overflow:

```cpp
long long sum = 0; // sempre para somas grandes
long long mult = (long long)a * b; // cast antes de multiplicar
```

### Constantes úteis:

```cpp
const int INF = 1e9;
const long long LINF = 1e18;
const int MOD = 1e9 + 7;
```

---

**DECORE OS TEMPLATES MAIS IMPORTANTES:**
✅ BFS e DFS  
✅ Binary Search  
✅ Two Pointers  
✅ Crivo de Eratóstenes  
✅ Exponenciação Modular  
✅ Knapsack

**BOA SORTE NA COMPETIÇÃO! 🔥**
