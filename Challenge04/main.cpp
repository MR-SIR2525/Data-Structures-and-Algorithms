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
*  to exist. */
template<typename T>
void insert_search_time(T &dataStructure, int* arr, int count, int findMe, map<string, duration<double>> &list_of_times) 
{
    auto start = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {    // Insert array contents to data structure
        dataStructure.insert(arr[i]);
    }
    cout << "Data Structure find(" << findMe << "): " << dataStructure.find(findMe) << "\n";  // Find the value
    auto stop = high_resolution_clock::now();                                               // Record stop time
    list_of_times["1 dozen random"] = duration_cast<duration<double>>(stop - start);         // Store the duration
}


// inserts numbers to a BST sequentially (either forwards or backwards)
void populateSequentially(BST& bst, int start, int end, int step=1) 
{
    for (int i = start; ((step > 0) ? i <= end : i >= end); i += step) {
        bst.insert(i);
    }
}
// inserts numbers to a LinkedList sequentially (either forwards or backwards)
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


    

    //clear BST and List
    bst.~BST();
    list.~LinkedList();
    delete[] nums;


    // TODO: time each insertion and search...

    // 2 dozen random numbers
    insertRandomNumbers(bst, list, 24, 1, 1000);
    findMe = randomNumber(1, 1000);

    start = high_resolution_clock::now();
    cout << "BST find(" << findMe << "): " << bst.find(findMe) << "\n";
    stop = high_resolution_clock::now();
    bst_times["2 dozen random"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    cout << "List find(" << findMe << "): " << list.search(findMe) << "\n";
    stop = high_resolution_clock::now();
    list_times["2 dozen random"] = duration_cast<duration<double>>(stop - start);

    //clear BST and List
    bst.~BST();
    list.~LinkedList();


    // 200 random numbers
    insertRandomNumbers(bst, list, 200, 1, 1000);
    findMe = randomNumber(1, 1000);

    start = high_resolution_clock::now();
    cout << "BST find(" << findMe << "): " << bst.find(findMe) << "\n";
    stop = high_resolution_clock::now();
    bst_times["200 random"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    cout << "List find(" << findMe << "): " << list.search(findMe) << "\n";
    stop = high_resolution_clock::now();
    list_times["200 random"] = duration_cast<duration<double>>(stop - start);

    //clear BST and List
    bst.~BST();
    list.~LinkedList();


    // 1 through 1k backwards
    populateSequentially(bst, list, 1000, 1, -1);
    findMe = randomNumber(1, 1000);

    start = high_resolution_clock::now();
    cout << "BST find(" << findMe << "): " << bst.find(findMe) << "\n";
    stop = high_resolution_clock::now();
    bst_times["1 through 1k backwards"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    cout << "List find(" << findMe << "): " << list.search(findMe) << "\n";  
    stop = high_resolution_clock::now();
    list_times["1 through 1k backwards"] = duration_cast<duration<double>>(stop - start);

    //clear BST and List
    bst.~BST();
    list.~LinkedList();


    // 1 through 1k forwards
    populateSequentially(bst, list, 1, 1000, 1);

    start = high_resolution_clock::now();
    cout << "BST find(" << findMe << "): " << bst.find(findMe) << "\n";
    stop = high_resolution_clock::now();
    bst_times["1 through 1k forwards"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    cout << "List find(" << findMe << "): " << list.search(findMe) << "\n";
    stop = high_resolution_clock::now();
    list_times["1 through 1k forwards"] = duration_cast<duration<double>>(stop - start);

    //clear BST and List
    bst.~BST();
    list.~LinkedList();


    if (bst_times.size() == list_times.size()) 
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

    return 0;
}