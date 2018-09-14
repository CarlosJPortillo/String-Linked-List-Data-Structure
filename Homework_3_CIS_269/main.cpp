//this program makes a custom string data type using a linked list structure 
#include <iostream>
#include "simplestring.h"



int main(){

	 //output statements if you like
	MyString myString;
	MyString myString2("CIS269");
    MyString myString3(myString2);

	//use operand
	myString2 += '-';

	myString = myString2;
	myString2.length();

	std::cout << "MyString2: " << std::endl;
	myString2.PrintString();
	system("Pause");


	//char 'a'  = myString2[2]; // a should be 'I' from myString2

	
	 
	return 0;
}

