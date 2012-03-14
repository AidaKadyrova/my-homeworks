#include <iostream>
#include "array.h"

using namespace std;

int main()
{
    List * m = new Array();
    int command = 0;
    cout << "1 - add an element to the begin\n2 - add an element to the end\n3 - add an element to some position\n4 - delete element\n5 - is element in list\n6 - print list\n7 - print a number of elements\n0 - exit" << endl;
    while(1)
    {
        cout << "enter the command" << endl;
        cin >> command;
        switch(command)
        {
        case 1:
        {
            cout << "enter the number" << endl;
            int n = 0;
            cin >> n;
            m->addToBegin(n);
            break;
        }
        case 2:
        {
            cout << "enter the number" << endl;
            int n = 0;
            cin >> n;
            m->addToEnd(n);
            break;;
        }
        case 3:
        {
            cout << "enter the number" << endl;
            int n = 0;
            cin >> n;
            cout << "enter the position" << endl;
            int position = 0;
            cin >> position;
            m->addToThePosition(n, position);
            break;
        }
        case 4:
        {
            cout << "enter the number" << endl;
            int n = 0;
            cin >> n;
            m->deleteElement(n);
            break;
        }
        case 5:
        {
            cout << "enter the number" << endl;
            int n = 0;
            cin >> n;
            m->isElement(n);
            break;
        }
        case 6:
        {
            m->printList();
            break;
        }
        case 7:
        {
            m->printSize();
            break;
        }
        case 0:
        {
            cout << "goodbye" << endl;
            return 0;
        }
        }
    }

    return 0;
}
