#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, t;cin>>n>>t;
    vector<ll> a(n);
    for (auto& x: a) cin>>x;
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        ll sum = a[l] + a[r];
        if (sum == t) {
            cout << a[l] << " " << a[r] << endl;
            return 0;
        } else if (sum < t) l++;
        else r--;
    }
    cout << -1 << endl;
    return 0;
}