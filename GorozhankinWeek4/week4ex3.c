#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){
	char input[100], folder[100];
	
	for(;;) {
		getcwd(folder, sizeof(folder));
		printf("shell:%s:", folder);
		scanf("%s", input);
		if (input == "exit") 
			break;
		else
	  		system(command);
	}

	return 0;
}