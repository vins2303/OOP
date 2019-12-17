#include "../../include/Tool/Tool.h"

void Tool::findDir(string path, vector<string>& files) {
    intptr_t   hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)//assign��k�i�H�z�Ѭ����N��r��M�šA�M��ᤩ�s���ȧ@�����C
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR)) {//�O�_����Ƨ�
                if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0) {
                    files.push_back(fileinfo.name);
                    //  files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                }
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

void Tool::findFile(string path, vector<string>& files) {
    intptr_t   hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1) {
        do {
            if (!(fileinfo.attrib & _A_SUBDIR)) {
                //files.push_back(p.assign(path).append("\\").append(fileinfo.name));
                files.push_back(fileinfo.name);
            }
        } while (_findnext(hFile, &fileinfo) == 0);
        _findclose(hFile);
    }
}

void Tool::mkdir(string _path) {
    int ret;
    vector<string> vec;
    SplitString(_path, vec, "/");
    _path = "";
    for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
        _path += *it + "/";
        if (_access(_path.c_str(), 0)) {
            ret = _mkdir(_path.c_str());
        }
    }
}

void Tool::SplitString(const string input_string, vector<string>& v, const string c) {
    string::size_type pos1, pos2;
    pos2 = input_string.find(c);
    pos1 = 0;
    while (string::npos != pos2) {
        v.push_back(input_string.substr(pos1, pos2 - pos1));//2019/01/01 7 - 5
        pos1 = pos2 + c.size();
        pos2 = input_string.find(c, pos1);
    }
    if (pos1 != input_string.length())
        v.push_back(input_string.substr(pos1));
}

vector<string> Tool::SplitString(const string input_string, const string c) {
    vector<string> v;
    SplitString(input_string, v, c);
    return v;
}

void Tool::ReadIpAppName(string _path, vector<string>& _data) {
    TCHAR name[2048] = { 0 };
    string ss = "";
    GetPrivateProfileSectionNames(name, 2048, _path.c_str());
    if (name[0] == 0) return;
    for (int i = 0; i < 2048; i++) {
        if (name[i] == 0) {
            if (ss != "") _data.push_back(ss);
            ss = "";
        }
        else {
            ss += name[i];
        }
    }
}

vector<string> Tool::ReadIpAppName(string _path) {
    vector<string> out;
    ReadIpAppName(_path, out);
    return out;
}

vector<int> Tool::String_To_Int(vector<string> _str) {
    vector<int >out;
    for (vector<string>::iterator it = _str.begin(); it != _str.end(); it++)
        out.push_back(stoi(*it));
    return out;
}

int Tool::FindMax(vector<int> _num) {
    int out = INT_MIN;
    for (vector<int>::iterator it = _num.begin(); it != _num.end(); it++)
        if (*it > out)
            out = *it;
    return out;
}

bool Tool::CheckFolderExist(const string& strPath) {
    return _access(strPath.c_str(), 0) == 0 ? true : false;
}

string Tool::ReadStringIni(string lpAppName, string lpKeyName, string lpDefaut, string lpFileName) {
    CString read;
    GetPrivateProfileString(lpAppName.c_str(), lpKeyName.c_str(), lpDefaut.c_str(), read.GetBuffer(255), 255, lpFileName.c_str());
    read.ReleaseBuffer();
    return string(read);
}

int Tool::Delay(int sec) {
    time_t _t;
    _t = time(NULL);
    static int n;
    while (time(NULL) <= _t + sec) {
        if (_kbhit()) {
            return _getch();
        }
    }
}