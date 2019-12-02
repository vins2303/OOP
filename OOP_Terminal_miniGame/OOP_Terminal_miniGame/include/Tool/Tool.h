#ifndef _TOOL_H_
#define _TOOL_H_

#include <iostream>
#include <atlstr.h>
#include<vector>
#include<string>
#include <io.h>
#include <direct.h>
#include <Windows.h>

using std::string;
using std::vector;

class Tool {
public:
    static void findDir(string _path, vector<string>& _files);
    static void findFile(string _path, vector<string>& _files);
    static void mkdir(string _path);
    static void SplitString(const string input_string, vector<string>& v, const string c);
    static void getIpAppName(string _path, vector<string>& _data);
    static bool CheckFolderExist(const string& strPath);
    static string readStringIni(string lpAppName, string lpKeyName, string lpDefaut, string lpFileName);
    //static bool RmDir(const string& strPath);
};

#endif // ! _TOOL_H_
