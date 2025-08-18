#include<bits/stdc++.h>
using namespace std;

void display() {
    cout << "--ARRAY_OPERATION--" << endl;
    cout << "1. create array" << endl;
    cout << "2. display array" << endl;
    cout << "3. insert the element" << endl;
    cout << "4. delete element" << endl;
    cout << "5. linear search" << endl;
    cout << "6. exit" << endl;
}

int main() {
    int choice;
    vector<int> v;
    do {
        display();
        cout << "the enter the choice:" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                int x;
                cout << "please enter the the size of array you want to create:" << endl;
                cin >> x;


                cout << "pls enter the number you want to insert" << endl;
                for (int i = 0; i < x; i++) {
                    int num;
                    cin >> num;
                    v.push_back(num);
                }
                break;
            case 2:
                for (int val : v) {
                    cout << val << " ";
                }
                cout<<endl;
                break;
            case 3:
                int o, p;
                cout << "pls enter the element you want to insert" << endl;
                cin >> o;
                cout << "pls enter the position where you want to insert the element" << endl;
                cin >> p;
                v.insert(v.begin() + p, o);
                break;
            case 4:
                int i;
                cout << "pls enter the number you want to delete" << endl;
                cin >> i;
                for (int val: v) {
                    if (val == i) {
                        auto it = find(v.begin(), v.end(), val);
                        v.erase(it);
                    }
                }
                break;
            case 5:
                int d;
                cout << "lets apply the linear search" << endl;
                cout << "pls enter the number you want to find" << endl;
                cin >> d;
                auto it = find(v.begin(), v.end(), d);

                if (it != v.end()) {
                    cout << "the element is found at" << (it - v.begin())+1 << endl;
                }

                break;
        }



    }while (choice != 6);


    return 0;
}
