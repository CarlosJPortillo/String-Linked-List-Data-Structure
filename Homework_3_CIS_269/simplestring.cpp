#include "simplestring.h"

MyString::MyString(const char str[])
{
	string_node* current = NULL;
	head_ptr = NULL;
	tail_ptr = NULL;
	cursor   = NULL;
	many_nodes = 0 ;
	cursor_index = NULL;
	

	 
	many_nodes = strlen(str);
	
	for (size_t i = 0; i < many_nodes; i++)
	{
		cursor = new string_node;

		cursor->data = str[i];
		if (i == 0)
		{
			
			head_ptr = cursor;
			current = cursor;

		}
		else
		{
			current->node = cursor;
			current = cursor;
		}
			tail_ptr = cursor;
	}
	

}
MyString::MyString(const MyString& source)
{

	many_nodes = source.many_nodes;
	cursor = source.cursor;
	head_ptr = source.head_ptr;
	tail_ptr = source.tail_ptr;
	cursor_index = source.cursor_index;
	
}


MyString::~MyString()
{

}

size_t MyString::length() const
{
	return many_nodes;
}

char MyString:: operator [ ](size_t position) const
{
	
		char returnchar;
	/*	Node *returnNode = NULL;*/
		if ((position >= many_nodes))
		{
			std::cerr << "You have a ID10T error. Your position is past the end!" << std::endl;
		}

		if (position < 0)
		{
			std::cerr << "You have a ID10T error. Your position is less than zero!" << std::endl;
		}

		if (many_nodes <= 0)
		{
			std::cerr << "You have less than 0 items for some reason" << std::endl;
		}
		cursor = head_ptr;
		for (unsigned int ii = 0; ii < many_nodes; ii++, cursor = cursor->node)
		{
			if (ii == position)
			{
				returnchar = cursor->data;
			}
		}
		return returnchar;

}

void MyString::operator+= (const MyString& addend)
{
	/*string temp;
	for (size_t i = 0; i < addend.length; i++)
	{
		temp.push_back(addend[i]);
	}*/


	for (size_t i = 0; i < addend.length(); i++)
	{
		cursor = tail_ptr;
		cursor = new string_node;
		tail_ptr->node = cursor;
		tail_ptr = tail_ptr->node;
		tail_ptr->data = addend[i];
		many_nodes++;

	}



}

void MyString::operator+=(char addend)
{
	cursor = tail_ptr;
	cursor = new string_node;
	tail_ptr->node = cursor;
	tail_ptr = tail_ptr->node;
	tail_ptr->data = addend;
	many_nodes++;

}
	
void MyString:: operator+=(const char addend[])
{


	for (size_t i = 0; i < strlen(addend); i++)
	{
		cursor = tail_ptr;
		cursor = new string_node;
		tail_ptr->node = cursor;
		tail_ptr = tail_ptr->node;
		tail_ptr->data = addend[i];
		many_nodes++;

	}




}
 
MyString& MyString::operator = (const MyString& source)
{
	MyString newsource;
	newsource.head_ptr = newsource.head_ptr;
	this->head_ptr = source.head_ptr;
	newsource.tail_ptr = newsource.tail_ptr;
	this->tail_ptr = source.tail_ptr;
	newsource.cursor = newsource.cursor;
	this->cursor = source.cursor;
	newsource.cursor_index = newsource.cursor_index;
	this->cursor_index = source.cursor_index;
	newsource.many_nodes = newsource.many_nodes;
	this->many_nodes = source.many_nodes;
	return newsource;

}
//return headNode
string_node* MyString::ReturnHead() {
	return head_ptr;
}
//prints out the string 
void MyString::PrintString() {
	string_node * stringIterator = ReturnHead();
	
	while (stringIterator->node != NULL) {
		cout << stringIterator->data;
		stringIterator = stringIterator->node;
	}

}