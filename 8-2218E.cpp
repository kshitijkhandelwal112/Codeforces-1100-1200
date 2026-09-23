#include <bits/stdc++.h>
using namespace std;
// Used tutorial, this problem was unthinkable for me.
// Tutorial image pasted in excel sheet.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        vector<int> b;
        for(int i=0;i<n;i++){
            for(int j=0;j<n && j!=i;j++){
                b.push_back(a[i]^a[j]);
            }
        }
        auto z = max_element(b.begin(),b.end());
        cout<<(*z)<<"\n";
    }   
    return 0;
}