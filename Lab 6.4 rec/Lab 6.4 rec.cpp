#include <iostream>
#include <cmath>

void createArray(double* arr, int n, int index = 0) {
    if (index < n) {
        arr[index] = 1.0 * rand() / RAND_MAX * 200 - 100;
        createArray(arr, n, index + 1);
    }
}

void printArray(const double* arr, int n, int index = 0) {
    if (index < n) {
        std::cout << arr[index] << " ";
        printArray(arr, n, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

int findMinIndex(const double* arr, int n, int index = 0, int minIndex = 0) {
    if (index < n) {
        if (arr[index] < arr[minIndex]) {
            minIndex = index;
        }
        return findMinIndex(arr, n, index + 1, minIndex);
    }
    return minIndex;
}

double sumBetweenNegativesHelper(const double* arr, int n, int index, int firstNegIndex, double sum) {
    if (index < n) {
        if (arr[index] < 0) {
            if (firstNegIndex == -1) {
                firstNegIndex = index;
            }
            else {
                for (int j = firstNegIndex + 1; j < index; j++) {
                    sum += arr[j];
                }
                return sum;
            }
        }
        return sumBetweenNegativesHelper(arr, n, index + 1, firstNegIndex, sum);
    }
    return sum;
}

double sumBetweenNegatives(const double* arr, int n) {
    return sumBetweenNegativesHelper(arr, n, 0, -1, 0);
}

void transformArrayHelper(double* arr, int n, int index, int positiveIndex) {
    if (index < n) {
        if (std::abs(arr[index]) <= 1.0) {
            std::swap(arr[index], arr[positiveIndex]);
            positiveIndex++;
        }
        transformArrayHelper(arr, n, index + 1, positiveIndex);
    }
}

void transformArray(double* arr, int n) {
    transformArrayHelper(arr, n, 0, 0);
}

int main() {
    int n;
    std::cout << "Print size masive: ";
    std::cin >> n;

    double* arr = new double[n];
    createArray(arr, n);

    std::cout << "initial masive: ";
    printArray(arr, n);

    int minIndex = findMinIndex(arr, n);
    double sumBetween = sumBetweenNegatives(arr, n);

    std::cout << "number of minimal element: " << minIndex << std::endl;
    std::cout << "The sum of elements between the first and second negative: " << sumBetween << std::endl;

    transformArray(arr, n);

    std::cout << "mod masive: ";
    printArray(arr, n);

    delete[] arr; 

    return 0;
}
