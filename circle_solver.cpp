// ECE 431
// Circle Solver by group 3
//1. Control structure  X
//3. Function           *
//4. Array              *
//5. Pointers           *
//6. File processing    *
//7. Structure          X

#include <iostream>
#include <direct.h>
#include <fstream>
#include <string>
#include <cmath>

#define pi 3.14159265
#define size 100

const int centroidA = 256;
const int centroidB = 256;
const int new_centroidA = 232;
const int new_centroidB = 320;

double x[size], y[size], radius_val[size], angle_x[size], angle_y[size]; // Question 1
double new_x[size], new_y[size];                                         // Question 2

// usage of pointer
double *ptrnew_x = new_x;
double *ptrnew_y = new_y;

class Calculation
{
private:
    int centroid_A;
    int centroid_B;
    int new_centroid_A;
    int new_centroid_B;

public:
    Calculation(int centroidA, int centroidB, int new_centroidA, int new_centroidB)
    {
        centroid_A = centroidA;
        centroid_B = centroidB;
        new_centroid_A = new_centroidA;
        new_centroid_B = new_centroidB;
    }
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

    Calculation *cal = new Calculation(centroidA, centroidB, new_centroidA, new_centroidB);

    for (int i = 1; i <= size; i++)
    {
        read >> x[i] >> y[i];

        // Question 1
        radius_val[i] = cal->radius(x[i], y[i]);
        angle_x[i] = cal->radian_x(radius_val[i], x[i]);
        angle_y[i] = cal->radian_y(radius_val[i], y[i]);

        // Question 2
        new_x[i] = cal->get_new_x(radius_val[i], angle_x[i]);
        new_y[i] = cal->get_new_y(radius_val[i], angle_y[i]);

        writexy << *(ptrnew_x + i) << "," << *(ptrnew_y + i) << std::endl;
        write_angle_deg << ((angle_x[i] * 180) / pi) << "," << ((angle_y[i] * 180) / pi) << std::endl;
    }
    writexy.close();
    write_angle_deg.close();
    std::cout << "Calculation ended" << std::endl;
    return 0;
}