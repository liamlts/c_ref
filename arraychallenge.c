#include <stdio.h>

int main(void)
{
	char alphabet[26];
	int x;
	char c = 65;
	char *pa = alphabet;
	for(x=0;x<26;x++){
		//alphabet[x] = c;
		*pa = c + x;
		pa++;
	}

	for(x=0;x<26;x++){
		//putchar(alphabet[x]);
		printf("%c\n", alphabet[x]);
	}
	pa-=26;
	for(const char *i = pa;*i;i++){
		putchar(*i);
	}


	//printf("%c", 65);

	return 0;
}

