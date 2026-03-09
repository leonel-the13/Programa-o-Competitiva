#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n,k;cin>>n>>k;
    vector<ll> a(n);
    for (auto &x: a) cin>>x;
    for (int i = 0; i < n-k+1; i++)
        cout << max(a[i], max(a[i + 1], a[i + 2])) << " ";
    cout <<  endl;
    return 0;
}