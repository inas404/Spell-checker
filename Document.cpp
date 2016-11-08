#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include "Document.h"
using namespace std;

Document::Document(std::string  myfile){
   file_name = myfile;
   corrected = "";
}

void Document::setEngDictMap(EngDict* d){
    mydict = d;
}

void Document::readFile(){
    ifstream file;
    file.open (file_name.c_str());
    string original,word,line;
    word.clear();
    std::vector<string> suggestions;
    int choice;

    while ( getline(file,line) ){   //For every line in the document
        
        istringstream iss(line);
        while(iss >> word) {        //For every word in the line
            
            original = word;
        	transform(word.begin(), word.end(), word.begin(), ::tolower);  //To lower
            
            if(mydict->getEngDictMap()[word]){  //Word exist in english dictionary
                cout<<original<<" ";
                corrected+=original+" ";
            }
            else {
                suggestions = closestMatch(word); //Try find the closest matches in english dictionary
                if(!suggestions.empty()){
                    cout<<"\033[1;31m"+word+"\033[0m"<<endl<<"\033[31;47mDo you mean:\033[0m"<<endl;
                    for (int i = 0; i < (int)suggestions.size(); ++i)
                    {
                        cout<<"["<<i+1<<"\033[0m] "+suggestions[i]<<endl;
                    }
                    cout<<"Press the number of the correct word, or press 0 to leave it as it is."<<endl;
                    cin>>choice;
                    if(choice)
                        corrected+="\033[1;32m"+suggestions[choice-1]+"\033[0m ";
                    else
                        corrected +="\033[1;31m"+original+"\033[0m ";
                }
            }
        }
        cout<<endl;
        corrected+="\n";
    }
    cout<<corrected;    // Print corrected Document
}

std::vector<string> Document::closestMatch(string word){
    std::vector<string> suggestions;
    string trial;
    for (int i = 0; i < word.length(); ++i)
    {
       for (int j = 0; j < 26; ++j)
       {
         trial[i] = char(j+97);
         if(mydict->getEngDictMap()[trial])
            suggestions.push_back(trial);
        trial = word;
        
       }
    }
    return suggestions;
}