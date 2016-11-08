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
