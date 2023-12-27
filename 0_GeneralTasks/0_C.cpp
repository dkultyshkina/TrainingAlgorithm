/*
Нахождение самого короткого расстояния между двумя заданными точками с условием: можно двигаться по окружности и по радиусам 
*/

#include <iostream>
#include <math.h>

int main()
{
    double x_a, x_b, y_a, y_b, a, b;
    double result = 0.0;
    std::cin >> x_a >> y_a >> x_b >> y_b;
    a = atan2(y_a, x_a);
    b = atan2(y_b, x_b);
    double corner = 0;
    if (a > b) {
        corner = a - b;
    }
    else {
        corner = abs(b - a);
    }
    double R_a = sqrt(pow(y_a, 2) + pow(x_a, 2));
    double R_b = sqrt(pow(y_b, 2) + pow(x_b, 2));
    if (R_a > R_b) {
        result = R_b * corner;
        result = (R_a - R_b) + result;
    }
    else {
        result = R_a * corner;
        result = (R_b - R_a) + result;
    }
    if (R_a + R_b < result) {
        result = R_a + R_b;
    }

    printf("%.32f", result);
}
