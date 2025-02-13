#include <iostream>
#include <cmath>

using std::cout, std::endl, std::cin;

void Square(float a, float b) {
    
    // float a является острым углом, а float b является прилегающему к нему катету.
    if (a < 0 || a > 90) {
        cout << "ОШИБКА!\nУгол должен быть в диапазоне от 0 до 90 градусов\n" << endl;
    } else if (b < 0) {
        cout << "ОШИБКА!\nКатет должен быть положительным\n" << endl;
    } else {
        float radian_a = a * (M_PI / 180.0);
        float the_catheter = b  * tan(radian_a);
        float S = 0.5 * (b * the_catheter);
        cout << "Площадь этого треугольника: " << S << endl << endl;
    }

}

int main() {
    setlocale(LC_ALL, "RUS");

    float a, b;
    for (int i = 1; i <= 10; i++) {
        printf("Введите острый угол треугольника %i: ", i);
        cin >> a;
        printf("Введите прилегающий к нему катет: ");
        cin >> b;
        Square(a, b);

    }

    /*
    Угол: 30°, Прилежащий катет: 5.0
    Угол: 45°, Прилежащий катет: 7.0
    Угол: 60°, Прилежащий катет: 4.0
    Угол: 15°, Прилежащий катет: 3.0
    Угол: 75°, Прилежащий катет: 6.0
    Угол: 25°, Прилежащий катет: 8.0
    Угол: 50°, Прилежащий катет: 2.5
    Угол: 40°, Прилежащий катет: 9.0
    Угол: 10°, Прилежащий катет: 1.0
    Угол: 70°, Прилежащий катет: 3.5
    */

}