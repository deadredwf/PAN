using namespace std;

#include <iostream>
#include <locale>

double calculateDrag(double ro, double v, double s, double cd) { // функция для расчёта
    return 0.5 * ro * v * v * s * cd;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double ro = 0.0;   // плотность воздуха
    double v = 0.0;    // скорость полета
    double s = 0.0;    // площадь крыла
    double cd = 0.0;   // коэффициент сопротивления

    // ввод 
    cout << "Расчет аэродинамического сопротивления. Введите плотность воздуха (ro, кг/м^3): ";
    cin >> ro;
    cout << "Введите скорость полета (V, м/с): ";
    cin >> v;
    cout << "Введите площадь крыла (S, м^2): ";
    cin >> s;
    cout << "Введите коэффициент сопротивления (C_D): ";
    cin >> cd;

    double drag = calculateDrag(ro, v, s, cd);

    // вывод
    cout << "Расчёт завершен. Аэродинамическое сопротивление = " << drag << " Н" << endl;

    return 0;
}