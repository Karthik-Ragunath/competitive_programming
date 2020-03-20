#include <iostream>
using namespace std;

struct structs
{ 
	int *e = new int[10]; 
};

struct Def_Struct
{
	int e[10];
};

void pass_arrays_into_func(int *arr, int b)
{
	for(int i = 0; i < b; i++)	
	{
		arr[i] = 200;
	}
}

void poss_structs_into_function(structs *a, int b)
{
	int *arr_struct = a -> e;
	for(int i = 0; i < b; i++)
	{
		arr_struct[i] = 300;
	}
}


void pass_structs_value(Def_Struct a, int b)
{
	for(int i = 0; i < b; i++)	
	{
		a.e[i] = 300;
	}
}

int main() {
	int c = 20;
	int b = 100;
	string *f[30];
	string *heap_initialized_string = new string[b];
	int *a = new int[b];
	int *d[20];
	cout << d[10] << "\n";
	cout << a[10] << "\n";
	cout << f[10] << "\n";
	cout << heap_initialized_string[10] << "\n";
	if(heap_initialized_string[10] == "")
	{
		cout << "yes" << "\n";
	}
	else
	{
		cout << "no" << "\n";
	}
	for(int i = 0; i < b; i++)
	{
		a[i] = 100;
	}
	pass_arrays_into_func(a, b);
	for(int i = 0; i < 5; i++)
	{
		cout << "i: " << i << " : " << a[i] << "\n";
	}
	
	structs *structs_obj  = new structs;
	for(int i = 0; i < b; i++)
	{
		structs_obj -> e[i] = 1000;
	}
	poss_structs_into_function(structs_obj, b);
	cout << "After modifying struct pointer" << "\n";
	for(int i = 0; i < 5; i++)
	{
		cout << structs_obj -> e[i] << "\n";
	}
	Def_Struct structs_pass_by_value;
	for(int i = 0; i < b; i++)
	{
		structs_pass_by_value.e[i] = 1000;
	}
	pass_structs_value(structs_pass_by_value, b);
	cout << "after passing structs by value" << "\n";
	cout << "executed till here" << "\n";
	for(int i = 0; i < 5; i++)
	{
		cout << structs_pass_by_value.e[i] << "\n";
	}
	// // your code goes here
	return 0;
}