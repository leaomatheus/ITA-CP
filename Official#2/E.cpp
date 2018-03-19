#include <bits/stdc++.h>
using namespace std;
#define MAXN 200009
typedef long long int ll;

int p1[MAXN], p2[MAXN];

int main(){
	int n, r, x, y, cx, cy;
	ll score = 0;
	scanf("%d %d", &n, &r);
	for (int i = 1; i < r; i++) {
		scanf("%d %d %d %d", &x, &y, &cx, &cy);
		if (p1[cx] == 0) {
			p1[cx] = x;
		} else if (p1[cx] != x) {
			p2[cx] = x;
		}

		if (p1[cy] == 0) {
			p1[cy] = y;
		} else if (p1[cy] != y) {
			p2[cy] = y;
		}

		if (cx == cy) { score = max(score, 1LL*cx); }
	}

	double ans = 0, rnd = 0, prob = 0;

	int opn = 0;
	for (int i = 1; i <= n; i++) {
		if (p1[i] > 0 && p2[i] > 0) ans = max(ans, i*1.0);
		if (p1[i] > 0) opn++;
		if (p2[i] > 0) opn++;
	}

	for (int i = score + 1; i <= n; i++) {
		if (p1[i] > 0 && p2[i] == 0) {
			ans = max(ans, 1.0*i/(2*n-opn) + 1.0*score/(2*n-opn) * (2*n-opn-1));
		} else if (p1[i] == 0 && p2[i] == 0) {
			rnd += 2.0*i/(2*n - opn) * 1.0/(2*n - opn - 1);
			prob += 2.0/(2*n - opn) * 1.0/(2*n - opn - 1);
		}
	}

	printf("%.10lf\n", max(ans, rnd + (1 - prob)*score));
	return 0;
}