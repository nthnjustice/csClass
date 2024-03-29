#include <iostream>

/* 
      max3.cpp -- program to print out the largest of three input values
     usage: ./max3
     input: three doubles 
    output: the largest of the three input values
      note: no prompt for user, no explanation on output
    
    modified by: Nathan Justice
    modified on: 9/27/12
 */

using namespace std;

double max3(double, double, double);	// tell compiler about this

int main()
{
	double	a,b,c;			// input values
	double	largest;		// result
	
	cin >> a >> b >> c;		// read in three values
	largest = max3(a,b,c);		// compute the largest
	cout << largest << endl;	// display it on the screen
}

//
// max3() return the largest of three values passed as arguments
//
double max3(double n1, double n2, double n3)
{
	double largest;
	if (n1 > n2 && n1 > n3)
		largest = n1;
	if (n2 > n1 && n2 > n3)
		largest = n2;
	if (n3 > n2 && n3 > n1)
		largest = n3;
	
	return largest;
				// your code here
	// your function MUST use return to send back the
	// largest value of the three values passed in
}
