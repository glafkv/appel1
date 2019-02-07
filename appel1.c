#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//Declaration of variables;
	pid_t childpid = 0;
	int choice = 0;
	FILE *infptr = NULL;
	FILE *outfptr = NULL;
	char filename[100];
	//char *nums = NULL;
	int i;
	//Checking the arguments.
	if(argc == 5){
		//Allows it to take in two user-made text files.
		//input file first, then output file
		if(strcmp(argv[1],"-i")==0){
			infptr = fopen(argv[2],"r");
			outfptr = fopen(argv[4], "w");
		
		//Allows it to take in two user-made text files.
		//output file first, then input file
		}else if(strcmp(argv[1],"-o")==0){
			infptr = fopen(argv[4], "r");
			outfptr = fopen(argv[2], "w");
		}
		
	} else if(argc == 3){
		//User puts in input file, default output file
		if(strcmp(argv[1],"-i")==0){
			infptr = fopen(argv[2], "r");
			outfptr = fopen("output.dat", "w");
		//User puts in output file, default input file
		}else{
			infptr = fopen("input.dat", "r");
			outfptr = fopen(argv[2], "w");
		}
	//If user doesn't input anything, default files
	} else if(argc == 1){
		infptr = fopen("input.dat", "r");
		outfptr = fopen("output.dat","w");
	} 
	
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
				filename = optarg;
				break;
			
			case 'o':
				filename = optarg;
				break;

			case '?':
				fprintf(stderr, "Not an option.\n");
				return 1;

			default:	
			abort();
		}
	}
	
	filename = atoi(argv[2]);

	for(i = 1; i < c; i++){
		if(childpid = fork()){
			break;
		}
	}
	
	fprintf(stderr, "process ID: %ld\t", (long)getpid());

return 0;
}
