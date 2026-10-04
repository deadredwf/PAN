using namespace std;

#include <iostream>
#include <locale>

int main() {
    setlocale(LC_ALL, "Russian");

    double s = 0.0;    // площадь крыла
    double v = 0.0;    // скорость полета
    double ro = 0.0;   // плотность воздуха
    double cl = 0.0;   // коэффициент подъемной силы

    cout << "=== Расчет подъемной силы самолета ===" << endl;

    // ввод
    cout << "Введите площадь крыла (S, м^2): ";
    cin >> s;
    cout << "Введите скорость полета (V, м/с): ";
    cin >> v;
    cout << "Введите плотность воздуха (rho, кг/м^3): ";
    cin >> ro;
    cout << "Введите коэффициент подъемной силы (C_L): ";
    cin >> cl;

    double l = 0.5 * ro * v * v * s * cl;

    // вывод
    cout << "Расчёт завершен. Подъемная сила L = " << l << " Н" << endl;

    return 0;
}
