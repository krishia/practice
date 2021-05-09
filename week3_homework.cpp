// week3_homework.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "KhuString.h"

using namespace std;


int main()
{
    cout <<"1."<< khu::Construct("Hello") << endl;

    
    cout<<"2."<< khu::GetLength() << endl;

    khu::Append(", World!");

    cout <<"3."<< khu::gString << endl;

    cout <<"4."<< khu::RemoveAt(3) << endl;

    cout <<"5."<< khu::gString << endl;

    khu::Reverse();
    cout << "6." << khu::gString << endl;

    khu::ToUpper();
    cout << "7." << khu::gString << endl;

    khu::ToLower();
    cout << "8." << khu::gString << endl;

    cout <<"9."<< khu::Copy("Wow!") << endl;

    delete[]khu::gString;
    return 0;
}

const char* khu::Construct(const char* str) {
    int str_len = 0;
    const char* p = str;
    while (*p != '\0') {
        ++p;
        ++str_len;
    }
    khu::gString = new char[str_len+1];
    for (int i = 0; i < str_len; ++i) {
        khu::gString[i] = str[i];
    }
    khu::gString[str_len] = '\0';
    return khu::gString;
}


unsigned int khu::GetLength() {
    char* t = khu::gString;
    unsigned int str_len = 0;
    while (*t != '\0') {
        ++t;
        ++str_len;
    }

    return str_len;
}

void khu::Append(const char* str) {
    int str_len = 0;
    const char* p = str;
    int g_len = khu::GetLength();
    char* tempstr = new char[g_len+1];

    for (int i = 0; i < g_len; ++i) {
        tempstr[i] = khu::gString[i];
    }
    tempstr[g_len] = '\0';

    while (*p != '\0') {
        ++p;
        ++str_len;
    }

    delete[] khu::gString;

    khu::gString = new char[str_len + g_len + 1];

    for (int j = 0; j < g_len; ++j) {
        khu::gString[j] = tempstr[j];
    }

    for (int k = g_len; k < g_len + str_len + 1; ++k) {
        khu::gString[k] = str[k - g_len];
    }

    delete[] tempstr;
    khu::gString[str_len+g_len] = '\0';

}

bool khu::RemoveAt(unsigned int i) {
    unsigned int g_len = khu::GetLength();
    if (i < 0 || i >= g_len) {
        cout << "Invalid index input" << endl;
        return false;
    }

    char* tempstr = new char[g_len + 1];
    for (int i = 0; i < g_len; ++i) {
        tempstr[i] = khu::gString[i];
    }
    tempstr[g_len] = '\0';

    delete[] khu::gString;

    khu::gString = new char[g_len];
    for (unsigned int j = 0; j < g_len; ++j) {
        if (j < i) {
            khu::gString[j] = tempstr[j];
        }
        else if (j == i) {
            continue;
        }
        else if (j > i) {
            khu::gString[j-1] = tempstr[j];
        }

    }

    delete[] tempstr;

    khu::gString[g_len - 1] = '\0';

    return true;
}

void khu::Reverse() {
    int g_len = khu::GetLength();

    char* tempstr = new char[g_len+1];
    for (int i = 0; i < g_len; ++i) {
        tempstr[i] = khu::gString[i];
 
    }

    tempstr[g_len] = '\0';

    delete[] khu::gString;
    khu::gString = new char[g_len + 1];

    for (int i = 0; i < g_len; ++i) {
        khu::gString[i] = tempstr[g_len - i - 1];
    }
    khu::gString[g_len] = '\0';

    delete[] tempstr;
}

void khu::ToUpper() {
    int g_len = khu::GetLength();

    for (int i = 0; i < g_len; ++i) {
        if ((khu::gString[i] > 96) && (khu::gString[i] < 123)) {
            khu::gString[i] = khu::gString[i] - 32;
        }
    }
}

void khu::ToLower() {
    int g_len = khu::GetLength();

    for (int i = 0; i < g_len; ++i) {
        if ((khu::gString[i] > 64) && (khu::gString[i] < 91)) {
            khu::gString[i] = khu::gString[i] + 32;
        }
    }
}

const char* khu::Copy(const char* str) {
    delete[] khu::gString;
    int str_len = 0;
    const char* p = str;
    while (*p != '\0') {
        ++p;
        ++str_len;
    }
    khu::gString = new char[str_len + 1];
    for (int i = 0; i < str_len; ++i) {
        khu::gString[i] = str[i];
    }
    khu::gString[str_len] = '\0';
    return khu::gString;
}