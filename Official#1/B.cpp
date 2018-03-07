#include <bits/stdc++.h>
using namespace std;

int f, a, b, c, m, n, z;
map<int, int> mm;
vector<pair<int, int>> v, fs;
int ans[250*250*2];

int main() {
  scanf("%d%d%d%d", &f, &a, &b, &c);
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &z),
      mm[z]++;

  for (int i = 0; i < mm.size(); i++) {
    fs.push_back({ f, i });
    f = (a*f + b)%c+1;
  }

  for (auto x : mm)
    v.push_back({ x.second, x.first });

  sort(fs.begin(), fs.end());
  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++) {
    ans[fs[i].second] = v[i].second;
  }

  printf("%d\n", (int)v.size());
  for (int i = 0; i < v.size(); i++)
    printf("%d ", ans[i]);
  printf("\n");

  return 0;
}