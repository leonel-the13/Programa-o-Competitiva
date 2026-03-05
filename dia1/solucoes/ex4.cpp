#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> arr(n);
    for (int x = 0; x < n; x++) cin>>arr[x];
    sort(arr.begin(), arr.end());
    int m=1, count=1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]){
            count++;
            m = max(m, count);
        }
        else    
            count = 1;
    }
    if (m > (n+1)/2) {
        cout << "-1\n";
        return 0;
    }
    vector<int> res;
    int metade = (n+1)/2;
    int i = 0, j = metade;
    while (i < metade || j < n) {
        if (i < metade) res.push_back(arr[i++]);
        if (j < n) res.push_back(arr[j++]);
    }
    for (int x = 0; x < n; x++) cout << res[x] << " ";
    cout << "\n";
    return 0;
}