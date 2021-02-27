// ECE 431
// Circle Solver by group 3
//1. Control structure  X
//3. Function           *
//4. Array              *
//5. Pointers           *
//6. File processing    *
//7. Structure          X

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;

const double centroidA = 256;
const double centroidB = 256;
const double new_centroidA = 232;
const double new_centroidB = 320;
const double pi = 3.14159265;
const int SIZE = 100;

double x[SIZE], y[SIZE], radius_val[SIZE], angle_x[SIZE], angle_y[SIZE]; // Question 1
double new_x[SIZE], new_y[SIZE];                                         // Question 2

// usage of pointer
double *ptrnew_x = new_x;
double *ptrnew_y = new_y;

class Calculation
{

public:
    // Calculate radius
    double radius(double x, double y, double centroidA, double centroidB)
    {
        return sqrt(pow((x - centroidA), 2) + pow((y - centroidA), 2));
    }

    // Calculate angle for x (cos x)
    double radian_x(double radius_val, double x, double centroidA)
    {
        return acos((x - centroidA) / radius_val);
    }

    // Calculate angle of y (sin y)
    double radian_y(double radius_val, double y, double centroidA)
    {
        return asin((y - centroidA) / radius_val);
    }

    // Get new x value
    double get_new_x(double radius_val, double new_centroidA, double angle_x)
    {
        return (radius_val * cos(angle_x)) + new_centroidA;
    }

    // Get new y value
    double get_new_y(double radius_val, double new_centroidB, double angle_y)
    {
        return (radius_val * sin(angle_y)) + new_centroidB;
    }

} * cal;

int main()
{
    int index;

    ifstream read("appendix1_g3.txt");
    ofstream writexy("new_xy.csv");
    ofstream write_angle_deg("angle_in_degree.csv");

    cal = new Calculation;

    for (index = 0; index < SIZE; index++)
    {
        read >> x[index];
        read >> y[index];

        // Question 1
        radius_val[index] = cal->radius(x[index], y[index], centroidA, centroidB);
        angle_x[index] = cal->radian_x(radius_val[index], x[index], centroidA);
        angle_y[index] = cal->radian_y(radius_val[index], y[index], centroidB);

        // Question 2
        new_x[index] = cal->get_new_x(radius_val[index], new_centroidA, angle_x[index]);
        new_y[index] = cal->get_new_y(radius_val[index], new_centroidB, angle_y[index]);

        // writexy << new_x[index] << "," << new_y[index] << endl;
        writexy << *(ptrnew_x + index) << "," << *(ptrnew_y + index) << endl;
        write_angle_deg << ((angle_x[index] * 180) / pi) << "," << ((angle_y[index] * 180) / pi) << endl;
    }
    writexy.close();
    write_angle_deg.close();

    return 0;
}