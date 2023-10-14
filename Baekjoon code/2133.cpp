#include <iostream>

using namespace std;

int dp(int);
int a[31] = {0, };

int main(void) {
	int n;

	cin >> n;
	cout << dp(n);

	return 0;
}

int dp(int x) {
	if(x == 0) {
		return 1;
	}
	if (x == 1) {
		return 0;
	}
	if (x == 2) {
		return 3;
	}
	if (a[x]) {
		return a[x];
	}
	a[x] = 3 * dp(x - 2);
	for (int i = 4; i <= x; i++) {
		if (i % 2 == 0) {
			a[x] += 2 * dp(x - i);
		}
	}
	return a[x];
}