#include <bits/stdc++.h>
using namespace std;

map<string, int> cnt;
vector<string> A, B;

int main() {
	int n, pr = 0;
	cin >> n;
	while (n--) {
		string team, nome;
		cin >> team >> nome;
		if (pr >= 10) continue;
		if (team == "SCH") continue;
		if (team == "MSU" && cnt[team] < 4) {
			cnt[team] += 1;
			pr++;
			A.push_back(team); B.push_back(nome);
		} else if (team != "MSU" && cnt[team] < 2) {
			cnt[team] += 1;
			pr++;
			A.push_back(team); B.push_back(nome);
		}
	}
	cout << A.size() << endl;
	for (int i = 0; i < (int)A.size(); i++) {
		cout << A[i] << " " << B[i] << endl;
	}
	return 0;
}