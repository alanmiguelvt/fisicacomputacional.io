#include <iostream>
#include <fstream>
#include <cmath>

// Função que define as equações diferenciais
void equations(double x, double p, double& dx_dt, double& dp_dt) {
    dx_dt = p;
    dp_dt = -x;
}

// Método de Runge-Kutta de segunda ordem
void rungeKutta2(double& x, double& p, double dt) {
    double x1, x2, p1, p2;
    double dx_dt, dp_dt;

    // Primeira etapa
    equations(x, p, dx_dt, dp_dt);
    x1 = x + 0.5 * dt * dx_dt;
    p1 = p + 0.5 * dt * dp_dt;

    // Segunda etapa
    equations(x1, p1, dx_dt, dp_dt);
    x2 = x + dt * dx_dt;
    p2 = p + dt * dp_dt;

    // Atualizar os valores de x e p
    x = x2;
    p = p2;
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
    std::ofstream file("rungekuttaIIoh.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    // Integração numérica usando o método de Runge-Kutta de segunda ordem
    double t = 0.0;
    while (t <= t_max) {
        // Escrever os valores de x e p no arquivo
        file << x << " " << p << std::endl;

        // Atualizar os valores de x e p usando o método de Runge-Kutta de segunda ordem
        rungeKutta2(x, p, dt);

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
