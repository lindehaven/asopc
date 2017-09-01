#include "UnitTest++.h"

extern "C" {
    int lookup(const char []);
    int insert(const char [], const int);
    int token(const int p);
}

namespace
{

TEST(SymbolLookupKeywordDoesNotExist)
{
    CHECK(0 == lookup("thiskeywordhasnotbeeninserted"));
}

TEST(SymbolInsertKeyword)
{
    CHECK(0 < insert("insertedkeyword", 1001));
}

TEST(SymbolLookupKeywordExists)
{
    CHECK(0 < lookup("insertedkeyword"));
}

TEST(SymbolTokenExists)
{
    const int p = insert("anotherinsertedkeyword", 1002);
    CHECK(1002 == token(p));
}

}
