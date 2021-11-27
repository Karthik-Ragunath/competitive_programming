#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sys/time.h>
#include "common.h"

// common.h downloaded from - http://pages.cs.wisc.edu/~remzi/OSTEP/Code/code.intro.tgz
// int main(int argc, char* argv[]) would do too
// gcc -I/Users/karthikragunath/Desktop/Coding/MAC\ codes/OperatingSystems/common  -o simple_loop simple_loop.c -Wall
// ./simple_loop "A"
int main(int argc, char **argv)
{
	if(argc != 2)
	{
		fprintf(stderr, "usage: cpu <string>\n");
		exit(1)	;
	}
	char *str = argv[1];
	while(1)
	{
		Spin(1);
		printf("%s\n", str);
	}
	// for(int i = 0; i < 3; i++)
	// {
	// 	Spin(1);
	// 	printf("%s\n", str);
	// }
	return 0;
}

/*
for loop ran 3 times
Karthiks-MacBook-Pro:OperatingSystems karthikragunath$ ./simple_loop A & ./simple_loop  B & ./simple_loop C & ./simple_loop D &
[1] 4825
[2] 4826
[3] 4827
[4] 4828
Karthiks-MacBook-Pro:OperatingSystems karthikragunath$ A
D
B
C
A
B
D
C
A
D
C
B
*/