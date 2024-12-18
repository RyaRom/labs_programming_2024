#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

typedef double (*Tfun)(double);

double integrall(double, double, int, double, Tfun, double);

double fun0(double x);

double fun1(double x);

double fun2(double x);

double fun3(double x);

double fun4(double x);

double fun5(double x);

double fun6(double x);

double fun7(double x);

double fun8(double x);

double fun9(double x);

double fun10(double x);

double fun11(double x);

double fun12(double x);

double fun13(double x);

double fun14(double x);

double fun15(double x);

double fun16(double x);

double fun17(double x);

double fun18(double x);

double fun19(double x);

double fun20(double x);

int lab3_main() {
    int i = 0;
    int n = 10000;
    double x, y;
    double eps = 0.000001;
    double s = 0;

    cout << '\n' << "Enter the coordinates of the point (x, y): ";
    cin >> x >> y;

    if (y > 1 && y < 2 && x > -2 && x < 0 && x * x + (y - 1) * (y - 1) > 1) {
        cout << "The point is in Region M1. " << endl;
        i = 1;
    } else if (x > -1 && x < 1 && y > -1 && y < 1 &&
               (x + 1) * (x + 1) + (y + 1) * (y + 1) > 1 &&
               (x + 1) * (x + 1) + (y - 1) * (y - 1) > 1 &&
               (x - 1) * (x - 1) + (y + 1) * (y + 1) > 1 &&
               (x - 1) * (x - 1) + (y - 1) * (y - 1) > 1) {
        cout << "The point is in Region M2. " << endl;
        i = 2;
    } else if (x > 1 && x < 2 && y > -1 && y < 1 &&
               (x - 1) * (x - 1) + (y + 1) * (y + 1) > 1 &&
               (x - 1) * (x - 1) + (y - 1) * (y - 1) > 1) {
        cout << "The point is in Region M3. " << endl;
        i = 3;
    } else if ((x + 1) * (x + 1) + (y + 1) * (y + 1) < 1 &&
               (x + 1) * (x + 1) + y * y > 1 && x * x + (y + 1) * (y + 1) > 1) {
        cout << "The point is in Region M4. " << endl;
        i = 4;
    } else if ((x - 1) * (x - 1) + y * y > 1 && x * x + y * y > 1 &&
               x * x + (y + 1) * (y + 1) < 1 && (x - 1) * (x - 1) + (y + 1) * (y + 1) < 1) {
        cout << "The point is in Region M5. " << endl;
        i = 5;
    } else {
        cout << "The point is outside the defined regions." << endl;
    }

    cout.precision(4);
    double intersect1 = -1 - sqrt(3) / 2.0;
    double intersect2 = -0.5;
    double intersect3 = 0.5;
    switch (i) {
        case 1:
            cout << "Formula: S1 = " << 2 - M_PI / 4 << endl;
            cout << "Integral S1 = " << integrall(-2, -1, n, eps, fun2, s) + integrall(-1, 0, n, eps, fun0, s) << endl;
            break;
        case 2:
            cout << "Formula: S2 = " << 4 - M_PI << endl;
            cout << "Integral S2 = " << integrall(-1, 0, n, eps, fun3, s) + integrall(0, 1, n, eps, fun4, s) +
                    fabs(integrall(-1, 0, n, eps, fun5, s)) + fabs(integrall(0, 1, n, eps, fun6, s)) << endl;
            break;
        case 3:
            cout << "Formula: S3 = " << 2 - M_PI / 2 << endl;
            cout << "Integral S3 = " << integrall(1, 2, n, eps, fun7, s) + fabs(integrall(1, 2, n, eps, fun6, s)) << endl;
            break;
        case 4:
            cout << "Formula: S4 = " << M_PI / 4 + 2 * (M_PI / 4 - (2 * M_PI / 3 - sqrt(3) / 2) / 2) << endl;
            cout << "Integral S4 = " << fabs(integrall(-2, intersect1, n, eps, fun10, s))
                    + fabs(integrall(intersect1, -1, n, eps, fun11, s)) + fabs(
                        integrall(-1, intersect2, n, eps, fun14, s)) << endl;
            break;
        case 5:
            cout << "Formula: S5 = " << 1 - (1 - M_PI / 4) - (sqrt(3) / 2 + M_PI / 3 - M_PI / 4 - 1) << endl;
            cout << "Integral S5 = " << fabs(integrall(0, intersect3, n, eps, fun19, s)) + fabs(integrall(
                intersect3, 1, n, eps, fun20, s)) << endl;
            break;
    }

    return 0;
}

double integrall(double a, double b, int n, double eps, Tfun fun, double s1) {
    double x, h, s = 0;
    int i;
    h = (b - a) / n;
    for (i = 0; i < n; i++) {
        x = a + i * h + h / 2;
        s += fun(x);
    }
    s *= h;
    if (fabs(s - s1) > eps)
        s = integrall(a, b, 2 * n, eps, fun, s);
    return s;
}

//M1
double funConst1(double x) {
    return 1;
}

double funConst2(double x) {
    return 2;
}

double fun0(double x) {
    return funConst2(x) - fun1(x);
}

double fun1(double x) {
    return funConst1(x) + sqrt(1 - x * x);
}

double fun2(double x) {
    return funConst2(x) - funConst1(x);
}

//M2
double fun3(double x) {
    return 1 - sqrt(1 - (x + 1) * (x + 1));
}

double fun4(double x) {
    return 1 - sqrt(1 - (x - 1) * (x - 1));
}

double fun5(double x) {
    return -1 + sqrt(1 - (x + 1) * (x + 1));
}

double fun6(double x) {
    return -1 + sqrt(1 - (x - 1) * (x - 1));
}

//M3
double fun7(double x) {
    return 1 - sqrt(1 - (x - 1) * (x - 1));
}

//M4

double fun8(double x) {
    return -1 + sqrt(1 - (x + 1) * (x + 1));
}

double fun9(double x) {
    return -1 - sqrt(1 - (x + 1) * (x + 1));
}

double fun10(double x) {
    return fun9(x) - fun8(x);
}

double fun11(double x) {
    return fun9(x) - fun12(x);
}

double fun12(double x) {
    return -sqrt(1 - (x + 1) * (x + 1));
}

double fun13(double x) {
    return -1 - sqrt(1 - x * x);
}

double fun14(double x) {
    return fun9(x) - fun13(x);
}

//M5
double fun15(double x) {
    return -1 - sqrt(1 - (x - 1) * (x - 1));
}

double fun16(double x) {
    return -1 - sqrt(1 - x * x);
}

double fun17(double x) {
    return -sqrt(1 - x * x);
}

double fun18(double x) {
    return -sqrt(1 - (x - 1) * (x - 1));
}

double fun19(double x) {
    return fun15(x) - fun17(x);
}

double fun20(double x) {
    return fun16(x) - fun18(x);
}
