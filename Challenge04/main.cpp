/* Challenge 04 - BST and Linked List search time
 * Author: Andrew Blythe (cab1361)
 * Date: 2024-4-15
 * 
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <map>
#include "BST/BST.h"
#include "LinkedList/LinkedList.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::map;


int randomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

void insertRandomNumbers(BST& bst, int count, int min, int max) 
{
    for (int i = 0; i < count; ++i) 
    {
        bst.insert(randomNumber(min, max));
    }
}
void insertRandomNumbers(LinkedList& list, int count, int min, int max)
{
    for (int i = 0; i < count; ++i)
    {
        list.append(randomNumber(min, max));
    }
}

// inserts numbers to a BST sequentially (either forwards or backwards)
void populateSequentially(BST& bst, int start, int end, int step=1) 
{
    for (int i = start; ((step > 0) ? i <= end : i >= end); i += step) {
        bst.insert(i);
    }
}
// appends numbers to a LinkedList sequentially (either forwards or backwards)
void populateSequentially(LinkedList& list, int start, int end, int step=1)
{
    for (int i = start; ((step > 0) ? i <= end : i >= end); i += step) {
        list.append(i);
    }
}

int main() 
{
    srand(time(NULL));  //random number generator using the current time as the seed.

    BST bst;
    LinkedList list;

    // dictionaries here with "description" and "time"
    map<std::string, duration<double>> bst_times;
    map<std::string, duration<double>> list_times;
    
    //initialize the clock data types to make it fair for each run
    auto start = high_resolution_clock::now();  
    auto stop = start;  


    // 1 dozen random numbers
    start = high_resolution_clock::now();
    insertRandomNumbers(bst, 12, 1, 1000);
    stop = high_resolution_clock::now();
    bst_times["1 dozen random"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    insertRandomNumbers(list, 12, 1, 1000);
    stop = high_resolution_clock::now();
    list_times["1 dozen random"] = duration_cast<duration<double>>(stop - start);


    // 2 dozen random numbers
    start = high_resolution_clock::now();
    insertRandomNumbers(bst, 24, 1, 1000);
    stop = high_resolution_clock::now();
    bst_times["2 dozen random"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    insertRandomNumbers(list, 24, 1, 1000);
    stop = high_resolution_clock::now();
    list_times["2 dozen random"] = duration_cast<duration<double>>(stop - start);


    // 200 random numbers
    start = high_resolution_clock::now();
    insertRandomNumbers(bst, 200, 1, 1000);
    stop = high_resolution_clock::now();
    bst_times["200 random"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    insertRandomNumbers(list, 200, 1, 1000);
    stop = high_resolution_clock::now();
    list_times["200 random"] = duration_cast<duration<double>>(stop - start);


    // 1 through 1k backwards
    start = high_resolution_clock::now();
    populateSequentially(bst, 1000, 1, -1);
    stop = high_resolution_clock::now();
    bst_times["1 through 1k backwards"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    populateSequentially(list, 1000, 1, -1);    
    stop = high_resolution_clock::now();
    list_times["1 through 1k backwards"] = duration_cast<duration<double>>(stop - start);


    // 1 through 1k forwards
    start = high_resolution_clock::now();
    populateSequentially(bst, 1, 1000, 1);
    stop = high_resolution_clock::now();
    bst_times["1 through 1k forwards"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    populateSequentially(list, 1, 1000, 1);
    stop = high_resolution_clock::now();
    list_times["1 through 1k forwards"] = duration_cast<duration<double>>(stop - start);



    for (const auto& pair : bst_times) {
    std::cout << "BST - " << pair.first << ": " << pair.second.count() << " seconds\n";
    }

    for (const auto& pair : list_times) {
        std::cout << "LinkedList - " << pair.first << ": " << pair.second.count() << " seconds\n";
    }

    return 0;
}