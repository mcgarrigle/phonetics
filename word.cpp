
#include <ctype.h>
#include <string.h>

#include "word.h"


Word::Word(string s)
{
  _value = s;
}

Word::~Word()
{
}

string Word::value()
{
    return _value;
}

string Word::phonetic()
{
    if (_value.size() == 0)
    {
        return "";
    }

    string s = remove_vowels(_value);
    s = substitute_equivalents(s);
    s = remove_redundant_equivalents(s);

    // cout << "s = " << s << "\n";

    return s;
}

string Word::remove_vowels(string v)
{
    // cout << "v = " << v << "\n";

    string::iterator i = v.begin();

    char c = *i++;

    string s = first(c);

    while (i != v.end()) 
    {
        c = toupper(*i++);
        cout << "c = " << c << "\n";
        if (isalpha(c))
        {
            if (strchr("AEIOUWHY", c) == NULL)  // not vowely
            {
                s += c;
            }
        }
    }
    // cout << "s = " << s << "\n\n";
    
    return s;
}

string Word::substitute_equivalents(string v)
{
    string s;

    cout << "v = " << v << "\n";
    for (string::iterator i = v.begin(); i != v.end(); i++)
    {
        char c = *i;
        cout << "c = " << c << "\n";
        if (strchr("EIOU", c))
        {
            s += 'A';
        }
        else if (strchr("GJKQSXYZ", c))
        {
            s += 'C';
        }
        else if (strchr("FPVW", c))
        {
            s += 'B';
        }
        else if (c == 'T')
        {
            s += 'D';
        }
        else if (c == 'N')
        {
            s += 'M';
        }
        else
        {
            s += c;
        }
    }

    cout << "s = " << s << "\n";
    return s;
}

string Word::remove_redundant_equivalents(string v)
{
    string s;

    cout << "v = " << v << "\n";

    char last = '-';

    for (string::iterator i = v.begin(); i != v.end(); i++)
    {
        char c = *i;
        cout << "c = " << c << "\n";
        cout << "l = " << last << "\n";
        if (c != last)
        {
            s += c;
            last = c;
        }
    }

    cout << "s = " << s << "\n";
    return s;
}

string Word::first(char c)
{
    string s;

    if (isalpha(c)) 
    {
        s += toupper(c);
    }
    return s;
}


