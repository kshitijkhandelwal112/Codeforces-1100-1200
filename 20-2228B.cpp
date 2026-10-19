#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    //(M1)Common Silly mistake: Considering move of Remilia and Reimu to be done in 2 seconds; but instead both done in 1 second
    while (t--) {
        int n,x1,x2,k;
        cin>>n>>x1>>x2>>k;
        //mistake m1 done => did cout<<2 for n==3
        if(n<4)cout<<1<<"\n";
        else{
            // cout<<k+abs(x1-x2)<<"\n"; ==> Silly mistake: abs(x1-x2) will give only one distance, might be larger one.
            int z = min({abs(x1-x2),n+min(x1,x2)-max(x1,x2)});
            // Mistake M1 done => did z++;
            cout<<z+k<<"\n";
        }
    }
    return 0;
}