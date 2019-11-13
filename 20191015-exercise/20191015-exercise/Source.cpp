#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include <fstream>
#include<algorithm>
using namespace std;

void SplitString(const string input_string, vector<string>& v, const string c);

class Person{
public:
    int ID;
    string name;
    string address;
    int year, month, day;
    void setDate(string _date){
        vector<string> v;
        SplitString(_date, v, "/");
        year = stoi(v[0]);
        month = stoi(v[1]);
        day = stoi(v[2]);
    }
};

void SplitString(const string input_string, vector<string>& v, const string c) {
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

void readPerson(vector<Person *> &_person, string file){
	ifstream person_read(file);
    Person *p;
    string date;
    if(!person_read){
        cout<<"Person 開檔錯誤!"<<endl;
    }else{
        while(!person_read.eof()){
            p = new Person;
            person_read >> p->ID >> p->name >> p->address >> date;
            p->setDate(date);
            _person.push_back(p);
        }
    }
    person_read.close();
}

void new_data(vector <Person*> &_person){
    Person *p = new Person;
    string date;
    int maxid=0;
    for(vector<Person *>::iterator it = _person.begin(); it != _person.end();it++)
        if((*it)->ID > maxid)
            maxid = (*it)->ID;
    cout << "Name address date：";
    p -> ID = maxid + 1;
    cin >> p->name >> p->address >> date;
    p->setDate(date);
    _person.push_back(p);
    cout<<"Name:"<<p->name<<"\naddress:"<<p->address<<"\ndate:"<<date<<endl;
}

void del_data(vector <Person*> &_person){
    int id;
    cout << "請選擇刪除ID：";
    cin >> id;
    bool error = false;
    for(vector<Person*>::iterator it = _person.begin();it!=_person.end();it++)
        if((*it)->ID == id){
            error = true;
            _person.erase(it);
            cout << "刪除成功\!"<<endl;
            break;
        }
    if(!error) cout << "無此ID!" << endl;
}

void find_data(vector <Person*> &_person){
    cout << "ID\tName\tAddress\t\t\tdate\n";
    for(vector<Person*>::iterator it = _person.begin();it!=_person.end();it++){
        cout<<(*it)->ID<<"\t"<<(*it)->name<<"\t"<<(*it)->address<<"\t"<<(*it)->year<<"/"<<(*it)->month<<"/"<<(*it)->day<<"\n";
    }
}

void ed_data(vector <Person*> &_person){
    int ID;
    cout << "輸入修改ID：";
    cin >> ID;
    Person *p = NULL;
    string data;
    for(vector<Person*>::iterator it = _person.begin();it!=_person.end();it++){
        if((*it)->ID == ID){
            p = *it;
            break;
        }
    }
    if(p == NULL){
        cout<<"無此ID"<<endl;
    }else{
        while (1){
            cout << "修改 1.name 2.address 3.date：";
            cin >> ID;
            if(ID == 1){
                cin >> data;
                p->name = data;
            }else if(ID == 2){
                cin >> data;
                p->address = data;

            }else if(ID == 3){
                cin >> data;
                p->setDate(data);
            }else{
                break;
            }
        }
        
    }

}

void wiredata(vector <Person*> &_person){
    ofstream wire("Person.txt");
    bool tt = false;
    for(vector<Person*>::iterator it = _person.begin();it!=_person.end();it++){
        if(tt) wire<<"\n";
        wire<<(*it)->ID<<" "<<(*it)->name<<" "<<(*it)->address<<" "<<(*it)->year<<"/"<<(*it)->month<<"/"<<(*it)->day;
        tt = true;
        
    }    
    wire.close();
}

int main(){
    vector <Person*> person;
    string person_file = "Person.txt";
    readPerson(person, person_file);
    int input;
    while(1){
        system("cls");
        cout << "1.新增一筆 persondata\n2.刪除\n3.查詢\n4.修改" <<endl;
        cin >> input;
        switch (input)
        {
        case 1:
            new_data(person);
            wiredata(person);
            break;
        case 2:
            find_data(person);
            del_data(person);
            wiredata(person);

            break;
        case 3:
            find_data(person);
            break;
        case 4:
            find_data(person);
            ed_data(person);
            wiredata(person);
            break;

        default:
            return 0;
            break;
        }

        system("pause");

    }

    return 0;
}