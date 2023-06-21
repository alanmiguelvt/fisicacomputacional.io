#include <iostream>
#include <fstream>
#include <cmath>

// Função que define as equações diferenciais
void equations(double x, double p, double& dx_dt, double& dp_dt) {
    dx_dt = p;
    dp_dt = -x;
}

int main() {
    // Parâmetros do problema
    double k = 1.0; // Constante de mola
    double m = 1.0; // Massa
    double dt = 0.01; // Passo de tempo
    double t_max = 100.0; // Tempo máximo de simulação

    // Condições iniciais
    double x0 = 1.0; // Posição inicial
    double p0 = 0.0; // Momento inicial

    // Variáveis de estado
    double x = x0;
    double p = p0;

    // Abrir arquivo para escrita
    std::ofstream file("euler.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    // Integração numérica usando o método de Euler
    double t = 0.0;
    while (t <= t_max) {
        // Escrever os valores de x e p no arquivo
        file << x << " " << p << std::endl;

        // Calcular as derivadas
        double dx_dt, dp_dt;
        equations(x, p, dx_dt, dp_dt);

        // Atualizar os valores de x e p usando o método de Euler
        x += dx_dt * dt;
        p += dp_dt * dt;

        // Avançar o tempo
        t += dt;
    }

    // Fechar o arquivo
    file.close();

    // Mostrar os valores de x e p na tela
    std::cout << "Valores determinados:" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "p = " << p << std::endl;

    return 0;
}
