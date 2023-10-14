#include <stdio.h>
#include <cstring>

int main() {
	int a, sum, p;
	scanf("%d", &a);
	char arr[80];
	for(int i = 0; i < a; i++) {
		sum = 0;
		p = 1;
		scanf("%s", arr);
		for(int j = 0; j < strlen(arr); j++) {
			if(arr[j] == 'O') {
				sum += p++;
			}
			else if(arr[j] == 'X'){
				p = 1;
			}
		}
		printf("%d\n", sum);
	}
	
	return 0;
}