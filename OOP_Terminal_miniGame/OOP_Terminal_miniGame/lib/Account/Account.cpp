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
        cout << "1. �n�J�C��" << endl;
        cout << "2. ���U�b��" << endl;
        cout << "3. �����C��" << endl;
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
        cout << "�n�J...(eixt ���})\n�b���G";
        cin >> account_;
        if (account_ == "exit") return false;
        cout << "�K�X�G";
        cin >> password_;
        if (password_ == "exit") return false;

        if (isAccount(account_) == password_) {
            cout << "�n�J���\!" << endl;
            account  = account_;
            password = password_;
            system("pause");
            return true;
        }
        else {
            cout << "���˹�b���K�X�O�_���~!" << endl;
            system("pause");
        }
    }
    

}
void Account::Registered() {
    string account;
    string password;

    while (1) {
        system("cls");
        cout << "���U...(eixt ���})\n�b���G";
        cin >> account;
        if (account == "exit") return;
        cout << "�K�X�G";
        cin >> password;
        if (password == "exit") return;

        if (isAccount(account) == "NULL") {
            WritePrivateProfileString(account.c_str(), "Password", password.c_str(), AccountFile);
            cout << "���U���\!" << endl;
            system("pause");
            return;
        }
        else {
            cout << account << " �w���H�ϥ�" << endl;
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
