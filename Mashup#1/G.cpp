#include <bits/stdc++.h>
using namespace std;
#define MAXN 100009

vector<int> g[MAXN];
int parent[MAXN][20];
int h[MAXN], score[MAXN], acum[MAXN];

void dfs(int u, int p, int lvl) {
    h[u] = lvl+1;
    parent[u][0] = p;

    for (int k = 1; k < 20; k++) {
        if (parent[u][k-1]) parent[u][k] = parent[parent[u][k-1]][k-1];
    }

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v != p) {
            dfs(v, u, lvl+1);
        }
    }

    return;
}

int lca(int a, int b) {
    if (h[a] < h[b]) swap(a,b);
    
    for (int k = 19; k >= 0; k--) {
        if (h[parent[a][k]] >= h[b]) a = parent[a][k];
    }

    if (a == b) return a;
    for (int k = 19; k >= 0; k--) {
        if (parent[a][k] != parent[b][k]) { a = parent[a][k]; b = parent[b][k]; }
    }
    return parent[a][0];
}

vector<pair<int,int> > edges;

int compute(int u, int p) {
    acum[u] = score[u];

    for (int i = 0; i < (int)g[u].size(); i++) {
        int v = g[u][i];
        if (v != p) {
            int tmp = compute(v, u);
            acum[u] += tmp;
        }
    }
    return acum[u];
}

int main() {
    int n, a, b;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        edges.push_back(make_pair(a,b));
    }

    h[0] = 0;
    dfs(1, 0, 0);
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &a, &b);
        int p = lca(a, b);
        score[p] -= 2;
        score[a]++; score[b]++;
    }

    compute(1, 0);
    for (int i = 0; i < n-1; i++) {
        if (parent[edges[i].first][0] == edges[i].second) printf("%d ", acum[edges[i].first]);
        else printf("%d ", acum[edges[i].second]);
    }
    printf("\n");
}