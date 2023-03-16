#include <iostream>
#include <string>
#include <algorithm> // for std::swap

using namespace std;

// Function to swap two values by value
void swapValues(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to sort the array numerically
void sortArrayNumerically(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                swapValues(array[i], array[j]);
            }
        }
    }
}
// Function to swap two values by reference
void swapValues(string& a, string& b)
{
    std::swap(a, b);
}

// Function to sort the array alphabetically
void sortArrayAlphabetically(string array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                swapValues(array[i], array[j]);
            }
        }
    }
}

int main()
{
    int arraySize;
    cout << "Enter the size of the array: ";
    cin >> arraySize;

    // Dynamically allocate memory for the array
    string* stringArray = new string[arraySize];

    // Get the values from the user and store them in the array
    cout << "Enter the values in the array:" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        getline(cin >> ws, stringArray[i]); // trim any whitespace
    }

    // Ask the user whether they want to sort the array numerically or alphabetically
    int choice;
    cout << "Do you want to sort the array numerically (1) or alphabetically (2)? ";
    cin >> choice;

    if (choice == 1)
    {
        // Convert string to int array
        int* intArray = new int[arraySize];
        for (int i = 0; i < arraySize; i++)
        {
            intArray[i] = stoi(stringArray[i]);
        }

        // Sort numerically
        sortArrayNumerically(intArray, arraySize);
        cout << "Sorted array (numerically): ";
        for (int i = 0; i < arraySize; i++)
        {
            cout << intArray[i] << " ";
        }

        // Deallocate the memory allocated for the int array
        delete[] intArray;
    }
    else if (choice == 2)
    {
        // Sort array alphabetically
        sortArrayAlphabetically(stringArray, arraySize);
        cout << "Sorted array (alphabetically): ";
        for (int i = 0; i < arraySize; i++)
        {
            cout << stringArray[i] << " ";
        }
        // Deallocate the memory allocated for the string array
        delete[] stringArray;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}
    
