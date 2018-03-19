#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int N, M, K;
	cin >> N >> M >> K;	
	int n;
	if(N == 1 && M == 1){
		n = 1;	
	} else if(N == 1 || M == 1){
		n = 2;
	} else {
		n = 4;
	}
	while(K--){
		int i, j;
		cin >> i >> j;
		if(i == 1 && j == 1){
			n--;
		} else if(i == 1 && j == M && M != 1){
			n--;
		} else if(i == N && j == 1 && N != 1){
			n--;
		} else if(i == N && j == M && N != 1 && M != 1){
			n--;
		}
	}
	cout << n << endl;
	
	return 0;
}