Author: Gabi Appel
Due date: 2/7/2019

Purpose:
	The purpose of this program is to get well acquainted with getopt, perror, and fork(). To start, it's supposed to have a -h, -i, and -o option, which will bring up a help guide, give an option to input a file, and give an option to output a file. Then it will open an input file. The input file will have numbers that we will take in, loop based on the number, and fork off a copy. The child will read the number of integers, put them into a stack, write its PID to the output file, and the numbers in reverse. After it writes to the output file, and the children have terminated, the parent should write the pids of all the children that it launched, and its own pid into the output file. 


How to Run:
	Type these commands into the command line:
		make 		//this compiles the project
		./appel1 -h	//display the program options
		./appel1 -i <inputfilename> -o <outputfilename> 	//you choose the filenames, you can also
								//type it in the other way.
		./appel1 -i <inputfilename> 	//filename is your choice, output file is called output.dat
		./appel1 -o <outputfilename>	//filename is your choice, input file is called input.dat
		./appel1		//filenames are both default to input.dat and output.dat
		make clean	//remove all the files from when compiled

Issues:
	My code compiles and works, it just doesn't do 100% of what it's supposed to. Trust me, I worked on this for days on end trying to make it work, but unfortunately, I ran out of time. I turned in my best copy.
	
