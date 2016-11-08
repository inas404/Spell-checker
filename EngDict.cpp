#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "EngDict.h"
using namespace std;


EngDict::EngDict(){
	readFile();
}

void EngDict::readFile(){
    ifstream file;
    file.open ("words.txt");
    string word;
    word.clear();
    while ( file >> word )
    {
    	transform(word.begin(), word.end(), word.begin(), ::tolower);
        EngDictMap[word]=true;
    }
}

std::map<std::string, bool> EngDict::getEngDictMap(){
    return EngDictMap;
}