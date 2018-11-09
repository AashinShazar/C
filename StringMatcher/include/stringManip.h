/**
* stringReplace
* Replaces a word within a fileline string
* IN: template file line, word to replace, replacement word
* OUT: returns string with changed word
* POST: None
* ERROR: None
*/
char *stringReplace(const char *s, const char *old, const char *new1);

/**
* strtokData
* Uses string tokenizer on the data file lines to seperate variable name and value
* IN: Takes in Data file line, the delimeter to seperate variables and an integer to iterate throught the array
* OUT: Returns a gotValueName array
* POST: None
* ERROR: None
*/
char * strtokData(char * fileLine, char * delim, int i);