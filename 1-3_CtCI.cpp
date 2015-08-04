//Shane Tachick
//August 4, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.3

//Given two strings, write a method to decide if one is a permutation of the other.

/* Seems straightforward enough, make sure the strings are the same length, if they are
then check that all of the letters in the first string are contained within the second string.
Bucket sort both lists and make sure the buckets match.
Assumptions: Case matters, ascii only, no null string.
*/

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

void output(bool isPermutation)
{
	if (isPermutation)
		cout << "String 2 is a permutation of String 1" << endl;
	else
		cout << "String 2 is not a permutation of String 1" << endl;
}

void sortString(string str, vector <int> &unsortedStr)
{
	for (auto i = 0; i < str.length(); ++i)
	{
		++unsortedStr[str[i]];
	}
}

bool isSorted(const vector <int> strOne, const vector <int> strTwo)
{
	for (auto i = 0; i < strOne.size(); ++i)
	{
		if (strOne[i] != strTwo[i])
			return false;
	}
	return true;
}

void checkPermutation(string strOne, string strTwo)
{
	vector <int> sortedStrOne (256, 0);
	vector <int> sortedStrTwo (256, 0);

	sortString(strOne, sortedStrOne);
	sortString(strTwo, sortedStrTwo);

	output(isSorted(sortedStrOne, sortedStrTwo));
}

int main()
{
	string strOne = "abcdefghijklmnopqrstuvwxyz";
	string strTwo = "zyxwvutsrqponmlkjihgfedcba";

	if (strOne.length() == strTwo.length())
		checkPermutation(strOne, strTwo);
	else
		output(false);
	return 0;
}