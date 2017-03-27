
#include <string>
#include <iostream>


using namespace std;


class Word
{
    public:

    Word(string s = "");
    ~Word();
  
    string value();
    string phonetic();

    private:

    string remove_vowels(string);
    string substitute_equivalents(string);
    string remove_redundant_equivalents(string);
    string first(char);
    string _value;

}; 
