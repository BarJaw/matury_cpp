#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <format>

using namespace std;



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
        if (line.size() % 2 == 0) parzyste++;
        else nieparzyste++;


    }

    wynik4a << format("Liczba haseł o nieparzystej liczbie znaków{}\n", nieparzyste);
    wynik4a << format("Liczba haseł o parzystej liczbie znaków{}\n", parzyste);
    wynik4a.close();
    wynik4b.close();
    wynik4c.close();

    return 0;
}