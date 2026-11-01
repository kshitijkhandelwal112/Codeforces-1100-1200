#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int ops=0;
        for(int i=0;i<n-1;i++){
            if(a[i]==a[i+1] || a[i]+a[i+1]==7){ops++;i++;}
        }
        cout<<ops<<"\n";
    }
    return 0;
}