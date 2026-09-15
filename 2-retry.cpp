#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    
    int m; cin>>m;
    vector<int>q(m);
    for(int i=0;i<m;i++) cin>>q[i];
    vector<int> pfsum(n);
    int sum=0;
    int j=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        pfsum[i]=sum;
        if(sum-q[j]>0 && j<m){cout<<j<<endl;j++;}
    }
    /*
    while(m--){
        int q; cin>>q;
        bool found=false;
        for(int i=0;found==false && i<n;i++){
            if(pfsum[0]>=q){cout<<1<<"\n";found=true;}
            else if(pfsum[i]<q && pfsum[i+1]>=q && i<n-1){cout<<i+2<<"\n";found=true;}
            else if(i==n-1){cout<<n<<"\n";}
        }
    } */
    return 0;
}