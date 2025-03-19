#include <iostream>
#include <vector>

int main() {
    int n, r;
    
    std::cout << "Enter the number of locker doors: ";
    std::cin >> n;
    std::cout << "Enter the number of passes: ";
    std::cin >> r;

    //all lockers intially closed
    std::vector<bool> lockers(n, false);

    for (int pass = 1; pass <= r; ++pass) {
        for (int i = pass - 1; i < n; i += pass) {
            lockers[i] = !lockers[i]; //toggling the locker
        }
    }

    int openCount = 0;
    for (int i = 0; i < n; ++i) {
        std::cout << "Locker door #" << (i + 1) << ": " 
                  << (lockers[i] ? "open" : "closed") << std::endl;
        if (lockers[i]) ++openCount;
    }

    std::cout << "Total open lockers: " << openCount << std::endl;

    return 0;
}
