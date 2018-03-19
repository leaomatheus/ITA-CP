#include <bits/stdc++.h>
using namespace std;
#define MAXN 200009
typedef long long int ll;

int main() {
	int x[2], y[2], r[2];
	for (int i = 0; i < 2; i++) scanf("%d %d %d", &x[i], &y[i], &r[i]);
	if (r[0] > r[1]) { swap(x[0], x[1]); swap(y[0], y[1]); swap(r[0], r[1]); }
	
	if (hypot(x[0] - x[1], y[0] - y[1]) <= 1.0*min(r[0], r[1])) {
		printf("%d %d\n", x[0], y[0]); return 0;
	}

	double dx, dy, xi, yi;

	dx = 1.0*(x[1] - x[0]) / hypot(x[1] - x[0], y[1] - y[0]);
	dy = 1.0*(y[1] - y[0]) / hypot(x[1] - x[0], y[1] - y[0]);

	printf("%.6lf %.6lf\n", x[0] + dx*r[0], y[0] + dy*r[0]);
}