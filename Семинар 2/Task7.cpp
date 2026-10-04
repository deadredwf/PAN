using namespace std;

#include <iostream>
#include <locale>

double calculateA(double t, double d, double m) {
    return (t - d) / m;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double m = 0.0;
    double l = 0.0;
    double d = 0.0;
    double t = 0.0;

    cout << "Введите массу самолета (m, кг): ";
    cin >> m;
    cout << "Введите подъемную силу (L, Н): ";
    cin >> l;
    cout << "Введите аэродинамическое сопротивление (D, Н): ";
    cin >> d;
    cout << "Введите тягу двигателя (T, Н): ";
    cin >> t;

    double a = calculateA(t, d, m);

    cout << "\nУскорение самолета: " << a << " м/с^2" << endl;
    cout << "Режим полета: ";

    if (a > 0.5) {
        cout << "«набор высоты»" << endl;
    }
    else if (a >= 0 && a <= 0.5) {
        cout << "«горизонтальный полет»" << endl;
    }
    else {
        cout << "«снижение»" << endl;
    }

    return 0;
}