#include <bits/stdc++.h>
using namespace std;

/*
PROBLEMA: Existe par com diferença K?

ESTRATÉGIA: HashSet
Para cada elemento x, verificar se (x + k) ou (x - k) existe

COMPLEXIDADE: O(n) tempo, O(n) espaço
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    unordered_set<int> elements(arr.begin(), arr.end());
    
    bool found = false;
    for(int x : arr) {
        // Verificar se x + k existe
        if(elements.count(x + k)) {
            found = true;
            break;
        }
    }
    
    cout << (found ? "YES" : "NO") << endl;
    
    return 0;
}
