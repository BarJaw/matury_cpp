#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <fstream>

using namespace std;

int sum_of_digits(string number) {
    int sum{};
    int number_converted = stoi(number);
    while(number_converted > 0) {
        sum += number_converted % 10;
        number_converted /= 10;
    }
    return sum;
}

bool is_ascending(string number) {
    for (int i{0}; i < number.size() - 1; i++) {
        if (number[i] >= number[i + 1]) return false;
    }
    return true;
}



int main() {
    ifstream file("cyfry.txt");
    string line;
    vector<string> lines;
    while(getline(file, line)) {
        line = line.substr(0, line.find_last_not_of("\r\n") + 1);
        lines.push_back(line);
    }
    file.close();
    ofstream zadanie4("zadanie4.txt");

    auto ile_parzystych{0};
    auto najwieksza_suma_cyfr{sum_of_digits(lines[0])};
    auto najmniejsza_suma_cyfr{sum_of_digits(lines[0])};
    string najwieksza_liczba_suma{lines[0]};
    string najmniejsza_liczba_suma{lines[0]};
    
    for(auto& line : lines) {
        // podpunkt a
        if(stoi(line) % 2 == 0) ile_parzystych++;

        // podpunkt b
        int suma_cyfr = sum_of_digits(line);
        if(suma_cyfr > najwieksza_suma_cyfr) {
            najwieksza_suma_cyfr = suma_cyfr;
            najwieksza_liczba_suma = line;
        }
        if(suma_cyfr < najmniejsza_suma_cyfr) {
            najmniejsza_suma_cyfr = suma_cyfr;
            najmniejsza_liczba_suma = line;
        }
        
        
    }
    zadanie4 << format("a) Liczb parzystych jest {}", ile_parzystych) << "\n";
    zadanie4 << format("b) Liczba o najwiekszej sumie cyfr {}\n", najwieksza_liczba_suma);
    zadanie4 << format("Liczba o najmniejszej sumie cyfr {}\n", najmniejsza_liczba_suma);
    
    // podpunkt c
    zadanie4 << "c)\n";
    for(auto line : lines) {
        if (is_ascending(line)) zadanie4 << line + "\n";
    }
    zadanie4.close();

    return 0;
}
