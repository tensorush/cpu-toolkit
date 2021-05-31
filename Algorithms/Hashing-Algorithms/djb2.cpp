/*
    DJB2 (unsecure)
    ------------------
    Time: O(keyLength)
    Space: O(1)
*/
#include <iostream>
#include <string>

unsigned DJB2(const std::string& key) {
    unsigned hash = 5381;
    for (const unsigned& c : key) {
        hash = (hash << 5) + hash + c;
    }
    return hash;
}

int main() {
    std::string key;
    std::cin >> key;
    std::cout << DJB2(key);
    
    return EXIT_SUCCESS;
}