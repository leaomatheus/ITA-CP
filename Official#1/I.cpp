#include <bits/stdc++.h>
using namespace std;
#define MAXN 1009
#define ft first
typedef pair<int,int> ii;

pair<ii, int> x[MAXN], y[MAXN];
int prv[MAXN], n, ult;
bool possible[MAXN];

bool check(pair<ii, int> vec[], int& a, int& b, int desired) {
	if (vec[a].ft.first > vec[b].ft.first) swap(a,b);
	if (vec[a].ft.second > vec[b].ft.first) return false;
	
	sort(vec, vec+n);
	
	int index = -1;
	for (int i = index+1; i < n; i++) prv[i] = -1;
	memset(possible, 0, sizeof(possible));
	for (int i = 0; i < n; i++) {
		if (vec[i].ft.first == 0) {
			possible[i] = true; prv[i] = -1;
		}
		if (vec[i].second == a) { index = i; break; }
		if (!possible[i]) continue;
		
		for (int j = i+1; j < n; j++) {
			if (vec[i].ft.second == vec[j].ft.first) {
				possible[j] = true; prv[j] = i;
			}
		}
	}
	
	if (!possible[index]) return false;
	
	for (int i = index+1; i < n; i++) prv[i] = -1;
	memset(possible, 0, sizeof(possible));
	for (int i = index; i < n; i++) {
		if (vec[i].second == a) { possible[i] = true; }	
		if (vec[i].second == b) { index = i; break; }
		if (!possible[i]) continue;
		
		for (int j = i+1; j < n; j++) {
			if (vec[i].ft.second == vec[j].ft.first) {
				possible[j] = true; prv[j] = i;
			}
		}
	}
	if (!possible[index]) return false;
	
	for (int i = index+1; i < n; i++) prv[i] = -1;
	memset(possible, 0, sizeof(possible));
	for (int i = index; i < n; i++) {
		if (vec[i].second == b) { possible[i] = true; }
		if (!possible[i]) continue;

		if (vec[i].ft.second == desired) { ult = i; return true; }
		
		for (int j = i+1; j < n; j++) {
			if (vec[i].ft.second == vec[j].ft.first) {
				possible[j] = true; prv[j] = i;
			}
		}
	}
	return false;
}

int main() {
	int X, Y;
	scanf("%d %d %d", &X, &Y, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &x[i].first.first, &y[i].first.first, &x[i].first.second, &y[i].first.second);
		x[i].second = i;
		y[i].second = i;
	}
	
	int index[2];
	vector<int> sol;
	scanf("%d %d", &index[0], &index[1]);
	index[0]--; index[1]--;
	
	if (check(x, index[0], index[1], X)) {
		while (ult != -1) {
			sol.push_back(x[ult].second);
			ult = prv[ult];
		}
		reverse(sol.begin(), sol.end());
		
		printf("%d\n", (int)sol.size());
		for (int i = 0; i < (int)sol.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", sol[i]+1);
		}
	} else if (check(y, index[0], index[1], Y)) {
		while (ult != -1) {
			sol.push_back(y[ult].second);
			ult = prv[ult];
		}
		reverse(sol.begin(), sol.end());
		
		printf("%d\n", (int)sol.size());
		for (int i = 0; i < (int)sol.size(); i++) {
			if (i > 0) printf(" ");
			printf("%d", sol[i]+1);
		}
	}else printf("-1");
	printf("\n");
}