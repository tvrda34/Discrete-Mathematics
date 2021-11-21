#include <stdio.h>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

void formula(double &x0, double &x1, double &x2, double &a0, double &a1, double &a2, int &n)
{
    double l1, l2, l3, r;
    // sustav 3 jednadzbe sa 3 nepoznanice raspiso sam na papiru i dosao do ovih formula za izracun lamdi
    l3 = (((a2 - a0 * pow(x0, 2)) * (x1 - x0) * (-1)) + (pow(x1, 2) - pow(x0, 2)) * (a1 - a0 * x0)) / (((pow(x1, 2) - pow(x0, 2)) * (x2 - x0)) + (pow(x2, 2) - pow(x0, 2)) * (x1 - x0) * (-1));
    l2 = (a1 - a0 * x0 - (x2 - x0) * l3) / (x1 - x0);
    l1 = a0 - l2 - l3;

    r = l1 * pow(x0, n) + l2 * pow(x1, n) + l3 * pow(x2, n);
    if (fmod(r, 1) != 0)
    {
        cout << "Vrijednost n-tog clana niza pomocu formule: " << std::fixed << std::setprecision(4) << r << endl;
    }
    else
    {
        cout << "Vrijednost n-tog clana niza pomocu formule: " << std::fixed << std::setprecision(0) << r << endl;
    }
}

void rekurzija(double &x0, double &x1, double &x2, double &a0, double &a1, double &a2, int &n)
{
    double k1, k2, k3, r, a0p = a0, a1p = a1, a2p = a2;
    //formule za izracun koeficijenata dobivene iz raspisa na papiru
    k1 = -(-x2 + (-x0 - x1));
    k2 = -((-x0 - x1) * (-x2) + (-x0 * (-x1)));
    k3 = -((-x0 * (-x1)) * (-x2));
    for (int i = 3; i <= n; i++)
    {
        r = k1 * a2p + k2 * a1p + k3 * a0p;
        a0p = a1p;
        a1p = a2p;
        a2p = r;
    }
    if (fmod(r, 1) != 0)
    {
        cout << "Vrijednost n-tog clana niza iz rekurzije: " << std::fixed << std::setprecision(4) << r << endl;
    }
    else
    {
        cout << "Vrijednost n-tog clana niza iz rekurzije: " << std::fixed << std::setprecision(0) << r << endl;
    }
}

int main()
{

    double x0, x1, x2, a0, a1, a2;
    int n;

    cout << "Unesite prvo rjesenje x_0 karakteristicne jednadzbe: ";
    cin >> x0;
    cout << "Unesite drugo rjesenje x_1 karakteristicne jednadzbe: ";
    cin >> x1;
    cout << "Unesite trece rjesenje x_2 karakteristicne jednadzbe: ";
    cin >> x2;
    cout << "Unesite vrijednost nultog clana niza a_0: ";
    cin >> a0;
    cout << "Unesite vrijednost prvog clana niza a_1: ";
    cin >> a1;
    cout << "Unesite vrijednost drugog clana niza a_2: ";
    cin >> a2;
    cout << "Unesite redni broj n trazenog clana niza: ";
    cin >> n;

    formula(x0, x1, x2, a0, a1, a2, n);
    rekurzija(x0, x1, x2, a0, a1, a2, n);

    return 0;
}