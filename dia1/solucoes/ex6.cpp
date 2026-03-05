#include <bits/stdc++.h>
using namespace std;

int main() {
    int res=0,n;cin>>n;
    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
        res ^= x;
    }
    cout << res << endl;
    return 0;
}