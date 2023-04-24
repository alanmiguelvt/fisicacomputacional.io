#include <iostream>
#include <cmath>

using namespace std;

double gaussian(double x, double mu, double sigma) {
    return exp(-(x - mu) * (x - mu) / (2 * sigma * sigma)) / (sqrt(2 * M_PI) * sigma);
}

double trapezoidal_integral(double a, double b, int n, double mu, double sigma) {
    double h = (b - a) / n;
    double sum = 0.5 * (gaussian(a, mu, sigma) + gaussian(b, mu, sigma));
    for (int i = 1; i < n; i++) {
        double x_i = a + i * h;
        sum += gaussian(x_i, mu, sigma);
    }
    return h * sum;
}

int main() {
    double a = -10.0;
    double b = 10.0;
    int n = 1000;
    double mu = 0.0;
    double sigma = 1.0;
    double result = trapezoidal_integral(a, b, n, mu, sigma);
    cout << "Integral da Gaussiana de -10 a 10: " << result << endl;
    return 0;
}
