#include <gtest/gtest.h>

#include <iostream>
#include <set>
#include <string>

bool is_unique(const std::string& str)
{
    std::set<char> letters;
    for (int i = 0; i < str.size(); i++) {
        const char& c = str[i];
        if (letters.find(c) != letters.end()) {
            return false;
        }
        letters.insert(c);
    }
    return true;
}

std::string string_compression(const std::string& s)
{
    if (s.size() == 0) {
        return s;
    }

    std::string s_comp = "";
    char last_char = s.front();
    int num_repetitions = 1;

    for (const auto& c : s) {
        if (c == last_char) {
            num_repetitions++;
        } else {
            s_comp.push_back(last_char);
            s_comp.append(std::to_string(num_repetitions));
            last_char = c;
            num_repetitions = 1;
        }
    }

    s_comp.push_back(last_char);
    s_comp.append(std::to_string(num_repetitions));

    if (s_comp.size() < s.size()) {
        return s_comp;
    }
    return s;
}

TEST(is_unique, test_is_unique)
{
    EXPECT_FALSE(is_unique("this is a test"));
    EXPECT_TRUE(is_unique("Test"));
}

TEST(string_compression, string_compression)
{
    EXPECT_EQ(string_compression("abcdef"), "abcdef");
    // EXPECT_EQ(string_compression("abaaaaaaaac"), "a1b1a7c1");
}
