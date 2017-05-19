#include <iostream>
#include <cstdlib>

using namespace std;

int main(void)
{
	int numberOfCase = 0;
	int sizeOfCake = 0;
	int pieceOfCake = 0;

	cin >> numberOfCase;

	int count = 0;
	
	while (cin >> sizeOfCake)
	{
		cout << numberOfCase << sizeOfCake;

		++count;
		if (count == numberOfCase)
			break;
	}

		
	
	system("pause");
	return 0;
}