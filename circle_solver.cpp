/*
ECE 431
Circle Solver by Group 3
1. Control structure  X
3. Function           *
4. Array              *
5. Pointers           *
6. File processing    *
7. Structure          X
*/

#include <iostream>
#include <direct.h>
#include <fstream>
#include <string>
#include <cmath>
#include <array>

#define PI 3.14159265
#define N 100

// Variable for Question 1 (Q1)
std::array<double, N> x, y, radius_val, angle_x, angle_y;

// Variable for Question 2 (Q2)
double *new_x = new double[N];
double *new_y = new double[N];

class Calculation
{
private:
    const int centroid_A;
    const int centroid_B;
    const int new_centroid_A;
    const int new_centroid_B;

public:
    // Initializer list for given const value
    Calculation() : centroid_A(256), centroid_B(256), new_centroid_A(232), new_centroid_B(320) {}

    // Calculate radius
    double radius(double x, double y)
    {
        return sqrt(pow((x - centroid_A), 2) + pow((y - centroid_A), 2));
    }

    // Calculate angle for x (cos x)
    double radian_x(double radius_val, double x)
    {
        return acos((x - centroid_A) / radius_val);
    }

    // Calculate angle of y (sin y)
    double radian_y(double radius_val, double y)
    {
        return asin((y - centroid_A) / radius_val);
    }

    // Get new x value
    double get_new_x(double radius_val, double angle_x)
    {
        return (radius_val * cos(angle_x)) + new_centroid_A;
    }

    // Get new y value
    double get_new_y(double radius_val, double angle_y)
    {
        return (radius_val * sin(angle_y)) + new_centroid_B;
    }
};

int main()
{
    mkdir("./data/processed_data/");
    std::ifstream read("./data/raw_data/appendix1_g3.txt");
    std::ofstream writexy("./data/processed_data/new_xy.csv");
    std::ofstream write_angle_deg("./data/processed_data/angle_in_degree.csv");

    Calculation *cal = new Calculation;

    for (int i = 0; i < N; i++)
    {
        read >> x[i] >> y[i];

        // Question 1
        radius_val[i] = cal->radius(x[i], y[i]);
        angle_x[i] = cal->radian_x(radius_val[i], x[i]);
        angle_y[i] = cal->radian_y(radius_val[i], y[i]);

        // Question 2
        *(new_x + i) = cal->get_new_x(radius_val[i], angle_x[i]);
        *(new_y + i) = cal->get_new_y(radius_val[i], angle_y[i]);

        writexy << *(new_x + i) << "," << *(new_y + i) << std::endl;
        write_angle_deg << ((angle_x[i] * 180) / PI) << "," << ((angle_y[i] * 180) / PI) << std::endl;
    }
    writexy.close();
    write_angle_deg.close();
    delete[] new_x;
    delete[] new_y;
    delete cal;
    std::cout << "Calculation ended" << std::endl;
    return 0;
}