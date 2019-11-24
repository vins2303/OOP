#include "../../include/Account/Account.h"

Account::Account() {
    isSignIn = false;
    account = "";
    password = "";
    Menu();
}
Account::~Account() {
}

void Account::Menu(){
    while (!isSignIn){
        system("cls");
        cout << "1. 登入遊戲" << endl;
        cout << "2. 註冊帳號" << endl;
        cout << "3. 結束遊戲" << endl;
        switch (_getch())
        {
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
    while (1){
        system("cls");
        cout << "登入...(eixt 離開)\n帳號：";
        cin >> account_;
        if (account_ == "exit") return false;
        cout << "密碼：";
        cin >> password_;
        if (password_ == "exit") return false;

        if (isAccount(account_) == password_) {
            cout << "登入成功!" << endl;
            account  = account_;
            password = password_;
            system("pause");
            return true;
        }
        else {
            cout << "請檢察帳號密碼是否錯誤!" << endl;
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
    GetPrivateProfileString(_accout.c_str(), "Password","NULL", str.GetBuffer(200), 200, AccountFile);
    str.ReleaseBuffer();
    return string( str );
}
