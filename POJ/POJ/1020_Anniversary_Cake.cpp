#include <iostream>
#include <cstdlib>

using namespace std;

int sizeArray[16];
int col[64];
int sizeOfCake;

bool dfs(int a)
{
	if (a == pieceOfCake)
		return true;

	int minX = 10, colIndex;
	for (int i = 0; i < sizeOfCake; ++i)
	{
		if (minX > col[i])
		{
			minX = col[i];
			colIndex = i;
		}
	}

	for (int size = 10; size > 0; --size)
	{
		if (!sizeArray[size])
			continue;

		if (sizeOfCake - col[colIndex] >= size && sizeOfCake - colIndex + 1 >= size)
		{
			int t = 0;
			for (int c = colIndex; c < colIndex + size; ++c)
			{
				if (col[c] == col[colIndex])
				{
					++t;
					continue;
				}
				break;
			}

			if (t == size)
			{
				--sizeArray[szie];
				for (int c = colIndex; c < colIndex + size; ++c)
				{
					col[c] += size;
				}

				if (dfs(a + 1))
					return true;
				++sizeArray[size];

				for (int c = colIndex; c < colIndex + size; ++c)
					col[c] -= size;
			}
		}
	}

	return false;
}

void reset()
{
	memset(sizeArray, 0, sizeof(sizeArray));
	sizeOfCake = 0;
}

int main(void)
{
	int numberOfCase = 0;
	sizeOfCake = 0;
	int pieceOfCake = 0;
	int sum = 0;

	cin >> numberOfCase;
	
	while (cin >> sizeOfCake >> pieceOfCake)
	{
		reset();
		for (int i = 0; i < pieceOfCake; ++i)
		{
			int s = 0;
			cin >> s;
			++sizeArray[s];

			sum += s * s;
		}

		if (sum != sizeOfCake * sizeOfCake)
			cout << "HUTUTU!";

		if (dfs(0))
			cout << "KHOOOOB!";
		else
			cout << "HUTUTU!";

		--numberOfCase;
		if (0 == numberOfCase)
			break;
	}

		
	
	system("pause");
	return 0;
}