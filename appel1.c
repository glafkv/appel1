#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(int argc, char *argv[])
{
	//Declaration of variables;
	pid_t childpid;
	int choice = 0;
	FILE *infptr = NULL;
	FILE *outfptr = NULL;
	char *infile = "input.dat";
	char *outfile = "output.dat";
	int i, x;
	char num[150];
	
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
	//open the files
	infptr = fopen(infile, "r");

	outfptr = fopen(outfile, "w");
	//Read in the first number.
	fscanf(infptr, "%d", &x);
		
	//Loop up to the first num. 
	for(i = 0; i < x; i++){
	if((childpid = fork())  == -1){
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	
	 else if(childpid == 0){
		//get pid of child
		fprintf(outfptr, "Child: %d\n", getpid());
		exit(0);
	}
	else {
		wait(NULL);
		
	}
	}
	//Get pid of parent
	fprintf(outfptr, "Parent: %d\n", getppid());
	//This isn't right, but I tried my darndest.
	//Print numbers backwards
	while(fgets(num, 150, infptr)){
		for(i = strlen(num) -1; i>=0; i--){
			fprintf(outfptr, "%c", num[i]);
		}
	}
	fprintf(outfptr, "\n");

	//Close your files.
	fclose(infptr);
	fclose(outfptr);
return 0;
}


