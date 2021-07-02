/*
    SDBM (unsecure)
    ------------------
    Time: O(keyLength)
    Space: O(1)
*/
#include <iostream>
#include <string>

unsigned SDBM(const std::string& key) {
    unsigned hash = 0;
    for (const unsigned& c : key) {
        hash = (hash << 6) + (hash << 16) - hash + c;
    }
    return hash;
}

int main() {
    std::string key;
    std::cin >> key;
    std::cout << SDBM(key);

    return EXIT_SUCCESS;
}