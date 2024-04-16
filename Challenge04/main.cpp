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
#include "BST.h"
#include "LinkedList.h"

using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::map;
using std::cout;


int randomNumber(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

// insert the same random numbers into both BST and LinkedList
void insertRandomNumbers(BST& bst, LinkedList& list, int count, int min, int max) 
{
    for (int i = 0; i < count; ++i) 
    {
        bst.insert(randomNumber(min, max));
        list.append(randomNumber(min, max));
    }
}

// inserts numbers to a BST & LinkedList sequentially (either forwards or backwards)
void populateSequentially(BST& bst, LinkedList& list, int start, int end, int step=1) 
{
    for (int i = start; ((step > 0) ? i <= end : i >= end); i += step) {
        bst.insert(i);
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


    /* TODO: Add search to each scenario, time that instead. Format output ig. */

    // 1 dozen random numbers
    insertRandomNumbers(bst, list, 12, 1, 1000);
    int findMe = randomNumber(1, 1000);

    start = high_resolution_clock::now();
    cout << "BST find(" << findMe << "): " << bst.find(findMe) << "\n";
    stop = high_resolution_clock::now();
    bst_times["1 dozen random"] = duration_cast<duration<double>>(stop - start);

    start = high_resolution_clock::now();
    cout << "List find(" << findMe << "): " << list.search(findMe) << "\n";
    stop = high_resolution_clock::now();
    list_times["1 dozen random"] = duration_cast<duration<double>>(stop - start);

    //clear BST and List
    bst.~BST();
    list.~LinkedList();

    //are they cleared?
    bst.display(cout);
    list.display(cout);


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



    for (const auto& pair : bst_times) {
    std::cout << "BST - " << pair.first << ": " << pair.second.count() << " seconds\n";
    }

    for (const auto& pair : list_times) {
        std::cout << "LL - " << pair.first << ": " << pair.second.count() << " seconds\n";
    }

    return 0;
}