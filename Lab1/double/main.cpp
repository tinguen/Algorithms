#include "list.h"

int main() {
    int count, students;
    cout << "Enter number of students to move from list1 to list2.\n";
    cin >> count;
    while (!cin) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Please, try again.\n";
        cin >> count;
    }
    cout << "Enter total number of students in a group.\n";
    cin >> students;
    while (!cin) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Please, try again.\n";
        cin >> students;
    }
    if (count > students) {
        cout << "Swapping numbers...\n";
        int temp = count;
        count = students;
        students = temp;
    }
    List l1;
    List l2;
    l1.fill(1, students);
    l2.fill(1, students);
    cout << l1.to_string();
    cout << l2.to_string();
    l1.move_elements(count, &l2);
    for (List::iterator it = l1.begin(); it != l1.end(); ++it) {
        int x = *it;
        cout << x << endl;
    }
    cout << l1.to_string();
    cout << l2.to_string();
    l1.clear();
    l2.clear();
}