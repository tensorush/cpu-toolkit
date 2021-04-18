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

class HuffmanCoding{
private:
    struct CharSetFrequency{
        std::string char_set;
        int frequency;
        const bool operator < (const CharSetFrequency &other) const {
            return std::tie(frequency, char_set) > std::tie(other.frequency, other.char_set);
        }
    };
public:
    static std::unordered_map<char, std::string> Encode(const std::string &text) {
        std::unordered_map<char, int> char_frequencies;
        for(auto& c : text) {
            ++char_frequencies[c];
        }
        std::vector<CharSetFrequency> frequencies;
        for (auto& char_frequency : char_frequencies) {
            frequencies.push_back({std::string(1, char_frequency.first), char_frequency.second});
        }
        if (frequencies.size() == 1) {
            std::unordered_map<char, std::string> result;
            result[frequencies[0].char_set[0]] = "0";
            return result;
        }
        std::unordered_map<char, std::string> result;
        std::priority_queue<CharSetFrequency> queue(frequencies.begin(), frequencies.end());
        while (queue.size() >= 2) {
            auto first = queue.top();
            queue.pop();
            auto second = queue.top();
            queue.pop();
            for (auto& c : first.char_set) {
                result[c] += "0";
            }
            for (auto& c : second.char_set) {
                result[c] += "1";
            }
            queue.push({first.char_set + second.char_set, first.frequency + second.frequency});
        }
        for (auto& encoding : result) {
            std::reverse(encoding.second.begin(), encoding.second.end());
        }
        return result;
    }
    static std::string Decode(const std::string &text, const std::unordered_map<char, std::string> &huffman_encoding) {
        std::string result;
        size_t pos = 0, len = text.length();
        while (pos < len) {
            for (auto& encoded : huffman_encoding) {
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
    std::cin >> text;
    auto huffman_encoding = HuffmanCoding::Encode(text);
    std::string encoded_text;
    for (auto& character : text) {
        encoded_text += huffman_encoding[character];
    }
    std::cout << huffman_encoding.size() << ' ' << encoded_text.length() << std::endl;
    for (auto& encoded : huffman_encoding) {
        std::cout << encoded.first << ": " << encoded.second << std::endl;
    }
    std::cout << encoded_text << std::endl;

    return 0;
}