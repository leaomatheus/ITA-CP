#include <bits/stdc++.h>
using namespace std;

char str[205], tmp[205], tmp2[205], checkstr[205];
set<string> printed;

int get_value(int ini, int fim) {
	int i = ini, val = 0;
	while (i < fim) {
		if (i < fim-1 && tmp2[i] == 'I' && tmp2[i+1] == 'V') {
			val += 4; i += 2;
		} else if (i < fim-1 && tmp2[i] == 'I' && tmp2[i+1] == 'X') {
			val += 9; i += 2;
		} else if (i < fim-1 && tmp2[i] == 'X' && tmp2[i+1] == 'L') {
			val += 40; i += 2;
		} else if (tmp2[i] == 'I') { val += 1; i++; }
		else if (tmp2[i] == 'V') { val += 5; i++; }
		else if (tmp2[i] == 'X') { val += 10; i++; }
		else if (tmp2[i] == 'L') { val += 50; i++; }
	}
	return val;
}

int get_str(int val) {
	if (val >= 90) return 0;

	int sz = 0;
	while (val > 0) {
		if (val >= 50) {
			val -= 50;
			checkstr[sz++] = 'L';
		} else if (val >= 40) {
			val -= 40;
			checkstr[sz++] = 'X'; checkstr[sz++] = 'L';
		} else if (val >= 10) {
			val -= 10;
			checkstr[sz++] = 'X';
		} else if (val >= 9) {
			val -= 9;
			checkstr[sz++] = 'I'; checkstr[sz++] = 'X';
		} else if (val >= 5) {
			val -= 5;
			checkstr[sz++] = 'V';
		} else if (val >= 4) {
			val -= 4;
			checkstr[sz++] = 'I'; checkstr[sz++] = 'V';
		} else if (val >= 1) {
			val -= 1;
			checkstr[sz++] = 'I';
		}
	}
	return sz;
}

bool bad_str;
int evaluate(int ini, int fim, bool inverted = false) {
	int mid = -1;
	for (int i = ini; i < fim; i++) {
		if (tmp2[i] != '+' && tmp2[i] != '-') continue;
		mid = i; break;
	}

	int ans = 0;
	if (mid >= 0 && tmp2[mid] == '+') ans += evaluate(mid+1, fim);
	else if (mid >= 0 && tmp2[mid] == '-') ans += evaluate(mid+1, fim, true);
	else mid = fim;

	// evaluate from 0 to mid
	int v = get_value(ini, mid);
	int t = get_str(v);
	if (t != mid-ini) { bad_str = true; return -1; }
	for (int i = 0; i < t; i++) {
		if (checkstr[i] != tmp2[ini+i]) { bad_str = true; return -1; }
	}

	if (inverted) ans -= v;
	else ans += v;
	return ans; 
}

void check2(int sz) {
	int sz2 = 0;
	for (int i = 0; i < sz; i++) {
		if (str[i] == ' ') continue;
		tmp2[sz2++] = str[i];
	}
	tmp2[sz2] = '\0';
	//printf("--%s\n", tmp2);

	int eqpos = -1;
	for (int i = 0; i < sz2; i++) {
		if (tmp2[i] != '+' && tmp2[i] != '-' && tmp2[i] != '=') continue;
		if (i == 0 || i == sz2 - 1) return;

		if ((tmp2[i-1] == '+' || tmp2[i-1] == '-' || tmp2[i-1] == '=') ||
			(tmp2[i+1] == '+' || tmp2[i+1] == '-' || tmp2[i+1] == '=')) return;

		if (tmp2[i] == '=') {
			if (eqpos != -1) return;
			eqpos = i;
		}
	}
	if (eqpos == -1) return;

	bad_str = false;
	int a = evaluate(0, eqpos), b = evaluate(eqpos+1, sz2);
	if (a != b) return;
	if (bad_str) return;

	if (printed.find(tmp2) != printed.end()) return;
	printf("%s\n", tmp2);
	printed.insert(tmp2);
}

void check(int sz) {
	for (int i = 0; i < sz; i++) {
		if (str[i] == 'I') {
			str[i] = '+'; check2(sz); str[i] = 'I';
			str[i] = 'L'; check2(sz); str[i] = 'I';
		} else if (str[i] == '-') {
			str[i] = '='; check2(sz); str[i] = '-';
			str[i] = '+'; check2(sz); str[i] = '-';
		} else if (str[i] == ' ') {
			str[i] = 'I'; check2(sz); str[i] = ' ';
			str[i] = '-'; check2(sz); str[i] = ' ';
		}
	}
}

int main() {
	scanf("%s", tmp);
	int n = strlen(tmp);

	int sz = 1; str[0] = ' ';
	for(int i = 0; i < n; i++) {
		str[sz++] = tmp[i]; str[sz++] = ' ';
	}
	str[sz] = '\0';
	for (int i = 0; i < sz; i++) {
		if (str[i] == ' ') continue;
		memcpy(tmp, str, sizeof(str));

		if (str[i] == 'L') {
			str[i] = 'I'; check(sz);
		} else if (str[i] == '+') {
			str[i] = '-'; check(sz);
			str[i] = 'I'; check(sz);
		} else if (str[i] == '=') {
			str[i] = '-'; check(sz);
		} else if (str[i] == 'V') {
			str[i] = 'X'; check2(sz);
		} else if (str[i] == 'X') {
			str[i] = 'V'; check2(sz);
		} else if (str[i] == 'I' || str[i] == '-') {
			str[i] = ' '; check(sz);
		}

		memcpy(str, tmp, sizeof(str));
	}
}