#include "Stack.h"
#include "Queue.h"
#include "Trees.h"

#include <stdio.h>

unsigned int fibonacci_iterative(unsigned int position)
{
	int fibo_number = 1;
	int previous_fibo_number = 1;

	if (position == 0 || position == 1)
		return fibo_number;
	else
	{
		for (unsigned int i = 0; i < position - 1; i++)
		{
			fibo_number += previous_fibo_number;
			previous_fibo_number = fibo_number;
		}
		return fibo_number;
	}	

}

int main(int argc, char **argv)
{
	printf("%d",fibonacci_iterative(5));
	getchar();

	return 0;
}