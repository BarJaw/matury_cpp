#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>

using namespace std;

int main() {
    ifstream file("napisy.txt");
    string line {};
    vector<string> lines{};
    while(getline(file ,line)) {
        line = line.substr(0, line.find_last_not_of("\r\n") + 1);
        lines.push_back(line);
    }
    file.close();
    
    ofstream zadanie4("zadanie4.txt");
    auto parzyste{0};
    auto zera_jedynki{0};
    auto same_zera{0};
    auto same_jedynki{0};
    int k[17] = {0};

    for(auto line : lines) {
        // podpunkt a
        if (line.size() % 2 == 0) parzyste++;
        
        // podpunkt b i c
        auto zera{0};
        auto jedynki{0};
        for (auto cyfra : line) {
            if (cyfra == '1') jedynki++;
            else zera++;
        }
        if (zera == jedynki) zera_jedynki++;
        if (zera == 0) same_jedynki++;
        if (jedynki == 0) same_zera++;

        // podpunkt d
        k[line.size()]++;
    }

    zadanie4 << format("a) Liczba napisow o parzystej długości: {}\n", parzyste);
    zadanie4 << format("b) Liczba napisow o rownej liczbie zer i jedynek {}\n", zera_jedynki);
    zadanie4 << format("c) Liczba napisow skladajacych sie z samych zer {}\n", same_zera);
    zadanie4 << format("Liczba napisow skladajacych sie z samych jedynek {}\n", same_jedynki);
    zadanie4 << "d)\n";
    for (auto i{2}; i<=16; i++) {
        zadanie4 << format("napisy {}-znakowe: {}\n", i, k[i]);
    }
    zadanie4.close();

    return 0;
}