//Shane Tachick
//August 4, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.4

/*Write a method to replace all spaces in a string with '%20'. You may assume that
the string has sufficient space at the end of the string to hold the additional
characters, and that you are given the "true" length of the string. (Note: if implementing 
in Java, please use a character array so that you can perform this operation in place.)
	EXAMPLE
	Input : "Mr John Smith
	Output : "Mr%20Dohn%20Smith"
*/

/* My first thought was to just step through the string and replace spaces as I encounter them. The
more I thought about it the less I liked that solution because every time you encountered a space you
would need to edit everything after it because you are adding 2 extra characters, leading to a lot of
editing. My solution is to build a new string from scratch and replace the spaces as I encounter them.
*/

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

void output(const string &originalStr, const string &str)
{
	cout << "The string before its spaces are replaced:\n" << originalStr 
		 << "The string after its spaces are replaced:\n" << str << endl;
}

string replaceSpaces(string &str)
{
	string tempStr;
	
	for (auto i = 0; i < str.length(); ++i)
	{
		if (str[i] == ' ')
		{
			tempStr += '%';
			tempStr += '2';
			tempStr += '0';
		}
		else
			tempStr += str[i];
	}
	return tempStr;
}

int main()
{
	string str = "This is my test sentence. There are many sentences like it but this one is mine.";
	string originalStr = str;
	
	output(originalStr, replaceSpaces(str));

	return 0;
}