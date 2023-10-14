#include <stdio.h>

int main() {
	int n, m = 0;
	scanf("%d", &n);
	float a[n], sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%f", &a[i]);
		if(a[i] > m) {
			m = a[i];
		}
	}
	for(int i = 0; i< n; i++) {
		a[i] = a[i] / m * 100;
		sum += a[i];
	}
	printf("%f", sum / n);
	
	return 0;
}