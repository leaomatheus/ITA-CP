// http://codeforces.com/gym/100886/problem/G
// 2015-2016 Petrozavodsk Winter Training Camp, Saratov SU Contest

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

ll dp[20][2][2][2];
ll va, vb, c[20];

int get(int d, ll val) {
	val /= c[d];
	return val%10;
}

ll calc(int d, int moreA, int lessB, int nonZero) {
	if (d == -1) return 1LL;
	ll& ans = dp[d][moreA][lessB][nonZero];
	if (ans >= 0) return ans;

	int maxV = lessB ? 9 : get(d, vb);
	int minV = moreA ? 0 : get(d, va);
	
	ans = 0;
	for (int i = minV; i <= maxV; i++) {
		ll f = 1;
		if (nonZero || (i > 0)) f = i;
		ans = max(ans, 1LL*f*calc(d-1, moreA | (i > minV), lessB | (i < maxV), nonZero | (i > 0)));
	}
	return ans;
}

void reconstruct(int d, int moreA, int lessB, int nonZero) {
	if (d == -1) return;

	int maxV = lessB ? 9 : get(d, vb);
	int minV = moreA ? 0 : get(d, va);
	
	for (int i = minV; i <= maxV; i++) {
		ll f = 1;
		if (nonZero || (i > 0)) f = i;
		ll val = 1LL*f*calc(d-1, moreA | (i > minV), lessB | (i < maxV), nonZero | (i > 0));

		if (val == calc(d, moreA, lessB, nonZero)) {
			if (nonZero || (i > 0)) cout << i;
			reconstruct(d-1, moreA | (i > minV), lessB | (i < maxV), nonZero | (i > 0));
			return;
		}
	}
}
int main() {
	cin >> va >> vb;

	c[0] = 1;
	for (int i = 1; i <= 18; i++) {
		c[i] = c[i-1]*10LL;
	}

	memset(dp, -1, sizeof(dp));
	calc(18, 0, 0, 0);
	reconstruct(18, 0, 0, 0);
	cout << endl;
}
