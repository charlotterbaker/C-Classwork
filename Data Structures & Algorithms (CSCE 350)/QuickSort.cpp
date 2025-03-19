#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;

//Median of 3 function
int medianOfThree(vector<float>& arr, int left, int right){
    int mid = left + (right - left) / 2;
    if (arr[left] > arr[mid]) swap(arr[left], arr[mid]);
    if (arr[left] > arr[right]) swap(arr[left], arr[right]);
    if (arr[mid] > arr[right]) swap(arr[mid], arr[right]);
    
    return mid;
}
//Partition function
int partition(vector<float>& arr, int left, int right){
    int pivotIndex = medianOfThree(arr, left, right);
    swap(arr[left], arr[pivotIndex]); //Move pivot to beginning
    float pivot = arr[left];
    int i = left + 1;
    for (int j = left + 1; j <= right; j++){
        if(arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[left], arr[i-1]); //Place pivot in correct index position
    return i-1;
}
//Quicksort recursive function
void quickSort(vector<float>& arr, int left, int right){
    if (left < right){
        int pivotIndex = partition(arr, left, right);
        quickSort(arr, left, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, right);
    }
}

int main(int argc, char* argv[]){
    if (argc != 3){
        cerr << "Usage: " << argv[0] << " input.txt output.txt" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    ofstream outputFile(argv[2]);
    ofstream timeFile("execution_time.txt");

    if (!inputFile || !outputFile || !timeFile){
        cerr << "Error opening files." << endl;
        return 1;
    }

    vector<float> arr;
    float num;
    while (inputFile >> num) {
        arr.push_back(num);
    }

    auto start = chrono::high_resolution_clock::now();
    quickSort(arr, 0, arr.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, micro> duration = end - start;

    for (float val : arr) {
        outputFile << val << " ";
    }

    timeFile << "Execution Time: " << duration.count() << " microseconds" << endl;

    inputFile.close();
    outputFile.close();
    timeFile.close();

    return 0;

}