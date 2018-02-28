#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

// first for h, than s

bool comp(ii a, ii b){
   return 1LL*b.second * a.first < 1LL*a.second * b.first;
}

int main(){
   int N; cin >> N;
   vii p(N, ii(0,0));
   ll ans = 0;
   for(int i = 0; i < N; i++){
      string str; cin >> str;
      for(int j = 0; j < str.size(); j++)
         if(str[j] == 'h') {
            p[i].first++;
            ans += p[i].second;
         }
         else p[i].second++;
   }
   sort(p.begin(), p.end(), comp);
   int countS = p[0].second;
   for(int i = 1; i < N; i++){
      ans += countS * p[i].first;
      countS += p[i].second;
   }
   cout << ans << endl;
}