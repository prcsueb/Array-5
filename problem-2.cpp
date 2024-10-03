/*
tc O(n) sc o(1)
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

double calculateTax(vector<pair<double, double>>& levels, double salary) {
    double tax = 0.0;
    double prevLimit = 0.0;

    for (auto& level : levels) {
        if (level.first == 0) break; // Stop if the limit is None (0 in this case)

        double currentLimit = level.first;
        double rate = level.second;

        if (salary > currentLimit) {
            tax += (currentLimit - prevLimit) * rate;
            prevLimit = currentLimit;
        } else {
            tax += (salary - prevLimit) * rate;
            break;
        }
    }

    return tax;
}

int main() {
    vector<pair<double, double>> levels = {
        {10000.0, 0.3},
        {20000.0, 0.2},
        {30000.0, 0.1},
        {0.0, 0.1} // Representing None with 0.0
    };

    double salary = 45000.0;
    double tax = calculateTax(levels, salary);

    cout << "Tax: " << tax << endl;

    return 0;
}