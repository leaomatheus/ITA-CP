#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

set<pair<int, int> > sum;
pair<int,int> val[1009];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &val[i].first, &val[i].second);
	
	if (n <= 3) printf("0\n");
	else {
		bool f = false;
		for (int i = 0; i < n && !f; i++) {
			for (int j = i+1; j < n && !f; j++) {
				if (sum.find(ii(val[i].first+val[j].first, val[i].second + val[j].second)) != sum.end()) { f= true; }
				sum.insert(ii(val[i].first+val[j].first, val[i].second + val[j].second));
			}
		}
		if (f) printf("1\n");
		else printf("2\n");
	}
}