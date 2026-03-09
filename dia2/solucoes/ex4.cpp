#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<ll> a(n);
    for (auto& x: a) cin>>x;
    int t;cin>>t;
    while (t--) {
        int l, r;cin>>l>>r;
        int sum = 0;
        for (int i = l; i <= r; i++) sum += a[i];
        cout << sum << endl;
    }
    return 0;
}