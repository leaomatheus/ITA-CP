// x x x x x

dp[5][0] += dp[4][9] + dp[4][8] + dp[4][7] ... + dp[4][0]
dp[5][1] += dp[4][10] + dp[4][9] + dp[4][8] + dp...


int calc(int digit, int sum) {
	if (digit == 0) return 1;
	
	int ans = 0;
	for (int d = 0; d <= 9; d++) {
		ans = calc(digit-1, sum + d);
	}
	return ans;
}

int dp[20][20*10] = 0;

int main() {
	memset(dp, -1, sizeof(dp));
}

int calc(int digit, int sum) {
	if (digit == 0) return 1;
	int& ans = dp[digit][ans];

	if (ans != -1) return ans;
	
	ans = 0;
	for (int d = 0; d <= 9; d++) {
		ans = calc(digit-1, sum + d);
	}
	return ans;
}

// I cant place 0 to 9 digit

// _ _ _ _ _ _ _ _ _
// 0 3 2 3 4 8 1 2 3

// 0 _ _ _ _ _ _ _ _
// 0 0 x x x x x x x  ans += calc(digit-falta, 0)

// 0 _ _ _ _ _ _ _ _
// 0 1 x x x x x x x  ans += calc(digit-falta, 1)

// 0 _ _ _ _ _ _ _ _
// 0 2 x x x x x x x  ans += calc(digit-falta, 2)

// 0 _ _ _ _ _ _ _ _
// 0 3 0 x x x x x x

int compute(int limit) {
	int sum = 0; int n = get_size(limit); // n = 9

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int digit = get_nth(limit, i);
		for (int d = 0; d < digit; d++) {
			sum += d;
			ans += calc(n-i-1, sum);
			sum -= d;
		}
		sum += digit;
	}
	// limit nao foi testado
	// sum os digitos de limite e se der ans++;
	return ans;
}

// Q * N * 10 + N * (10*N)

// Raone
// 1 2 3 1
// (1 + 3) - (2 + 1) = 1

int calc(int digit, int sum) {
	if (digit == 0 && sum == 1) return 1;
	if (digit == 0 && sum != 1) return 0;

	int& ans = dp[digit][sum];

	if (ans != -1) return ans;
	
	ans = 0;
	for (int d = 0; d <= 9; d++) {
		ans = calc(digit-1, sum + (digit%2 == 0) ? d : -d);
	}
	return ans;
}

int compute(int limit) {
	int sum = 0;

	char w[20];
	sprintf(w, "%d", limit);
	n = strlen(w);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int digit = w[i] - '0';
		for (int d = 0; d < digit; d++) {
			sum += (n-i)%2 == 0 ? d : -d;
			ans += calc(n-i-1, sum);
			sum -= (n-i)%2 == 0 ? d : -d;
		}
		sum += (n-i)%2 == 0 ? digit : -digit;
	}
	return ans;
}

// Um problema no codigo
int dp[20][2*soma]
int& ans = dp[digit][sum + 100];

// Gone
// Checar se soma prima
// Precomputo os primos

bool isPrime[200];

bool dp[20][200][2];

int calc(int digit, int sum, int isLess) {
	if (digit == 0 && isPrime[sum]) return 1;
	if (digit == 0 && !isPrime[sum]) return 0;

	int& ans = dp[digit][sum][isLess];
	if (ans != -1) return ans;
	
	ans = 0;
	int maxV = (isLess == 1) ? 9 : w[digit]-'0';

	for (int d = 0; d <= maxV; d++) {
		ans += calc(digit-1, sum + d, isLess | (d < maxV));
	}
	return ans;
}

int precompute(int val) {
	sprintf(w, "%d", val);
	int n = strlen(w);
	memset(dp, -1, sizeof(dp));
	return cnt(n, 0, 1);
}

// a -> b => 0 a-1, 0 b


bool isPrime[200];

bool dp[20][200][2][2];

int calc(int digit, int sum, int isLess, int isMore) {
	if (digit == 0 && isPrime[sum]) return 1;
	if (digit == 0 && !isPrime[sum]) return 0;

	int& ans = dp[digit][sum][isLess];
	if (ans != -1) return ans;
	
	ans = 0;
	int minV = (isMore == 1) ? 0 : w2[digit]-'0';
	int maxV = (isLess == 1) ? 9 : w[digit]-'0';

	for (int d = minV; d <= maxV; d++) {
		ans += calc(digit-1, sum + d, isLess | (d < maxV), isMore | (d > minV));
	}
	return ans;
}

int precompute(int val, int val2) {
	sprintf(w, "%d", val);
	int n = strlen(w);
	
	sprintf(w, "%d", val);
	int n = strlen(w);
	
	memset(dp, -1, sizeof(dp));
	return cnt(n, 0, 1);
}

// Workchef

// 2 -> par
// 3 -> soma% 3 == 0
// 4 -> ultimos 2 digitos
// 5 -> termina 5 ou 0
// 6 -> div 2 e 3
// 7 -> checar
// 8 -> ultimos 3 digitos
// 9 -> soma% 9 == 0
// 0 -> erro

%(1*2*3*4*5*6*7*8*9) == rem
rem%2 == 0 (divisivel por 0)
rem%3 == 0 (divisivel por 0)

int dp[20][2][2][5*8*7*9]

// 111111111
// 100100100 -> 1,4,7
// [2][2][2][2][2][2][2]

int dp[20][2][2][5*8*7*9][1 << 9];

int calc(int digit, int isLess, int isMore, int rem, int mask) {
	if (digit == 0) {
		int cnt = 0;
		for (int i = 1; i <= 9; i++) {
			if ((1 << (i-1))&mask && rem%i == 0) cnt++;
		}
		if (cnt >= K) return 1;
		return 0;
	}

	int &ans = dp[digit][isLess][isMore][rem][mask];
	if (ans != -1) return ans;

	int maxV = isLess ? 9 : get(d, vb);
	int minV = isMore ? 0 : get(d, va);
	
	ans = 0;
	for (int i = minV; i <= maxV; i++) {
		if (i == 0) { ans += calc(d-1, isLess | (i < maxV), isMore | (i > minV), mask, rem); }
		else { ans += calc(d-1, isLess | (i < maxV), isMore | (i > minV), mask | (1 << (i-1)), (rem + i*pot10^[digit])%mod); }		
	}
	return ans;
}

// Palindromic
// Maximum product