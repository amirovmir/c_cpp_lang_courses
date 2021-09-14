#include <iostream>
#include <string>

/*
1. Написать класс для работы со строками FoooString
Вариант 1  - возвращает длину строки включая 0
int length();
*/

using namespace std;

class FooString 
{
    char* buf;
public:
    FooString(char* tbuf) 
    {
        int size = 0;
        while (tbuf != '\0')
            size++;
        tbuf = new char[size];
    };

    ~FooString() 
    {
        delete[] buf;
    };

    void show() 
    {
        cout << buf;
    };

    int length() 
    {
        int l = 0;
        while (true) 
        {
            if (buf != '\0')
                l++;
            else
                break;
        }
        return l;
    };

    bool testLength();
};

bool FooString::testLength() 
{
    char ch[10] = "proga";
    FooString str(ch);
    if (str.length() == 5)
        return true;
    else
        return false;
}

void runTest(const string& testName) {
    if (FooString::testLength)
        std::cout << "Test " << testName << " - OK" << std::endl;
    else
        std::cout << "Test " << testName << " - FAIL" << std::endl;
}

int main()
{
    runTest("testLength");    
    return 0;
}