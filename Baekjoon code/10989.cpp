#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	int a[10001] = { 0, };

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		a[m]++;
	}
	for (int i = 0; i < 10001; i++) {
		while (a[i] != 0) {
			cout << i << '\n';
			a[i]--;
		}
	}

	return 0;
}