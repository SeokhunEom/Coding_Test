#include <stdio.h>
#include <string.h>

int main() {
	char S[1000000];
	int a[26] = {0, }, num = 0, max = -1, len;
	scanf("%s", S);
	len = strlen(S);
	for(int i = 0; i < len; i++) {
		a[(S[i] - 65) % 32] ++; 
	}
	for(int i = 0; i < 26; i++) {
		if(a[i] == num) {
			num = a[i];
			max = -1;
		} else if(a[i] > num) {
			num = a[i];
			max = i;
		}
	}
	if(max == -1) {
		printf("?");
	} else {
		printf("%c", max + 65);
	}
	
	return 0;
}