#include <iostream>

using namespace std;

int a[1001] = {0, };

int dp(int);

int main(void) {
	int n;
	cin >> n;
	cout << dp(n);
	return 0;
}

int dp(int x) {
	if (x == 1) {
		return 1;
	}
	if (x == 2) {
		return 2;
	}
	if (a[x]) {
		return a[x];
	}
	return a[x] = (dp(x - 1) + dp(x - 2)) % 10007;
}