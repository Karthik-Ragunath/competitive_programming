#include <iostream>
using namespace std;

int** return_array(int **multi_d_arr)
{
	for(int i = 0; i < 100; i++)	
	{
		for(int j = 0; j < 100; j++)
		{
			multi_d_arr[i][j] = 1000;
		}
	}
	return multi_d_arr;
}

int main() {
	int **two_d = new int*[100];
	for(int i = 0; i < 100; i++)
	{
		two_d[i] = new int[100];
	}
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			two_d[i][j] = 200;
		}
	}
	int **two_d_mod = return_array(two_d);
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << two_d_mod[i][j] << "\n";
		}
	}
	// your code goes here
	return 0;
}