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
#include <ctime>
using std::ifstream;
using std::ofstream;
using std::string;

const int centroidA = 256;
const int centroidB = 256;
const int new_centroidA = 232;
const int new_centroidB = 320;

const double pi = 3.14159265;
const int SIZE = 100;

double x[SIZE], y[SIZE], radius_val[SIZE], angle_x[SIZE], angle_y[SIZE]; // Question 1
double new_x[SIZE], new_y[SIZE];                                         // Question 2

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

} * cal;

string get_time()
{

    time_t now = time(0);
    char *datetime = ctime(&now);
    return datetime;
}

int main()
{

    int index;
    mkdir("./data/processed-data/");
    ifstream read("./data/raw_data/appendix1_g3.txt");
    ofstream writexy("./data/processed-data/new_xy.csv");
    ofstream write_angle_deg("./data/processed-data/angle_in_degree.csv");

    cal = new Calculation(centroidA, centroidB, new_centroidA, new_centroidB);

    for (index = 0; index < SIZE; index++)
    {
        read >> x[index] >> y[index];

        // Question 1
        radius_val[index] = cal->radius(x[index], y[index]);
        angle_x[index] = cal->radian_x(radius_val[index], x[index]);
        angle_y[index] = cal->radian_y(radius_val[index], y[index]);

        // Question 2
        new_x[index] = cal->get_new_x(radius_val[index], angle_x[index]);
        new_y[index] = cal->get_new_y(radius_val[index], angle_y[index]);

        // writexy << new_x[index] << "," << new_y[index] << endl;
        writexy << *(ptrnew_x + index) << "," << *(ptrnew_y + index) << std::endl;
        write_angle_deg << ((angle_x[index] * 180) / pi) << "," << ((angle_y[index] * 180) / pi) << std::endl;
    }
    writexy.close();
    write_angle_deg.close();
    return 0;
}