#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	int a[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		int min = 1001, index;
		for (int j = i; j < n; j++) {
			if (a[j] < min) {
				min = a[j];
				index = j;
			}
		}
		int temp = a[i];
		a[i] = a[index];
		a[index] = temp;
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}