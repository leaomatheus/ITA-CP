// http://www.spoj.com/problems/GONE/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 300009
#define MAXM 320
#define MOD 1000000007
#define INF 1000000009
#define FOR(x,n) for(int x=0; x<n; x++)
#define FOR1e(x,n) for(int x=1; x<=n; x++)
typedef pair<int, int> ii;
typedef long long ll;

int dp[11][200][2];
bool isPrime[200];
char w[20];

// digito, soma, 
// 345
// 1---- (false)
// 3---- (true)

int cnt(int digit, int t, int sum, int less) {
	if (digit == t) {
		return (!less && isPrime[abs(sum)]) ? 1 : 0;
	}
	int& ans = dp[digit][sum][less];
	if (ans >= 0) return ans;
	
	ans = 0;
	int maxV = (less == 0) ? 9 : (w[digit]-'0');
	for (int i = 0; i <= maxV; i++) {
		ans += cnt(digit+1, t, sum + i, less&(maxV == i));
	}
	return ans;
}

int calc(int val) {
	sprintf(w, "%d", val);
	int n = strlen(w);
	memset(dp, -1, sizeof(dp));
	return cnt(0, n, 0, 1);
}

int main() {
	for (int i = 2; i <= 200; i++) {
		bool p = true;
		for (int k = 2; k*k <= i; k++) {
			if (i%k == 0) p = false;
		}
		if (p) isPrime[i] = true;
	}
	int t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", calc(b+1) - calc(a));
	}
}