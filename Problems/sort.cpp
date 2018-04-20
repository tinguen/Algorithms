#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
vector<T> shell_sort(vector<T> &arr, bool (*compare)(T, T)) {
    int length = arr.size();
    int step = floor(length / 2);
    while (step >= 1) {
        for (int i = step; i < length; i++) {
            for (int j = i; j > 0; j = j - step) {
                int index = j - step;
                if (index < 0) continue;
                bool condition = compare(arr[j], arr[index]);
                if (condition) {
                    T tmp = arr[j];
                    arr[j] = arr[index];
                    arr[index] = tmp;
                }
            }
        }
        step = step / 2;
    }
    return arr;
}

template <typename T>
int partition(vector<T> &arr, int start, int end, bool (*compare)(T, T)) {
    T pivot = arr[end];
    int index = start - 1;
    for (int i = start; i < end; i++) {
        bool condition = compare(arr[i], pivot);
        if (condition) {
            index += 1;
            T tmp = arr[index];
            arr[index] = arr[i];
            arr[i] = tmp;
        }
    }
    T tmp = arr[end];
    arr[end] = arr[index + 1];
    arr[index + 1] = tmp;
    return index;
}

template <typename T>
vector<T> quicksort(vector<T> &arr, int start, int end, bool (*compare)(T, T)) {
    if (start < end) {
        int index = partition(arr, start, end, compare);
        quicksort(arr, start, index, compare);
        quicksort(arr, index + 1, end, compare);
    }
    return arr;
}
