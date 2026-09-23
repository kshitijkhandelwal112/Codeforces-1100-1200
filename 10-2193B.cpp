#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        sort(a.begin(),a.end());
        vector<long long int> pfsum(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=b[i];
            pfsum[i]=sum;
        }
        vector<long long> score;
        for(int i=0;i<n;i++){
            long long x = a[i];
            long long available = n-i;
            auto k = upper_bound(pfsum.begin(),pfsum.end(),available);
            long long z = (k!=pfsum.end() ? (k-pfsum.begin()):n);
            score.push_back(1LL*x*z); // Learnt new thing, 1LL is used for typecasting within a calculation.
        }
        auto w = max_element(score.begin(),score.end());
        long long m = *w;
        cout<<m<<"\n";
    }
    return 0;
}
/* BEST SOLUTION GIVEN BY CLAUDE
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end()); // ascending strengths

        vector<long long> pfsum(n + 1, 0); // pfsum[k] = b[0] + ... + b[k-1]
        for (int i = 0; i < n; i++) pfsum[i + 1] = pfsum[i] + b[i];

        long long best = 0;
        int z = n; // max levels affordable with current "available" swords
        for (int i = 0; i < n; i++) {
            long long available = n - i; // swords with strength >= a[i]
            while (z > 0 && pfsum[z] > available) z--;
            best = max(best, (long long)a[i] * z);
        }

        cout << best << "\n";
    }
    return 0;
}
*/