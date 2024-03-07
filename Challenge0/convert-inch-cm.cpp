/**
 * @file convert-inch-cm.cpp
 * @author Andrew Blythe (cab1361)
 * @brief Challenge 0
 * ...... 2383-02 Data Structures and Algorithms
 * @date 2024-02-02 
 */

#include <iostream>
#include <iomanip>
#include <string> 

// using namespace std;

using std::string;
using std::cout;
using std::cin;

void convert(float *measurement);

int main()
{
    string userInput = "";
    float measurement = 0.0;

    cout << "**Inches to Centimeters conversion** \nEnter inches: ";
    cin >> userInput;

    std::istringstream iss(userInput);

    // if userInput successfully converts to float...
    if (iss >> measurement) 
    {
        cout << std::setprecision(3);
        cout << std::fixed << std::showpoint;

        cout << measurement << " in = ";
        convert(&measurement); // pass address of measurement, function will modify it

        cout << measurement << " cm\n";
    } 
    else 
        cout << "\nError:  Input must be a number." << "\n";

    cout << "\n";
    return 0;
}

/**
 * Converts the given measurement from inches to centimeters at the memory location.
 * @param measurement a pointer to the measurement (`float`) in inches
 * @return void
 */
void convert(float *measurement)
{
    *measurement = *measurement * 2.54;
}