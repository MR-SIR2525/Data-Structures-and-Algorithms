/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Workspace & Template C++
 * Program description: from time at PRCC
 * Date: 
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>  // input/output manipulation
#include <cstdlib>	// Needed to use the exit function
#include <cmath>    // maths?
#include <cctype>   // Needed for the toupper function
#include <string>
#include <chrono>   
#include <windows.h>// Needed to display colors and call Sleep
#include <ctime>
#include <conio.h>  // for getch() and pausing
#include <fstream>  // Needed to use files
#include <vector>   //
#include <climits>
using namespace std;

template <class T>
T min_16(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <class T>
T max_16(T aa, T bb)
{
    if (aa > bb)
        return aa;
    else 
        return bb;
}

long long factorial_my(int num)
{
    if (num > 1)
        return num * factorial_my(num - 1);
    else
        return 1;
}

int sumArray(int numArr[], int size)
{
    if (size == 0)
        return 0;
    else 
        return numArr[size-1] + sumArray(numArr, size-1);
}

int main()
{
    //call factorial function...
    int num;
    cout << "enter num:  ";
    cin >> num;

    cout << factorial_my(num) << "\n";

    int numbers[5] = {5, 10, 16, 22, 30};
    cout << "sum of nums " << sumArray(numbers, 5);




    return 0;
}