#include <iostream>
#include <cmath>

using std::cin, std::endl, std::cout;

float calculatey(float a) 
{
    if (a > 360) 
    {
        cout << "Угол больше 360" << endl;
        return 1;
    } else if (a < -360) 
    {
        cout << "Угол меньше чем -360" << endl;
        return 1;
    }
    // Перевод угла в радианы
    float a_radians = a * M_PI / 180.0;
    float Y = tan(2.0 * a_radians) * cos(2.0 * a_radians); 
    
    return Y;
}

int main() 
{
    float g = calculatey(70);
    cout << g << endl;
}
