#include <stdio.h>
#include <string.h>

void crypt(char *c);

void decrypt(char *c);

int main(int argc, char const *argv[])
{
	char c[100] = "crabwolfcrabcrabwolfcrab";
	printf("%s\n", c);
	return 0;
}

void crypt(char *c){
	char start = c[0]; //1 byte
	char end = c[1]; //1 byte

	for(int k = 1; k <= strlen(c); k++){
		for(int i = 1; c[i] != '\0'; i++){
			if(start != end){
				start = c[i]
				if(c[i+k] != '\0'){
					end = c[i+k];
				}else{
					break;
				}
			}else if(start == end){
					
			}
		}
	}

}
