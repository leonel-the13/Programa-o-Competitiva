#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;cin>> n>>k;
    vector<int> arr(n);
    for (auto &x: arr) cin>>x;
    sort(arr.begin(), arr.end());
    int l=0, r=1;
    int flag = 0;
    while(l < n && r < n) {
        if (l == r) {
            r++;
            continue;
        }
        int diff = arr[r] - arr[l];
        if (diff == k) 
        {
            flag = 1;
            break;
        }
        else if (diff < k) l++;
        else r++;
    }
    (flag) ? cout << "YES\n" : cout << "NO\n";
    return 0;
}