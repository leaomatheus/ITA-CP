// https://www.codechef.com/problems/DIGIMU
// Logan and Digit Imune numbers

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

ll dp[20][315][1 << 4][2];
ll a, b, pot10[20];

int get(ll val, int d) {
	return (val/pot10[d])%10;
}

void precalc() {
	for (int sum = 0; sum < 315; sum++) {
		for (int has = 0; has < (1 << 4); has++) {
			if ((has&(1 << 0)) && sum%3 == 0) continue;
			if ((has&(1 << 1)) && sum%5 == 0) continue;
			if ((has&(1 << 2)) && sum%7 == 0) continue;
			if ((has&(1 << 3)) && sum%9 == 0) continue;
			
			dp[0][sum][has][1] = 1;
		}
	}
	for (int d = 1; d <= 19; d++) {
		for (int sum = 0; sum < 315; sum++) {
			for (int has = 0; has < (1 << 4); has++) {
				for (int isZero = 0; isZero < 2; isZero++) {
					if (!isZero) dp[d][sum][has][isZero] += dp[d-1][sum][has][isZero];
					dp[d][sum][has][isZero] += dp[d-1][(sum + 3LL*pot10[d-1])%315][has|(1 << 0)][1];
					dp[d][sum][has][isZero] += dp[d-1][(sum + 5LL*pot10[d-1])%315][has|(1 << 1)][1];
					dp[d][sum][has][isZero] += dp[d-1][(sum + 7LL*pot10[d-1])%315][has|(1 << 2)][1];
					dp[d][sum][has][isZero] += dp[d-1][(sum + 9LL*pot10[d-1])%315][has|(1 << 3)][1];
				}
			}
		}
	}
}

ll cnt(ll val) {
	ll ans = 0;

	int has = 0, sum = 0, isZero = 0;
	for (int d = 18; d >= 0; d--) {
		int digit = get(val, d);
	
		if (digit > 0 && !isZero) {
			ans += dp[d][sum][has][isZero];
		} if (digit > 3) {
			int i = 3;
			int newHas = has|(1 << 0);
			ans += dp[d][(sum + 1LL*i*pot10[d])%315][newHas][1];
		} if (digit > 5) {
			int i = 5;
			int newHas = has|(1 << 1);
			ans += dp[d][(sum + 1LL*i*pot10[d])%315][newHas][1];
		} if (digit > 7) {
			int i = 7;
			int newHas = has|(1 << 2);
			ans += dp[d][(sum + 1LL*i*pot10[d])%315][newHas][1];
		}
		
		if (digit > 0 && (digit%2 == 0 || digit == 1) ) return ans;
		if (isZero && digit == 0) return ans;

		if (digit == 0) continue;
		sum = (sum + 1LL*digit*pot10[d])%315;
		has = has|(1 << ((digit-3)/2));
		isZero = isZero|(digit != 0);
	}
	return ans;
}

ll construct(ll val, ll k) {
	ll ans = 0;
	
	int has = 0, sum = 0, isZero = 0;
	bool eq = true;
	
	for (int d = 18; d >= 0; d--) {
		int digit = eq ? get(val, d) : 9;


		for (int i = 0; i < digit; i++) {
			if (isZero && i == 0) continue;
			if (i > 0 && i%2 == 0) continue;
			if (i == 1) continue;

			int newHas = (i == 0) ? has : has|(1 << ((i-3)/2));
			ll v = dp[d][(sum + 1LL*i*pot10[d])%315][newHas][isZero|(i != 0)];
			if (v < k) { k -= v; continue; }
			
			eq = false;
			digit = i;
			break;
		}
		if (digit == 0) continue;
		ans += 1LL*digit*pot10[d];

		sum = (sum + 1LL*digit*pot10[d])%315;
		has = has|(1 << ((digit-3)/2));
		isZero = isZero|(digit != 0);
	}
	return ans;
}
int main() {
	ll k;

	pot10[0] = 1;
	for (int i = 1; i <= 18; i++) pot10[i] = pot10[i-1]*10;
	int t;
	cin >> t;

	precalc();
	while (t--) {
		cin >> a >> b >> k;
		b++;
		ll ca = cnt(a), cb = cnt(b);
	//	cout << ca << " finished " << cb << endl;
		if (cb-ca < k) cout << -1 << endl;
		else cout << construct(b, k+ca) << endl;
	}
}