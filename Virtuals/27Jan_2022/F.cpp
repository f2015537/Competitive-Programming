#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
    int n; cin>>n;
    vector<int> h(n+1),dp(n+1,1e9);
    for(int i = 1; i <= n; ++i) cin>>h[i];
    dp[1] = 0;
    for(int i = 2; i <= n; ++i){
      dp[i] = min(dp[i], dp[i-1] + abs(h[i]-h[i-1]));
      if(i-2>=1)  dp[i] = min(dp[i], dp[i-2] + abs(h[i]-h[i-2]));            
    }
  cout<<dp[n];
} 