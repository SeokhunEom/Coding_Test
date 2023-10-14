#include <stdio.h>

int hansu(int a) {
	if(a / 100 == 0) {
		return 1;
	} else if(a == 1000) {
		return 0;
	} else {
		int i = a % 10;
		int j = (a / 10) % 10;
		int k = a / 100;
		if(i - j == j - k) {
			return 1;
		}
		return 0;
	}
}

int main() {
	int x, num = 0;
	scanf("%d", &x);
	int arr[x] = {0, };
	
	for(int i = 0; i < x; i++) {
		if(hansu(i + 1)) {
			arr[i] = 1;
		}
	}
	for(int i = 0; i < x; i++) {
		if(arr[i] == 1) {
			num ++;
		}
	}
	printf("%d", num);
	return 0;
}