#ifndef _TOOL_H_
#define _TOOL_H_

#include <iostream>
#include <atlstr.h>
#include<vector>
#include <ctime>
#include<string>
#include <io.h>
#include <direct.h>
#include <conio.h>
#include <Windows.h>

using std::string;
using std::vector;

class Tool {
public:
    static void findDir(string _path, vector<string>& _files);
    static void findFile(string _path, vector<string>& _files);
    static void mkdir(string _path);
    static void SplitString(const string input_string, vector<string>& v, const string c);
    static vector<string> SplitString(const string input_string, const string c);
    static void ReadIpAppName(string _path, vector<string>& _data);
    static bool CheckFolderExist(const string& strPath);
    static string ReadStringIni(string lpAppName, string lpKeyName, string lpDefaut, string lpFileName);
    static void Delay(int sec);
    //static bool RmDir(const string& strPath);
};

#endif // ! _TOOL_H_
