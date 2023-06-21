
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * Calcula a interpolação de Lagrange para um conjunto de pontos (x, y)
 * e retorna o valor interpolado de y correspondente a x_value.
 */
double interpolation_lagrange(vector<double> x, vector<double> y, double x_value) {
    double result = 0;

    for (int i = 0; i < x.size(); i++) {
        double term = y[i];

        for (int j = 0; j < x.size(); j++) {
            if (i != j) {
                term = term * (x_value - x[j]) / (x[i] - x[j]);
            }
        }

        result += term;
    }

    return result;
}

int main() {
    // Pontos conhecidos da função
    vector<double> x {1, 2, 3, 4, 5, 6, 100};
    vector<double> y {4, 15, 40, 85, 156, 259, 1010101};

    // Interpolação em 100 pontos igualmente espaçados entre -100 e 100
    int n_points = 200;
    double step = 200.0 / (n_points - 1);

    // Abre o arquivo de saída
    ofstream output_file("lagrange.txt");

    // Calcula a interpolação para cada ponto e exibe os resultados na tela
    cout << "x\ty" << endl;
    for (int i = 0; i < n_points; i++) {
        double x_value = -100.0 + i * step;
        double interpolated_y = interpolation_lagrange(x, y, x_value);
        cout << x_value << "\t" << interpolated_y << endl;
        // Escreve os resultados no arquivo de saída
        output_file << x_value << "\t" << interpolated_y << endl;
    }

    // Fecha o arquivo de saída
    output_file.close();

    return 0;
}

