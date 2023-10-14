#include <stdio.h>
#include <string.h>

int main() {
	int t, r;
	char S[20];
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		scanf("%d", &r);
		scanf("%s", S);
		for(int j = 0; j < strlen(S); j++) {
			for(int k = 0; k < r; k++) {
				printf("%c", S[j]);
			}
		}
		printf("\n");
	}
	
	return 0;
}