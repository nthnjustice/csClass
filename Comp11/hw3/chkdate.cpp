//Nathan Justice
//2-6-13
//program: chkdate.cpp
//purpose: reads three integers and checks if the entire date is
//	   valid between Jan 1, 1 and Dec 31, 9999.
//input:   three integers from cin represening month, day and year
//output:  'Y' or 'N' to represent valid or not, respectively

#include <iostream>
using namespace std;

const int Jan = 1, Feb = 2, Mar = 3, Apr = 4, May = 5, Jun = 6,
		Jul = 7, Aug = 8, Sep = 9, Oct = 10, Nov = 11, Dec = 12;
int month, day, year;
void invalid ();
void thirty_month();
void thirty_one_month();
void feb();

int main ()
{
	
	cin >> month >> day >> year;
	invalid();
	thirty_month();
	thirty_one_month();
	feb();
	
	return 0;
}
	
//weeds out invalid dates due to unacceptable day, month, or year	
void invalid()
{
	char N = 'N';
			
	if((month < 1) || (month > 12)){
		 cout << N << endl;
	}
	
	else if((day < 1) || (day > 31)){
		cout << N << endl;
	}
	
	else if((year < 1) || (year > 9999)){
		cout << N << endl;
	}	
	
}

//checks date validity for months with 30 days
void thirty_month()
{
	char Y = 'Y';
	
	if((month == Apr) || (month == Jun) || (month == Sep) || (month == Nov) 
		   && (day <=30)){
		cout << Y << endl;
	}
}

//checks date validy for months with 31 days
void thirty_one_month()
{
	char Y = 'Y';
	
	if((month == Jan) || (month == Mar) || (month == May) || (month == Jul)
		    || (month == Aug) || (month == Oct) || (month == Dec) && (day <= 31)){
		cout << Y << endl;
	}
}

//checks date validy for the month of February w/ leap years
void feb()
{
	
	if(((month == Feb && day <= 28)) || ((day = 29)
		    && ((year % 4) == 0) && ((year % 400) != 0))){
		cout << "Y" << endl;
		   }
	 else if(month == Feb){
		cout << "N" << endl;
	}
	
}


		


