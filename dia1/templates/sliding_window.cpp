#include <bits/stdc++.h>
using namespace std;

// PADRÃO: Sliding Window (Janela Deslizante)
// Complexidade: O(n)
// Útil para: soma/produto de k elementos consecutivos, substring de tamanho k, etc.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Calcula soma da primeira janela
    long long windowSum = 0;
    for(int i = 0; i < k; i++) {
        windowSum += arr[i];
    }
    
    long long maxSum = windowSum;
    
    // Desliza a janela
    for(int i = k; i < n; i++) {
        // Remove elemento que saiu, adiciona elemento que entrou
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = max(maxSum, windowSum);
    }
    
    cout << maxSum << endl;
    
    return 0;
}

/*
EXEMPLO:
arr = [1, 4, 2, 10, 23, 3, 1, 0, 20], k = 4

Janela inicial [1, 4, 2, 10]: soma = 17

i=4: remove arr[0]=1,  adiciona arr[4]=23 → [4, 2, 10, 23]  = 39
i=5: remove arr[1]=4,  adiciona arr[5]=3  → [2, 10, 23, 3]  = 38
i=6: remove arr[2]=2,  adiciona arr[6]=1  → [10, 23, 3, 1]  = 37
i=7: remove arr[3]=10, adiciona arr[7]=0  → [23, 3, 1, 0]   = 27
i=8: remove arr[4]=23, adiciona arr[8]=20 → [3, 1, 0, 20]   = 24

maxSum = 39
*/

/*
VARIAÇÃO: Maior janela com soma ≤ S (tamanho variável)

int left = 0, maxLen = 0;
long long sum = 0;

for(int right = 0; right < n; right++) {
    sum += arr[right];
    
    while(sum > S && left <= right) {
        sum -= arr[left];
        left++;
    }
    
    maxLen = max(maxLen, right - left + 1);
}

cout << maxLen << endl;
*/
