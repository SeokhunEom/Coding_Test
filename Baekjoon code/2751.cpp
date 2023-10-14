#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int n, a[1000000];

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	std::sort(a, a + n);

	for (int i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}