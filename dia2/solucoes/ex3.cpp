#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end(), greater<int>());
    // nth_element(a.begin(), a.begin() + m - 1, a.end(), greater<int>()); 
    int m;cin>>m;
    cout << a[m-1] << endl;
    return 0;
}