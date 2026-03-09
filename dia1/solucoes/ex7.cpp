#include <bits/stdc++.h>
using namespace std;
using ll= long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<pair<ll, ll>> mesc(n);
    for (auto &x: mesc) cin >> x.first >> x.second;
    sort(mesc.begin(), mesc.end());
    vector<pair<ll, ll>> res;
    for(auto &[l, r]: mesc) {
        if (res.empty() || res.back().second < l)
            res.push_back({l, r});
        else   
            res.back().second = max(res.back().second, r);  
    }
    cout << res.size() << endl;
    for (auto &[l, r]: res) cout << l << " " << r << endl;
    return 0;
}