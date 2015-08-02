//Shane Tachick
//August 2, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.1

//Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures ?

/*
My first solution uses a map, each time a character is encountered an entry is created and assigned a value of 1.
I chose map because this way my function can handle unicode and this way I dont allocate a huge amount of space that I wont use.
I also created a function for if I was guranteed to only encounter ascii characters. I use a bitset with a size of 127 
(the full range of standard ascii) and initialize it to 0, flipping an index on when I encountered its corresponding ascii value.

At any time if I encounter a duplicate character the algoritm ends and returns false.
*/

#include <string>
using std::string;
#include <map>
using std::map;
#include <iostream>
using std::cout;
using std::endl;
#include <bitset>
using std::bitset;


//this solution should account for unicode characters and extended ascii
bool withDataStructure(string testString)
{
	map <char, bool> uniqueChar;
	for (auto i = 0; i < testString.length(); ++i)
	{
		if (uniqueChar.find(testString[i]) != uniqueChar.end())				//The character exists in the map
			return false;
		uniqueChar[testString[i]] = true;

	}
	return true;
}

//this solution assumes that only the first 127 ascii characters are considered legal input and is O(n) and optimized to take up
//less space than a traditional array/vector
bool withDataStructureASCIIonly(string testString)
{
	bitset <127> asciiArray;
	for (auto i = 0; i < testString.length(); ++i)
	{
		if (asciiArray.test(testString[i]))
			return false;
		asciiArray.set(testString[i]);
	}
	return true;
}


//this solution is O(n^2) but it is optimized so that if you are checking a letter for duplication it does not compare
//itself with anything before it because that has already been checked. I considered doing a sort and then comparing for 
//an O(n) compare but the only in-place sort that would work is quicksort which has a worst case of O(n^2) (because I cannot
//control the data coming in), negating the benefit of sorting.
bool withoutDataStructure(string testString)
{
	for (size_t i = 0; i < testString.length()-1; ++i)
	{
		for (size_t j = i+1; j < testString.length(); ++j)
		{
			if (testString[i] == testString[j])
				return false;
		}
	}
	return true;
}


void output(bool result)
{
	if (result)
		cout << "String is composed of unique characters" << endl;
	else
		cout << "String contains duplicate characters" << endl;
}

int main()
{
	string testString = "ABCDEFGHIJKLMNOPQRSTUVWXZYabcdefghijklmnopqrstuvwxyz1234567890";
	//string testString = "abcdefghiabcdefghi";

	output(withDataStructure(testString));
	output(withDataStructureASCIIonly(testString));
	output(withoutDataStructure(testString));

	return 0;
}