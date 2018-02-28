#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long PD[2004][2004][2][2];

long m, d;
string low, sup;

long pd(long digit, long prop, long isLess, long isMore){
	long resp = 0;

	if(PD[digit][prop][isLess][isMore] != -1) return PD[digit][prop][isLess][isMore];

	if(digit == low.size()){
		return (prop == 0);
	}

	bool pularD = false;
	if(digit % 2 == 0){
		pularD = true;
	}
	for(long i = 0; i < 10; i++){
		if (pularD && i == d) continue;
		if (!pularD && i != d) continue;

		if(!isLess && i > sup[digit] - '0'){
			continue;
		}
		if(!isMore && i < low[digit] - '0'){
			continue;
		}
		
		bool nextLess = isLess | (i < (sup[digit]-'0'));
		bool nextMore = isMore | (i > (low[digit]-'0'));

		resp += pd(digit + 1, (prop*10 + i)%m , nextLess, nextMore)%MOD;
		resp %= MOD;
	}
	return PD[digit][prop][isLess][isMore] = resp;
}


int main(){
	cin >> m >> d;
	cin >> low;
	cin >> sup;

	memset(PD, -1, sizeof (PD));

	cout << pd(0, 0, 0, 0) << endl;
	
	return 0;
}