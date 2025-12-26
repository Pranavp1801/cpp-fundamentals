#include <iostream>
using namespace std;

int addNumbers(int first, int second) {
    return first + second;
}

int main() {
    int result = addNumbers(10, 20);
    cout << "Sum is: " << result << endl;
    return 0;
}
