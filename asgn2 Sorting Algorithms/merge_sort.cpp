#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm> // For std::shuffle
#include <random> // Include for std::shuffle and random number generator

// Merge Sort Helper function declaration
void merge_sort_helper(int x[], int start, int end);

// Merge function to merge two sorted halves
void merge(int x[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        left[i] = x[start + i];
    }
    for (int j = 0; j < n2; j++) {
        right[j] = x[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    // Merge the temp arrays back into the original array
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            x[k] = left[i];
            i++;
        } else {
            x[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[] if any
    while (i < n1) {
        x[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[] if any
    while (j < n2) {
        x[k] = right[j];
        j++;
        k++;
    }
}

// Merge Sort function
void merge_sort(int x[], int size) {
    // Call mergeSort to sort the array
    merge_sort_helper(x, 0, size - 1);
}

// Helper function for merge sort
void merge_sort_helper(int x[], int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        // Recursively sort the first and second halves
        merge_sort_helper(x, start, mid);
        merge_sort_helper(x, mid + 1, end);

        // Merge the sorted halves
        merge(x, start, mid, end);
    }
}




// Function to generate a sequential array (1 to size)
void generateSequentialArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
}

int main() {
    std::ofstream outputFile("merge_execution_times.txt");

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

            merge_sort(arr, size); // Sort the array

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
