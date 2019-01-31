Author: Gabi Appel
Due date: 2/7/2019

Purpose:
	The purpose of this program is to get well acquainted with getopt, perror, and fork(). To start, it's supposed to have a -h, -i, and -o option, which will bring up a help guide, give an option to input a file, and give an option to output a file. Then it will open an input file. The input file will have numbers that we will take in, loop based on the number, and fork off a copy. The child will read the number of integers, put them into a stack, write its PID to the output file, and the numbers in reverse. After it writes to the output file, and the children have terminated, the parent should write the pids of all the children that it launched, and its own pid into the output file. 


How to Run:
	Type these commands into the command line:
		make 		//this compiles the project
		./proj1 -h	//display the program options
		./proj1 -i <inputfilename> -o <outputfilename> 	//you choose the filenames, you can also
								//type it in the other way.
		./proj1 -i <inputfilename> 	//filename is your choice, output file is called output.dat
		./proj1 -o <outputfilename>	//filename is your choice, input file is called input.dat
		./proj1		//filenames are both default to input.dat and output.dat
		make clean	//remove all the files from when compiled

Issues:
	If the user types in ./proj1 -o output.dat -i input.dat
		or 	     ./proj1 -o output.dat
	it will print "Unknown option", but still prints to the files properly.
