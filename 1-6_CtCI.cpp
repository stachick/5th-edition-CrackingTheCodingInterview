//Shane Tachick
//August 5, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.6

/*Given an image represented by an NxN matrix, where each pixel in the image is
4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?
*/

/*I'm going to use a 2d vector to represent the matrix. I'm certain that with a temp variable
the rotation can be done in place.
*/

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;

void fillVector(vector<vector<int>> &nXn, int n)
{
	for (auto i = 0; i < n; ++i)
	{
		vector<int> temp;
		for (auto j = 0; j < n; ++j)
		{
			temp.push_back(((i*n)+j));
		}
		nXn.push_back(temp);
	}
}

void printVector(const vector <vector <int>> nXn, int n)
{
	for (auto i = 0; i < n; ++i)
	{
		for (auto j = 0; j < n; ++j)
		{
			cout << nXn[i][j] << "   ";
		}
		cout << endl;
	}
}

void rotateVector(vector <vector <int>> &nXn, int n)
{
	for (auto i = 0; i < (n/2); ++i)
	{
		int first = i;
		int last = n - 1 - i;
		for (auto j = first; j < last; ++j)
		{
			//topLeft = nXn[first][j]
			//topRight = nXn[last-offset][first]
			//botLeft = nXn[j][last]
			//botRight = nXn[last][last - offset]

			int offset = j - first;

			int temp = NULL;
			temp = nXn[first][j];									//store the top left value 
			nXn[first][j] = nXn[last-offset][first];				//move the top right node into the top left
			nXn[last-offset][first] = nXn[last][last-offset];		//move the bot right node into the top right
			nXn[last][last-offset] = nXn[j][last];					//move the bot left node to the bot right
			nXn[j][last] = temp;									//move the stored value into the bot left

			
		}
	}
}

int main()
{
	int n = 5;
	vector <vector <int>> nXn;

	fillVector(nXn, n);
	printVector(nXn, n);
	rotateVector(nXn, n);

	cout << endl;

	printVector(nXn, n);

	return 0;
}