#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n,q;cin>>n>>q;
        vector<int> a(n);
        vector<int> odd(n);
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]%2!=0)odd[i]=1;}
        vector<int> pfsum(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            pfsum[i]=sum;
        }
        while(q--){
            int l,r,k; cin>>l>>r>>k;
            l--;r--;
            int z=0;
            if(l==0){z=pfsum[n-1]-pfsum[r]+(r+1)*k;}
            else z = pfsum[n-1]-(pfsum[r]-pfsum[l-1])+k*(r-l+1);
            if(z%2!=0)cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}