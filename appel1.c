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
	char *infile = "input.dat";
	char *outfile = "output.dat";
	char c[1000];
	//char *nums = NULL;
	//int i;

	
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
	if((infptr = fopen(infile, "r"))!=NULL){
		int x;
		fscanf(infptr, "%d", &x);
		printf("First = %d\n",x);
	}	
	
/*if((infptr = fopen(infile, "r")) == NULL){
		printf("Error!");
		exit(1);
//	}
	int i = 0;
	fscanf(infptr, "%d", &i);
	while(!feof (infptr)){
		printf("%d ", i);*/
	//	fscanf(infptr, "%d", &i);
//	}
	//fscanf(infptr, "%[^\n]", infile);
	
	//printf("Data:\n%s",infile);
	fclose(infptr);

return 0;
}
