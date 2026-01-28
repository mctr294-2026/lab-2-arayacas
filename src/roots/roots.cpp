#include "roots.hpp"
#include <iostream>
#include <math.h>

bool bisection(std::function<double(double)> f, double a, double b, double *root)
{
    double mid = 0;
    bool done = true;
    if (f(a) * f(b) <= 0)
    { // Check if there are roots to find
        while (done)
        {
            mid = (a + b) / 2;     // find the middle
            double aprox = f(mid); // f(middle)
            if ((aprox >= 1e-6) || (aprox <= -1e-6))
            { // Is the approx not on the desired interval?
                if (aprox * f(a) >= 0)
                { // If aprox and a are in the same side move a
                    a = mid;
                }
                else
                    b = mid; // othewise move b
            }
            else
            {
                *root = mid;
                done = false;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return false;
}

bool regula_falsi(std::function<double(double)> f, double a, double b, double *root)
{
    double mid = 0;
    bool done = true;
    if (f(a) * f(b) <= 0)
    { // Check if there are roots to find
        while (done)
        {
            mid = a - (f(a) * (b - a)) / (f(b) - f(a)); // find the middle
            double aprox = f(mid);                      // f(middle)
            if ((aprox >= 1e-6) || (aprox <= -1e-6))
            { // Is the approx not on the desired interval?
                if (aprox * f(a) >= 0)
                { // If aprox and a are in the same side move a
                    a = mid;
                }
                else
                    b = mid; // othewise move b
            }
            else
            {
                *root = mid;
                done = false;
                return true;
            }
        }
    }
    else
    {
        return false;
    }
    return false;
}

bool newton_raphson(std::function<double(double)> f, std::function<double(double)> g, double a, double b, 
double c,double *root)
{
    double xn = 0;
    bool done = true;
    double maxc = 0;
    if (f(a) * f(b) <= 0){
            while((done && g(c) != 0)&&(maxc <= 5000)){
                xn = c - (f(c)/g(c));
                if (std::abs(xn - c) <= 1e-6){
                    *root = xn;
                    done = false;
                    return true; 
                }
                else{
                    c = xn;
                }
                maxc += 1;
            }
    }  
    else{
        std::cout << "Could not approximate, either derivative = 0, or too many bounces, or no roots possible" << std::endl;
        return false;
    }
    return false;
}





bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root)
{
    double d = c+0.2; //Second Guess!
    double xn = 0;
    bool done = true;
    double maxc = 0;
    if (f(a) * f(b) <= 0){
            while((done && (f(c)-f(d) != 0))&&(maxc <= 5000)){
                xn = c - f(c)*((c-d)/(f(c)-f(d)));
                if (std::abs(xn - c) <= 1e-6){
                    *root = xn;
                    done = false;
                    return true; 
                }
                else{
                    d = c;
                    c = xn;
                }
                maxc += 1;
            }
    }  
    else{
        std::cout << "Could not approximate, either derivative = 0, or too many bounces, or no roots possible" << std::endl;
        return false;
    }
    return false;  
}
