#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int v;
	
	//while loop to get the argument	
	while((v = getopt(argc, argv, "hio:")) != -1)
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
				
			
			case ':':
				printf("Option needs another argument\n");
				break;
			case '?':
				printf("Unknown option: %c\n", optopt);
				break;
			
			default:
			abort();

		}
	}
	
	return 0;
}
