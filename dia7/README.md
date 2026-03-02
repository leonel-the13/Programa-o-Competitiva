# 🔥 DIA 7 – STRINGS

**Tempo estimado**: 5 horas  
**Meta**: 10 problemas (6 médios + 4 difíceis)

---

## 🎯 OBJETIVOS DO DIA

1. 🔤 **Manipulação Básica**: Reverter, rotacionar, frequência
2. 🪞 **Palíndromos**: Verificar, maior palíndromo
3. 🔀 **Anagramas**: Detectar, agrupar
4. 🧩 **Substrings**: KMP, Z-algorithm, Rolling Hash
5. 📝 **Padrões**: Matching, subsequências

---

## 📚 TEORIA ESSENCIAL

### 1️⃣ OPERAÇÕES BÁSICAS

```cpp
string s = "hello";

// Tamanho
int n = s.size(); // ou s.length()

// Acessar caractere
char c = s[0]; // 'h'
char ultimo = s.back(); // 'o'

// Modificar
s[0] = 'H'; // "Hello"

// Adicionar
s += " world"; // "Hello world"
s.push_back('!'); // "Hello world!"

// Substring
string sub = s.substr(0, 5); // "Hello" (inicio, tamanho)

// Encontrar
size_t pos = s.find("world"); // posição ou string::npos se não achar

// Reverter
reverse(s.begin(), s.end());

// Ordenar
sort(s.begin(), s.end());

// Comparar
if(s1 == s2) // lexicográfica
if(s1 < s2)  // "abc" < "abd"
```

---

### 2️⃣ FREQUÊNCIA DE CARACTERES

```cpp
string s = "programming";
unordered_map<char, int> freq;

for(char c : s)
    freq[c]++;

// Ou use array (mais rápido para letras):
int freq[26] = {0};
for(char c : s)
    freq[c - 'a']++;

// Para todas as letras ASCII:
int freq[256] = {0};
for(char c : s)
    freq[c]++;
```

---

### 3️⃣ PALÍNDROMOS

**Verificar se é palíndromo**: O(n)

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

// Ou simplesmente:
bool ehPalindromo(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}
```

**Maior palíndromo (Expansão ao redor do centro)**:

```cpp
string expandir(string& s, int left, int right) {
    while(left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string maiorPalindromo(string s) {
    if(s.empty()) return "";

    string maior = "";

    for(int i = 0; i < s.size(); i++) {
        // Palíndromo ímpar (centro em i)
        string p1 = expandir(s, i, i);
        // Palíndromo par (centro entre i e i+1)
        string p2 = expandir(s, i, i+1);

        if(p1.size() > maior.size()) maior = p1;
        if(p2.size() > maior.size()) maior = p2;
    }

    return maior;
}
```

---

### 4️⃣ ANAGRAMAS

**Verificar se duas strings são anagramas**:

```cpp
bool saoAnagramas(string s1, string s2) {
    if(s1.size() != s2.size()) return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    return s1 == s2;
}

// Ou com frequência:
bool saoAnagramas(string s1, string s2) {
    if(s1.size() != s2.size()) return false;

    int freq[26] = {0};
    for(char c : s1) freq[c - 'a']++;
    for(char c : s2) freq[c - 'a']--;

    for(int i = 0; i < 26; i++)
        if(freq[i] != 0) return false;

    return true;
}
```

**Agrupar anagramas**:

```cpp
vector<vector<string>> agruparAnagramas(vector<string>& strs) {
    unordered_map<string, vector<string>> grupos;

    for(string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        grupos[key].push_back(s);
    }

    vector<vector<string>> resultado;
    for(auto& [key, grupo] : grupos)
        resultado.push_back(grupo);

    return resultado;
}
```

---

### 5️⃣ SUBSEQUÊNCIA vs SUBSTRING

**Subsequência**: Pode pular caracteres (não precisa ser contíguo)  
**Substring**: Deve ser contíguo

**Verificar se T é subsequência de S**:

```cpp
bool ehSubsequencia(string s, string t) {
    int j = 0; // ponteiro para t

    for(int i = 0; i < s.size() && j < t.size(); i++) {
        if(s[i] == t[j])
            j++;
    }

    return j == t.size();
}
```

---

### 6️⃣ KMP (Knuth-Morris-Pratt)

**Problema**: Encontrar todas as ocorrências de padrão P em texto T

**Complexidade**: O(n + m) onde n = |T|, m = |P|

```cpp
vector<int> computeLPS(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0); // longest proper prefix which is also suffix

    int len = 0; // tamanho do prefixo anterior
    int i = 1;

    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> KMP(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = computeLPS(pattern);
    vector<int> ocorrencias;

    int i = 0; // índice para text
    int j = 0; // índice para pattern

    while(i < n) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == m) {
            ocorrencias.push_back(i - j);
            j = lps[j - 1];
        } else if(i < n && text[i] != pattern[j]) {
            if(j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return ocorrencias;
}
```

---

### 7️⃣ Z-ALGORITHM

**Uso**: Pattern matching, prefixos comuns

```cpp
vector<int> zAlgorithm(string s) {
    int n = s.size();
    vector<int> z(n);

    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n && s[r - l] == s[r])
                r++;
            z[i] = r - l;
            r--;
        } else {
            int k = i - l;
            if(z[k] < r - i + 1)
                z[i] = z[k];
            else {
                l = i;
                while(r < n && s[r - l] == s[r])
                    r++;
                z[i] = r - l;
                r--;
            }
        }
    }

    return z;
}
```

---

## 🧠 PADRÕES DESTE DIA

### Padrão A: "Frequência de caracteres"

→ Array de 26 ou HashMap

### Padrão B: "Anagramas"

→ Ordenar string ou comparar frequências

### Padrão C: "Pattern matching"

→ KMP ou Z-algorithm para O(n + m)

### Padrão D: "Palíndromo"

→ Expansão ao redor do centro ou DP

---

## 📝 EXERCÍCIOS DO DIA

### Nível Médio (6 problemas)

1. [Anagramas em Grupo](exercicios/p01_anagramas.md)
2. [Primeiro Caractere Único](exercicios/p02_primeiro_unico.md)
3. [Maior Palíndromo](exercicios/p03_maior_palindromo.md)
4. [É Subsequência](exercicios/p04_subsequencia.md)
5. [Comprimir String](exercicios/p05_comprimir.md)
6. [Rotações de String](exercicios/p06_rotacoes.md)

### Nível Difícil (4 problemas)

7. [KMP Pattern Matching](exercicios/p07_kmp.md)
8. [Menor Janela com Todos Caracteres](exercicios/p08_min_window.md)
9. [Distinct Substrings](exercicios/p09_distinct_substrings.md)
10. [Longest Palindromic Substring (DP)](exercicios/p10_lis_palindrome.md)

---

## 🔥 MENTALIDADE

> "Strings são arrays de caracteres. Use frequências, two pointers, e pattern matching."

---

## ✅ CHECKLIST DO DIA

- [ ] Manipulei strings com operações básicas
- [ ] Resolvi problema de anagramas
- [ ] Implementei verificação de palíndromo
- [ ] Entendi KMP (pelo menos a ideia)
- [ ] Usei frequência de caracteres
- [ ] Anotei padrões no [NOTAS.md](NOTAS.md)

---

**Próximo**: [DIA 8 - Simulação de Maratona (CRÍTICO!)](../dia8/README.md)
