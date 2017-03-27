
#include <iostream>

#include "word.h"


int main(int argc, char *argv[])
{
    Word w = Word("ABC");

    std::cout << "w = " << w.value() << "\n";
    std::cout << "p = " << w.phonetic() << "\n";

    return 0;
}

