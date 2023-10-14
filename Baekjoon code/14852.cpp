#include <iostream>

using namespace std;

long long int dp(int);
long long int a[1000001][2] = {0,};

int main(void) {
	int n;

	cin >> n;
	cout << dp(n);

	return 0;
}

long long int dp(int x) {
	a[0][0] = 0;
	a[1][0] = 2;
	a[2][0] = 7;
	a[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		a[i][1] = (a[i - 1][1] + a[i - 3][0]) % 1000000007;
		a[i][0] = (3 * a[i - 2][0] + 2 * a[i - 1][0] + 2 * a[i][1]) % 1000000007;
	}
	return a[x][0];
}