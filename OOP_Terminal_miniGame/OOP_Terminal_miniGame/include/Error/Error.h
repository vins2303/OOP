#ifndef _ERROR_H_
#define _ERROR_H_

#include<iostream>
#include<string>
using namespace std;

class Error {
public:
    static void showOpenError(string _class, string _function, string data);
};

#endif // !_ERROR_H_
