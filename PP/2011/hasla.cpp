#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <format>

using namespace std;

bool is_palindrome(string word) {
    for(int i{0}; i < word.size() / 2; i++) {
        if (word[i] != word[word.size() - i - 1]) {
            return false;
        }
    }
    return true;
}


int main() {
    ifstream file("hasla.txt");
    vector<string> lines;
    string line;
    while(getline(file, line)) {
        line = line.substr(0, line.find_last_not_of("\r\n") + 1);
        lines.push_back(line);
    }
    file.close();

    ofstream wynik4a("wynik4a.txt");
    ofstream wynik4b("wynik4b.txt");
    ofstream wynik4c("wynik4c.txt");

    int parzyste = 0;
    int nieparzyste = 0;
    for(const auto& line : lines) {
        // podpunkt a
        if (line.size() % 2 == 0) {
            parzyste++;
        }
        else {
            nieparzyste++;
        }

        // podpunkt b
        for(const auto& line : lines) {
            if (is_palindrome(line)) {
                wynik4b << line << '\n';
            }
        }

        // podpunkt c
        for(int i{0}; i < line.size() - 1; i++) {
            if (line[i] + line[i + 1] == 220) {
                wynik4c << line + '\n';
                break;
            }
        }
    }

    wynik4a << format("Liczba haseł o nieparzystej liczbie znaków: {}\n", nieparzyste);
    wynik4a << format("Liczba haseł o parzystej liczbie znaków: {}\n", parzyste);
    wynik4a.close();
    wynik4b.close();
    wynik4c.close();

    return 0;
}