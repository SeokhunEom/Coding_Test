#include <stdio.h>

int main() {
	int n, m, i = 1, temp;
	scanf("%d", &n);
	temp = n;
	while(1) {
		m = (n / 10 + n % 10) % 10 + (n % 10) * 10;
		if(temp == m) {
			break;
		}
		i++;
		n = m;
	}
	printf("%d", i);
	
	return 0;
}