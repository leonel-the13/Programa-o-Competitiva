#include <bits/stdc++.h>
using namespace std;

/*
PROBLEMA: Existe subarray com soma zero?

ESTRATÉGIA: Prefix Sum com HashMap
- Se duas posições têm a mesma soma acumulada, o subarray entre elas tem soma 0
- Se soma acumulada = 0 em algum ponto, subarray desde o início tem soma 0

EXEMPLO: [4, 2, -3, 1, 6]
Prefix sums: [0] 4, 6, 3, 4, 10
                    ^        ^
Posições com prefix 4 → subarray entre elas = 0
Subarray [2, -3, 1] tem soma 0

COMPLEXIDADE: O(n) tempo, O(n) espaço
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_set<long long> prefixSums;
    prefixSums.insert(0); // Importante: soma vazia
    
    long long sum = 0;
    bool found = false;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        
        // Se essa soma já apareceu antes, existe subarray com soma 0
        if(prefixSums.count(sum)) {
            found = true;
            break;
        }
        
        prefixSums.insert(sum);
    }
    
    cout << (found ? "YES" : "NO") << endl;
    
    return 0;
}
