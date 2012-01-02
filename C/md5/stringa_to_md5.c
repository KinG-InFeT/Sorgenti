#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

void printMD5(char* str) {
	int i;
	unsigned char hash[16];

	MD5((unsigned char*)str,strlen(str),hash);

	for( i = 0; i < 16; i++ )
		printf("%02x",hash[ i ]);
}

int main(int argc,char **argv) {

	if(!argv[1])
		return 1;

	printMD5(argv[1]);

	putchar('\n');
	return 0;
}


