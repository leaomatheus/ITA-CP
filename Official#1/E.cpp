#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

int N, Tmax;
pair<ii,int> vec[105];
pair<long long, long long> pd[105][1005];
bool reachable[105][1005];
int prv[105][1005];

bool comp(const pair<ii,int>&a, const pair<ii,int>&b) {
	int pa = a.first.second, pb = b.first.second;
	int ta = a.first.first, tb = b.first.first;
	return pb*ta < pa*tb;
}

int main() {
	scanf("%d %d", &N, &Tmax);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &vec[i].first.first, &vec[i].first.second);
		vec[i].second = i+1;
	}

	sort(vec, vec + N, comp);

	for (int i = 0; i <= N; i++) {	
		reachable[i][0] = true;
		prv[i][0] = -1;

		for (int t = 0; t <= Tmax; t++) {
			if (!reachable[i][t]) continue;

			int newt = t + vec[i].first.first;
			if (newt > Tmax) continue;
			long long et = pd[i][t].first + 1LL*newt*vec[i].first.second;
			long long ep = pd[i][t].second + vec[i].first.second;

			for (int j = i+1; j <= N; j++) {
				if (ep > pd[j][newt].second || (ep == pd[j][newt].second && et < pd[j][newt].first)) {
					pd[j][newt] = make_pair(et, ep);
					prv[j][newt] = i;
					reachable[j][newt] = true;
				}
			}
		}
	}

	int best = 0;
	for (int t = 0; t <= Tmax; t++) {
		if (reachable[N][t]) {
			if (pd[N][t].second > pd[N][best].second || (pd[N][t].second == pd[N][best].second &&
				pd[N][t].first < pd[N][best].first)) {
				best = t;
			}
		}
	}
	
	vector<int> sol;
	int v = prv[N][best];

	while(v != -1) {
		sol.push_back(vec[v].second);
		best = best - vec[v].first.first;
		v = prv[v][best];
	}
	reverse(sol.begin(), sol.end());

	printf("%d\n", (int)sol.size());
	for (int i = 0; i < (int)sol.size(); i++) {
		if (i > 0) printf(" ");
		printf("%d", sol[i]);
	}
	printf("\n");
	return 0;
}