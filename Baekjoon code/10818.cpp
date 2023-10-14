#include <stdio.h>

int main() {
	int n, temp, min, max;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if(i == 0) {
			min = temp;
			max = temp;
		}
		if(temp > max) {
			max = temp;
		}
		if(temp < min) {
			min = temp;
		}
	}
	printf("%d %d", min, max);
	
	return 0;
}