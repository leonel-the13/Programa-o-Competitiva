# 🔥 DIA 5 – GRAFOS (CRÍTICO!)

**Tempo estimado**: 5 horas  
**Meta**: 11 problemas (6 médios + 5 difíceis)

---

## ⚠️ ESTE É O DIA MAIS IMPORTANTE!

**Grafos SEMPRE caem em competições. Sem exceção.**

---

## 🎯 OBJETIVOS DO DIA

1. 🌳 **BFS**: Busca em Largura (menor caminho sem peso)
2. 🔍 **DFS**: Busca em Profundidade (exploração completa)
3. 🔗 **Componentes Conexas**: Quantos grupos isolados
4. 🗺️ **Grid BFS**: Menor caminho em matriz
5. 🎯 **Aplicações**: Detectar ciclo, bipartição, ordenação topológica

---

## 📚 TEORIA ESSENCIAL

### 1️⃣ REPRESENTAÇÃO DE GRAFOS

**Lista de Adjacências** (mais comum):

```cpp
int n = 5; // número de vértices
vector<vector<int>> adj(n);

// Adicionar aresta u → v
adj[u].push_back(v);

// Se não direcionado:
adj[u].push_back(v);
adj[v].push_back(u);
```

**Matriz de Adjacências** (se grafo for denso):

```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
adj[u][v] = 1; // aresta de u para v
```

---

### 2️⃣ BFS (BUSCA EM LARGURA)

**Uso**: Menor caminho em grafo não ponderado

**Template**:

```cpp
void bfs(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        // Processar u
        cout << u << " ";

        // Visitar vizinhos
        for(int v : adj[u]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
```

**Com distâncias**:

```cpp
vector<int> bfs_dist(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1); // -1 = não alcançado
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

**Complexidade**: O(V + E) — visitamos cada vértice e aresta uma vez

---

### 3️⃣ DFS (BUSCA EM PROFUNDIDADE)

**Uso**: Exploração completa, detectar ciclos, ordenação topológica

**Template Recursivo**:

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;

    // Processar u
    cout << u << " ";

    // Visitar vizinhos
    for(int v : adj[u]) {
        if(!visited[v])
            dfs(v, adj, visited);
    }
}
```

**Template Iterativo** (com stack):

```cpp
void dfs_iterativo(int start, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);

    while(!s.empty()) {
        int u = s.top();
        s.pop();

        if(visited[u]) continue;
        visited[u] = true;

        cout << u << " ";

        for(int v : adj[u])
            if(!visited[v])
                s.push(v);
    }
}
```

**Complexidade**: O(V + E)

---

### 4️⃣ COMPONENTES CONEXAS

**Problema**: Quantos grupos isolados existem?

```cpp
int contarComponentes(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    int componentes = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            componentes++;
            // BFS ou DFS a partir de i
            bfs(i, adj, visited); // ou dfs(i, adj, visited);
        }
    }

    return componentes;
}
```

---

### 5️⃣ BFS EM GRID (MATRIZ)

**Problema clássico**: Menor caminho em labirinto

```cpp
int bfs_grid(vector<vector<int>>& grid, int startX, int startY,
             int endX, int endY) {
    int m = grid.size(), n = grid[0].size();

    // Direções: cima, baixo, esquerda, direita
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<tuple<int,int,int>> q; // {x, y, distância}

    q.push({startX, startY, 0});
    visited[startX][startY] = true;

    while(!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop();

        if(x == endX && y == endY)
            return dist;

        // Tentar 4 direções
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Verificar limites e se não é obstáculo
            if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
               !visited[nx][ny] && grid[nx][ny] != 1) {
                visited[nx][ny] = true;
                q.push({nx, ny, dist + 1});
            }
        }
    }

    return -1; // sem caminho
}
```

---

### 6️⃣ DETECTAR CICLO

**Em grafo não direcionado**:

```cpp
bool temCiclo_dfs(int u, int parent, vector<vector<int>>& adj,
                  vector<bool>& visited) {
    visited[u] = true;

    for(int v : adj[u]) {
        if(!visited[v]) {
            if(temCiclo_dfs(v, u, adj, visited))
                return true;
        } else if(v != parent) {
            return true; // encontrou ciclo
        }
    }

    return false;
}
```

**Em grafo direcionado** (usar pilha de recursão):

```cpp
bool temCiclo_dir(int u, vector<vector<int>>& adj,
                  vector<int>& color) {
    // 0 = não visitado, 1 = visitando, 2 = visitado
    color[u] = 1;

    for(int v : adj[u]) {
        if(color[v] == 1) return true; // ciclo!
        if(color[v] == 0 && temCiclo_dir(v, adj, color))
            return true;
    }

    color[u] = 2;
    return false;
}
```

---

### 7️⃣ ORDENAÇÃO TOPOLÓGICA

**Uso**: Ordem de dependências (cursos, tarefas)  
**Requisito**: Grafo direcionado acíclico (DAG)

**Algoritmo de Kahn** (BFS):

```cpp
vector<int> topoSort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);

    // Calcular grau de entrada
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

    if(resultado.size() != n)
        return {}; // tem ciclo!

    return resultado;
}
```

---

## 🧠 PADRÕES DESTE DIA

### Padrão A: "Menor caminho sem peso"

→ **BFS** simples

### Padrão B: "Explorar tudo / detectar ciclo"

→ **DFS**

### Padrão C: "Quantos grupos isolados?"

→ **Componentes conexas** (DFS/BFS múltiplas vezes)

### Padrão D: "Labirinto / Grid"

→ **BFS em matriz** com 4 ou 8 direções

### Padrão E: "Ordem de dependências"

→ **Ordenação topológica**

---

## 📝 EXERCÍCIOS DO DIA

### Nível Médio (6 problemas)

1. [Componentes Conexas](exercicios/p01_componentes.md)
2. [Menor Caminho em Grid](exercicios/p02_grid_path.md)
3. [Detectar Ciclo](exercicios/p03_ciclo.md)
4. [Número de Ilhas](exercicios/p04_ilhas.md)
5. [Labirinto](exercicios/p05_labirinto.md)
6. [É Bipartido?](exercicios/p06_bipartido.md)

### Nível Difícil (5 problemas)

7. [Ordenação Topológica](exercicios/p07_topo_sort.md)
8. [Rotting Oranges](exercicios/p08_rotting_oranges.md)
9. [Word Ladder](exercicios/p09_word_ladder.md)
10. [Shortest Bridge](exercicios/p10_shortest_bridge.md)
11. [Course Schedule II](exercicios/p11_course_schedule.md)

---

## 🔥 MENTALIDADE

> "BFS para menor caminho, DFS para exploração. Grid é grafo disfarçado."

**No Dia 8, você VAI ver grafo. Esteja preparado.**

---

## ✅ CHECKLIST DO DIA

- [ ] Implementei BFS do zero
- [ ] Implementei DFS do zero
- [ ] Resolvi problema de componentes conexas
- [ ] Resolvi BFS em grid
- [ ] Entendi detecção de ciclo
- [ ] Implementei ordenação topológica
- [ ] Anotei padrões no [NOTAS.md](NOTAS.md)

---

**Próximo**: [DIA 6 - Teoria dos Números](../dia6/README.md)
