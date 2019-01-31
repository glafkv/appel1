#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fptr = NULL;
	FILE *out = NULL;
	//char *infile = NULL;
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
				exit(0);
			
			//option i takes in an input file.
			case 'i':
				//If the user doesn't put in a file, automatically set it to input.dat. If the user does input a file, set it to what the user input.
				if(argc != 3){
					fptr = fopen("input.dat", "r");
					if(fptr == NULL){
						return EXIT_FAILURE;
					}

				}else {
					fptr = fopen(argv[2],"r");
					if(fptr == NULL){
						return EXIT_FAILURE;
					}
				}
				break;
			case 'o':
				if(argc != 3){
					out = fopen("output.dat", "w");
					if(out == NULL){
						fclose(fptr);
						return EXIT_FAILURE;
					}
				c = fgetc(fptr);
				while(c != EOF){
					fputc(c, out);
					c = fgetc(fptr);
				}
				
				//fclose(fptr);
				//fclose(out);
				}/*else{
					out = fopen(argv[2], "w");
					if(out == NULL){
						fclose(fptr);
						return EXIT_FAILURE;
			//		}
				c = fgetc(fptr);
				while(c != EOF){
					fprintf(out, "%c", c);
					c = fgetc(fptr);
			//	}
				}*/
				//fclose(fptr);
				//fclose(out);
				break;
				
				/*infile = optarg;
				if(argc != 3){
					fptr = fopen("input.dat","r");
					//fptr = optarg;
					//out = fopen("output.dat", "w");
					c = fgetc(fptr);
					while(c != EOF){
					//	fprintf(out,"%c", c);
						printf("%c", c);
						c = fgetc(fptr);
					}
					
					fclose(fptr);
				}
				else {
					fptr = fopen(argv[2], "r");
					
					//fptr = optarg;
					//out = fopen("tester.out", "w");
					c = fgetc(fptr);
					while(c != EOF){
						printf("%c", c);
					//	fprintf(out, "%c", c);
						c = fgetc(fptr);
					}
					fclose(fptr);
				}
				exit(0);*/	
			/*case 'o':
				if(argc != 3)
				                                                                                   ,k	out = fopen("output.dat","w");
					c = fgetc(fptr);
					while(c != EOF){
						fprintf(out, "%c", c);
						c = fgetc(fptr);
					}
					fclose(out);
				}
				else {
					out = fopen(argv[2], "w");
					c = fgetc(fptr);
					while(c != EOF){
						fprintf(out, "%c", c);
						c = fgetc(fptr);
					}
					fclose(out);
				}
				exit(0);*/
				
	
			case '?':
				printf("Unknown option: %c\n", optopt);
				break;
			
			default:
			abort();

		}
	}
	
	return 0;
}
