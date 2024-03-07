#include <iostream>
#include <string>



int main()
{
    int myNums[15];

    for (int i = 0; i < 15; i++)
    {
        // generate random number between 1 and 100
        myNums[i] = rand() % 100 + 1;
    }

    //print to screen...
    for (int i = 0; i < 15; i++)
    {
        std::cout << myNums[i] << "\n";
    }


    return 0;
}