#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k; cin>>n>>k;
        int gsize = n-1;
        int grps = k/gsize;
        int left = k%gsize;
        if(left==0) cout<<(n*grps)-1<<"\n";
        else cout<<(n*grps)+left<<"\n";
    }
    return 0;
}