#include "../../include/Account/Account.h"

Account::Account() : isSignIn(false), account(""), password("") {
    //Menu();
}
Account::~Account() {
}

void Account::AccountMenu() {
    while (!isSignIn) {
        system("cls");
        cout << "1. 登入遊戲" << endl;
        cout << "2. 註冊帳號" << endl;
        cout << "3. 結束遊戲" << endl;
        switch (_getch()) {
        case '1':
            isSignIn = SignIn();
            break;
        case '2':
            Registered();
            break;
        case '3':
            exit(1);

            break;
        }
    }
}

bool Account::SignIn() {
    string account_;
    string password_;
    while (1) {
        system("cls");
        cout << "登入...(exit 離開)\n帳號：";
        cin >> account_;
        if (account_ == "exit") return false;
        cout << "密碼：";
        cin >> password_;
        if (password_ == "exit") return false;

        if (isAccount(account_) == password_) {
            cout << "登入成功!" << endl;
            account = account_;
            password = password_;
            //system("pause");
            return true;
        }
        else {
            cout << "請檢查帳號密碼是否錯誤!" << endl;
            system("pause");
        }
    }
}
void Account::Registered() {
    string account;
    string password;

    while (1) {
        system("cls");
        cout << "註冊...(eixt 離開)\n帳號：";
        cin >> account;
        if (account == "exit") return;
        cout << "密碼：";
        cin >> password;
        if (password == "exit") return;

        if (isAccount(account) == "NULL") {
            WritePrivateProfileString(account.c_str(), "Password", password.c_str(), AccountFile);
            cout << "註冊成功!" << endl;
            system("pause");
            return;
        }
        else {
            cout << account << " 已有人使用" << endl;
            system("pause");
        }
    }
}

string Account::isAccount(string _accout) {
    CString str;
    GetPrivateProfileString(_accout.c_str(), "Password", "NULL", str.GetBuffer(200), 200, AccountFile);
    str.ReleaseBuffer();
    return string(str);
}

string Account::GetAccount() { return account; }

void Account::Sign_out() {
    isSignIn = false;
    account = "";
    password = "";
}

bool Account::IsSignIn() { return isSignIn; }

bool Account::rmAccount() {
    int getKey;
    string dir = "";
    system("cls");
    cout << "確定刪除此帳號? 是(y) 否(n)" << endl;
    while (1) {
        getKey = _getch();
        if (getKey == 'n' || getKey == 'N')
            return false;
        if (getKey == 'y' || getKey == 'Y') {
            WritePrivateProfileString(account.c_str(), NULL, NULL, "Data/Account.ini");
            dir = "Data\\Account\\" + account;
            //if (GetFileAttributesA(dir.c_str()) == INVALID_FILE_ATTRIBUTES) {
            //dir = ;
            if (Tool::CheckFolderExist(dir)) {
                system(("rmdir /s /q " + dir).c_str());
                system("cls");
                //_rmdir(dir.c_str());
            }
            //}
            cout << "刪除帳號成功!" << endl;
            system("pause");
            return true;

            //break;
        }
    }
}