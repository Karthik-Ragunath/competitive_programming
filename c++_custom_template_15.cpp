#include <iostream>
using namespace std;

class Dynamic_Init
{
	public:
		int val;
		int *e;
		Dynamic_Init(int x) : val(x), e(new int[x]) {}
};

int main() {
	int class_count = 10;
	Dynamic_Init *dyn = new Dynamic_Init(100);
	cout << dyn -> e[99] << "\n";
	Dynamic_Init *dime[class_count];
	for(int i = 0; i < class_count; i++)
	{
		dime[i] = new Dynamic_Init(100);
	}
	cout << dime[9] -> e[99] << "\n";
	// your code goes here
	return 0;
}