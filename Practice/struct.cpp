#include <iostream>
#include <string>
#include <iomanip>

// Define a struct named 'Person'
struct Person {
    std::string name; // Data member for the person's name
    int age;          // Data member for the person's age
    float height;     // Data member for the person's height in meters
};

int main() {
    // Create an instance of the Person struct
    Person person1;
    
    // user inputs values to the data members of person1
    std::cout << "Enter name: ";
    std::cin >> person1.name;
    std::cout << "Enter age: ";
    std::cin >> person1.age;

    // Output the data of person1
    std::cout << "\nPerson 1:" << std::endl;
    std::cout << "Name: " << person1.name << std::endl;
    std::cout << "Age: " << person1.age << std::endl;
    // std::cout << "Height: " << person1.height << " meters" << std::endl;

    return 0;
}
