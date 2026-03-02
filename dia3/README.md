# 🔥 DIA 3 – RECURSÃO + BACKTRACKING

**Tempo estimado**: 5 horas  
**Meta**: 9 problemas (5 médios + 4 difíceis)

---

## 🎯 OBJETIVOS DO DIA

1. 🔄 **Recursão**: Pensar em problemas de forma recursiva
2. 🔙 **Backtracking**: Explorar todas as possibilidades
3. 🎲 **Geração**: Subsets, Permutations, Combinations
4. ✂️ **Poda**: Otimizar backtracking com cortes

---

## 📚 TEORIA ESSENCIAL

### 1️⃣ RECURSÃO BÁSICA

**Estrutura**:

```cpp
void recursao(parametros) {
    // Caso base: quando parar
    if(condicao_parada) {
        // processar resultado
        return;
    }

    // Caso recursivo: dividir problema
    // processo_atual
    recursao(subproblema);
}
```

**Exemplo - Fatorial**:

```cpp
int fatorial(int n) {
    if(n <= 1) return 1; // caso base
    return n * fatorial(n - 1); // caso recursivo
}
```

**Exemplo - Fibonacci**:

```cpp
int fib(int n) {
    if(n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
// CUIDADO: Isso é O(2^n)! Use DP ou memoization
```

---

### 2️⃣ BACKTRACKING

**Template Geral**:

```cpp
void backtrack(estado_atual, &resultado) {
    // Caso base: solução completa
    if(eh_solucao(estado_atual)) {
        resultado.push_back(estado_atual);
        return;
    }

    // Tentar todas as escolhas
    for(escolha : escolhas_possiveis) {
        // Fazer escolha
        estado_atual.push_back(escolha);

        // Recursão
        backtrack(estado_atual, resultado);

        // Desfazer escolha (BACKTRACK)
        estado_atual.pop_back();
    }
}
```

---

### 3️⃣ GERAR TODOS OS SUBSETS

**Problema**: Dado [1, 2, 3], gerar [], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]

```cpp
void gerarSubsets(vector<int>& nums, int idx, vector<int>& atual,
                  vector<vector<int>>& resultado) {
    // Adiciona subset atual
    resultado.push_back(atual);

    // Gera subsets estendendo o atual
    for(int i = idx; i < nums.size(); i++) {
        atual.push_back(nums[i]); // escolhe
        gerarSubsets(nums, i + 1, atual, resultado); // recursão
        atual.pop_back(); // remove
    }
}

// Uso:
vector<vector<int>> resultado;
vector<int> atual;
gerarSubsets(nums, 0, atual, resultado);
```

**Complexidade**: O(2^n) - cada elemento pode estar ou não

---

### 4️⃣ GERAR TODAS AS PERMUTAÇÕES

**Problema**: Dado [1, 2, 3], gerar todas as ordenações

```cpp
void gerarPermutacoes(vector<int>& nums, vector<bool>& usado,
                      vector<int>& atual, vector<vector<int>>& resultado) {
    // Caso base: permutação completa
    if(atual.size() == nums.size()) {
        resultado.push_back(atual);
        return;
    }

    // Tentar cada elemento
    for(int i = 0; i < nums.size(); i++) {
        if(usado[i]) continue; // já usado nesta permutação

        usado[i] = true;
        atual.push_back(nums[i]);

        gerarPermutacoes(nums, usado, atual, resultado);

        atual.pop_back();
        usado[i] = false;
    }
}

// Uso:
vector<int> atual;
vector<bool> usado(n, false);
vector<vector<int>> resultado;
gerarPermutacoes(nums, usado, atual, resultado);
```

**Complexidade**: O(n!)

---

### 5️⃣ N-QUEENS (Problema Clássico)

Colocar N rainhas em tabuleiro N×N sem se atacarem.

```cpp
bool ehSeguro(vector<string>& tabuleiro, int row, int col, int n) {
    // Verificar coluna
    for(int i = 0; i < row; i++)
        if(tabuleiro[i][col] == 'Q') return false;

    // Verificar diagonal superior esquerda
    for(int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if(tabuleiro[i][j] == 'Q') return false;

    // Verificar diagonal superior direita
    for(int i = row-1, j = col+1; i >= 0 && j < n; i--, j++)
        if(tabuleiro[i][j] == 'Q') return false;

    return true;
}

void resolveNQueens(int row, int n, vector<string>& tabuleiro,
                    vector<vector<string>>& resultado) {
    if(row == n) {
        resultado.push_back(tabuleiro);
        return;
    }

    for(int col = 0; col < n; col++) {
        if(ehSeguro(tabuleiro, row, col, n)) {
            tabuleiro[row][col] = 'Q'; // coloca rainha
            resolveNQueens(row + 1, n, tabuleiro, resultado);
            tabuleiro[row][col] = '.'; // remove rainha (backtrack)
        }
    }
}
```

---

### 6️⃣ PODA (OTIMIZAÇÃO)

Evitar explorar caminhos que não podem levar à solução.

**Exemplo - Soma Exata**:

```cpp
void somaExata(vector<int>& nums, int idx, int somaAtual, int target,
               vector<int>& caminho, vector<vector<int>>& resultado) {
    // Poda: se já passou do target, não continua
    if(somaAtual > target) return; // PODA!

    if(somaAtual == target) {
        resultado.push_back(caminho);
        return;
    }

    for(int i = idx; i < nums.size(); i++) {
        caminho.push_back(nums[i]);
        somaExata(nums, i+1, somaAtual + nums[i], target, caminho, resultado);
        caminho.pop_back();
    }
}
```

---

## 🧠 PADRÕES DESTE DIA

### Padrão A: "Gerar todas as possibilidades"

→ **Backtracking** com caso base + loop + recursão + desfazer

### Padrão B: "Escolher ou não escolher"

→ **Recursão binária**: incluir elemento OU não incluir

### Padrão C: "Otimizar busca exaustiva"

→ **Poda**: adicionar condições para não explorar caminhos inúteis

---

## 📝 EXERCÍCIOS DO DIA

### Nível Médio (5 problemas)

1. [Gerar Todos os Subsets](exercicios/p01_subsets.md)
2. [Gerar Permutações](exercicios/p02_permutations.md)
3. [Combination Sum](exercicios/p03_combination_sum.md)
4. [Subsets com Soma K](exercicios/p04_subsets_soma_k.md)
5. [Gerar Parênteses Válidos](exercicios/p05_parenteses.md)

### Nível Difícil (4 problemas)

6. [N-Queens](exercicios/p06_n_queens.md)
7. [Sudoku Solver](exercicios/p07_sudoku.md)
8. [Word Break II](exercicios/p08_word_break.md)
9. [Partition Equal Subset Sum](exercicios/p09_partition.md)

---

## 🔥 MENTALIDADE

> "Backtracking é busca bruta com elegância. Não tenha medo de tentar todas as possibilidades."

**Dica crucial**: Sempre desenhe a árvore de recursão no papel antes de codificar.

---

## ✅ CHECKLIST DO DIA

- [ ] Entendi o padrão de backtracking (escolher → recursão → desfazer)
- [ ] Implementei geração de subsets do zero
- [ ] Implementei geração de permutações do zero
- [ ] Resolvi problema com poda
- [ ] Desenhei árvore de recursão de pelo menos 1 problema
- [ ] Anotei padrões no [NOTAS.md](NOTAS.md)

---

**Próximo**: [DIA 4 - Programação Dinâmica](../dia4/README.md)
