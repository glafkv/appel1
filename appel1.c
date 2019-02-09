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
	infptr = fopen(infile, "r");
	outfptr = fopen(outfile, "w");
	//infptr = fopen("input.dat","r");
	//outfptr = fopen("output.dat","w");
	n = getw(infptr);
	int i, m, j, x;
	///char c[100];
	//int x, i,s, nums;
	//char *nums = NULL;
	//char charac;

	
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


	outfptr = fopen(outfile, "w");
	if((infptr = fopen(infile, "r")) != NULL){
		fscanf(infptr, "%d", &x);
		printf("First= %d\n", x);
		//fscanf(infptr, "%d", &s);
		//printf("Next = %d\n", s);
	
	}

	childpid = fork();
	for(i = 1; i <= x; i++){
		if(childpid< 0){
			fprintf(stderr, "fork Failed");
			return 1;
		} else if(childpid == 0){
			//This will read the next two lines and print to outfile.
			//I need to figure out how to read the first number,
			//What am I doing wrong??
			m = getw(infptr);
			clearstack();
			for(j = 1; j <= m; j++){
				push(getw(infptr));
			}
			for(j= 1; j <= m; j++){
				putw(pop(), outfptr);
			}
			putw(getpid(), outfptr);
		} else{
			printf("parent pid: %d , child: %d\n", getpid(),childpid);
		}
	}
	putw(getpid(), outfptr);


	fclose(infptr);
	fclose(outfptr);
return 0;
}
