#include <iostream>
#include <vector>
#include <cmath>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int sum=0,sum2=0;
        while(n--){
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            sum+=abs(a-c)+abs(b-d);
            if(b-d>0) sum2+=(a>c ? c:a);
        }
        sum/=2;
        sum+=sum2;
        cout<<sum<<"\n";
    }
    return 0;
}