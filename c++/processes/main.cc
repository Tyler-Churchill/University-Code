#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

using namespace std;

int main() {

	pid_t pid;
	int status;

	if((pid = vfork()) == 0) {

		// child proccess, print out a - z
		char childLetter; 
  		for(childLetter = 'a'; childLetter <= 'z'; childLetter++) {
    		cout << "Child: " << childLetter << " "  << endl; 
    	}

    	// part two requirement
    	printf("[CHILD] Current PID: %u Parent PID: %u", getpid(), getppid());

    	cout << endl << endl; // used to seperate output of parent/child
    	
	} else {

		wait(&status); // makes sure the parent waits** 
					   // Helps display information in the console properly.
					   // Without this wait both processes fight for the ostream giving
					   // non-desirable output

		// parent process, print out A - Z
		char parentLetter; 
  		for(parentLetter = 'A'; parentLetter <= 'Z'; parentLetter++) {
    		cout << "Parent: " << parentLetter << " "  << endl; 
    	}
    	
    	// part two requirement 
		printf("[PARENT] Current PID: %u Parent PID: %u", getpid() ,getppid());
	}

	return 0;
}