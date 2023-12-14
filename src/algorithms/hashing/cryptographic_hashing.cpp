/*
    Cryptographic Hashing
    ---------------------
*/
#include <iostream>
#include <string>

int main() {
    std::string key;
    std::cin >> key;

    // DJB2 (unsecure)
    int djb2 = 5381;
    for (const int& character : key) {
        djb2 = (djb2 << 5) + djb2 + character;
    }

    // SDBM (unsecure)
    unsigned sdbm = 0;
    for (const unsigned& c : key) {
        sdbm = (sdbm << 6) + (sdbm << 16) - sdbm + c;
    }

    return EXIT_SUCCESS;
}