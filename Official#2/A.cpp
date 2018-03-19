#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vi;

int main(){
   ll N; cin >> N;
   vi D(N+1, 0);
   for(ll i = 1; i <= N; i++) cin >> D[i];
   sort(D.begin(), D.end());
   ll ans = 0;
   for(ll i = 1; i <= N; i++){
      if(D[i] > i) ans += min(D[i] - i, N - i);
   }
   ans *= 2;
   cout << ans << endl;
}