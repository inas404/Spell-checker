#ifndef ENGDICT_H
#define ENGDICT_H

#include <map>
#include <string>
class EngDict
{
private:
	std::map<std::string, bool> EngDictMap;
public:
	EngDict();
	std::map<std::string, bool> getEngDictMap();
	void readFile();
	//~EngDict();
	
};

#endif