#include "sort.cpp"
#include <vector>
#include <string>

//  13. В массиве А находятся элементы. Составить программу, которая сформирует массив В, в котором расположить
//        элементы массива А в порядке убывания.
//  14. Дан упорядоченный массив А - числа, расположенные в порядке возрастания, и число а, которое необходимо
//        вставить в массив А, так,  чтобы упорядоченность массива сохранилась.
//  15. Составить программу для быстрой перестройки данного массива А, в котором элементы расположены в порядке
//        возрастания, так, чтобы  после перестройки эти же элементы оказались расположенными в порядке убывания.
//  16. Дан массив А, содержащий как отрицательные, так и положительные числа. Составить программу исключения
//        из него всех отрицательных чисел, а оставшиеся положительные расположить в порядке их возрастания.
//  17. Составить программу, которая будет из массива А брать одно число за другим и формировать из них массив В,
//        располагая числа в порядке возрастания.
//  18. Дан список авторов в форме массива А. Составить программу формирования указателя авторов в алфавитном порядке
//        и вывести его на экран.
//  19. Имеется n абонентов телефонной станции. Составить программу, в которой формируется  список по форме: номер телефона,
//        фамилия (номера идут в порядке возрастания).
//  20. Имеется n слов различной  длины, все они занесены в массив А.  Составить программу упорядочения слов
//        по возрастанию их длин.
//  21. Составить программу для сортировки массива А по возрастанию и убыванию модулей его элементов.
//  22. В отсортированный массив А. между каждой соседней парой элементов вставить число больше левого
//        и меньше правого элемента в массиве и вывести полученный массив на экран.

// problem 13
vector<int> problem_13(vector<int> arr) {
    bool (*compare)(int, int) = [](int x, int y) { return x > y; };
    shell_sort(arr, compare); // quicksort(arr, 0, arr.size() - 1, compare);
    return arr;
}

// problem 14
void problem_14(vector<int> &arr, int value) {
    for (int i = 0; i < arr.size(); i++) {
        int tmp = arr[i];
        if (value <= arr[i]) {
            arr.insert(arr.begin() + i, 1, 0);
            arr[i] = value;
            return;
        }
    }
    arr.push_back(value);
}

// problem 15
vector<int> problem_15(vector<int> &arr) {
    vector<int> arr_copy(arr);
    int length = arr.size();
    for (int i = 0; i < length; i++) {
        arr[i] = arr_copy[length - i - 1];
    }
    return arr;
}

// problem 16
vector<int> problem_16(vector<int> arr) {
    bool (*compare)(int, int) = [](int x, int y) { return x <= y; };
    shell_sort(arr, compare); // quicksort(arr, 0, arr.size() - 1, compare);
    int index;
    for (index = 0; index < arr.size(); index++) {
        if (arr[index] >= 0) break;
    }
    vector<int> filtered_arr(arr.begin() + index, arr.end());
    return filtered_arr;
}

// problem 17
vector<int> problem_17(vector<int> arr) { // insertion sort
    for (int i = 1; i < arr.size(); i++) {
        int tmp = arr[i];
        int index = i - 1;
        while (index >= 0 && arr[index] > tmp) {
            arr[index + 1] = arr[index];
            index -= 1;
        }
        arr[index + 1] = tmp;
    }
    return arr;
}

// problem 18
vector<string> problem_18(vector<string> &arr) {
    bool (*compare)(string, string) = [](string s1, string s2) { return s1[0] < s2[0]; };
    shell_sort(arr, compare);
    for (auto it = arr.begin(); it < arr.end(); it++) {
        cout << *it << endl;
    }
    return arr;
}

// problem 19
template <typename T>
vector<T> problem_19(vector<T> &arr) {
    bool (*compare)(pair <double, string>, pair <double, string>) = [](pair <double, string> pair1, pair <double, string> pair2) {
        return pair1.first < pair2.first;
    };
    shell_sort(arr, compare);
    return arr;
}

// problem 20
vector<string> problem_20(vector<string> &arr) {
    bool (*compare)(string, string) = [](string s1, string s2) { return s1.length() < s2.length(); };
    shell_sort(arr, compare);
    for (auto it = arr.begin(); it < arr.end(); it++) {
        cout << *it << endl;
    }
    return arr;
}

// problem 21
vector<int> problem_21(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            arr[i] = abs(arr[i]);
        }
    }
    bool (*compare)(int, int) = [](int x, int y) { return x <= y; };
//    bool (*compare)(int, int) = [](int x, int y) { return x > y; }; // in descending order
    shell_sort(arr, compare); // quicksort(arr, 0, arr.size() - 1, compare);
    return arr;
}

// problem 22
vector<float> problem_22(vector<float> arr) {
    vector<float> arr2;
    for (int i = 0; i < arr.size(); i++) {
        float delta = arr[i + 1] - arr[i];
        arr2.push_back(arr[i]);
        arr2.push_back(delta / 10 + arr[i]);
    }
    arr2.push_back(arr[arr.size() - 1]);
    return arr2;
}