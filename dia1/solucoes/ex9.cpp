#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin>>n>>t;
    vector<ll> a(n);
    for (auto& x: a) cin>>x;
    sort(a.begin(), a.end());
    int l=0, r= a.size() - 1;
    ll best = LLONG_MAX;
    while (l < r) {
        ll element=0;
        element = a[l] + a[r];
        if (element == t) {
            if (best < element) best = element;
            break;
        }
        else if (element < t) l++;
        else r--;
    }
    cout << best << endl;
    return 0;
}