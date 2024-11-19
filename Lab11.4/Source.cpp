#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int CountVowels(const string& word) {
    string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯaeiouAEIOU";
    return count_if(word.begin(), word.end(), [&vowels](char c) {
        return vowels.find(c) != string::npos;
        });
}

string FindWordWithMostVowels(const string& line) {
    istringstream iss(line);
    string word, maxVowelWord;
    int maxVowels = 0;

    while (iss >> word) {
        int vowels = CountVowels(word);
        if (vowels > maxVowels) {
            maxVowels = vowels;
            maxVowelWord = word;
        }
    }

    return maxVowelWord;
}

int main() {
    setlocale(LC_ALL, "ukr");

    string inputFileName, outputFileName;

    cout << "Введiть iм'я вхiдного файлу: ";
    cin >> inputFileName;
    cout << "Введiть iм'я вихiдного файлу: ";
    cin >> outputFileName;

    ofstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cout << "Не вдалося створити файл для введення даних!" << endl;
        return 1;
    }

    int n;
    cout << "Скiльки рядкiв ви хочете ввести? ";
    cin >> n;
    cin.ignore();

    cout << "Введiть " << n << " рядкiв:" << endl;
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        inputFile << line << endl;
    }

    inputFile.close();

    ifstream inputFileRead(inputFileName);
    ofstream outputFile(outputFileName);
    if (!inputFileRead.is_open() || !outputFile.is_open()) {
        cout << "Не вдалося вiдкрити один iз файлів!" << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;

    while (getline(inputFileRead, line)) {
        string processedLine = line;
        if (lineNumber % 2 != 0) {
            string maxVowelWord = FindWordWithMostVowels(line);
            if (!maxVowelWord.empty()) {
                processedLine += " " + maxVowelWord;
            }
        }
        outputFile << processedLine << endl;
        lineNumber++;
    }

    inputFileRead.close();
    outputFile.close();

    cout << "Оброблений файл записано в: " << outputFileName << endl;

    return 0;
}
