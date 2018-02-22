// https://vjudge.net/problem/LightOJ-1205

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

ll va, vb;
ll dp[20][20][3][2];
ll pot10[20];

int get(ll val, int d) {
	return (val/pot10[d])%10;
}
// 0 = equal, 1 = less, 2 = more
ll calc(int st, int en, int sit, int flag) {
	if (st > en) {
		if (sit == 2) return 0;
		return 1;
	}

	ll& ans = dp[st][en][sit][flag];
	if (ans >= 0) return ans;

	ans = 0;
	
	ll maxDigit = get(va, en), minDigit = get(va, st);

	if (flag == 0) ans += calc(st, en-1, maxDigit > 0 ? 1 : sit, 0);
	for (int i = 0; i <= 9; i++) {
		if (flag == 0 && i == 0) continue;
		if (sit == 1) { ans += calc(st+1, en-1, 1, flag|(i != 0)); continue; }

		if (i < maxDigit) ans += calc(st+1, en-1, 1, flag|(i != 0));
		if (i == maxDigit && i < minDigit) ans += calc(st+1, en-1, sit == 2 ? 0 : sit, flag|(i != 0));
		if (i == maxDigit && i == minDigit) ans += calc(st+1, en-1, sit, flag|(i!=0));
		if (i == maxDigit && i > minDigit) ans += calc(st+1, en-1, sit == 0 ? 2 : sit, flag|(i != 0));
	}
//	cout << st << " " << en << " " << sit << " " << flag << " " << dp[st][en][sit][flag] << endl;
	return ans;
}

int main() {
	int t;
	cin >> t;
	pot10[0] = 1;
	for (int i = 1; i <= 18; i++) pot10[i] = 10LL*pot10[i-1];

	FOR1e(casos, t) {
		cin >> va >> vb;

		if (va > vb) swap(va, vb);
		memset(dp, -1, sizeof(dp));
		va--;

		ll a;
		if (va < 0) { va = 0; a = calc(0, 18, 0, 0) - 1; }
		else a = calc(0, 18, 0, 0);
		
		va = vb;
		memset(dp, -1, sizeof(dp));	
		ll b = calc(0, 18, 0, 0);
		cout << "Case " << casos << ": " << b-a << endl;
	}
}