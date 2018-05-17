#include <cmath>
#include "../Lab2/tree.h"

using namespace std;

//Используя генератор случайных чисел сформировать бинарное дерево, состоящее из 15 элементов
// (предусмотреть ручной ввод элементов). Причем числа должны лежать в диапазоне от -99 до 99.
// Произвести поиск со вставкой и  удалением  элементов в соответствии со следующими вариантами заданий:
//1. Числа кратные N.
//2. Нечетные числа.
//3. Числа > N.
//4. Числа < N.
//5. Числа по выбору.
//6. Простые числа.
//7. Составные числа.
//8. Числа в интервале от X до Y.
//9. Числа, сумма цифр (по модулю) которого > N.
//10. Числа, сумма цифр (по модулю) которого < N.
//11. Числа, сумма цифр (по модулю) которого лежит в интервале от X до Y.
//12. Числа, взятые по модулю, квадратный корень которых целое число.

class Tree_problems: public Tree {
private:
public:
    void random_push(int n); // push n random number from -99 to 99
    void manual_push(vector<int>); // push manually all numbers from vector
    vector<int> problem1_search(int n);
    void problem1_delete(int n);
    vector<int> problem2_search();
    void problem2_delete();
    vector<int> problem3_search(int n);
    void problem3_delete(int n);
    vector<int> problem4_search(int n);
    void problem4_delete(int n);
    vector<int> problem5_search(vector<int> elements);
    void problem5_delete(vector<int> elements);
    vector<int> problem6_search();
    void problem6_delete();
    vector<int> problem7_search();
    void problem7_delete();
    vector<int> problem8_search(int from, int to);
    void problem8_delete(int from, int to);
    vector<int> problem9_search(int n);
    void problem9_delete(int n);
    vector<int> problem10_search(int n);
    void problem10_delete(int n);
    vector<int> problem11_search(int from, int to);
    void problem11_delete(int from, int to);
    vector<int> problem12_search();
    void problem12_delete();
};