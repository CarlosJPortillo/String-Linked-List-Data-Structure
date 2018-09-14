// FILE: simplestring.h
// CLASS PROVIDED: string (a sequence of characters)
//
// CONSTRUCTOR for the string class:
//   string(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
// CONSTANT MEMBER FUNCTIONS for the string class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the
//     string.
//
//   char operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
// MODIFICATION MEMBER FUNCTIONS for the string class:
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the string.
//
// NON-MEMBER FUNCTIONS for the string class:
//   string operator +(const string& s1, const string& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   ostream& operator <<(ostream& outs, const string& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//   istream& getline(istream& ins, string& target)
//     Postcondition: A string has been read from the istream ins. The reading
//     operation reads all characters (including white space) until a newline
//     or end of file is encountered. The newline character is read and
//     discarded (but not added to the end of the string).
//
//  VALUE SEMANTICS for the string class:
//    Assignments and the copy constructor may be used with string objects.
// 
// DYNAMIC MEMORY usage by the string class: 
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, operator +=, operator +, and the
//   assignment operator.

#ifndef SIMPLESTRING_H
#define SIMPLESTRING_H
#include <cstdlib>  // Provides size_t
#include <iostream> // Provides ostream and istream
#include <string>

using namespace std;


class string_node
{
public:
	
	char data;
	string_node* node;
};

class MyString
{
public:  
	// TYPEDEF
	typedef std::size_t size_type;
	// CONSTRUCTORS and DESTRUCTOR
	MyString(const char str[] = "");
	MyString(const MyString& source);
	~MyString();
	// MODIFICATION MEMBER FUNCTIONS
	// OPERATOR OVERLOADING
	void operator +=(const MyString& addend);
	void operator +=(const char addend[]);
	void operator +=(char addend);
	MyString& operator =(const MyString& source);
	// CONSTANT MEMBER FUNCTIONS
	std::size_t length() const;
	char operator [ ](size_t position) const;
	string_node* ReturnHead();
	void PrintString();
private:
	string_node* head_ptr;
	string_node* tail_ptr;
	size_type many_nodes;
	mutable string_node* cursor;
	mutable	size_type cursor_index;
};

// NON-MEMBER FUNCTIONS for the string class.
// Remove this comment before submitting your work!
// >>>The student may move these to friend functions if needed.<<<
MyString operator +(const MyString& s1, const MyString& s2);
std::ostream& operator <<(std::ostream& outs, const MyString& source);
void getline(std::istream& ins, MyString& target);

#endif
