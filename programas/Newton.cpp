#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

const int N = 4; // número de pontos para interpolação

// função para calcular as diferenças divididas de Newton
void div_diff(double *x, double *y, double *coef) {
    for (int i = 0; i < N; i++) {
        coef[i] = y[i];
    }

    for (int j = 1; j < N; j++) {
        for (int i = N-1; i >= j; i--) {
            coef[i] = (coef[i] - coef[i-1]) / (x[i] - x[i-j]);
        }
    }
}

// função para avaliar a função interpolada em um ponto x
double eval_interp(double *x, double *coef, double x_interp) {
    double result = coef[N-1];
    for (int i = N-2; i >= 0; i--) {
        result = coef[i] + (x_interp - x[i]) * result;
    }
    return result;
}

int main() {
    double x[N] = {1, 2, 3, 4};
    double y[N] = {4, 15, 40, 85};

    // calcular os coeficientes da interpolação
    double coef[N];
    div_diff(x, y, coef);

    // avaliar a função interpolada em 100 pontos uniformemente distribuídos entre 1 e 4
    int num_points = 100;
    double x_interp[num_points];
    double y_interp[num_points];
    double delta_x = (x[N-1] - x[0]) / (num_points-1);
    for (int i = 0; i < num_points; i++) {
        x_interp[i] = x[0] + i * delta_x;
        y_interp[i] = eval_interp(x, coef, x_interp[i]);
    }

    // exibir os resultados na tela
    cout << "x_interp\ty_interp\n";
    for (int i = 0; i < num_points; i++) {
        cout << x_interp[i] << "\t" << y_interp[i] << endl;
    }

    // salvar os resultados em um arquivo
    ofstream outfile("dadosnewton.txt");
    outfile << "x_interp\ty_interp\n";
    for (int i = 0; i < num_points; i++) {
        outfile << x_interp[i] << "\t" << y_interp[i] << endl;
    }
    outfile.close();

    cout << "Os valores interpolados foram salvos em dadosnewton.txt.\n";

    return 0;
}
