// http://www.spoj.com/problems/LOTGAME/
// Google Code Jam 2014 Round 1B

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

ll dp[MAXN][2][2][2];
int t, a, b, k;

ll cnt(int digit, int lessA, int lessB, int lessK) {
	if (digit == -1) {
		if (lessA == 0 && lessB == 0 && lessK == 0) return 1;
		return 0;
	}
	ll& ans = dp[digit][lessA][lessB][lessK];
	if (ans >= 0) return ans;
	
	ans = 0;
	// 0, 0, 0
	ans += cnt(digit-1, lessA&(((1 << digit)&a) == 0), lessB&(((1 << digit)&b) == 0), lessK&(((1 << digit)&k) == 0));
	// 0, 1, 0
	if (!lessB || ((1 << digit)&b))
		ans += cnt(digit-1, lessA&(((1 << digit)&a) == 0), lessB, lessK&(((1 << digit)&k) == 0));
	// 1, 0, 1
	if (!lessA || ((1 << digit)&a))
		ans += cnt(digit-1, lessA, lessB&(((1 << digit)&b) == 0), lessK&(((1 << digit)&k) == 0));
	// 1, 1, 1
	if ((!lessA || ((1 << digit)&a)) && (!lessB || ((1 << digit)&b)) && (!lessK || ((1 << digit)&k)))
		ans += cnt(digit-1, lessA, lessB, lessK);
	return ans;
}

int main() {
	scanf("%d", &t);
	
	memset(dp, -1, sizeof(dp));

	FOR1e(cases, t) {
		scanf("%d %d %d", &a, &b, &k);
		
		memset(dp, -1, sizeof(dp));		
		printf("Case #%d: %lld\n", cases, cnt(30, 1, 1, 1));
	}
}