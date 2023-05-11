#include <iostream>

using namespace std;

int calculateDiscount(int price) {
    if (price < 100) {
        return 0;
    } else if (price < 500) {
        return price * 0.05;
    } else if (price < 1000) {
        return price * 0.1;
    } else {
        return price * 0.15;
    }
}

void testDiscount() {
    // Test lower boundary of input
    int discount = calculateDiscount(99);
    cout << "Discount for 99: " << discount << endl;

    // Test upper boundary of input
    discount = calculateDiscount(1000);
    cout << "Discount for 1000: " << discount << endl;

    // Test just above lower boundary of input
    discount = calculateDiscount(100);
    cout << "Discount for 100: " << discount << endl;

    // Test just below upper boundary of input
    discount = calculateDiscount(999);
    cout << "Discount for 999: " << discount << endl;

    // Test middle of input range
    discount = calculateDiscount(500);
    cout << "Discount for 500: " << discount << endl;
}

int main() {
    testDiscount();
    return 0;
}
