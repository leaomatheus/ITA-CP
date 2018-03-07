#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define cl(x, v) memset((x), (v), sizeof(x))
#define gcd(x,y) __gcd((x),(y))
#define FOR(x,n) for(int x=0; x<n; x++)
#define FOR1e(x,n) for(int x=1; x<=n; x++)

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f, MOD = 1e9+7;
const int N = 3e2+5;

int n, m;
int dp[N][N];
int v[N];

int go(int a, int b) {
  if (a > b) return 0;
  if (a == b) return 1;
  if (dp[a][b] >= 0) return dp[a][b];

  int& ans = dp[a][b];
  ans = INF;
  for (int i = a; i <= b; i++) {
  	if (v[i] == v[a]) ans = min(ans, go(a+1, i-1) + go(i, b));
  }
  ans = min(ans, 1 + go(a+1, b));
  ans = min(ans, 1 + go(a, b-1));

  return ans;
}

int main() {
  scanf("%d%d", &n, &m);

  int sz = 0, tmp;
  for (int i = 0; i < n; i++) {
  	scanf("%d", &tmp);
  	if (sz == 0 || tmp != v[sz-1]) v[sz++] = tmp;
  }

  cl(dp, -1);
  printf("%d\n", go(0, sz-1)-1);

  return 0;
}