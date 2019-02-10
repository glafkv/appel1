#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int stack[30];
int top;
void push(int e){
	top = top +1;
	stack[top] = e;
}
int pop(){
	int x=stack[top];
	top--;
	return x;
}
void clearstack(){
	top = -1;
}

int main(int argc, char *argv[])
{
	//Declaration of variables;
	pid_t childpid = 0;
	int choice = 0;
	int n;
	FILE *infptr = NULL;
	FILE *outfptr = NULL;
	
	char *infile = "input.dat";
	char *outfile = "output.dat";

	//n = getw(infptr);
	int i, m, j, x;
	

	
	//getopt statement
	while((choice = getopt(argc, argv, "hi:o:")) != -1){
		switch(choice){
			case 'h':
				printf("\tI'm here to help!\n");
				printf("***************************\n");
				printf("-h brings up the help menu\n");
				printf("-i allows you to add your own input file\n");
				printf("-o allows you to add your own output file\n");
				exit(0);

			case 'i':
				infile = optarg;
				
				break;
			
			case 'o':
				outfile = optarg;
				break;

			case '?':
				fprintf(stderr, "Not an option.\n");
				return 1;

			default:	
			abort();
		}
	}
	//printf("input file: %s, output file: %s", infile, outfile);
	infptr = fopen(infile, "r");

	outfptr = fopen(outfile, "w");
	//Read in the first number.
	fscanf(infptr, "%d", &x);
	//Loop to that first number.
	for(i = 0; i < x; i++){
		
		if(fork()==0){
			fprintf(outfptr,"child: %d parent: %d\n", getpid(), getppid());
			exit(0);
		}else{
			wait(NULL);
		}
	}
	for(i = 0; i < x; i++){
		wait(NULL);
	}
	

	//Close your files.
	fclose(infptr);
	fclose(outfptr);
return 0;
}
