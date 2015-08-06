//Shane Tachick
//August 6, 2015
//Cracking the Coding Interview 5th edition
//Problem 1.7

/*Write an algorithm such that if an element in an MxN matrix is 0, its entire row
and column are set to 0
*/

/* I cannot think of a way to accomplish this without traversing the entire matrix first to see where the 0's are.
You cannot change rows/columns on your first pass because if the matrix contains 0's then your entire matrix will
cascade into 0's.
*/

#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <cstdlib>
using std::rand;
using std::srand;
#include <ctime>
using std::time;
#include <tuple>
using std::pair;
using std::make_pair;

void printVector(const vector <vector <int>> mXn, int m, int n)
{
	cout << endl;
	for (auto i = 0; i < m; ++i)
	{
		for (auto j = 0; j < n; ++j)
		{
			cout << mXn[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

void fillVector(vector<vector<int>> &mXn, int m, int n)
{
	for (auto i = 0; i < m; ++i)
	{
		vector<int> temp;
		for (auto j = 0; j < n; ++j)
		{
			temp.push_back(rand()%9);
		}
		mXn.push_back(temp);
	}
}

void findZeros(vector<vector<int>> &mXn, vector<pair<int, int>> &zeros, int m, int n)
{
	for (auto i = 0; i < m; ++i)
	{
		for (auto j = 0; j < n; ++j)
		{
			if (mXn[i][j] == 0)
			{
				zeros.push_back(make_pair(i, j));
			}
		}
	}
}

void modifyColumn(vector<vector<int>> &mXn, int index, int m, int n)
{
	for (auto i = 0; i < n; ++i)
	{
		mXn[index][i] = 0;
	}
}

void modifyRow(vector<vector<int>> &mXn, int index, int m, int n)
{
	for (auto i = 0; i < m; ++i)
	{
		mXn[i][index] = 0;
	}
}

void modifyMatrix(vector<vector<int>> &mXn, vector<pair<int, int>> &zeros, int m, int n)
{
	pair<int, int> temp;
	for (auto i = 0; i < zeros.size(); ++i)
	{
		temp = zeros[i];
		cout << "Coordinates of a 0 (row/column): " << temp.first << "  " << temp.second << endl;
		modifyColumn(mXn, temp.first, m, n);
		modifyRow(mXn, temp.second, m, n);
	}
}

int main()
{
	srand(time(0));
	int m = 4;
	int n = 8;
	vector<vector<int>> mXn;
	vector<pair<int, int>> zeros;		// mXn coordinates of a zero.

	fillVector(mXn, m, n);
	printVector(mXn, m, n);

	findZeros(mXn, zeros, m, n);
	
	modifyMatrix(mXn, zeros, m, n);
	printVector(mXn, m, n);

	return 0;
}