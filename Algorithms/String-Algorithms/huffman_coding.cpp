/*
    Huffman Coding
    -----------------
    Time: O(n log(n))
    Space: O(n)
*/
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>

class HuffmanCoding final {
private:
    struct CharSetFrequency {
        std::string charSet;
        int frequency;
        const bool operator < (const CharSetFrequency &other) const {
            return std::tie(frequency, charSet) > std::tie(other.frequency, other.charSet);
        }
    };
public:
    static std::unordered_map<char, std::string> Encode(const std::string &text) {
        std::unordered_map<char, int> charFrequencies;
        for(auto& c : text) {
            ++charFrequencies[c];
        }
        std::vector<CharSetFrequency> frequencies;
        for (auto& char_frequency : charFrequencies) {
            frequencies.push_back({std::string(1, char_frequency.first), char_frequency.second});
        }
        if (frequencies.size() == 1) {
            std::unordered_map<char, std::string> result;
            result[frequencies[0].charSet[0]] = "0";
            return result;
        }
        std::unordered_map<char, std::string> result;
        std::priority_queue<CharSetFrequency> queue(frequencies.begin(), frequencies.end());
        while (queue.size() >= 2) {
            auto first = queue.top();
            queue.pop();
            auto second = queue.top();
            queue.pop();
            for (auto& c : first.charSet) {
                result[c] += "0";
            }
            for (auto& c : second.charSet) {
                result[c] += "1";
            }
            queue.push({first.charSet + second.charSet, first.frequency + second.frequency});
        }
        for (auto& encoding : result) {
            std::reverse(encoding.second.begin(), encoding.second.end());
        }
        return result;
    }
    static std::string Decode(const std::string &text, const std::unordered_map<char, std::string> &huffmanEncoding) {
        std::string result;
        size_t pos = 0, len = text.length();
        while (pos < len) {
            for (auto& encoded : huffmanEncoding) {
                if (text.substr(pos, encoded.second.length()) == encoded.second) {
                    result += encoded.first;
                    pos += encoded.second.length();
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    std::string text;
    std::getline(std::cin, text);
    auto huffmanEncoding = HuffmanCoding::Encode(text);
    std::string encodedText;
    for (auto& character : text) {
        encodedText += huffmanEncoding[character];
    }
    std::cout << huffmanEncoding.size() << ' ' << encodedText.length() << std::endl;
    for (auto& encoded : huffmanEncoding) {
        std::cout << encoded.first << ": " << encoded.second << std::endl;
    }
    std::cout << encodedText << std::endl;

    return EXIT_SUCCESS;
}