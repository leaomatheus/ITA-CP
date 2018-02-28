#include <bits/stdc++.h>
using namespace std;

int main() {
	int x, y; cin >> x >> y;

	bool possible = true;

	if(y <= 1) possible = false;
	if(x-y+1<0 || (x-y+1)%2==1) possible = false;
	if(x == 0 && y==1) possible = true;
	
	if(possible) puts("Yes");
	else puts("No");
	
	return 0;
}