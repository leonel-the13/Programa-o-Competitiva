#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int> arr(n);
    for (auto &x: arr) cin>>x;
    ll sum = 0;
    int flag = 0;
    unordered_map<ll, int> pf;
    pf[0] = 1;
    for (auto &x: arr) {
        sum += x;
        if (pf[sum]) {
            flag = 1;
            break;
        }
        pf[sum]++;
    }
    (flag) ? cout << "YES\n" : cout << "NO\n";
}