#include <iostream>
#include <fstream>
#include <cmath>

void equations(double x, double p, double& dx_dt, double& dp_dt) {
    dx_dt = p;
    dp_dt = -x;
}

void rungeKutta4(double& x, double& p, double dt) {
    double k1_x, k1_p, k2_x, k2_p, k3_x, k3_p, k4_x, k4_p;
    double dx_dt, dp_dt;

    // K1
    equations(x, p, dx_dt, dp_dt);
    k1_x = dx_dt * dt;
    k1_p = dp_dt * dt;

    // K2
    equations(x + 0.5 * k1_x, p + 0.5 * k1_p, dx_dt, dp_dt);
    k2_x = dx_dt * dt;
    k2_p = dp_dt * dt;

    // K3
    equations(x + 0.5 * k2_x, p + 0.5 * k2_p, dx_dt, dp_dt);
    k3_x = dx_dt * dt;
    k3_p = dp_dt * dt;

    // K4
    equations(x + k3_x, p + k3_p, dx_dt, dp_dt);
    k4_x = dx_dt * dt;
    k4_p = dp_dt * dt;

    // Update the values of x and p
    x += (k1_x + 2.0 * k2_x + 2.0 * k3_x + k4_x) / 6.0;
    p += (k1_p + 2.0 * k2_p + 2.0 * k3_p + k4_p) / 6.0;
}

int main() {
    double k = 1.0;  // Spring constant
    double m = 1.0;  // Mass
    double dt = 0.01;  // Time step
    double t_max = 100.0;  // Maximum simulation time

    double x0 = 1.0;  // Initial position
    double p0 = 0.0;  // Initial momentum

    double x = x0;
    double p = p0;

    std::ofstream file("rungekuttaivoh.txt");
    if (!file.is_open()) {
        std::cout << "Error opening the file." << std::endl;
        return 1;
    }

    double t = 0.0;
    while (t <= t_max) {
        file << x << " " << p << std::endl;
        rungeKutta4(x, p, dt);
        t += dt;
    }

    file.close();

    std::cout << "Simulation completed. Results saved in 'rungekuttaivoh.txt'." << std::endl;

    return 0;
}
