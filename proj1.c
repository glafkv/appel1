#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//Declaration of variables
	FILE *infptr = NULL;
	FILE *outfptr = NULL;
	int v;
	char filename[100], c;
	
	//while loop to get the argument	
	while((v = getopt(argc, argv, "hio")) != -1)
	{
		//switch statement
		switch(v)
		{
			//option h displays a help message
			case 'h':
				printf("\tI'm here to help!\n");
				printf("\t -h : displays this help message.\n");
				printf("\t -i <inputfilename> : takes in\n");
				printf("\t whatever file you specify. If you do\n");
				printf("\t not put a filename, input.dat will be the\n");
				printf("\t default.\n");
				printf("\t -o <outputfilename> : outputs to\n");
				printf("\t whatever file you specify. If you do\n");
				printf("\t not put a filename, output.dat will be the\n");
				printf("\t default.\n");
				printf("\t -i <inputfilename> -o <outputfilename> is also\n");
				printf("\t an option if you want to choose your own filenames.\n");
				printf("\t -o <outputfilename> -i <inputfilename> is also\n");
				printf("\t an option if you want to choose your own filenames.\n");
				exit(0);
			
			//option i takes in an input file. If the user does input a file, set it to what the user input.
				//If the user specifies both specific input and output files, this will do that
			case 'i':	
				if(argc == 5){
					//This will read in the 2nd argument
					infptr = fopen(argv[2], "r");
					//Error if the file isn't there
					if(infptr == NULL){
						return EXIT_FAILURE;
					}
					//This will write to the 4th argument.
					outfptr = fopen(argv[4], "w");
					//Error if the file isn't there
					if(outfptr == NULL){
						fclose(infptr);
						return EXIT_FAILURE;
					}
					//Get the information from the read file, then print to the write file
					c = fgetc(infptr);
					while(c != EOF){
					//	fscanf(infptr, "%[^\n]", c);
						fprintf(outfptr, "%c", c);
						c = fgetc(infptr);	
					}
					
				}
				//If the user does not specify an output file, output.dat will be the default
				else if(argc == 3){
					//This will read in the 2nd argument
					infptr = fopen(argv[2], "r");
					//Error if the file isn't there
					if(infptr == NULL){
						return EXIT_FAILURE;
					}
					//This will default to output.dat as the write file	
					outfptr = fopen("output.dat", "w");
					//Error if the file isn't there
					if(outfptr == NULL){
						fclose(infptr);
						return EXIT_FAILURE;
					}
					//Get the info from the read, print to the write.
					c = fgetc(infptr);
					while(c != EOF){
						//fscanf(infptr, "%[^\n]", c);
						fprintf(outfptr, "%c", c);
						c = fgetc(infptr);
					}
				}
				//DON'T FORGET TO CLOSE YOUR FILES EVER AGAIN
				fclose(infptr);
				fclose(outfptr);		
				exit(0);
				
				//Same deal as i
				case 'o':
				if(argc == 5){
					//This time, the read file is the 4th argument.
					infptr = fopen(argv[4], "r");
					//Error
					if(infptr == NULL){
						return EXIT_FAILURE;
					}
					//The write file is the 2nd argument.	
					outfptr = fopen(argv[2], "w");
					//Error
					if(outfptr == NULL){
						fclose(infptr);
						return EXIT_FAILURE;
					}
					//Read then write to the file
					c = fgetc(infptr);	
					while(c != EOF){
					//	fscanf(infptr, "%[^\n]", c);
						fprintf(outfptr, "%c", c);
						c = fgetc(infptr);
					}
				}
				else if(argc == 3){
					//This one autosets the read file to input.dat
					infptr = fopen("input.dat","r");
					//Error
					if(infptr == NULL){
						return EXIT_FAILURE;
					}
					//The output is argument 2
					outfptr = fopen(argv[2], "w");
					//Error
					if(outfptr == NULL){
						fclose(infptr);
						return EXIT_FAILURE;
					}
					//Read from then write to the file
					c = fgetc(infptr);
					while(c != EOF){
					//	fscanf(infptr, "%[^\n]", c);
						fprintf(outfptr, "%c", c);
						c = fgetc(infptr);
					}

				}
				//Close out ya files
				fclose(infptr);
				fclose(outfptr);
			
				exit(0);                                                                     
				
	
			case '?':
				printf("Unknown option: %c\n", optopt);
				break;
			
			default:
			abort();

		}
	}
	//If the user doesn't do any of the above choices, it will completely default.
	if(argc == 1){
		infptr = fopen("input.dat", "r");
		//Error
		if(infptr == NULL){
			return EXIT_FAILURE;
		}
	
		outfptr = fopen("output.dat", "w");
		//Error
		if(outfptr == NULL){
			fclose(infptr);
			return EXIT_FAILURE;
		}
		c = fgetc(infptr);
		while(c != EOF){
	//		fscanf(infptr, "%[^\n]", c);
			fprintf(outfptr, "%c", c);
			c = fgetc(infptr);
		}
	}
	fclose(infptr);
	fclose(outfptr);

	return 0;
}
