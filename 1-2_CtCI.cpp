//Shane Tachick
//August 3, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.2

//Implement a function void reverse(char* str) in C or C++ which reverses a null-terminated string.

/* Question seems straightforward enough, given a pointer to the beginning of a string, find the end,
then reverse its message while keeping it null terminated. For my solution I substituted a '&' for the
null character so that I could have a visual representation that my solution worked.
*/

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

void output(string startStr, string endStr)
{
	cout << "The starting string was:\n" << startStr << "\nand now it is:\n" << endStr << endl;
}

void reverse(char* str)
{
	char* end = str;
	char tempChar;

	//finds end of the string. Mine searches for a '&' character which I
	//am using to represent a NULL termination. Realistically my solution
	//could be:
	// while (*end)
	while (*end != '&')
		++end;

	//end has been located, set the pointer back one so it doesn't
	//reverse the NULL character
	--end;

	//Reverse the string by swapping characters until the 2 pointers meet/overlap

	while (str <= end)
	{
		tempChar = *str;
		*str++ = *end;
		*end-- = tempChar;
	}
}

int main()
{
	string str = "This is the string I am reversing.&";
	string startStr = str;

	char* charPoint = &str[0];		//get a character pointer to the beginning of the string
	reverse(charPoint);

	output(startStr, str);

	return 0;
}