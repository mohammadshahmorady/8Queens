#include<iostream>
#include<conio.h>

using namespace std;

int n;
bool variables[20][20];

bool CSP(int row, int column) {
	if (row == n - 1)
	{
		for (int i = 0; i < n; i++)
			if (i != column)
				variables[row][i] = false;
		return true;
	}

	bool copy[20][20];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			copy[i][j] = variables[i][j];

	for (int i = 0; i < n; i++)
		if (i != column)
			variables[row][i] = false;
	for (int i = 1; i < n; i++)
	{
		if (row + i == n)
			break;
		variables[row + i][column] = false;
		if (column + i < n)
			variables[row + i][column + i] = false;
		if (column - i >= 0)
			variables[row + i][column - i] = false;
	}

	row++;
	for (int i = 0; i < n; i++)
		if (variables[row][i])
			if (CSP(row, i))
				return true;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			variables[i][j] = copy[i][j];

	return false;
}

int main() {
	cout << "Enter n (number of queens and size of the board): ";
	cin >> n;
	if (n < 4)
	{
		cout << endl << "There is no possible answer for n = " << n ;
		_getch();
		return 0;
	}
	else if (n > 20)
	{
		cout << endl << "n is too big";
		_getch();
		return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			variables[i][j] = true;

	for (int i = 0; i < n; i++)
	{
		if (CSP(0, i))
		{
			cout << endl << "One possible answer : " << endl;
			for (int row = 0; row < n; row++)
			{
				cout << endl << endl;
				for (int column = 0; column < n; column++)
				{
					if (variables[row][column])
						cout << "q\t";
					else
						cout << "*\t";
				}
				cout << endl;
			}
			break;
		}
	}
	
	
	_getch();
	return 0;
}