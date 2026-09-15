// THIS CODE IS FOR LEARING PREFIX SUMS.
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin>>s;
    int n = s.size();
    int m; cin>>m;
     /* This is the method that I tried for the first time but TLE
    while(m--){
        int l,r;
        cin>>l>>r;
        int ans=0;
        for(int i=l-1;i<r-1;i++){
            if(s[i]==s[i+1]) ans++;
        }
        cout<<ans<<"\n";
    }
    */
    // This is the method I tried for the second time after reading one line of tutorial. But same time complexity.
    int xyz[n-1];
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1])xyz[i]=1;
        else xyz[i]=0;
    }
    /* This is specifically what gave same time complexity in second time.
    while(m--){
        int sum=0;
        int l,r; cin>>l>>r;
        for(int i=l-1;i<r-1;i++) sum+=xyz[i];
        cout<<sum<<"\n";
    } */
    // PROPER WAY IS BELOW:
    int SUM[n-1];
    for(int i=0;i<n-1;i++){
        int sum=0;
        for(int j=0;j<=i;j++)sum+=xyz[j];
        SUM[i]=sum;
    }
    while(m--){
        int l,r; cin>>l>>r;
        cout<<SUM[r-2]-SUM[l-2]<<endl; // This is also something that does many errors.
        // It is given that l <= i < r and for array, since positions starts from 0, it is l-1 <= i < r-1;
        // This we want l-1 to be included but r-1 not to be included.
        // In case l+1 = r, then we just want l-th one, then use the concept that S_(n) - S_(n-1) is T_n and not S(n)-S(n). I was doing mistake related to this concept.
    }
    // Thus even if m is very large, we just need to calculate all partial sums for 1 time,
    return 0;
}
// Basically, we just wanted comparison of adjacent charagcers, multiple times, nothing else.
// Due to high time complexity, (that was probably due to large m) we needed 2 (not 1) arrays, one having 0/1 and other having partial sums. (These are prefix sums.)