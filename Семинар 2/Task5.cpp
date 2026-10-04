using namespace std;

#include <iostream>
#include <locale>
#include <cmath>

struct airplane {
    double m;
    double s;
    double t;
    double cl;
    double cd;
    double l;
    double d;
    double ay;
    double time;
};

double calculateLift(double ro, double v, double s, double cl) {
    return 0.5 * ro * v * v * s * cl;
}

double calculateDrag(double ro, double v, double s, double cd) {
    return 0.5 * ro * v * v * s * cd;
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
    double h = 0.0;
    const double g = 9.81;

    cout << "Введите плотность воздуха (ro, кг/м^3): ";
    cin >> ro;
    cout << "Введите скорость полета (V, м/с): ";
    cin >> v;
    cout << "Введите заданную высоту (h, м): ";
    cin >> h;

    airplane planes[3];

    for (int i = 0; i < 3; i++) {
        cout << "\n--- Самолет " << i + 1 << " ---" << endl;
        cout << "Масса (m, кг): ";
        cin >> planes[i].m;
        cout << "Площадь крыла (S, м^2): ";
        cin >> planes[i].s;
        cout << "Тяга двигателя (T, Н): ";
        cin >> planes[i].t;
        cout << "Коэффициент подъемной силы (C_L): ";
        cin >> planes[i].cl;
        cout << "Коэффициент сопротивления (C_D): ";
        cin >> planes[i].cd;

        planes[i].l = calculateLift(ro, v, planes[i].s, planes[i].cl);
        planes[i].d = calculateDrag(ro, v, planes[i].s, planes[i].cd);
        planes[i].ay = calculateAy(planes[i].l, planes[i].m, g);
        planes[i].time = calculateTime(h, planes[i].ay);
    }

    cout << "\nРезультаты расчетов:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Самолет " << i + 1 << ": Подъемная сила = " << planes[i].l
            << " Н, Сопротивление = " << planes[i].d
            << " Н, Ускорение ay = " << planes[i].ay << " м/с^2";
        if (planes[i].ay <= 0) {
            cout << " (Не наберет высоту)" << endl;
        }
        else {
            cout << ", Время = " << planes[i].time << " с" << endl;
        }
    }

    int bestIdx = 0;
    for (int i = 1; i < 3; i++) {
        if (planes[i].time < planes[bestIdx].time) {
            bestIdx = i;
        }
    }

    if (planes[bestIdx].ay <= 0) {
        cout << "\nНи один самолет не может набрать заданную высоту." << endl;
    }
    else {
        cout << "\nБыстрее всего наберет высоту самолет " << bestIdx + 1 << endl;
    }

    return 0;
}
