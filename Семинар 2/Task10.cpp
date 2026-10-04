using namespace std;

#include <iostream>
#include <locale>
#include <cmath>

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

    double m = 0.0;
    double s = 0.0;
    double cl = 0.0;
    double ro = 0.0;
    double v = 0.0;
    double h = 0.0;

    double tMin = 0.0;
    double tMax = 0.0;
    double deltaT = 0.0;
    const double g = 9.81;

    cout << "Введите массу самолета (m, кг): ";
    cin >> m;
    cout << "Введите площадь крыла (S, м^2): ";
    cin >> s;
    cout << "Введите коэффициент подъемной силы (C_L): ";
    cin >> cl;
    cout << "Введите плотность воздуха (ro, кг/м^3): ";
    cin >> ro;
    cout << "Введите скорость полета (V, м/с): ";
    cin >> v;
    cout << "Введите заданную высоту (h, м): ";
    cin >> h;

    cout << "Введите минимальную тягу (T_min, Н): ";
    cin >> tMin;
    cout << "Введите максимальную тягу (T_max, Н): ";
    cin >> tMax;
    cout << "Введите шаг изменения тяги (delta T, Н): ";
    cin >> deltaT;

    double l = calculateLift(ro, v, s, cl);
    double ay = calculateAy(l, m, g);

    double bestT = -1.0;
    double minTime = 1e9;

    cout << "\nРезультаты перебора тяги:" << endl;

    for (double t = tMin; t <= tMax; t += deltaT) {
        double currentTime = calculateTime(h, ay);

        cout << "Тяга T = " << t << " Н | Ускорение ay = " << ay << " м/с^2 | Время t = ";
        if (ay <= 0) {
            cout << "Не наберет высоту" << endl;
        }
        else {
            cout << currentTime << " с" << endl;
        }

        if (ay > 0 && currentTime < minTime) {
            minTime = currentTime;
            bestT = t;
        }
    }

    if (bestT == -1.0) {
        cout << "\nНи при одном значении тяги самолет не может набрать высоту." << endl;
    }
    else {
        cout << "\nОптимальное значение тяги T = " << bestT << " Н" << endl;
        cout << "Минимальное время набора высоты = " << minTime << " с" << endl;
    }

    return 0;
}