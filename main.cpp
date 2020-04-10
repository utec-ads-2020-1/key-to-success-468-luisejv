#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int main()
{
    int contLines = 0;
    string blank, ogLine, codedLine, lines;
    getline(cin, lines);
    while (contLines < stoi(lines))
    {
        contLines++;
        getline(cin, blank); //for the blank space
        getline(cin, ogLine);
        unordered_map<char, int> freqOgLine;
        stringstream ss(ogLine);
        char letra;
        while (ss >> letra)
        {
            if (letra != ' ')
            {
                freqOgLine[letra]++;
            }
        }
        getline(cin, codedLine);
        unordered_map<char, int> freqCodedLine;
        stringstream ss2(codedLine);
        while (ss2 >> letra)
        {
            if (letra != ' ')
            {
                freqCodedLine[letra]++;
            }
        }
        unordered_map<char, char> mapedChars;
        unordered_map<char, char> mapedCharsBack;
        bool mapeado = false;
        while (!mapeado)
        {
            char mayorFreqOg, mayorFreqCoded;
            int mayorFreqValueOg = 0, mayorFreqValueCoded = 0;
            bool foundInOg = false;
            bool foundInCoded = false;
            for (auto & p : freqOgLine)
            {
                if ((p.second > mayorFreqValueOg) && (mapedChars.find(p.first) == mapedChars.end()))
                {
                    mayorFreqOg = p.first;
                    mayorFreqValueOg = p.second;
                    foundInOg = true;
                }
            }
            for (auto & q : freqCodedLine)
            {
                if ((q.second > mayorFreqValueCoded) && (mapedCharsBack.find(q.first) == mapedCharsBack.end()))
                {
                    mayorFreqCoded = q.first;
                    mayorFreqValueCoded = q.second;
                    foundInCoded = true;
                }
            }
            mapedChars[mayorFreqOg] = mayorFreqCoded;
            mapedCharsBack[mayorFreqCoded] = mayorFreqOg;
            if (!foundInCoded && !foundInOg)
            {
                mapeado = true;
            }
        }
        for (char i : codedLine)
        {
            cout << mapedCharsBack[i];
        }
        cout << endl;
        if (contLines != stoi(lines)){
            cout << endl;
        }
    }
}