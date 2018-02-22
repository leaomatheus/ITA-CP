// http://www.spoj.com/problems/RAONE/

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

int dp[11][200];

int cnt(int digit, int sum) {
	if (digit == 0) {
		return (sum == 1) ? 1 : 0;
	}
	if (dp[digit][sum+100] >= 0) return dp[digit][sum+100];
	int& ans = dp[digit][sum+100];

	ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans += cnt(digit-1, sum + (digit%2 ? -i : i));
	}
	return ans;
}

int calc(int val) {
	int ans = 0;
	int sum = 0;

	char w[20];
	sprintf(w, "%d", val);
	int n = strlen(w);
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) {
		int digit = w[i] - '0';
		for (int d = 0; d < digit; d++) {
			sum += (n-i)%2 ? -d : d;
			ans += cnt(n-i-1, sum);
			sum -= (n-i)%2 ? -d : d;
		}
		sum += (n-i)%2 ? -digit : digit;
	}
	return ans;
}
int main() {
	int t, a, b;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", calc(b+1) - calc(a));
	}
}