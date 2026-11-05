/////////////////////////////////////////////////////////////////////
// Name: Your Name Joel Deleon 
// Date: Submission Date: 11/04
// Class: CSCI 1470.0X
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: This program loads words from a dictionary file into
// an array counts the words
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

const bool debug = true;

void initializeArray(string words[], int size);
bool populateArray(string words[], int size, string fileName);
int countWords(string words[], int size)
void printArray(string words[], int size);

int main()
{
    const int MAX_WORDS = 1000;

    string dictionary[MAX_WORDS];

    cout << "*****************************" << endl;
    cout << "Welcome to the spell checker! [UNDER CONSTRUCTION]" << endl;
    cout << "*****************************" << endl;

    auto start = high_resolution_clock::now();

    initializeArray(dictionary, MAX_WORDS);

    auto end = high_resolution_clock::now();

    duration<double, micro> elapsed = end - start;

    if (debug)
    {
        cout << " debug: Initialization took "
             << elapsed.count()
             << " microseconds." << endl;
    }

    start = high_resolution_clock::now();

    bool fileLoaded =
        populateArray(dictionary,
                      MAX_WORDS,
                      "dictionary_small.txt");

    end = high_resolution_clock::now();

    elapsed = end - start;

    if (debug)
    {
        cout << " debug : Loading took "
             << elapsed.count()
             << " microseconds." << endl;
    }

    if (!fileLoaded)
    {
        cout << "Error opening dictionary file." << endl;
        return 1;
    }

    if (debug)
    {
        start = high_resolution_clock::now();

        printArray(dictionary, MAX_WORDS);

        end = high_resolution_clock::now();

        elapsed = end - start;

        cout << "DEBUGGING: Printing took "
             << elapsed.count()
             << " microseconds." << endl;
    }

    start = high_resolution_clock::now();

    int totalWords =
        countWords(dictionary, MAX_WORDS);

    end = high_resolution_clock::now();

    elapsed = end - start;

    cout << "Loaded "
         << totalWords
         << " words from dictionary."
         << endl;

    if (debug)
    {
        cout << " debug: Word count took "
             << elapsed.count()
             << " microseconds." << endl;
    }

    return 0;
}

void initializeArray(string words[], int size)
{
    for (int i = 0; i < size; i++)
    {
        words[i] = "";
    }
}

bool populateArray(string words[],
                   int size,
                   string fileName)
{
    ifstream inputFile(fileName);

    if (!inputFile)
    {
        return false;
    }

    int index = 0;
    string word;

    while (inputFile >> word && index < size)
    {
        words[index] = word;
        index++;
    }

    inputFile.close();

    return true;
}

int countWords(string words[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (words[i] != "")
        {
            count++;
        }
    }

    return count;
}

void printArray(string words[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (words[i] != "")
        {
            cout << i + 1
                 << " "
                 << words[i]
                 << endl;
        }
    }
}