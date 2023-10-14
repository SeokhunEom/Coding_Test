#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string, string);

int main(void) {
	int n;
	string a[20000];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			continue;
		}
		cout << a[i] << '\n';
	}


	return 0;
}

bool compare(string a, string b) {
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {
		return a < b;
	}
}