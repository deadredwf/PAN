using namespace std;

#include <iostream>
#include <locale>
#include <cmath>

struct Aircraft {
    double m;
    double t;
    double cl;
    double cd;
    double ay;
    double time;
    int id;
};

double calculateLift(double ro, double v, double s, double cl) {
    return 0.5 * ro * v * v * s * cl;
}

double calculateAy(double l, double m, double g) {
    return (l - m * g) / m;
}

double calculateTime(double h, double ay) {
    if (ay <= 0) return 1e9;
    return sqrt((2 * h) / ay);
}

int main() {
    setlocale(LC_ALL, "Russian");

    double ro = 0.0;
    double v = 0.0;
    double s = 0.0;
    double h = 0.0;
    int n = 0;
    const double g = 9.81;

    cout << "Введите плотность воздуха (ro, кг/м^3): ";
    cin >> ro;
    cout << "Введите скорость полета (V, м/с): ";
    cin >> v;
    cout << "Введите площадь крыла для всех самолетов (S, м^2): ";
    cin >> s;
    cout << "Введите заданную высоту (h, м): ";
    cin >> h;
    cout << "Введите количество самолетов: ";
    cin >> n;

    Aircraft* planes = new Aircraft[n];

    for (int i = 0; i < n; i++) {
        planes[i].id = i + 1;
        cout << "\n--- Самолет " << planes[i].id << " ---" << endl;
        cout << "Масса (m, кг): ";
        cin >> planes[i].m;
        cout << "Тяга двигателя (T, Н): ";
        cin >> planes[i].t;
        cout << "Коэффициент подъемной силы (C_L): ";
        cin >> planes[i].cl;
        cout << "Коэффициент сопротивления (C_D): ";
        cin >> planes[i].cd;

        double l = calculateLift(ro, v, s, planes[i].cl);
        planes[i].ay = calculateAy(l, planes[i].m, g);
        planes[i].time = calculateTime(h, planes[i].ay);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (planes[j].time > planes[j + 1].time) {
                Aircraft temp = planes[j];
                planes[j] = planes[j + 1];
                planes[j + 1] = temp;
            }
        }
    }

    cout << "\nРезультаты (отсортированы по времени набора высоты):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Самолет " << planes[i].id << ": Ускорение ay = " << planes[i].ay << " м/с^2; ";
        if (planes[i].ay <= 0) {
            cout << "Ошибка: ay <= 0" << endl;
        }
        else {
            cout << "Время = " << planes[i].time << " с" << endl;
        }
    }

    delete[] planes;

    return 0;
}