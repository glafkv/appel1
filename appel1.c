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
	char filename[100], c;
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

return 0;
}
