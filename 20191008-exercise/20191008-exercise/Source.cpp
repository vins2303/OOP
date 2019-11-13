#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include <fstream>
#include<algorithm>

using namespace std;

// template<class X> X
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

class Books{
public:
    int ID;
    string name;
    string publishername;
    int year, month, day;    
    void setDate(string _date){
        vector<string> v;
        SplitString(_date, v, "/");
        year = stoi(v[0]);
        month = stoi(v[1]);
        day = stoi(v[2]);
    }
};

class Borrow{
public:
    Person *person;
    Books *Books;
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

void readBooks(vector<Books *> &_books, string file){
	ifstream book_read(file);
    Books *p;
    string date;
    if(!book_read){
        cout<<"Books 開檔錯誤!"<<endl;
    }else{
        while(!book_read.eof()){
            p = new Books;
            book_read >> p->ID >> p->name >> p->publishername >> date;
            p->setDate(date);
            _books.push_back(p);
        }
    }
    book_read.close();

}

void readBorrow(vector<Borrow*> &_Borrow, vector<Person *> _person, vector<Books *> _books, string file){
	ifstream borrow_read(file);
    Borrow *b;
    int n1,n2;
    string date;
    if(!borrow_read){
        cout<<"Borrow 開檔錯誤!"<<endl;
    }else{
        while(!borrow_read.eof()){
            borrow_read>>n1>>n2>>date;
            b = new Borrow;
            b->setDate(date);
            
            for (vector<Person*>::iterator it = _person.begin(); it != _person.end(); it++){
                if((*it) ->ID == n1){
                    b->person = *it;
                    break;
                }
            }

            for (vector<Books*>::iterator it = _books.begin(); it != _books.end(); it++){
                if((*it) ->ID == n2){
                    b->Books = *it;
                    break;
                }
            }
        
            _Borrow.push_back(b);    
            
        }
    }
    borrow_read.close();
}

bool SortMaxMin(Person *p1, Person *p2){
    if (p2->year == p1->year) {
		if (p2->month == p1->month) 
			return p2->day < p1->day;
		else return p2->month < p1->month;
	}else return p2->year < p1->year;
}

void sel1(vector<Person*> _person){
    cout << "1大到小 2小到大：";
    int inp;
    // _person[0]->ID = 100000;
    cin>> inp;
    sort(_person.begin(), _person.end(), SortMaxMin);
    if(inp == 2)
        reverse(_person.begin(), _person.end());
    
    for (vector<Person*>::iterator it = _person.begin(); it != _person.end(); it++)
        cout<<(*it)->ID<<"\t"<<(*it)->name<<"\t"<<(*it)->address<<"\t"<<(*it)->year<<"/"<<(*it)->month<<"/"<<(*it)->day<<endl;
    

}

int main(){
    vector <Person*> person;
    vector <Books*> book;
    vector <Borrow*> borrow;
    string person_file = "Person.txt";
    string book_file = "Books.txt";
    string borrow_file = "Borrow.txt";
    readPerson(person, person_file);
    readBooks(book, book_file);
    readBorrow(borrow ,person, book, borrow_file);
    int input;
    while(1){
        cin >> input;

        switch (input)
        {
        case 1:
            // sel1(person, book, borrow);
            sel1(person);
            // cout<<"IDDDD："<<person[0]->ID<<endl;
            break;
        case 2:
            for (vector<Borrow*>::iterator it = borrow.begin(); it != borrow.end(); it++){
                cout<< (*it)->person->name<<"\t"<< (*it)->Books->name<<"\t"<<(*it)->person->address<<"\t"<<(*it)->Books->publishername<<"\t"<<(*it)->year<<"/"<<(*it)->month<<"/"<<(*it)->day<<endl;
            }    
            break;
        default:
            break;
        }

    }
    cout<<endl;
    return 0;
}