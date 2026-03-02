#include <bits/stdc++.h>
using namespace std;

// PADRÃO: Maximum Subarray Sum (Kadane's Algorithm)
// Complexidade: O(n)
// Encontra o subarray contíguo com maior soma

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long maxSum = LLONG_MIN; // Importante: começa com menor valor possível
    long long currentSum = 0;
    
    for(int i = 0; i < n; i++) {
        // Decide: adiciona ao subarray atual OU começa novo
        currentSum = max((long long)arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    cout << maxSum << endl;
    
    return 0;
}

/*
EXEMPLO:
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

i=0: current=max(-2, 0-2)=-2,     maxSum=-2
i=1: current=max(1, -2+1)=1,      maxSum=1
i=2: current=max(-3, 1-3)=-2,     maxSum=1
i=3: current=max(4, -2+4)=4,      maxSum=4
i=4: current=max(-1, 4-1)=3,      maxSum=4
i=5: current=max(2, 3+2)=5,       maxSum=5
i=6: current=max(1, 5+1)=6,       maxSum=6
i=7: current=max(-5, 6-5)=1,      maxSum=6
i=8: current=max(4, 1+4)=5,       maxSum=6

Subarray [4, -1, 2, 1] tem soma 6
*/

/*
VARIAÇÃO: Retornar os índices do subarray

int start = 0, end = 0, tempStart = 0;
long long maxSum = LLONG_MIN, currentSum = 0;

for(int i = 0; i < n; i++) {
    if(currentSum + arr[i] < arr[i]) {
        currentSum = arr[i];
        tempStart = i;
    } else {
        currentSum += arr[i];
    }
    
    if(currentSum > maxSum) {
        maxSum = currentSum;
        start = tempStart;
        end = i;
    }
}

cout << "Soma: " << maxSum << endl;
cout << "De índice " << start << " até " << end << endl;
*/
