//Shane Tachick
//August 10, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.8

/*Assume you have a method isSubstring which checks if one word is a substring of another.
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one
call to isSubstring (e.g.,"waterbottle"is a rotation of "erbottlewat")
*/

/*My answer to this problem came from thinking about using only rotation as a form of encrypting
a message. If all you do is rotate the message, then all you need to do is add the rotated message
to the end of itself and it will contain a full unrotated message.
Example: foobar rotated to obarfo. We add the rotated string to the end of itself and
we get obarfoobarfo, and this contains our original word, obarFOOBARfo.

All that is left is to check that both words are the same size and not empty strings, which I will do first.

For this solution I am assuming isSubstring() is written for me and functions correctly 
*/


#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

bool isSubstring(string s1, string s2)
{
	//checks if s2 is a substring of s1
	return true;
}

void output(const bool substring)
{
	if (substring)
		cout << "s2 is a rotation of s1." << endl;
	else
		cout << "s1 is not a rotation of s2. " << endl;
}

int main()
{
	string s1;
	string s2;

	if ((s1.length() == s2.length()) && s1.length() != 0)
	{
		string temp = s1 + s1;
		isSubstring(temp, s2);
	}
	else
		cout << "The strings are not the same size, therefore s2 cannot be a rotation of s1." << endl;

	return 0;
}