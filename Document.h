#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <iostream>
#include <vector>
#include <string>
#include "EngDict.h"
class Document
{
private:
	std::string file_name,corrected;
	EngDict* mydict;//Association with the EngDict class

public:
	Document(std::string  myfile);
	void readFile();
	void setEngDictMap(EngDict* d);
	std::vector<std::string> closestMatch(std::string file_name);
	//~Document();
	
};

#endif