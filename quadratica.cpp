#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, x1, x2, delta;

    // Pedir ao usuário para digitar os coeficientes a, b e c
    cout << "Digite o coeficiente a: ";
    cin >> a;

    cout << "Digite o coeficiente b: ";
    cin >> b;

    cout << "Digite o coeficiente c: ";
    cin >> c;

    // Calcular o delta
    delta = b * b - 4 * a * c;

    // Verificar se a equação tem raízes reais
    if (delta < 0) {
        cout << "A equacao nao possui raizes reais." << endl;
    } else if (delta == 0) {
        x1 = -b / (2 * a);
        cout << "A equacao possui uma raiz real: " << x1 << endl;
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "A equacao possui duas raizes reais: " << x1 << " e " << x2 << endl;
    }

    return 0;
}
