/**
 * @file Big-O-notation.cpp
 * @author Andrew
 * @brief Practice - Sorting Algorithms and Big O Analysis
    Objective: Implement two sorting algorithms (Bubble Sort and Insertion Sort) in C++ and 
    analyze their time complexities using Big O notation.
 * @version 0.1
 * @date 2024-02-08
 */

#include <iostream>
#include "delay.h" //my delay function

//Pass me array and size. I print.
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}


/**
 * @brief Prints an array and highlights two elements at i=a and i=b.
 * You should print `\\r` after each call in a loop. 
 * You should also print `'\\n'` before first call and after the last call.
 * 
 * @param arr
 * @param size (required to be greater than 2)
 * @param a index of first element updated (default = 0)
 * @param b index of second element updated (default = 1)
 * @param delay_milliseconds (default = 100)
 */
void highlightElements(int arr[], int size, int a=0, int b=1, int delay_milliseconds = 100)
{
    for (int i=0; i < size; i++)
    {
        delay(delay_milliseconds);
        if (i == a || i == b) //catch the updated elements
        {
            // delay(100);
            std::cout << "(" << arr[i] << ") ";
        }
        else 
            std::cout << arr[i] << " "; // normal print

        delay(delay_milliseconds);
    }
}

/**
 * @brief 
 * - traverse from left and compare adjacent elements and the higher one is placed at right side. 
 * - In this way, the largest element is moved to the rightmost end at first. 
 * - This process is then continued to find the second largest and place it and so on until the data is sorted.
 * 
 * @param myNums 
 * @param size 
 * @return none
 */
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
                highlightElements(arr, n, j, j+1);
                std::cout << "\r";
            }
        }
 
        // If no two elements were swapped by inner loop, then break
        if (swapped == false) 
            break;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i]; //key = current item
        j = i - 1; //j = previous item

        highlightElements(arr, n, j, j+1); //highlight items to be swapped
        // std::cout << "\r"; //print over self effect
        std::cout << "\n";

        // Move elements of arr[0..i-1], that are greater than key (aka out of order), 
        // to one position ahead of their current position.
        while ((j >= 0) && (arr[j] > key)) 
        {   
            arr[j+1] = arr[j]; //swap items
            j = j-1; //decrement j
        }
        arr[j + 1] = key;
    }
}

int main() 
{
    std::cout << "Menu: \n"
            << "1. Bubble Sort\n"
            << "2. Insertion Sort\n"
            << "\nEnter your choice: ";

    int choice = 0;
    std::cin >> choice;

    int myNums[15] = {42, 68, 35, 1, 83, 70, 53, 25, 79, 59, 63, 65, 6, 46, 82};
    std::cout << "\n";


    if (choice == 1)
    {
        bubbleSort(myNums, 15);

        std::cout << "\nSorted array: \n";
        printArray(myNums, 15);
    }
    else if (choice == 2)
    {
        std::cout << "\n"; //line break 
        insertionSort(myNums, 15);

        std::cout << "\n";
        printArray(myNums, 15);
    }

    return 0;
}