#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n;
		
	while((n = getopt(argc, argv, "hio:")) != -1)
	{
		switch(n)
		{
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
			
			case '?':
				if(optopt == 'n')
					fprintf(stderr,"Argument 'opt' requires another variable.\n", optopt);
				else
					fprintf(stderr, "Unknown option\n");
		
				return 1;
			
			default:
			abort();

		}
	}
	
	return 0;
}
