#include <stdio.h>
#include <openssl/md5.h>

int main() {

	MD5_CTX md5;
	
	unsigned char result[16];
	char* message = "Hello World!";
	int i;

	MD5_Init( &md5 );

	MD5_Update( &md5, message, strlen(message) );

	MD5_Final( &result, &md5 );
	
    for(i = 0;i < strlen(string);i++) {
    
        if(i && !(i % 2))
            putchar(',');
            
        putchar( string[i] );
    }

	return 0;
}

