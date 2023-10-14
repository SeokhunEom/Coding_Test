#include <stdio.h>
#include <string.h>

int main() {
	char S[100];
	int a[26];
	for(int i = 0; i < 26; i++) {
		a[i] = -1;
	}
	scanf("%s", S);
	for(int i = 0; i < strlen(S); i++) {
		if(a[S[i] - 97] == -1) {
			a[S[i] - 97] = i;
		}
	}
	for(int i = 0; i < 26; i++) {
		printf("%d ", a[i]);
	}
	
	return 0;
}