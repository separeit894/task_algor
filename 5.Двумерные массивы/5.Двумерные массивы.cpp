#include <iostream>

using namespace std;




void printArray(int arr[][100], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}



void editingArray(int arr[][100], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int k = -30 + rand() % 61;
			arr[i][j] = k;
		}
	}
}

void Rearranging_Array_Elements(int arr[][100])
{
	int n;
	cout << "Сколько вы хотите переставить столбцов: ";
	cin >> n;
	cout << endl;

	for (int i = 1; i <= n;)
	{
		i++;
		int row1, col1, row2, col2;

		cout << "Введите строку, с которого будете брать столбец: ";
		cin >> row1;
		cout << "Введите cтолбец, который хотите переставить: ";
		cin >> col1;
		cout << endl;
		cout << "Введите строку, в который будете переставлять столбец: ";
		cin >> row2;
		cout << "Введите cтолбец, который хотите переставить: ";
		cin >> col2;

		int temp = arr[row1][col1];
		arr[row1][col1] = arr[row2][col2];
		arr[row2][col2] = temp;

		cout << endl;

	}

}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));


	int arr[100][100];

	int total_rows, total_cols;
	cout << "Введите кол-во строк в массиве: ";
	cin >> total_rows;
	cout << "Введите кол-во столбцов в массиве: ";
	cin >> total_cols;
	
	editingArray(arr, total_rows, total_cols);
	printArray(arr, total_rows, total_cols);
	Rearranging_Array_Elements(arr);
	printArray(arr, total_rows, total_cols);



	return 0;
}