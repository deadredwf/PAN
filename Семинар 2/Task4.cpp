using namespace std;

#include <iostream>
#include <locale>
#include <cmath> 

double calculateTime(double h, double ay) {
    return sqrt((2 * h) / ay);
}

int main() {
    setlocale(LC_ALL, "Russian");

    double h = 0.0;
    double ay = 0.0;

    cout << "Введите заданную высоту (h, м): ";
    cin >> h;
    cout << "Введите вертикальное ускорение (ay, м/с^2): ";
    cin >> ay;

    if (ay <= 0 || h <= 0) {
        cout << "Ошибка: ускорение и высота должны быть больше 0" << endl;
        return 1;
    }

    double t = calculateTime(h, ay);

    cout << "\nРасчёт завершен. Время набора высоты t = " << t << " с" << endl;

    return 0;
}
