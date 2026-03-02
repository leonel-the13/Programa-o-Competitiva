# 📝 NOTAS DO DIA 6

## 🎯 Padrões Aprendidos Hoje

### 1. Crivo de Eratóstenes - DECORE!

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

### 2. Exponenciação Modular - DECORE!

```cpp
long long potMod(long long a, long long n, long long m) {
    long long res = 1; a %= m;
    while(n > 0) {
        if(n % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        n /= 2;
    }
    return res;
}
```

### 3. MDC - DECORE!

```cpp
int mdc(int a, int b) {
    while(b) { int t = b; b = a % b; a = t; }
    return a;
}
```

---

## ⚠️ Erros Comuns

- [ ] Esqueci de tomar mod a cada operação
- [ ] Overflow em exponenciação (não usei long long)
- [ ] Teste de primalidade com loop até n (deveria ser até √n)

---

## 💡 Insights

- MOD a cada operação, não só no final!
- Crivo é O(n log log n), muito rápido
- a^n mod m: SEMPRE use exponenciação rápida

---

**Data**: **_/_**/\_\_\_
