#include <stdio.h>

int main() {
	int c, n, a;
	float sum;
	scanf("%d", &c);
	for(int i = 0; i < c; i++) {
		scanf("%d", &n);
		int arr[n];
		sum = 0;
		for(int j = 0; j < n; j++) {
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		sum /= n;
		a = 0;
		for(int j = 0; j < n; j++) {
			if(arr[j] > sum) {
				a++;
			}
		}
		printf("%.3f%%\n", (float) a / n * 100);
	}
	
	return 0;
}