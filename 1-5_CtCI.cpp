//Shane Tachick
//August 4, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.5

/*Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. 
If the "compressed" string would not become smaller than the original 
string, your method should return the original string.
*/

/*Same approach as as problem 1.4, traverse through the original string and build the 'compressed'
string. Compare them at the end and return the proper string.
Assumptions: Only ascii strings, no null strings.

edit: Wow, this problem was a much larger pain than I thought it would be. Properly handling the final grouping of letters 
turned out to be much more of a headache than anticipated because I stubbornly refused to repeat the code I was using to append
onto the end of my compressed string. In the end I gave in and just reused 1 line of code but doing so makes me feel slightly dirty.
The reused code is lines 48 and 58.
*/

#include <string>
using std::string;
using std::to_string;
#include <iostream>
using std::cout;
using std::endl;

void output(const string &original, const string &compressed)
{
	cout << "The original string is:\n" << original << '\n'
		<< "The compressed string is:\n" << compressed << endl;
}

string compressString(string &str)
{
	string compressedStr;
	char compareChar = NULL;
	char prevChar = str[0];
	int counter = 0;
	
	for (auto i = 0; i < str.length(); ++i)
	{
		compareChar = str[i];

		if (compareChar != prevChar)
		{
			compressedStr = compressedStr + prevChar + to_string(counter);
			counter = 0;
		}

		++counter;
		prevChar = compareChar;
	}

	//could not find a way to accomplish this gracefully inside the loop.
	//Adds the compression for the last grouping of letters.
	compressedStr = compressedStr + prevChar + to_string(counter);

	if (compressedStr.length() < str.length())
		return compressedStr;
	else
		return str;
}

int main()
{
	string str = "mbbbbbbbbbbbbbbbcccccccccccccdefgggggaabba";
	//string str = "abcdefghijklmnopqrstuvwxyz";
	output(str, compressString(str));
	return 0;
}