#include <bits/stdc++.h>
using namespace std;

// PADRÃO: Verificar se existe subarray com soma = k
// Complexidade: O(n)
// Usa: unordered_map para guardar prefix sums

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    long long k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // prefix[sum] = quantas vezes a soma 'sum' apareceu
    unordered_map<long long, int> prefix;
    prefix[0] = 1; // Importante: soma vazia = 0
    
    long long sum = 0;
    bool found = false;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        
        // Se (sum - k) existe, achamos subarray com soma k
        if(prefix.count(sum - k)) {
            found = true;
            break;
        }
        
        prefix[sum]++;
    }
    
    cout << (found ? "YES" : "NO") << endl;
    
    return 0;
}

/*
EXEMPLO:
Input: n=5, k=7, arr=[2, 3, 1, 4, -1]
Queremos subarray com soma 7

Iteração:
i=0: sum=2,  verifica se (2-7=-5) existe → não, prefix[2]=1
i=1: sum=5,  verifica se (5-7=-2) existe → não, prefix[5]=1
i=2: sum=6,  verifica se (6-7=-1) existe → não, prefix[6]=1
i=3: sum=10, verifica se (10-7=3) existe → não, prefix[10]=1
     Mas subarray [3,1,4] tem soma 8, não 7... erro no exemplo

Exemplo correto:
arr=[2, 5, -2, 1, 3], k=6
i=0: sum=2,  verifica -4 → não
i=1: sum=7,  verifica 1 → não
i=2: sum=5,  verifica -1 → não
i=3: sum=6,  verifica 0 → SIM! prefix[0] existe
     Subarray de índice 0 até 3: [2,5,-2,1] = 6
*/
