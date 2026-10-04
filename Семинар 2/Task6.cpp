using namespace std;

#include <iostream>
#include <locale>

double calculateLift(double ro, double v, double s, double cl) {
    return 0.5 * ro * v * v * s * cl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double s = 0.0;
    double cl = 0.0;
    int n = 0;

    cout << "Введите площадь крыла (S, м^2): ";
    cin >> s;
    cout << "Введите коэффициент подъемной силы (C_L): ";
    cin >> cl;
    cout << "Введите количество шагов траектории: ";
    cin >> n;

    double* v = new double[n];
    double* ro = new double[n];

    for (int i = 0; i < n; i++) {
        cout << "Шаг " << i + 1 << " - Скорость (V, м/с): ";
        cin >> v[i];
        cout << "Шаг " << i + 1 << " - Плотность воздуха (ro, кг/м^3): ";
        cin >> ro[i];
    }

    cout << "\n| Шаг | Скорость | Плотность | Подъемная сила |" << endl;
    cout << "---------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        double l = calculateLift(ro[i], v[i], s, cl);
        cout << "|  " << i + 1 << "  |   " << v[i] << "   |    " << ro[i] << "    |      " << l << "       |" << endl;
    }

    delete[] v;
    delete[] ro;

    return 0;
}
