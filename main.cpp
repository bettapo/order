#include <iostream>
#include <cstdio>
#include "string"
#include "order.h"
#include "tests.h"

using namespace std;

int main() {

    run_tests();

    int menu = -1;

    cout << "MANUAL TESTING for string type" << endl;
    while( menu != 0) {
        cout << "Press 1 to test the enqueue and dequeue functions." << endl;
        cout << "Press 2 to test the concatenation of 2 oders." << endl;
        cout << "Press 3 to extract a subsequence by given indexes." << endl;
        cout << "Press 4 to search for the occurrence of a subsequence." << endl;
        cout << "Press 0 to exit the program." << endl;

        cin >> menu;

        switch(menu) {
            case 1: {
                order_list<string> order;

                cout << "How many items do you want to queue?" << endl;
                int itemsNumber;
                cin >> itemsNumber;

                for (int i = 0; i < itemsNumber; i++) {
                    string item;
                    cout << "Enter item " << i+1 << endl;
                    cin >> item;
                    order.enqueue(item);
                }
                order.orderCout();
                cout << endl;

                int degueueMenu = -1;
                while(degueueMenu != 0)
                {
                    cout << "Press 1 to dequeue 1 item" << endl;
                    cout << "Press 0 to return to main menu." << endl;
                    cin >> degueueMenu;

                    string item;
                    item = order.dequeue();
                    cout << "Item: " << item << endl;
                    order.orderCout();
                    cout << endl;
                }
            }
                break;
            case 2: {
                order_list<string> A;
                order_list<string> B;

                cout << "How many items do you want to queue in A?" << endl;
                int itemsNumber;
                cin >> itemsNumber;

                for (int i = 0; i < itemsNumber; i++) {
                    string item;
                    cout << "Enter item " << i+1 << endl;
                    cin >> item;
                    A.enqueue(item);
                }

                cout << "How many items do you want to queue in B?" << endl;
                cin >> itemsNumber;

                for (int i = 0; i < itemsNumber; i++) {
                    string item;
                    cout << "Enter item " << i+1 << endl;
                    cin >> item;
                    B.enqueue(item);
                }

                A.orderCout();
                cout << endl;
                B.orderCout();
                cout << endl;

                A = A.concatenation(B);
                A.orderCout();

                cout << endl;
            }
                break;

            case 3: {
                order_list<string> order;
                order_list<string> subsequence ;

                cout << "How many items do you want to queue?" << endl;
                int itemsNumber;
                cin >> itemsNumber;

                for (int i = 0; i < itemsNumber; i++) {
                    string item;
                    cout << "Enter item " << i+1 << endl;
                    cin >> item;
                    order.enqueue(item);
                }

                cout << "Which elements do you want to get?" << endl;
                cout << "From: " << endl;
                int from;
                cin >> from;
                cout << "To: " << endl;
                int to;
                cin >> to;

                subsequence = order.subsequenceByIndexes(from, to);

                cout << endl;
                order.orderCout();
                subsequence.orderCout();
            }
                break;

            case 4: {
                order_list<string> order;
                order_list<string> subsequence ;

                cout << "How many items do you want to queue?" << endl;
                int itemsNumber;
                cin >> itemsNumber;

                for (int i = 0; i < itemsNumber; i++) {
                    string item;
                    cout << "Enter item " << i+1 << endl;
                    cin >> item;
                    order.enqueue(item);
                }

                cout << "How many items do you want to add in subsequence?" << endl;
                cin >> itemsNumber;
                for (int i = 0; i < itemsNumber; i++) {
                    string item;
                    cout << "Enter item " << i+1 << endl;
                    cin >> item;
                    subsequence.enqueue(item);
                }

                bool result;
                result = order.searchSubsequence(subsequence);

                cout << endl;
                cout << "Main ";
                order.orderCout();
                cout << "Subsequence ";
                subsequence.orderCout();
                cout << "Result: " << result << endl;
            }
                break;
        }

    }

    return 0;
}
