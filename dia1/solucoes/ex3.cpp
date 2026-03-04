#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vector<int> arr(n);
    map<int, int> freq;
    for (auto &x: arr){
        cin>>x;
        freq[x]++;
    } 
    int m=0, value=0;
    for (const auto& pair: freq) {
        auto k = pair.first;
        auto q = pair.second;
        if (q > m) {
            m = q;
            value = k;
        }
    }
    cout << m << " " << value << endl;
    return 0;
}