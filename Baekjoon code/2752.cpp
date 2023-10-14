#include <stdio.h>

int main(void) {
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	for (int i = 0; i < 3; i++) {
		int temp, index;
		int min = 1000001;
		for (int j = i; j < 3; j++) {
			if (a[j] < min) {
				min = a[j];
				index = j;
			}
		}
		temp = a[i];
		a[i] = a[index];
		a[index] = temp;
		
	}
	printf("%d %d %d", a[0], a[1], a[2]);
	return 0;
}