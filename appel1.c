#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	//Declaration of variables;
	pid_t childpid = 0;
	int choice = 0;
	FILE *infptr = NULL;
	FILE *outfptr = NULL;
	char *infile = "input.dat";
	char *outfile = "output.dat";
	char c[1000];
	int x, i,s, nums;
	//char *nums = NULL;
	char charac;

	
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


	
	if((infptr = fopen(infile, "r")) != NULL){
		fscanf(infptr, "%d", &x);
		printf("First= %d\n", x);
		//fscanf(infptr, "%d", &s);
		//printf("Next = %d\n", s);
	
	}
	for(i = 1; i < x; i++){
		if(childpid = fork())
			break;
	}
	while(!EOF){
	fscanf(infptr, "%d", &s);
	printf("Second: %d\n", s);
	
	}
	
	/*for(i = 0; i < nums -1; i++){
		scanf(" %c", charac);
		infile[i] = charac;
		if(i == nums -1){
			infile[i+1] = '\0';
		}
	}*/
	//printf("ID: %ld\n", (long)getpid());
	//this takes in the first number of the file and assigns it to x
	//now I need to read the next line of the file, assign it to a variable
	//this will tell me how many numbers are going into the stack
	//read the next line, put the numbers into the stack
	//print the child PID then the numbers from the stack in reverse order
	//I think it would go, while not end of file, read the second number, 
	//
	//do one set at a time. 
	//the forked off copy will read the next two lines, will terminate
	//when it's done

	//This is forking awesome
//	for(i = 1; i < x; i++){
//		if(childpid = fork()){
//			break;
//		}
//	}
//	fprintf(stderr, "i: %d\t", i);
//	fprintf(stderr, "process ID: %ld\t", (long)getpid());
//	fprintf(stderr, "parent ID: %ld\t", (long)getppid());
//	fprintf(stderr, "child ID: %ld\n", (long)childpid);
	fclose(infptr);

return 0;
}
