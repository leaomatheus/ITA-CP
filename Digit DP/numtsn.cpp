// http://www.spoj.com/problems/NUMTSN/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 59
#define MAXM 320
#define MOD 1000000007
#define INF 1000000009
#define FOR(x,n) for(int x=0; x<n; x++)
#define FOR1e(x,n) for(int x=1; x<=n; x++)
typedef pair<int, int> ii;
typedef long long ll;

int dp[MAXN][MAXN][MAXN][MAXN];

int cnt(int digit, int t, int s, int n) {
	if (digit == 0) {
		return (t >= 1 && s == t && s == n) ? 1 : 0;
	}
	int& ans = dp[digit][t][s][n];
	if (ans >= 0) return ans;
	
	ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += cnt(digit-1, t + (i == 3), s + (i == 6), n + (i == 9));
		ans %= MOD;
	}
	return ans;
}

int calc(const char *w, bool inclusive) {
	int ans = 0;
	int three = 0, six = 0, nine = 0;

	int n = strlen(w);

	for (int i = 0; i < n; i++) {
		int digit = w[i] - '0';
		for (int d = 0; d < digit; d++) {
			three += (d == 3); six += (d == 6); nine += (d == 9);
			
			ans += cnt(n-i-1, three, six, nine);
			ans %= MOD;
			three -= (d == 3); six -= (d == 6); nine -= (d == 9);
		}
		three += (digit == 3); six += (digit == 6); nine += (digit == 9);
	}
	if (inclusive && three >= 1 && three == six && three == nine) ans++;

	return ans;
}
int main() {
	int t, a, b;
	scanf("%d", &t);
	
	memset(dp, -1, sizeof(dp));

	char w[100];
	while(t--) {
		scanf("%s", w);
		int ans = (MOD - calc(w, false))%MOD;
		scanf("%s", w);
		ans = (ans + calc(w, true))%MOD;
		printf("%d\n", ans);
	}
}