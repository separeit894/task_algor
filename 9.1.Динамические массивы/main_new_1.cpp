#include <iostream>
#include <iomanip>

using namespace std;


double myFunction(double x) {
    return (x * x * x) - (x * x) - (4 * x) + 4; 
}

int main() {
    setlocale(LC_ALL, "RUS");
    int size;
    double start, end;


    cout << "Введите размер массива: ";
    cin >> size;
    cout << "Введите начальное значение: ";
    cin >> start;
    cout << "Введите конечное значение: ";
    cin >> end;


    double* array = new double(size);


    double step = (end - start) / (size - 1);
    for (int i = 0; i < size; ++i) {
        array[i] = myFunction(start + i * step);
    }

    cout << "Элементы массива:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << fixed << setprecision(2) << array[i] << " ";
    }
    cout << endl;


    double sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    cout << "Сумма элементов массива: " << sum << endl;


    delete[] array;

    return 0;
}
