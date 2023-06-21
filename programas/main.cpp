#include <iostream>
#include <fstream>
#include <cmath>

// Fun��o que define as equa��es diferenciais
void equations(double x, double p, double& dx_dt, double& dp_dt) {
    dx_dt = p;
    dp_dt = -x;
}

int main() {
    // Par�metros do problema
    double k = 1.0; // Constante de mola
    double m = 1.0; // Massa
    double dt = 0.01; // Passo de tempo
    double t_max = 100.0; // Tempo m�ximo de simula��o

    // Condi��es iniciais
    double x0 = 1.0; // Posi��o inicial
    double p0 = 0.0; // Momento inicial

    // Vari�veis de estado
    double x = x0;
    double p = p0;

    // Abrir arquivo para escrita
    std::ofstream file("euler.txt");
    if (!file.is_open()) {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    // Integra��o num�rica usando o m�todo de Euler
    double t = 0.0;
    while (t <= t_max) {
        // Escrever os valores de x e p no arquivo
        file << x << " " << p << std::endl;

        // Calcular as derivadas
        double dx_dt, dp_dt;
        equations(x, p, dx_dt, dp_dt);

        // Atualizar os valores de x e p usando o m�todo de Euler
        x += dx_dt * dt;
        p += dp_dt * dt;

        // Avan�ar o tempo
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
