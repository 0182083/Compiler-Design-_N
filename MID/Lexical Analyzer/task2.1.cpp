
#include <iostream>

using namespace std;

bool isNumericConstant(string input) {
    for (char ch : input) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return !input.empty();
}

int main() {
    string input;
    cout << "Enter input: ";
    cin >> input;

    if (isNumericConstant(input)) {
        cout << "This is a numeric constant." << endl;
    } else {
        cout << "This is not numeric." << endl;
    }

    return 0;
}

