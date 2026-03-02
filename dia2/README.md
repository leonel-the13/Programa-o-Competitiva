# 🔥 DIA 2 – ORDENAÇÃO + DOIS PONTEIROS

**Tempo estimado**: 5 horas  
**Meta**: 10 problemas (6 médios + 4 difíceis)

---

## 🎯 OBJETIVOS DO DIA

1. ⚡ **sort()**: Dominar ordenação e critérios customizados
2. 🔍 **Binary Search**: Busca binária em O(log n)
3. 👉 **Two Pointers**: Técnica para problemas com arrays ordenados
4. 📊 **Prefix Sum**: Consultas de soma em O(1)

---

## 📚 TEORIA ESSENCIAL

### 1️⃣ ORDENAÇÃO (SORT)

```cpp
vector<int> arr = {3, 1, 4, 1, 5};

// Crescente
sort(arr.begin(), arr.end()); // [1, 1, 3, 4, 5]

// Decrescente
sort(arr.begin(), arr.end(), greater<int>()); // [5, 4, 3, 1, 1]

// Critério customizado
sort(arr.begin(), arr.end(), [](int a, int b) {
    return abs(a) < abs(b); // ordena por valor absoluto
});
```

#### Ordenar Pares/Structs:

```cpp
vector<pair<int,int>> pairs = {{3,1}, {1,2}, {3,0}};
sort(pairs.begin(), pairs.end());
// Ordena por .first, depois por .second: [(1,2), (3,0), (3,1)]

// Custom
struct Person { int idade, altura; };
vector<Person> pessoas;
sort(pessoas.begin(), pessoas.end(), [](Person a, Person b) {
    if(a.idade != b.idade) return a.idade < b.idade;
    return a.altura > b.altura; // idade igual → maior altura primeiro
});
```

**Complexidade**: O(n log n)

---

### 2️⃣ BINARY SEARCH

Procurar elemento em array **ORDENADO**: O(log n)

```cpp
vector<int> arr = {1, 3, 5, 7, 9, 11};

// Verificar se existe
bool existe = binary_search(arr.begin(), arr.end(), 7); // true

// Encontrar posição
int pos = lower_bound(arr.begin(), arr.end(), 7) - arr.begin(); // índice 3

// lower_bound: primeiro elemento >= x
// upper_bound: primeiro elemento > x

int x = 5;
auto it = lower_bound(arr.begin(), arr.end(), x);
if(it != arr.end() && *it == x) {
    cout << "Encontrado na posição " << (it - arr.begin()) << endl;
}
```

#### Binary Search Manual:

```cpp
int busca(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2; // evita overflow

        if(arr[mid] == target) return mid;
        if(arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1; // não encontrado
}
```

**CUIDADO**: Array DEVE estar ordenado!

---

### 3️⃣ TWO POINTERS

Técnica para problemas em arrays ordenados: O(n) em vez de O(n²)

#### Padrão A: Soma de Pares

```cpp
// Dado array ordenado, encontrar par com soma = target
vector<int> arr = {1, 2, 3, 4, 5, 6};
int target = 7;

int left = 0, right = arr.size() - 1;
while(left < right) {
    int sum = arr[left] + arr[right];

    if(sum == target) {
        cout << arr[left] << " + " << arr[right] << endl;
        break;
    } else if(sum < target) {
        left++; // precisamos de soma maior
    } else {
        right--; // precisamos de soma menor
    }
}
```

#### Padrão B: Remover Duplicatas

```cpp
// Remove duplicatas in-place em array ordenado
int removeDuplicates(vector<int>& arr) {
    if(arr.empty()) return 0;

    int slow = 0;
    for(int fast = 1; fast < arr.size(); fast++) {
        if(arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }

    return slow + 1; // novo tamanho
}
```

#### Padrão C: Container With Most Water

```cpp
// Dois ponteiros para maximizar área
int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while(left < right) {
        int h = min(height[left], height[right]);
        int width = right - left;
        maxWater = max(maxWater, h * width);

        // Move o ponteiro do lado menor
        if(height[left] < height[right]) left++;
        else right--;
    }

    return maxWater;
}
```

---

### 4️⃣ PREFIX SUM (Soma Acumulada)

Consultar soma de um intervalo em O(1).

```cpp
vector<int> arr = {3, 1, 4, 1, 5};
int n = arr.size();

// Construir prefix sum: O(n)
vector<long long> prefix(n + 1, 0);
for(int i = 0; i < n; i++) {
    prefix[i + 1] = prefix[i] + arr[i];
}
// prefix = [0, 3, 4, 8, 9, 14]

// Soma de arr[L] até arr[R]: O(1)
int L = 1, R = 3; // índices 1, 2, 3
long long soma = prefix[R + 1] - prefix[L]; // = 14 - 3 = 11... erro

// Correção: soma de índices 1 a 3 → arr[1]+arr[2]+arr[3] = 1+4+1 = 6
soma = prefix[R + 1] - prefix[L]; // = prefix[4] - prefix[1] = 9 - 3 = 6 ✓
```

**Aplicação**: Responder Q consultas de soma de intervalos em O(Q) total.

---

## 🧠 PADRÕES DESTE DIA

### Padrão A: "Encontrar par/tripla com soma X"

→ Ordena + **Two Pointers** (O(n) ou O(n²) para triplas)

### Padrão B: "Buscar elemento/primeira ocorrência"

→ **Binary Search** se array ordenado

### Padrão C: "Múltiplas consultas de soma de intervalo"

→ **Prefix Sum** para otimizar

### Padrão D: "Processar array de forma específica"

→ Primeiro **ordena**, depois processa linearmente

---

## 📝 EXERCÍCIOS DO DIA

Acesse [exercicios/](exercicios/) para enunciados completos.

### Nível Médio (6 problemas)

1. [Par com Soma Alvo](exercicios/p01_par_soma_alvo.md)
2. [Contar Inversões](exercicios/p02_contar_inversoes.md)
3. [Kth Maior Elemento](exercicios/p03_kth_maior.md)
4. [Soma de Intervalo](exercicios/p04_soma_intervalo.md)
5. [Três Números com Soma Zero](exercicios/p05_tres_soma_zero.md)
6. [Buscar em Array Rotacionado](exercicios/p06_busca_rotacionado.md)

### Nível Difícil (4 problemas)

7. [Quatro Números com Soma Alvo](exercicios/p07_quatro_soma.md)
8. [Subarray com Soma Divisível por K](exercicios/p08_subarray_divisivel.md)
9. [Agressivos Cows (Binary Search em Resposta)](exercicios/p09_aggressive_cows.md)
10. [Median of Two Sorted Arrays](exercicios/p10_median_two_arrays.md)

---

## 🔥 MENTALIDADE

> "Antes de escrever O(n²), pergunte: posso ordenar e usar two pointers?"

Ordenação + Two Pointers é uma das combinações mais poderosas em competição.

**No Dia 8, você vai ver um problema de soma de triplas e vai resolver em 5 minutos.**

---

## ✅ CHECKLIST DO DIA

- [ ] Dominei sort() e comparadores customizados
- [ ] Implementei binary search do zero
- [ ] Resolvi problema com two pointers
- [ ] Usei prefix sum para consultas
- [ ] Tentei todos os 10 problemas
- [ ] Anotei padrões no [NOTAS.md](NOTAS.md)

---

**Próximo**: [DIA 3 - Recursão + Backtracking](../dia3/README.md)
