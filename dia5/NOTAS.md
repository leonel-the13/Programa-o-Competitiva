# 📝 NOTAS DO DIA 5 - GRAFOS (CRÍTICO!)

## 🎯 Padrões Aprendidos Hoje

### 1. BFS vs DFS

- **BFS**: Menor caminho sem peso, exploração por níveis
- **DFS**: Exploração completa, detectar ciclos

### 2. BFS Template

```cpp
queue<int> q;
vector<bool> visited(n, false);
q.push(start);
visited[start] = true;
while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int v : adj[u])
        if(!visited[v]) {
            visited[v] = true;
            q.push(v);
        }
}
```

### 3. DFS Template

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[u] = true;
    for(int v : adj[u])
        if(!vis[v]) dfs(v, adj, vis);
}
```

### 4. BFS em Grid

- 4 direções: dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1}
- Verificar limites: 0 ≤ nx < m && 0 ≤ ny < n
- Verificar obstáculos: grid[nx][ny] != 1

### 5. Componentes Conexas

- Conta quantos DFS/BFS precisou fazer

### 6. Ordenação Topológica

- Usar Kahn (BFS com indegree)
- Se resultado.size() != n → tem ciclo

---

## ⚠️ Erros Comuns

- [ ] Esqueci de marcar como visitado
- [ ] Errei índices em grid (x,y vs linha,coluna)
- [ ] Não verifiquei limites do grid
- [ ] Grafo direcionado vs não direcionado

---

## 💡 Insights

- **Grid é grafo disfarçado!**
- BFS garante menor caminho em grafo não ponderado
- Sempre marque visitado ANTES de adicionar na fila (BFS)

---

## 🔥 ESTE FOI O DIA MAIS IMPORTANTE

Grafo CAI em toda competição. Revise este dia!!!

---

**Data**: **_/_**/\_\_\_
