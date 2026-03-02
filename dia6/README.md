# 🔥 DIA 6 – TEORIA DOS NÚMEROS

**Tempo estimado**: 5 horas  
**Meta**: 11 problemas (6 médios + 5 difíceis)

---

## 🎯 OBJETIVOS DO DIA

1. 🔢 **Primos**: Teste de primalidade, Crivo de Eratóstenes
2. ➗ **MDC/MMC**: Máximo Divisor Comum, Mínimo Múltiplo Comum
3. ⚡ **Exponenciação Rápida**: Calcular a^n em O(log n)
4. 🔐 **Aritmética Modular**: (a + b) mod m, (a × b) mod m
5. 🧮 **Fatoração**: Decomposição em fatores primos

---

## 📚 TEORIA ESSENCIAL

### 1️⃣ NÚMEROS PRIMOS

**Teste de Primalidade Simples**: O(√n)

```cpp
bool ehPrimo(int n) {
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    for(int i = 5; i * i <= n; i += 6) {
        if(n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
```

**Por que i += 6?**  
Primos > 3 são da forma 6k ± 1. Então testamos 5, 7, 11, 13, 17, 19, ...

---

### 2️⃣ CRIVO DE ERATÓSTENES

**Problema**: Encontrar todos os primos até N

**Algoritmo**: O(n log log n)

```cpp
vector<bool> crivo(int n) {
    vector<bool> primo(n+1, true);
    primo[0] = primo[1] = false;

    for(int i = 2; i * i <= n; i++) {
        if(primo[i]) {
            for(int j = i * i; j <= n; j += i)
                primo[j] = false;
        }
    }

    return primo;
}

// Uso:
vector<bool> primo = crivo(1000000);
if(primo[17]) cout << "17 é primo" << endl;
```

**Otimização**: Guardar lista de primos

```cpp
vector<int> gerarPrimos(int n) {
    vector<bool> eh_primo = crivo(n);
    vector<int> primos;

    for(int i = 2; i <= n; i++)
        if(eh_primo[i])
            primos.push_back(i);

    return primos;
}
```

---

### 3️⃣ MDC e MMC

**MDC (Máximo Divisor Comum)** - Algoritmo de Euclides: O(log min(a,b))

```cpp
int mdc(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Ou use a função built-in de C++17:
int g = __gcd(a, b);
```

**MMC (Mínimo Múltiplo Comum)**:

```cpp
long long mmc(int a, int b) {
    return (long long)a / mdc(a, b) * b; // evita overflow
}
```

**Propriedade importante**: `mdc(a, b) × mmc(a, b) = a × b`

---

### 4️⃣ EXPONENCIAÇÃO RÁPIDA

**Problema**: Calcular a^n em O(log n)

**Algoritmo**:

```cpp
long long potencia(long long a, long long n) {
    if(n == 0) return 1;

    long long half = potencia(a, n/2);

    if(n % 2 == 0)
        return half * half;
    else
        return half * half * a;
}
```

**Versão Iterativa**:

```cpp
long long potencia(long long a, long long n) {
    long long resultado = 1;

    while(n > 0) {
        if(n % 2 == 1)
            resultado *= a;
        a *= a;
        n /= 2;
    }

    return resultado;
}
```

---

### 5️⃣ EXPONENCIAÇÃO MODULAR

**Problema**: Calcular (a^n) mod m

```cpp
long long potenciaMod(long long a, long long n, long long m) {
    long long resultado = 1;
    a %= m;

    while(n > 0) {
        if(n % 2 == 1)
            resultado = (resultado * a) % m;
        a = (a * a) % m;
        n /= 2;
    }

    return resultado;
}
```

**Por que isso evita overflow?**  
Fazemos mod a cada multiplicação, mantendo números pequenos.

---

### 6️⃣ ARITMÉTICA MODULAR

**Propriedades**:

