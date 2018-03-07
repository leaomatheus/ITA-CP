#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000000LL
#define FOR(x,n) for(int x = 0; x < n; x++)
typedef pair<int,int> ii;
typedef long long ll;

ll dist[100][100];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	FOR(x,n) {
		FOR(y,n) {
			dist[x][y] = INF;
		}
	}
	FOR(x, n) {
		dist[x][x] = 0;
	}
	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--; c;
		dist[a][b] = min(dist[a][b], 1LL*c);
		dist[b][a] = dist[a][b];
	}
	FOR(k,n) {
		FOR(i,n) {
			FOR(j,n) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	ll minBFG = INF, minUp = 0;
	FOR(i, n) {
		FOR(j, n) {
			ll BFG = 0;
			FOR(a, n) {
				FOR(b, n) {
					BFG = max(BFG, min(dist[a][b], min(dist[a][i] + dist[j][b], dist[a][j] + dist[i][b])));
				}
			}
			ll up = INF;
			FOR(a, n) {
				FOR(b, n) {
					if (dist[a][b] <= BFG) continue;
					else {
						up = min(up, BFG-min(dist[a][i] + dist[j][b], dist[a][j] + dist[i][b]));
					}
				}
			}
			if (BFG < minBFG) {
				minBFG = BFG; minUp = up;
			} else if (BFG == minBFG) {
				minUp = max(minUp, up);
			}
		}
	}
	
	printf("%lld %lld\n", (minBFG >= INF) ? -1 : minBFG, (minUp >= INF) ? -1 : minUp);
}