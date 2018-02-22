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
    l1.display();
    l1.moveElements(movers, &l2);
    l2.insert(5, 100);
    l2.remove(5);
    l2.display();
    l1.clear();
    l2.clear();
}