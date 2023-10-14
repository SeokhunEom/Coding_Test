#include <stdio.h>

int self(int a) {
	int b = a;
	while(a) {
		b += a % 10;
		a /= 10;
	}
	return b;
}

int main() {
	int a[10000] = {0, }, k;
	
	for(int i = 1; i < 10000; i++) {
		k = self(i);
		if(k < 10000) {
			a[k] = 1;
		}
	}
	for(int i = 1; i < 10000; i++) {
		if(!a[i]) {
			printf("%d\n", i);
		}
	}
	return 0;
}