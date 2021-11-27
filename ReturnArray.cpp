#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;


int *sum_of_all_subset ( vector< int > s ){
            int n = s.size() ;
            cout << "n: " << n << endl;
            int *results = new int[(1 << n)];
            // int results[ ( 1 << n ) ] ; // ( 1 << n )= 2^n
            cout << "1 << n " << (1 << n) << endl;

         //initialize results to 0
            memset( results, 0, sizeof( results ) );

        // iterate through all subsets

           for( int i = 0 ; i < ( 1 << n ) ; ++ i ) {    // for each subset, O(2^n)
                 for ( int j = 0; j < n ; ++ j ) {   // check membership, O(n)
                	cout << "i & (1 << j): " << (i & (1 << j)) << " i: " << i << " j: " << j << " (1 << j): " << (1 << j) << endl;
                     if (( i & ( 1 << j ) ) != 0 )    // test if bit ‘j’ is turned on in subset ‘i’?
            	{
                          results[i] += s [j] ;          // if yes, process ‘j’
            	}
                     }
                 }
                 return results;
           }

int main() {
	// your code goes here
	vector<int> s;
	s.push_back(1);
	s.push_back(2);
	s.push_back(3);
	int* sum = sum_of_all_subset(s);
	cout << "Size: " << sizeof(sum) << endl;
	cout << "Sum: " << sum[7] << endl;
	return 0;
}
