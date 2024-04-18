/* Challenge 04 - BST and Linked List search time
 * Author: Andrew Blythe (cab1361)
 * Date: 2024-4-15
 * 
*/
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
#include <unordered_map>
#include "BST.h"
#include "LinkedList.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::string;
using std::unordered_map;
using std::cout;
using std::right;
using std::left;
using std::setw;
using std::setprecision;

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

struct Timings {        //{double `timeToInsert`, double `timeToFind`}
    double timeToInsert;
    double timeToFind;
};

// Helper function to format floating point numbers to string with fixed precision
string formatNumber(double value, int n=7) {
    std::ostringstream out;
    out << std::fixed << setprecision(n) << value;
    return out.str();
}

// Prepends "w" if condition is true, otherwise returns an empty space for alignment
string prependWinner(bool condition, const string& text) {
    return (condition ? "w " : "  ") + text;
}

/* Inserts numbers to a data structure, searches for 'findMe', and appends the 
*  duration to 'list_of_times'. *Requires data_structure.insert() and data_structure.find() 
*  to exist. 
*  @param dataStructure, arr, count, findMe, list_of_times 
*  @return Timings {timeToInsert, timeToFind}    */
template<typename T>
Timings insert_search_time(T &dataStructure, int* arr, int count, int findMe) 
{
    double timeToInsert = 0.00;
    double timeToFind = 0.00;

    auto startTime = high_resolution_clock::now();
    for (int i = 0; i < count; ++i) {    // Insert array contents to data structure
        dataStructure.insert(arr[i]);
    }
    auto stopTime = high_resolution_clock::now();
    timeToInsert = duration_cast<duration<double>>(stopTime - startTime).count();

    // Find the value, prints failure or success
    startTime = high_resolution_clock::now();
    cout << setw(11) << right << dataStructure.name 
         << " find(" << setw(3) << right << findMe << "): " 
         << setw(1) << left << (dataStructure.find(findMe) ? "success" : "failure") << "\n";
    stopTime = high_resolution_clock::now();
    timeToFind = duration_cast<duration<double>>(stopTime - startTime).count();

    return {timeToInsert, timeToFind};
}

/* @param dataStructure, start, end, step, findMe, list_of_times 
* @return Timings: {timeToInsert, timeToFind} */
template<typename T>
Timings populateSequentially(T &dataStructure, int start, int end, int step, int findMe) 
{
    double timeToInsert = 0.00;
    double timeToFind = 0.00;

    auto startTime = high_resolution_clock::now();
    for (int i = start; ((step > 0) ? i <= end : i >= end); i += step) {
        dataStructure.insert(i);
    }
    auto stopTime = high_resolution_clock::now();
    timeToInsert = duration_cast<duration<double>>(stopTime - startTime).count();

    // Find the value, print failure or success
    startTime = high_resolution_clock::now();
    cout << setw(11) << right << dataStructure.name 
         << " find(" << setw(3) << right << findMe << "): " 
         << setw(1) << left << (dataStructure.find(findMe) ? "success" : "failure") << "\n";
    stopTime = high_resolution_clock::now();                   // Record stop time
    timeToFind = duration_cast<duration<double>>(stopTime - startTime).count();

    return {timeToInsert, timeToFind};
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

    unordered_map<std::string, Timings > bst_times;  //BST "operation" and {timeToInsert, timeToFind}
    unordered_map<std::string, Timings > list_times; //LL  "operation" and {timeToInsert, timeToFind}
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
    cout << "\n";


    // Print out the results
    if (bst_times.size() == list_times.size()) //verify we didn't have a slipup
    {
        int nameWidth = 25;
        int typeWidth = 12;
        int numWidth = 12;  // Adjusted for space for "w"

        cout << left << setw(nameWidth) << "Description"
            << right << setw(typeWidth) << "Type"
            << right << setw(numWidth + 2) << "Insert Time"
            << right << setw(numWidth + 1) << "Find Time"
            << right << setw(numWidth + 2) << "Total Time" << "\n";

        cout << std::setfill('-') <<  std::setw(nameWidth + 4 * numWidth + 18) << "" << std::setfill(' ') << '\n';  // Draw a line

        auto bst_pair = bst_times.begin();
        auto list_pair = list_times.begin();

        while (bst_pair != bst_times.end() && list_pair != list_times.end()) {
            double bstTotal = bst_pair->second.timeToInsert + bst_pair->second.timeToFind;
            double listTotal = list_pair->second.timeToInsert + list_pair->second.timeToFind;

            // Print BST row
            cout << left << setw(nameWidth) << bst_pair->first
                << right << setw(typeWidth) << "BST"
                << right << setw(numWidth + 2) << prependWinner(bst_pair->second.timeToInsert < list_pair->second.timeToInsert, formatNumber(bst_pair->second.timeToInsert) + "s")
                << right << setw(numWidth + 2) << prependWinner(bst_pair->second.timeToFind < list_pair->second.timeToFind, formatNumber(bst_pair->second.timeToFind) + "s")
                << right << setw(numWidth + 2) << prependWinner(bstTotal < listTotal, formatNumber(bstTotal) + "s");
            cout << "\n";

            // Print LinkedList row
            cout << left << setw(nameWidth) << list_pair->first
                << right << setw(typeWidth) << "LinkedList"
                << right << setw(numWidth + 2) << prependWinner(list_pair->second.timeToInsert < bst_pair->second.timeToInsert, formatNumber(list_pair->second.timeToInsert) + "s")
                << right << setw(numWidth + 2) << prependWinner(list_pair->second.timeToFind < bst_pair->second.timeToFind, formatNumber(list_pair->second.timeToFind) + "s")
                << right << setw(numWidth + 2) << prependWinner(listTotal < bstTotal, formatNumber(listTotal) + "s");
            cout << "\n\n";

            ++bst_pair;
            ++list_pair;
        }
    }
    else
    {
        std::cerr << "There is a missing or extra operation duration record in the BST and LinkedList times" << std::endl;
    }

    return 0;
}