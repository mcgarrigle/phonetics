
#include <string>
#include <vector>

#include "word.h"


using namespace std;


class Matcher
{
    public:

    Matcher(vector<string>);

    vector<string> matches(string);

    private:

    vector<Word> words;
};

