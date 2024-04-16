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
*  @param dataStructure, arr, count, findMe, list_of_times 
*  @return double `duration`    */
template<typename T>
double insert_search_time(T &dataStructure, int* arr, int count, int findMe) 
{
    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {    // Insert array contents to data structure
        dataStructure.insert(arr[i]);
    }
    // Find the value, prints 0 for failure and 1 for success
    cout << dataStructure.name << " find(" << findMe << "): " << dataStructure.find(findMe) << "\n";
    auto stopTime = high_resolution_clock::now();                     // Record stop time
    auto totalTime = duration_cast<duration<double>>(stopTime - startTime);
    return totalTime.count();
}

/* @param dataStructure, start, end, step, findMe, list_of_times 
* @return double `duration` */
template<typename T>
double populateSequentially(T &dataStructure, int start, int end, int step, int findMe) 
{
    auto startTime = high_resolution_clock::now();
    for (int i = start; ((step > 0) ? i <= end : i >= end); i += step) {
        dataStructure.insert(i);
    }
    // Find the value, prints 0 for failure and 1 for success
    cout << dataStructure.name << " find(" << findMe << "): " << dataStructure.find(findMe) << "\n";
    auto stopTime = high_resolution_clock::now();                   // Record stop time
    auto totalTime = duration_cast<duration<double>>(stopTime - startTime);
    return totalTime.count();
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

    map<std::string, double > bst_times;   // BST times dictionary: "operation description" and "time"
    map<std::string, double > list_times;  // LL times dictionary: "operation description" and "time"
    int count = -1;
    int findMe = -1;
    int maxCount = 1000;
    int nums[maxCount];

    // 1 dozen random numbers
    findMe = randomNumber(1, 1000);
    count = 12;
    getRandomNumbers(nums, count, 1, 1000);

    bst_times["1 dozen random numbers"] = insert_search_time(bst, nums, count, findMe);
    list_times["1 dozen random numbers"] = insert_search_time(list, nums, count, findMe);

    // Got what we needed, destroy the evidence.
    bst.clear();
    list.clear();


    // 2 dozen random numbers
    findMe = randomNumber(1, 1000);
    count = 24;
    getRandomNumbers(nums, count, 1, 1000);

    bst_times["2 dozen random numbers"] = insert_search_time(bst, nums, count, findMe);
    list_times["2 dozen random numbers"] = insert_search_time(list, nums, count, findMe);

    // Got what we needed, destroy the evidence.
    bst.clear();
    list.clear();


    // 200 random numbers
    findMe = randomNumber(1, 1000);
    count = 200;
    getRandomNumbers(nums, count, 1, 1000);

    bst_times["200 random numbers"] = insert_search_time(bst, nums, count, findMe);
    list_times["200 random numbers"] = insert_search_time(list, nums, count, findMe);

    // Got what we needed, destroy the evidence.
    bst.clear();
    list.clear();


    // 1 through 1k backwards
    findMe = randomNumber(1, 1000);

    bst_times["1 through 1k backwards"] = populateSequentially(bst, 1000, 1, -1, findMe);
    list_times["1 through 1k backwards"] = populateSequentially(list, 1000, 1, -1, findMe);

    bst.clear();
    list.clear();


    // 1 through 1k forwards
    findMe = randomNumber(1, 1000);

    bst_times["1 through 1k forwards"] = populateSequentially(bst, 1, 1000, 1, findMe);
    list_times["1 through 1k forwards"] = populateSequentially(list, 1, 1000, 1, findMe);

    bst.clear();
    list.clear();


    if (bst_times.size() == list_times.size()) //verify we didn't have a slipup
    {
        int nameWidth = 30;
        int numWidth = 10;
        std::cout << std::setfill('-') << std::setw(nameWidth + numWidth) << "" << std::setfill(' ') << '\n';  // Draw a line

        auto bst_pair = bst_times.begin();
        auto list_pair = list_times.begin();

        while (bst_pair != bst_times.end() && list_pair != list_times.end())
        {
            std::string bst_label = bst_pair->first + " BST:";
            std::string ll_label = list_pair->first + "  LL:";

            std::cout << std::left << std::setw(nameWidth) << bst_label
                    << std::right << std::setw(numWidth) << std::fixed 
                    << std::setprecision(7) << bst_pair->second << " s\n";

            std::cout << std::left << std::setw(nameWidth) << ll_label
                    << std::right << std::setw(numWidth) << std::fixed 
                    << std::setprecision(7) << list_pair->second << " s\n";
            std::cout << "\n";

            bst_pair++;
            list_pair++;
        }
    }
    else
    {
        std::cerr << "There is a missing or extra operation duration record in the BST and LinkedList times" << std::endl;
    }

    return 0;
}