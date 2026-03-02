#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    map<int, int> freq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }
    
    int maxFreq = 0, element = -1;
    for(auto [val, count] : freq) {
        if(count > maxFreq) {
            maxFreq = count;
            element = val;
        }
    }
    
    cout << element << " " << maxFreq << endl;
    
    return 0;
}
