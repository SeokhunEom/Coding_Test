#include <stdio.h>

int main() {
	int arr[9], max = 0, n;
	for(int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < 9; i++) {
		if(arr[i] > max) {
			max = arr[i];
			n = i + 1;
		}
	}
	
	printf("%d\n%d", max, n);
	
	return 0;
}