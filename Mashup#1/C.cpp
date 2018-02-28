#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define sz(x) x.size()

typedef long long ll;
using namespace std;

int trie[100009][26], cnt = 0;

int add(int p, int l) {
    if (trie[p][l] == 0) trie[p][l] = ++cnt;
    return trie[p][l];
}

bool dfs(int p) {
    for(int i = 0; i < 26; i++) {
        if (trie[p][i] != 0 && !dfs(trie[p][i])) {
            return true;
        }
    }
    return false;
}

bool dfs2(int p) {
    bool leaf = true;
    for (int i = 0; i < 26; i++) {
        if (trie[p][i] != 0) leaf = false;
    }
    if (leaf) { return true; }
    
    for (int i = 0; i < 26; i++) {
        if (trie[p][i] != 0 && !dfs2(trie[p][i])) return true;
    }
    return false;
}
char w[100009];
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%s", w);
        
        int r = 0;
        for (int j = 0; w[j]; j++) {
            r = add(r, w[j]-'a');
        }
    }
    bool a = dfs(0), b = dfs2(0);
    if (a && !b) puts(k%2 ? "First" : "Second");
    if (!a && b) puts("Second");
    if (a && b) { puts("First"); }
    if (!a && !b) { puts("Second"); }
    return 0;
}