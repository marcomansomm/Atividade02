#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	
	pid_t pid;
	int pipeFileDescriptor[2];
	char writeMessages[20] = {"Maria"};
	char readMessages[20];

	int returnPipe = pipe(pipeFileDescriptor);

		printf("Writing Message: %s\n", writeMessages);
		write(pipeFileDescriptor[1], writeMessages, sizeof(char) * 20);
	

	pid = fork();
	
	if(returnPipe == -1){
		printf("Error to create pipe\n");
		return 1;
	}
	
	if(pid == 0){//child
		read(pipeFileDescriptor[0], readMessages, sizeof(char) * 20);
		printf("Reading Message: %s\n", readMessages);

	}
	return 0;
}
