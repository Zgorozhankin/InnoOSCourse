#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){
	char input[100], folder[100];
	
	for(;;) {
		getcwd(folder, sizeof(folder));
		printf("shell: %s: ", folder);
		scanf("%s", input);
		fgets(input, 100, stdin);
		input[strlen(input) - 1] = '\0';
		if(strcmp(input, "exit") == 0)
			break;
		else
			system(command);
	}

	return 0;
}