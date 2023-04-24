#include <iostream>
#include <cmath>

using namespace std;

double f(double x)
{
    double a = 1.0; // Amplitude da gaussiana
    double mu = 0.0; // Média da gaussiana
    double sigma = 1.0; // Desvio padrão da gaussiana
    double fx = a * exp(-pow((x - mu), 2) / (2.0 * pow(sigma, 2))); // Função gaussiana
    return fx;
}

double dfdx(double x, double h)
{
    double df;
    df = (f(x+h) - f(x)) / h; // Fórmula da primeira derivada numérica
    return df;
}

int main()
{
    double x = 0.5; // Ponto no qual a derivada será calculada
    double h = 0.01; // Tamanho do passo
    double df;

    df = dfdx(x, h);

    cout << "A primeira derivada numérica de f(x) em x = " << x << " é " << df << endl;

    return 0;
}
