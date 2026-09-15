#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> pfsum(n);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        pfsum[i]=sum;
    }
    int m; cin>>m;
    while(m--){
        int q; cin>>q;
        /* THIS THING IS CAUSING TLE ISSUES.
        bool found = false;
        for(int i=0;found==false && i<n;i++){
            if(pfsum[0]>=q){cout<<1<<"\n";found=true;}
            else if(pfsum[i]<q && pfsum[i+1]>=q && i<n-1){cout<<i+2<<"\n";found=true;}
            else if(i==n-1){cout<<n<<"\n";}
        }
        */
        // PROPER METHOD:
        // One nice thing: the pfsum vector is already sorted! Thus indexes are a good thing to use.
        int idx = lower_bound(pfsum.begin(),pfsum.end(),q) - pfsum.begin();
        cout<<idx + 1<<"\n";
        /*
        Basically lower_bound and upper_bound are defined for sorted vectors, and give the FIRST iterator corresponding to the value that is
        (>= in case of lower_bound and > in case of upper_bound)
        For vector, array etc. its time complexity is O(log n) and for lists etc. it is still O(log n) with some difference that is later theory, not for rn.

        Also, quite obvious, lower_bound returns iterator, and to find index, we need to subtract vec.begin()
        */
    }
    return 0;
}