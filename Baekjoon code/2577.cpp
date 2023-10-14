#include <stdio.h>

int main() {
	int a, b, c, product;
	int n[10] = {0, };
	scanf("%d %d %d", &a, &b, &c);
	product = a * b * c;
	
	while(product) {
		n[product % 10]++;
		product /= 10;
	}
	
	for(int i = 0; i < 10; i++) {
		printf("%d\n", n[i]);
	}
	
	return 0;
}