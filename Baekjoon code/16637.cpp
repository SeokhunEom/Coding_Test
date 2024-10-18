#include <iostream>
using namespace std;

int N;
long long ans = -1000000000000;
string s;

long long calc(long long a, long long b, char op) {
	long long ret = a;
	switch (op) {
	case '+': 
        ret += b; 
        break;
	case '*': 
        ret *= b; 
        break;
	case '-': 
        ret -= b; 
        break;
	}
	return ret;
}

void func(int idx, long long cur) {
	if (idx >= N) {
		ans = max(ans, cur);
		return;
	}
    
	char op = (idx == 0) ? '+' : s[idx - 1];
	if (idx + 2 < N) {
		long long temp = calc(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
		func(idx + 4, calc(cur, temp, op));
	}
	func(idx + 2, calc(cur, s[idx] - '0', op));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

    cin >> N;
    cin >> s;
    func(0, 0);
    cout << ans;

  return 0;
}