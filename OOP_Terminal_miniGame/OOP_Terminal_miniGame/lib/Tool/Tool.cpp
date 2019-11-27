#include "../../include/Tool/Tool.h"


void Tool::findDir(string path, vector<string>& files) {
    intptr_t   hFile = 0;
    struct _finddata_t fileinfo;
    string p;
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)//assign方法可以理解為先將原字串清空，然後賦予新的值作替換。
    {
        do
        {
            if ((fileinfo.attrib & _A_SUBDIR)){//是否為資料夾
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
    if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1){
        do{
            int sss = fileinfo.attrib & _A_SUBDIR;
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
        if (_access(_path.c_str(),0)) {
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

void Tool::getIpAppName(string _path, vector<string>& _data) {
    TCHAR name[2048] = {0};
    string ss = "";
    GetPrivateProfileSectionNames(name, 2048, _path.c_str());
    if (name[0] == 0) return;
    for (int i = 0; i < 2048; i++) {
        if (name[i] == 0) {
            if(ss != "") _data.push_back(ss);
            ss = "";
        }
        else {
            ss += name[i];
        }
    }
}
