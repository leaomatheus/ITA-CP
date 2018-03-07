#include <bits/stdc++.h>
using namespace std;

vector<int> building;
int main() {
	int n, m, v;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n*m; i++) {
		scanf("%d", &v);
		building.push_back(v);
	}
	sort(building.begin(), building.end());
	if (n < m) swap(n, m);
	
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 2*i+1; j++) {
			if (i == 0) ans += 2*building.back();
			if (j == 0 || j == i) ans += 2*building.back();
			building.pop_back();
		}
	}
	for (int i = 0; i < (n-m); i++) {
		ans += 2*building.back();
		for (int j = 0; j < m; j++) building.pop_back();
	}
	printf("%lld\n", ans);
}