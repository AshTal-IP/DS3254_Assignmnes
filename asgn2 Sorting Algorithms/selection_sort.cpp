#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm> // For std::shuffle
#include <random> // Include for std::shuffle and random number generator

// Function to get the index of the minimum element
int getMin(int x[], int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (x[i] < x[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

// Selection sort implementation
void selection_sort(int x[], int size) {
    for (int i = 0; i < size; i++) {
        int min = getMin(x, i, size - 1);
        int temp1 = x[i];
        int temp2 = x[min];
        x[i] = temp2;
        x[min] = temp1;
    }
}

// Function to generate a sequential array (1 to size)
void generateSequentialArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

int main() {
    std::ofstream outputFile("selection_execution_times.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file for writing!" << std::endl;
        return 1;
    }

    srand(static_cast<unsigned>(time(0))); // Seed for random number generation


    for (int size = 1000; size <= 50000; size += 2000) {
        double totalExecTime = 0.0;

        int* arr = new int[size]; // Dynamically allocate array
        generateSequentialArray(arr, size); // Generate sequential array

	
         std::random_device rd;                       // Obtain a random number from hardware
            std::mt19937 g(rd());                  // Seed the generator

        // Perform 10 iterations for each input size
        for (int iter = 0; iter < 5; iter++) {
                                    
             std::shuffle(arr, arr + size, g);            // Permute the array randomly
            auto start = std::chrono::high_resolution_clock::now(); // Start time

            selection_sort(arr, size); // Sort the array

            auto end = std::chrono::high_resolution_clock::now(); // End time
            std::chrono::duration<double> execTime = end - start; // Execution time

            totalExecTime += execTime.count(); // Accumulate execution time
        }

        double avgExecTime = totalExecTime / 5; // Average execution time

        // Write input size and average execution time to the file
        outputFile << "Input Size: " << size << ", Avg Execution Time: " << avgExecTime << " seconds" << std::endl;

        delete[] arr; // Free dynamically allocated memory
    }

    outputFile.close();
    std::cout << "Execution times recorded in 'execution_times.txt'." << std::endl;

    return 0;
}
