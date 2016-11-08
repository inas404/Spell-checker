## Spell checker
This is a document spellchecker implementation.
* It takes a document
* Detects errors
* Suggests correction

English dictionary referenece is /usr/share/dict/words.txt in unix system.

Run from terminal:
```bash
g++ main.cpp EngDict.cpp EngDict.h Document.cpp Document.h -o spellchecker
```
##### Input:
```bash
This is a spelk shecker I built
It reada each line and correvts it so that it will be free of erroes
```
##### Output:
![Screenshot](/Spell-checker/Screenshot.png?raw=true "Screenshot")