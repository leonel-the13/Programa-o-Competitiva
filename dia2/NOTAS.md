# 📝 NOTAS DO DIA 2

## 🎯 Padrões Aprendidos Hoje

### 1. Two Pointers (Soma de Pares)

**Template**:

```cpp
sort(arr.begin(), arr.end());
int left = 0, right = n-1;
while(left < right) {
    int sum = arr[left] + arr[right];
    if(sum == target) break;
    else if(sum < target) left++;
    else right--;
}
```

### 2. Binary Search

**Template**:

```cpp
int left = 0, right = n-1;
while(left <= right) {
    int mid = left + (right-left)/2;
    if(arr[mid] == target) return mid;
    if(arr[mid] < target) left = mid+1;
    else right = mid-1;
}
```

### 3. Prefix Sum

**Template**:

```cpp
vector<long long> prefix(n+1, 0);
for(int i = 0; i < n; i++)
    prefix[i+1] = prefix[i] + arr[i];
// Soma [L, R] = prefix[R+1] - prefix[L]
```

---

## ⚠️ Erros Comuns

- [ ] Esqueci de ordenar antes de usar two pointers
- [ ] Binary search: usei `left < right` em vez de `left <= right`
- [ ] Overflow em `(left + right) / 2`

---

## 📊 Progresso

| Problema | Tempo | Status |
| -------- | ----- | ------ |
| P01      |       |        |
| P02      |       |        |

---

**Data**: **_/_**/\_\_\_
