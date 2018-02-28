#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int solve(int n, ll k){
	if(n == 1) return 1;
	ll size = (1LL << n) - 1;

	if(k == (size+1)/2) return n;
	if(k > (size+1)/2) return solve(n-1, k - (size+1)/2);
	return solve(n-1,k);	
}

int main(){
	int n; ll k;
	cin >> n >> k;
	
	printf("%d\n", solve(n,k));
	return 0;
}