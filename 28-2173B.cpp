#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; cin>>n;
        vector<int> a(n),b(n),dp1(n),dp2(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        /*
        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=max(dp[i-1]-a[i-1],b[i-1]-dp[i-1]);
        }
        cout<<dp[n]<<"\n";
        */
       // This basic DP algorithm won't work because in we have to maximise final result
       // and not intermediate results after each turn.

       // Nice thing (from editorial): Last step may be b-k or k-a
       // so accordingly, till last step we might need minimum and maximum k both, that can be found from DP
       // And in last step, b-k and k-a will be compared, maximum would be answer.
        /* IDK WHY GETTING STUCK HERE:
        dp1[0]=0;
        for(int i=1;i<=n;i++){
            dp1[i]=max(dp1[i-1]-a[i-1],b[i-1]-dp1[i-1]);
        }
        dp2[0]=0;
        for(int i=1;i<=n;i++){
            dp2[i]=min(dp2[i-1]-a[i-1],b[i-1]-dp2[i-1]);
        }
        cout<<max(dp1[n-1]-a[n-1],b[n-1]-dp2[n-1])<<"\n";
        */
       dp1[0]=max(-a[0],b[0]);
       dp2[0]=min(-a[0],b[0]);
       for(int i=1;i<n;i++){
        //dp1[i]=max(dp1[i-1]-a[i],b[i]-dp2[i-1]);
        //dp2[i]=min(dp2[i-1]-a[i],b[i]-dp1[i-1]);
       //}// MY MISTAKE: I WAS KEEPING ONLY DP1 IN BOTH COMPARED THINGS, IN THE DP1 EXPRESSION AND SIMILARLY IN DP2
       // WE RATHER HAD TO TAKE DP1, DP2 BOTH. DP1 GIVES MAXIMIZED THING AND DP2 GIVES MINIMIZED THING.
       /*BASICALLY AT A POINT WE HAD 4 OPTIONS:
       dp1[i-1]-a[i], b[i]-dp1[i-1], dp2[i-1]-a[i], b[i]-dp2[i-1]
       OUT OF THESE FOUR OPTIONS, WE NEEDED TO TAKE THE MINIMUM ONE, IN dp2 AND MAXIMUM ONE in DP1.
       WE COULD OF COURSE COMPARE ALL THESE 4 THINGS IN BOTH CASES, BUT WE ALREADY KNOW THAT 2 OUT OF THE 4 OPTIONS WILL ALREADY BE REJECTED
       IN OTHER WORDS, WE MIGHT HAD WRITTEN:*/
       dp1[i]= max({dp1[i-1]-a[i], b[i]-dp1[i-1], dp2[i-1]-a[i], b[i]-dp2[i-1]});
       dp2[i]= min({dp1[i-1]-a[i], b[i]-dp1[i-1], dp2[i-1]-a[i], b[i]-dp2[i-1]});
       }
       /*THIS WOULD WORK, BUT NOT REQUIRED.
       // And my mistake was that I was comparing the wrong 2 options out of 4 for both cases dp1 and dp2.
       */
       // cout<<max(dp1[n-2]-a[n-1],b[n-1]-dp2[n-2])<<"\n"; THIS STEP IS ALSO WRONG.
       cout<<dp1[n-1]<<"\n"; // This is the right step and above working explains the reason.
    }
    return 0;
}
/* PROPER BEST SOLUTION GIVEN IN EDITORIAL (DP AS A VECTOR NOT USED, BUT SAME THING DONE IN SMALL STRUCTURED SYNTAX)
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int mx = 0, mn = 0;
        for (int i = 0; i < n; i++) {
            int new_mx = max(mx - a[i], b[i] - mn);
            int new_mn = min(mn - a[i], b[i] - mx);
            mx = new_mx;
            mn = new_mn;
        }
        cout << mx << "\n";
    }
    return 0;
}
*/