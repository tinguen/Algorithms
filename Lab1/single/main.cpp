#include "list.h"

int main() {
    int movers, students;
    cout << "Enter number of students to move from list1 to list2.\n";
    cin >> movers;
    while (!cin) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Please, try again.\n";
        cin >> movers;
    }
    cout << "Enter total number of students in a group.\n";
    cin >> students;
    while (!cin) {
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Please, try again.\n";
        cin >> students;
    }
    if (movers > students) {
        cout << "Swapping numbers...\n";
        int temp = movers;
        movers = students;
        students = temp;
    }

    List l1;
    List l2;
    l1.fill(1, students);
    l2.fill(1, students);
    // test
    cout << l1.to_string(); // before
    cout << l2.to_string();
    l1.move_elements(movers, &l2);
    cout << l1.to_string(); // after
    cout << l2.to_string();
}


