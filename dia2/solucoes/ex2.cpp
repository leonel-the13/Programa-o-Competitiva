#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;cin>>n;
    vector<int> a(n);
    for (auto& x: a) cin>>x;
    int c=0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                c++;    
    }
    cout << c << endl;
    return 0;
}