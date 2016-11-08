/*
	Run from terminal g++ main.cpp EngDict.cpp EngDict.h Document.cpp Document.h -o spellchecker
	
	This is a document spellchecker implementation.
	*	It takes a document
	*	Detects errors
	*	Suggests correction

	english dictionary referenece is /usr/share/dict/words.txt in unix system
*/



#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include "EngDict.h"
#include "Document.h"

using namespace std;

int main(int argc, char const *argv[])
{
	EngDict myDict;
	std::string file_name = "doc.txt";
	Document myDoc(file_name);
	myDoc.setEngDictMap(&myDict);
	myDoc.readFile();
	return 0;
}