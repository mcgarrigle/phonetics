
#include <assert.h>

#include <iostream>

#include "word.h"


void phonetic_returns_empty_string()
{
  Word s = Word("");
  assert(s.phonetic() == "");
}

void phonetic_returns_the_string()
{
  Word s = Word("L");
  assert(s.phonetic() == "L");
}

void phonetic_omits_non_alphabetics()
{
  string s = Word("A-L").phonetic();
  assert(s == "AL");
}

void phonetic_substitutes_equivalents()
{
    string s;

    // AEIOU = A

    s = Word("AL").phonetic();
    assert(s == "AL");

    s = Word("EL").phonetic();
    assert(s == "AL");

    s = Word("IL").phonetic();
    assert(s == "AL");

    s = Word("OL").phonetic();
    assert(s == "AL");

    s = Word("UL").phonetic();
    std::cout << "subject = '" << s << "'\n";
    assert(s == "AL");

    // CGJKQSXYZ = C

    s = Word("CL").phonetic();
    assert(s == "CL");

    s = Word("GL").phonetic();
    assert(s == "CL");

    s = Word("JL").phonetic();
    assert(s == "CL");

    s = Word("KL").phonetic();
    assert(s == "CL");

    s = Word("QL").phonetic();
    assert(s == "CL");

    s = Word("SL").phonetic();
    assert(s == "CL");

    s = Word("XL").phonetic();
    assert(s == "CL");

    // BFPVW = B

    s = Word("BL").phonetic();
    assert(s == "BL");

    s = Word("FL").phonetic();
    assert(s == "BL");

    s = Word("PL").phonetic();
    assert(s == "BL");

    s = Word("VL").phonetic();
    assert(s == "BL");

    s = Word("WL").phonetic();
    assert(s == "BL");

    // T = D

    s = Word("DL").phonetic();
    assert(s == "DL");

    s = Word("TL").phonetic();
    assert(s == "DL");

    // N = M

    s = Word("ML").phonetic();
    assert(s == "ML");

    s = Word("NL").phonetic();
    assert(s == "ML");
}

void phonetic_removes_duplicates()
{
    string s;

    s = Word("LL").phonetic();
    assert(s == "L");
 
    s = Word("LLDD").phonetic();
    assert(s == "LD");
 
    s = Word("LLLDTTLLL").phonetic();
  std::cout << "subject = '" << s << "'\n";
    assert(s == "LDL");
}


int main()
{
    cout << "tests\n";
    phonetic_returns_empty_string();
    phonetic_returns_the_string();
    phonetic_omits_non_alphabetics();
    phonetic_substitutes_equivalents();
    phonetic_removes_duplicates();

    return 0;
}
