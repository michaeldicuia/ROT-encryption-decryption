
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]){

	if (argc != 3) {printf("You must enter an encrypted string followed by the ROT scheme.\n"); return 1;}

	int rotation = atoi(argv[2]);
	int string_length = strlen(argv[1]);

	char given_string[string_length];
	for (int i=0; i<string_length; i++){  
		given_string[i] = argv[1][i];
	}

	char decoded[string_length+1]; decoded[string_length] = '\0';
	char encoded[string_length+1]; encoded[string_length] = '\0';
	for (int i=0; i<string_length; i++){

		if ((given_string[i] > 96) && (given_string[i] < 123)){
			encoded[i] = ((given_string[i] - 97 + rotation) % 26) + 97;
			decoded[i] = ((given_string[i] - 97 + 26 - rotation) % 26) + 97;
			continue; 
		} 

		if ((given_string[i] > 64) && (given_string[i] < 91)){
			encoded[i] = ((given_string[i] - 65 + rotation) % 26) + 65;
			decoded[i] = ((given_string[i] - 65 + 26 - rotation) % 26) + 65;
			continue;
		}
		
		encoded[i] = given_string[i];
		decoded[i] = given_string[i];
	} 

printf("The encrypted string is %s\n", encoded);
printf("The decrypted string is %s\n", decoded);

}
