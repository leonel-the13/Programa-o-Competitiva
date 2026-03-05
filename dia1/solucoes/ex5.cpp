#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int n,k;cin>>n>>k;
    vector<int> arr(n);
    ll sum = 0;
    ll maxSum;
    for (auto &x: arr) cin>>x;
    for (int i = 0; i < k; i++) sum += arr[i];
    maxSum = sum;
    for (int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        maxSum = max(maxSum, sum);
    }
    cout << maxSum << endl;
    return 0;
}