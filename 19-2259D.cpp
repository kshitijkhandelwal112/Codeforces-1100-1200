#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        int zero=0;
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]==0)zero++;}
        if(zero==0){
            cout<<"YES\n";
            for(int i=0;i<n;i++)cout<<"A";
            cout<<"\n";
        }else if(zero==1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            bool once=false;
            for(int i=0;i<n;i++){
                if(a[i]==0){
                    if(once==false){cout<<"C";once=true;}
                    else cout<<"B";
                }else cout<<"A";
            }
            cout<<"\n";
        }
    }
    return 0;
}
/*  MY OLD LENGTHY SOLUTION THAT DIDN'T WORK (LOGICALLY INCORRECT:)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n);
        int maxm=0;
        for(int i=0;i<n;i++){cin>>a[i];if(a[i]>maxm) maxm=a[i];}
        vector<int> freq(maxm+1,0);
        vector<bool> freq3(maxm+1);
        for(int i=0;i<n;i++){freq[a[i]]++;if(freq[a[i]]>=3) freq3[a[i]]=true;}
        int j=0;
        for(j=0;j<=maxm;j++){
            if(freq[j]>=3)continue;
            else break;
        }
        bool meow=false;
        if(freq[j]==0){cout<<"YES\n";for(int i=0;i<n-1;i++)cout<<"A";cout<<"B\n";}
        else if(freq[j]==1){
            int idx=j+1;
            for(idx=j+1;idx<=maxm;idx++){
                if(freq[idx]>=3)continue;
                else break;
            }
            if(idx<=2*j){
                cout<<"YES\n";
                meow=true;
            }else cout<<"NO\n";
        }else if(freq[j]==2){
            int idx1=j+1;
            for(idx1=j+1;idx1<=maxm;idx1++){
                if(freq[idx1]>=2)continue;
                else break;
            }
            if(freq[idx1]==0){
                cout<<"YES\n";
                meow=true;
            }else if(freq[idx1]==1){
                int idx2=idx1+1;
                for(idx2=idx1+1;idx2<=maxm;idx2++){
                    if(freq[idx2]==0)break;
                }
                if(idx2>=j+idx1){
                    cout<<"YES\n";
                    meow=true;
                }else cout<<"NO\n";
            }
        }
        if(meow==true){
            vector<char>x(maxm+1,'A');
            for(int i=0;i<n;i++){
                if(freq[a[i]]>0){
                    cout<<x[a[i]];
                    x[a[i]]++;freq[a[i]]--;
                    if(x[a[i]]>='D')x[a[i]]='A';
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}
*/