```
(a + b) mod m = ((a mod m) + (b mod m)) mod m
(a - b) mod m = ((a mod m) - (b mod m) + m) mod m
(a × b) mod m = ((a mod m) × (b mod m)) mod m
```

**CUIDADO**: Divisão modular NÃO funciona assim!
Para divisão modular, use **inverso multiplicativo**.

**Inverso Modular** (quando m é primo):

```cpp
// Teorema de Fermat: a^(p-1) ≡ 1 (mod p)
// Logo: a^(-1) ≡ a^(p-2) (mod p)
long long inversoMod(long long a, long long p) {
    return potenciaMod(a, p - 2, p);
}

// (a / b) mod p = (a × b^(-1)) mod p
long long divisaoMod(long long a, long long b, long long p) {
    return (a * inversoMod(b, p)) % p;
}
```

---

### 7️⃣ FATORAÇÃO PRIMA

**Decompor N em fatores primos**: O(√n)

```cpp
vector<pair<int,int>> fatorar(int n) {
    vector<pair<int,int>> fatores; // {primo, expoente}

    for(int i = 2; i * i <= n; i++) {
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

// Exemplo: 60 = 2² × 3 × 5
// Retorna: [(2, 2), (3, 1), (5, 1)]
```

---

### 8️⃣ NÚMERO DE DIVISORES

```cpp
int numDivisores(int n) {
    int count = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            count++; // divisor i
            if(i != n/i)
                count++; // divisor n/i
        }
    }
    return count;
}
```

**Usando fatoração**:
Se n = p₁^a₁ × p₂^a₂ × ... × pₖ^aₖ  
Então número de divisores = (a₁ + 1) × (a₂ + 1) × ... × (aₖ + 1)

---

### 9️⃣ SOMA DE DIVISORES

```cpp
long long somaDivisores(int n) {
    long long soma = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            soma += i;
            if(i != n/i)
                soma += n/i;
        }
    }
    return soma;
}
```

---

## 🧠 PADRÕES DESTE DIA

### Padrão A: "Contar primos até N"

→ **Crivo de Eratóstenes**

### Padrão B: "Calcular a^n grande"

→ **Exponenciação rápida** O(log n)

### Padrão C: "Operações com mod"

→ **Aritmética modular**, tomar mod a cada operação

### Padrão D: "Decomposição de número"

→ **Fatoração prima**

---

## 📝 EXERCÍCIOS DO DIA

### Nível Médio (6 problemas)

1. [Contar Primos até N](exercicios/p01_contar_primos.md)
2. [MDC de Array](exercicios/p02_mdc_array.md)
3. [Potência Modular](exercicios/p03_potencia_mod.md)
4. [Número Perfeito](exercicios/p04_numero_perfeito.md)
5. [Fatores Primos](exercicios/p05_fatores_primos.md)
6. [Fibonacci Modular](exercicios/p06_fib_mod.md)

### Nível Difícil (5 problemas)

7. [Contar Divisores de Fatorial](exercicios/p07_divisores_fatorial.md)
8. [Equação Diofantina](exercicios/p08_diofantina.md)
9. [Exponenciação de Matrizes](exercicios/p09_exp_matriz.md)
10. [Números Coprimos em Range](exercicios/p10_coprimos.md)
11. [Modular Inverse Array](exercicios/p11_inverse_array.md)

---

## 🔥 MENTALIDADE

> "Números grandes? Mod. Primos até 10^7? Crivo. a^(10^9)? Exponenciação rápida."

**Essas técnicas aparecem MUITO em competições.**

---

## ✅ CHECKLIST DO DIA

- [ ] Implementei teste de primalidade
- [ ] Implementei Crivo de Eratóstenes
- [ ] Implementei exponenciação rápida
- [ ] Usei aritmética modular corretamente
- [ ] Fatorei números em primos
- [ ] Calculei MDC/MMC
- [ ] Anotei padrões no [NOTAS.md](NOTAS.md)

---

**Próximo**: [DIA 7 - Strings](../dia7/README.md)
