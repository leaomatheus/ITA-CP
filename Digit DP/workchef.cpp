// https://www.codechef.com/problems/WORKCHEF
// Codechef July16

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

const int mod = 5*7*8*9;
ll dp[20][2][2][1 << 9][mod];
ll va, vb, c[20];

int cnt[1 << 9];
int memo[1 << 9][mod];

int K;

int get(int d, ll val) {
	val /= c[d];
	return val%10;
}

ll calc(int d, int moreA, int lessB, int mask, int rem) {
	if (cnt[mask] + d + 1 < K) return 0;

	if (d == -1) {
		int &ans = memo[mask][rem];
		if (ans >= 0) return ans;

		int vc = 0;
		for (int i = 0; i < 9; i++) {
			if (((1 << i)&mask) && rem%(i+1) == 0) vc++;
			if (vc >= K) return ans = 1;
		}
		return ans = 0;
	}

	ll& ans = dp[d][moreA][lessB][mask][rem];
	if (ans >= 0) return ans;

	int maxV = lessB ? 9 : get(d, vb);
	int minV = moreA ? 0 : get(d, va);
	
	ans = 0;
	for (int i = minV; i <= maxV; i++) {
		if (i == 0)	ans += calc(d-1, moreA | (i > minV), lessB | (i < maxV), mask, (1LL*i*c[d] + rem)%mod);
		else ans += calc(d-1, moreA | (i > minV), lessB | (i < maxV), mask | (1 << (i-1)), (1LL*i*c[d] + rem)%mod);
	}
//	cout << d << " " << moreA <<  " " <<lessB <<  " " <<mask << " " << rem << " " << ans << endl;

	return ans;
}

int main() {
	int q;
	scanf("%d", &q);
	c[0] = 1LL;
	for (int i = 1; i <= 18; i++) {
		c[i] = 10LL*c[i-1];
	}
	for (int i = 0; i < (1 << 9); i++) {
		cnt[i] = 0;
		for (int k = 0; k < 9; k++) {
			if (i&(1 << k)) cnt[i]++;
		}
	}
	while (q--) {
		scanf("%lld %lld %d", &va, &vb, &K);
		memset(memo, -1, sizeof(memo));
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", calc(18, 0, 0, 0, 0));
	}
}