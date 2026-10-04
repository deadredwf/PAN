using namespace std;

#include <iostream>
#include <locale>

double calculateA(double t, double d, double m) {   // функция для расчёта ускорения по направлению движения
    return (t - d) / m;
}

double calculateAy(double l, double m, double g) {  // функция для расчёта вертикального ускорения
    return (l - m * g) / m;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double m = 0.0;           // масса самолета
    double l = 0.0;           // подъемная сила
    double d = 0.0;           // аэродинамическое сопротивление
    double t = 0.0;           // тяга двигателя
    const double g = 9.81;    // ускорение свободного падения 

    // ввод
    cout << "Введите массу самолета (m, кг): ";
    cin >> m;
    cout << "Введите подъемную силу (L, Н): ";
    cin >> l;
    cout << "Введите аэродинамическое сопротивление (D, Н): ";
    cin >> d;

    cout << "Введите тягу двигателя (T, Н): ";
    cin >> t;

    double a = calculateA(t, d, m);
    double ay = calculateAy(l, m, g);

    // вывод
    cout << "\nРасчёт завершен. Результаты:" << endl;
    cout << "Ускорение по направлению движения a = " << a << " м/с^2" << endl;
    cout << "Вертикальное ускорение ay = " << ay << " м/с^2" << endl;

    return 0;
}
