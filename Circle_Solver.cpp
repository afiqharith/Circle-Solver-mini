// ECE 431
// Circle Solver by group 3

//Member:   1. Afiq Harith Bin Ahamad
//          2. Zulfikar Firdaus Bin Kamis
//          3. Nursyamimi Binti Norazrin

//1. Control structure  *
//3. Function           *
//4. Array              *
//5. Pointers           *
//6. File processing    *
//7. Structure          *

#include <iostream>
#include <cmath> //using math library
#include <fstream> //input and output stream class to operate on files
#include <stdlib.h> // "cls" & "pause"
#include <iomanip> //set precision
#include <windows.h> //timer
using namespace std;

struct abnew{
    double anew = 232;
    double bnew = 320;
} newcenter;

//function prototype
double radius(double, double, double, double);
double radianX(double, double, double);
double radianY(double, double, double);
double xnew(double, abnew newcenter, double);
double ynew(double, abnew newcenter, double);


//variable
const double pi = 3.14159265;
int user;

int main(){

restart:
    cout << endl;
    cout << "       ::::    ::::  ::::::::::: ::::    ::: :::::::::::      :::::::::  :::::::::   ::::::::  ::::::::::: :::::::::: :::::::: :::::::::::\n";
    cout << "       +:+:+: :+:+:+     :+:     :+:+:   :+:     :+:          :+:    :+: :+:    :+: :+:    :+:     :+:     :+:       :+:    :+:    :+:    \n";
    cout << "       +:+ +:+:+ +:+     +:+     :+:+:+  +:+     +:+          +:+    +:+ +:+    +:+ +:+    +:+     +:+     +:+       +:+           +:+    \n";
    cout << "       +#+  +:+  +#+     +#+     +#+ +:+ +#+     +#+          +#++:++#+  +#++:++#:  +#+    +:+     +#+     +#++:++#  +#+           +#+    \n";
    cout << "       +#+       +#+     +#+     +#+  +#+#+#     +#+          +#+        +#+    +#+ +#+    +#+     +#+     +#+       +#+           +#+    \n";
    cout << "       #+#       #+#     #+#     #+#   #+#+#     #+#          #+#        #+#    #+# #+#    #+# #+# #+#     #+#       #+#    #+#    #+#    \n";
    cout << "       ###       ### ########### ###    #### ###########      ###        ###    ###  ########   #####      ########## ########     ###\n\n\n\n";

    cout << "              ######  #### ########   ######  ##       ########     ######   #######  ##       ##     ## ######## ########\n";
    cout << "             ##    ##  ##  ##     ## ##    ## ##       ##          ##    ## ##     ## ##       ##     ## ##       ##     ## \n";
    cout << "             ##        ##  ##     ## ##       ##       ##          ##       ##     ## ##       ##     ## ##       ##     ## \n";
    cout << "             ##        ##  ########  ##       ##       ######       ######  ##     ## ##       ##     ## ######   ########  \n";
    cout << "             ##        ##  ##   ##   ##       ##       ##                ## ##     ## ##        ##   ##  ##       ##   ##   \n";
    cout << "             ##    ##  ##  ##    ##  ##    ## ##       ##          ##    ## ##     ## ##         ## ##   ##       ##    ##  \n";
    cout << "              ######  #### ##     ##  ######  ######## ########     ######   #######  ########    ###    ######## ##     ## by Group 3\n";
    cout << endl;
    cout <<endl;
    system ("pause");
    system ("cls");

    // constant old center point a,b
    double a = 256; //a centerOld
    double b = 256; //b centerOld

    //array & pointer
    double rad[100]; // total value of radius = 100
    double *ptrrad = rad; // pointer rad
    double angleX[100]; // total value of degree = 100
    double angleY[100]; // total value of degree = 100

    //array refer by Xnew func & Ynew func
    double xbaru[100]; //total value of Xnew array size =100
    double ybaru[100]; // total value of Ynew array size = 100

    //array from file txt
    double x[100]; //total value of x in txt file=100
    double y[100]; //total value of y in txt file=100

    //pointer from file txt
    double *ptrx = x; // array using pointer
    double *ptry = y; // array using pointer

    ifstream read("appendix1_g3.txt"); //read value of x and y in appendix1_g3 txt file

    main_again:
            cout << "\nQuestion 1: \n";
            cout << "Table below shows values of Radius, Angles of X and Y when center point is C(a, b) = C(256,256).\n";
            cout << "\nNote: For reference, the list of the angles recorded in Degree.txt file.\n";


            cout << "\n _______________________________________________\n";
            cout << "|No.\t|Coor X\t|Coor Y\t|Radius\t|AngleX\t|AngleY\t|\n";
            cout << " _______________________________________________\n";

        for(int i=0;i<100;i++){

            read >> x[i]; // read value of x from appendix1_g3
            read >> y[i]; // read value of y from appendix1_g3

            //function call
            //function call radius
            rad[i] = radius(x[i], y[i], a, b); //sub values calculated in function radius() into rad[i]
            //function call radian for x
            angleX[i] = radianX(rad[i], x[i], a);// sub values calculated in function radianX() into angleX[i]
            //function call radian for y
            angleY[i] = radianY(rad[i], y[i], b);// sub values calculated in function radianY() into angleY[i]

            double radnew = rad[i];
            double radXnew = angleX[i];
            double radYnew = angleY[i];

            //function call for new x given Q2
            xbaru[i] = xnew(radnew, newcenter, radXnew);// sub values calculated in xnew() function into xbaru
            //function call for new y given Q2
            ybaru[i] = ynew(radnew, newcenter, radXnew);// sub values calculated in ynew() function into ybaru

        cout << fixed << showpoint << setprecision(2); // set decimal places to 2decimal
        cout << "|" <<i+1 << "\t|" << *(ptrx+i) << "\t|" << *(ptry+i) << "\t|" << *(ptrrad+i) << "\t|" << (angleX[i]*180)/pi << "\t|" << (angleY[i]*180)/pi << "\t|\n";
        cout << "|\t|\t|\t|\t|\t|\t|\n";
        }

        cout << "-------------------------------------------------\n\n\n";
        cout << "Proceed to next question . . .\n";

    //save to txt file
    ofstream write1("Angle_in_Degree.txt");
        write1 << "COS X\tSIN Y" << endl;
        for (int i=0; i< 100; i++){

            write1 << (angleX[i]*180)/pi << "\t" << (angleY[i]*180)/pi << endl; //
        }
        write1.close(); //close to write new txt file for Q2

        system ("pause");
        system ("cls");

    main_again2:
        cout << "\nQuestion 2: \n";
        cout << "The points of X and Y changed when new center point is given. New center point,C(a, b) = C(232, 320).\n";
        cout << "Note: For reference, the new X and Y points recorded in PointXYnew.txt  file.\n\n";

    //Q2 save to txt file
    ofstream write2("PointXYnew.txt");
        write2 << "Points X\tPoints Y\n";

        for (int i=0; i<100; i++){
            write2 << xbaru[i] << "\t\t" << ybaru[i] << endl; //write value of x&y into txt file

        }

        cout << " _______________________\n";
        cout << "|No.\t|X new\t|Y new  |\n";
        cout << " _______________________\n";

            for(int i=0; i<100; i++){

                cout << "|" << i+1 << "\t|" << xbaru[i] << "\t|" << ybaru[i] << " |\n";
                cout << "|\t|\t|\t|\n";

            } //for loop

            cout << "-------------------------\n";
            system ("pause");
            system ("cls");


            cout << "\n\t\t****************************\n";
            cout << "\t\t*                          *\n";
            cout << "\t\t* 1- Return to Question 1  *\n";
            cout << "\t\t* 2- Return to Question 2  *\n";
            cout << "\t\t* 3- Restart program       *\n";
            cout << "\t\t* 0- Exit                  *\n";
            cout << "\t\t*                          *\n";
            cout << "\t\t****************************\n\n";

            again:
            cout << "Enter any selection: \n";
            cin >> user;

                if (user == 0){

                    system ("cls");
                    cout << "\nEnd of program. Thank you!\n\n";
                    return 0; // return 0
                }

                if (user == 1){

                    system ("cls"); //refresh system
                    goto main_again; //looping to main_again
                }

                if (user == 2){

                    system ("cls");
                    goto main_again2;
                }

                if (user == 3){

                    system ("cls");
                    goto restart;
                }

                if (user != 0 && user != 1 && user != 2 && user != 3){

                    cout << "Invalid command!\n\n";
                    goto again;
                }

    return 0;
} //main function


//function definition
//calculation of radius
double radius(double x,double y,double a,double b){

    return sqrt(pow((x-a),2)+pow((y-b),2));
}

//calculation of angle for x (COS X)
double radianX(double radius, double x, double a){

        return acos((x-a)/radius);
}

//calculation of angle for y (SIN Y)
double radianY(double radius, double y, double b){

    return asin((y-b)/radius);
}

//calculation of xnew
double xnew(double radnew, abnew newcenter, double radXnew){

   return (radnew*cos(radXnew)) + newcenter.anew;
}

//calculation of ynew
double ynew(double radnew, abnew newcenter, double radYnew){

   return (radnew*sin(radYnew)) + newcenter.bnew;
}
