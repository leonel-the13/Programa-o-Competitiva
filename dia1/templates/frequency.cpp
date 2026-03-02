#include <bits/stdc++.h>
using namespace std;

// PADRÃO: Contador de Frequências
// Complexidade: O(n)
// Útil para: encontrar elemento mais frequente, anagramas, etc.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Opção 1: map (ordenado)
    map<int, int> freq;
    for(int x : arr) {
        freq[x]++;
    }
    
    // Encontrar elemento mais frequente
    int maxFreq = 0, mostFrequent = -1;
    for(auto [valor, count] : freq) {
        if(count > maxFreq) {
            maxFreq = count;
            mostFrequent = valor;
        }
    }
    
    cout << "Elemento mais frequente: " << mostFrequent << endl;
    cout << "Aparece " << maxFreq << " vezes" << endl;
    
    return 0;
}

/*
QUANDO USAR map vs unordered_map?

map<int, int>:
  - Ordenado
  - O(log n) por operação
  - Usa quando precisa ordem

unordered_map<int, int>:
  - NÃO ordenado
  - O(1) médio por operação
  - Usa quando só precisa velocidade

Exemplo: array = [1, 2, 2, 3, 3, 3, 1]

freq após processar:
  1 → 2 vezes
  2 → 2 vezes
  3 → 3 vezes

Elemento mais frequente: 3 (aparece 3 vezes)
*/

/*
VARIAÇÃO: Encontrar primeiro elemento que aparece k vezes

for(int x : arr) {
    freq[x]++;
    if(freq[x] == k) {
        cout << x << endl;
        return 0;
    }
}
cout << "Nenhum elemento aparece " << k << " vezes" << endl;
*/

/*
VARIAÇÃO: Verificar se todos elementos são únicos

set<int> unicos(arr.begin(), arr.end());
if(unicos.size() == arr.size()) {
    cout << "Todos são únicos" << endl;
} else {
    cout << "Existem repetidos" << endl;
}
*/
