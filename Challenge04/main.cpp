/* Challenge 04 - BST and Linked List search time
 * Author: Andrew Blythe (cab1361)
 * Date: 2024-4-15
 * 
*/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <string>
#include <map>
#include "BST.h"
#include "LinkedList.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::string;
using std::map;
using std::cout;

int randomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}
// fill your array of size=count with random numbers
void getRandomNumbers(int* arr, int count, int min, int max)
{
    for (int i = 0; i < count; ++i)
    {
        arr[i] = randomNumber(min, max);
    }
}

/* Inserts numbers to a data structure, searches for 'findMe', and appends the 
*  duration to 'list_of_times'. *Requires data_structure.insert() and data_structure.find() 
*  to exist. 
*  @param dataStructure, arr, count, findMe, list_of_times */
template<typename T>
void insert_search_time(T &dataStructure, int* arr, int count, int findMe, map<string, duration<double>> &list_of_times) 
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {    // Insert array contents to data structure
        dataStructure.insert(arr[i]);
    }
    cout << dataStructure.name << " find(" << findMe << "): " << dataStructure.find(findMe) << "\n";  // Find the value
    auto stop = high_resolution_clock::now();                                               // Record stop time
    list_of_times["1 dozen random"] = duration_cast<duration<double>>(stop - start);         // Store the duration
}

/* @param dataStructure, start, end, step, findMe, list_of_times */
template<typename T>
void populateSequentially(T &dataStructure, int start, int end, int step, int findMe, map<string, duration<double>> &list_of_times) 
{
    auto start = high_resolution_clock::now();
    for (int i = start; ((step > 0) ? i <= end : i >= end); i += step) {
        dataStructure.insert(i);
    }
    cout << dataStructure.name << " find(" << findMe << "): " << dataStructure.find(findMe) << "\n";
}


int main() 
{
    srand(time(NULL));  //random number generator using the current time as the seed.

    BST bst;
    LinkedList list;
    
    /* Each scenario:
     * - defines a value to seach for
     * - get a batch of random numbers
     *    - BST and LinkedList separately...
     *      - record start time
     *      - insert the batch
     *      - find the value
     *      - record stop time
     */

    map<std::string, duration<double>> bst_times;   // BST times dictionary: "operation description" and "time"
    map<std::string, duration<double>> list_times;  // LL times dictionary: "operation description" and "time"
    int count = -1;
    int findMe = -1;

    // 1 dozen random numbers
    count = 12;
    findMe = randomNumber(1, 1000);
    int nums[count];
    getRandomNumbers(nums, count, 1, 1000);

    insert_search_time(bst, nums, count, findMe, bst_times);
    insert_search_time(list, nums, count, findMe, list_times);

    // Got what we needed, destroy the evidence.
    bst.~BST();
    list.~LinkedList();


    // 2 dozen random numbers
    count = 24;
    findMe = randomNumber(1, 1000);
    int nums[count];
    getRandomNumbers(nums, count, 1, 1000);

    insert_search_time(bst, nums, count, findMe, bst_times);
    insert_search_time(list, nums, count, findMe, list_times);

    // Got what we needed, destroy the evidence.
    bst.~BST();
    list.~LinkedList();


    // 200 random numbers
    count = 200;
    findMe = randomNumber(1, 1000);
    int nums[count];
    getRandomNumbers(nums, count, 1, 1000);

    insert_search_time(bst, nums, count, findMe, bst_times);
    insert_search_time(list, nums, count, findMe, list_times);

    // Got what we needed, destroy the evidence.
    bst.~BST();
    list.~LinkedList();


    // 1 through 1k backwards
    count = 1000;
    findMe = randomNumber(1, 1000);
    int nums[count];

    populateSequentially(bst, 1000, 1, -1, findMe, bst_times);
    populateSequentially(list, 1000, 1, -1, findMe, list_times);

    bst.~BST();
    list.~LinkedList();


    // 1 through 1k forwards
    count = 1000;
    findMe = randomNumber(1, 1000);
    int nums[count];

    populateSequentially(bst, 1, 1000, 1, findMe, bst_times);
    populateSequentially(list, 1, 1000, 1, findMe, list_times);

    bst.~BST();
    list.~LinkedList();


    if (bst_times.size() == list_times.size()) //verify we didn't have a slipup
    {
        int nameWidth = 30;
        int numWidth = 10;
        std::cout << std::setfill('-') << std::setw(nameWidth + numWidth) << "" << std::setfill(' ') << '\n';  // Draw a line

        for (const auto& pair : bst_times) 
        {
            std::string bst_label = "BST " + pair.first + ":";
            std::string ll_label = "LL " + pair.first + ":";

            std::cout << std::left << std::setw(nameWidth) << bst_label
                    << std::right << std::setw(numWidth) << std::fixed 
                    << std::setprecision(7) << pair.second.count() << '\n';

            std::cout << std::left << std::setw(nameWidth) << ll_label
                    << std::right << std::setw(numWidth) << std::fixed 
                    << std::setprecision(7) << pair.second.count() << '\n';
        }
    }
    else
    {
        std::cerr << "There is a missing or extra operation duration record in the BST and LinkedList times" << std::endl;
    }

    return 0;
}