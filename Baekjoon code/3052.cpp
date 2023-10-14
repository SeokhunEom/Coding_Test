#include <stdio.h>

int main() {
	int a[10] = {-1, }, n = 10;
	
	for(int i = 0; i < 10; i++) {
		scanf("%d", &a[i]);
		a[i] %= 42;
	}
	for(int i = 0; i < 10; i++) {
		for(int j = i + 1; j < 10; j++) {
			if(a[i] == a[j]) {
				n--;
				break;
			}
		}
	}
	printf("%d", n);
	
	return 0;
}