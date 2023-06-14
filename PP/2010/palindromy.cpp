#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

bool czy_palindrom(string wyraz) {
    for(int i = 0; i < wyraz.size() / 2; i++) {
        if (wyraz[i] != wyraz[wyraz.size() - i - 1]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    ifstream file("dane.txt");    
    vector<string> lines;
    string line;
    
    while(getline(file, line)) {
        line = line.substr(0, line.find_last_not_of("\r\n") + 1);
        lines.push_back(line);
    }
    file.close();


    ofstream wynik("wynik.txt");

    for(const auto& line : lines) {
        if (czy_palindrom(line)) {
            wynik << line + "\n";   
        }
    }
    wynik.close();


    return 0;
}