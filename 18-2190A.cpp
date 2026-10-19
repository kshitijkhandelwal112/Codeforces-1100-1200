// SOLUTION GIVEN BY AI
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        int k = count(s.begin(), s.end(), '0'); // This counts number of 0's
        vector<int> idx;
        for (int i = 0; i < k; i++)
            if (s[i] == '1') idx.push_back(i + 1);   // ones that sit in the zero zone; {i+1 is because considering 1 to n indices instead of 0 to n-1}
        for (int i = k; i < n; i++)
            if (s[i] == '0') idx.push_back(i + 1);   // zeros that sit in the one zone

// Basically, what we did above is that, idx includes indices of 1's in first k characters ("Zero zone") and 0's in next remaining characters ("One zone").
// All these idx indices can be chosen by Alice, and inverted, so that Bob doesn't remain with any chance.
// Only possibility when Alice remains with no chance is when idx is an empty vector, i.e. binary string is already sorted. Then Bob wins.

        if (idx.empty()) { // learnt new thing, idx.empty() gives 0 or 1, used instead of idx.size()==0
            cout << "Bob\n";
        } else {
            cout << "Alice\n" << idx.size() << "\n";
            for (int x : idx) cout << x << " ";
            cout << "\n";
        }
    }
}
/* MY LENGTHY WRONG SOLUTION:
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        string s; cin>>s;
        vector<int> binary;
        for(int i=0;i<n;i++)binary.push_back(s[i]-'0');
        while(!binary.empty() && binary.back()==1)binary.pop_back(); // this line told by AI, as alternative to old one to cure out of bounds error
        if(binary.size()==0){cout<<"Bob\n";continue;}
        int z = binary.size();
        vector<int> Aidx;
        for(int i=0;i<z;i++){
            if(binary[i]==1){
                Aidx.push_back(i);
                while(binary[i+1]!=0)i++;
            }
        }
        if(Aidx.size()%2==0){cout<<"Bob\n";continue;}
        else{
            int m = (Aidx.size()>1 ? Aidx[1]-Aidx[0] : z-Aidx[0]);
            cout<<"Alice\n";
            cout<<m<<"\n";
            for(int k=Aidx[0];k<m;k++) cout<<k+1<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
    */