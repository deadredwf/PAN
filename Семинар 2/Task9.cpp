using namespace std;

#include <iostream>
#include <locale>

struct Aircraft {
    double m;
    double s;
    double t;
    double cl;
    double cd;
    double l;
    double d;
    double ay;
    int id;
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

int main() {
    setlocale(LC_ALL, "Russian");

    double ro = 0.0;
    double v = 0.0;
    int n = 0;
    const double g = 9.81;

    cout << "Введите плотность воздуха (ro, кг/м^3): ";
    cin >> ro;
    cout << "Введите скорость полета (V, м/с): ";
    cin >> v;
    cout << "Введите количество конфигураций самолетов N: ";
    cin >> n;

    Aircraft* planes = new Aircraft[n];

    for (int i = 0; i < n; i++) {
        planes[i].id = i + 1;
        cout << "\n-------- Самолет " << planes[i].id << " --------" << endl;
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
    }

    cout << "\nРезультаты расчетов:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Самолет " << planes[i].id << ": Подъемная сила = " << planes[i].l
            << " Н, Сопротивление = " << planes[i].d
            << " Н, Ускорение ay = " << planes[i].ay << " м/с^2" << endl;
    }

    int bestIdx = 0;
    for (int i = 1; i < n; i++) {
        if (planes[i].ay > planes[bestIdx].ay) {
            bestIdx = i;
        }
    }

    cout << "\nНаибольшее ускорение имеет самолет " << planes[bestIdx].id
        << " (ay = " << planes[bestIdx].ay << " м/с^2)" << endl;

    delete[] planes;

    return 0;
}