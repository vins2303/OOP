#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include <fstream>
#include<algorithm>
using namespace std;

class Customer;
class Transaction;
void SplitString(const string input_string, vector<string>& v, const string c);

//顧客資料
class Customer {
private:
	int ID, year, month, day;
	string name;

public:
	Customer() {};
	Customer(int ID_, string name_, string data_) {
		setID(ID_);
		setName(name_);
		setData(data_);
	}

	int getID()      { return ID;    }
	int getYear()    { return year;  }
	int getMonth()   { return month; }
	int getDay()     { return day;   }
	string getName() { return name;  }

	void set(int ID_, string name_, string data_) {
		setID(ID_);
		setName(name_);
		setData(data_);
	}

	void setID(int ID_) { ID = ID_; }

	void setName(string name_) { name = name_; }

	void setData(string data_) {
		vector<string> split_data;
		SplitString(data_, split_data, "/");
		year = stoi(split_data.at(0));
		month = stoi(split_data.at(1));
		day = stoi(split_data.at(2));
	}
};

//交易紀錄
class Transaction {
private:
	Customer *customer;
	int ID, money, year, month, day;

public:
	Transaction() {};
	Transaction(int ID_, string data_, int Moeny_, vector<Customer>& cus) {
		setID(ID_);
		setMoney(Moeny_);
		setData(data_);
		setName(ID_, cus);
		
	}

	int getID()     { return ID;    }
	int getMoney()  { return money; }
	int getYear()   { return year;  }
	int getMonth()  { return month; }
	int getDay()    { return day;   }
	int getAge() { return year - customer->getYear(); }
	string getName() { return customer->getName(); }

	bool datecmp(int month_, int year_) { return (month == month_ ? true : false) && (year == year_ ? true : false); }

	void set(int ID_, string data_, int Moeny_, vector<Customer>& cus){
		setID(ID_);
		setMoney(Moeny_);
		setData(data_);
		setName(ID_, cus);
	}
	void setID(int ID_) { ID = ID_; }
	void setMoney(int money_) { money = money_; }
	void setData(string data_) {
		vector<string> split_data;
		SplitString(data_, split_data, "/");
		year = stoi(split_data.at(0));
		month = stoi(split_data.at(1));
		day = stoi(split_data.at(2));
	}
	void setName(int ID_, vector<Customer>& cus) {
		for (int i = 0; i < cus.size(); i++) {
			if (ID_ == cus[i].getID()) {
				customer = &cus[i];
				return;
			}
		}
		cout << "Customer no ID error!"<<endl;
	}

	void print() {
		cout << ID << "\t" << customer->getName() << "\t" << getAge() << "\t" << year << "/" << month << "/" << day << "\t" << money << endl;
	}
};


class sel1_ {
private:
	int total_money;
	Transaction *transaction;

public:
	sel1_() {};
	sel1_(Transaction *transaction_) : transaction(transaction_), total_money(transaction_->getMoney()){}
	
	int getID() { return transaction->getID(); }
	int getMoney() { return total_money; }
	void Money_Add( int addMoney) { total_money += addMoney; }

	void set(Transaction *transaction_) {
		transaction = transaction_;
		total_money = transaction->getMoney();
	}

	void print() {
		cout << transaction->getID() << "\t" << transaction->getName() << "\t" << transaction->getAge() << "\t" << transaction->getYear() << "/" << transaction->getMonth() << "\t" << total_money << endl;
	}
};

bool sortMaxMini(Customer c1, Customer c2) {
	if (c2.getYear() == c1.getYear()) {
		if (c2.getMonth() == c1.getMonth()) 
			return c2.getDay() < c1.getDay();
		else return c2.getMonth() < c1.getMonth();
	}else return c2.getYear() < c1.getYear();
}

bool sortMiniMax(Customer c1, Customer c2) {
	if (c2.getYear() == c1.getYear()) {
		if (c2.getMonth() == c1.getMonth()) 
			return c2.getDay() > c1.getDay();
		else return c2.getMonth() > c1.getMonth();
	}
	else return c2.getYear() > c1.getYear();
}

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

//------------------------- swap -----------------------
void swap(Transaction *nd1, Transaction *nd2) {
	static Transaction Nd3 = *nd1;
	*nd1 = *nd2;
	*nd2 = Nd3;
}

void swap(sel1_ *d1, sel1_ *d2) {
	static sel1_ swap_save = *d1;
	*d1 = *d2;
	*d2 = swap_save;
}
//------------------------------------------------------

int findID(vector<sel1_> data, int ID) {
	for (int i = 0; i < data.size(); i++) {
		if (ID == data[i].getID()) {
     		return i;
		}
	}
	return -1;
}

void Data_read(string cu, string tr, vector<Customer>& cus, vector<Transaction>&   tran) {
	ifstream cus_read(cu);
	ifstream tran_read(tr);
	int ID, money;
	string name;
	string data;
	Customer customer;
	Transaction transaction;

	if (!cus_read || !tran_read) {
		cout << "開檔錯誤"<<endl;
		return;
	}
	
	while (!cus_read.eof()) {
		cus_read >> ID >> name >> data;
		customer.set(ID, name, data);
		cus.push_back(customer);
	}

	while (!tran_read.eof()) {
		tran_read >> ID >> name >> money;
		transaction.set(ID, name, money, cus);
		tran.push_back(transaction);
	}

	for (int i = tran.size() - 1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (tran.at(j).getMoney() < tran.at(j + 1).getMoney())
				swap(tran.at(j), tran.at(j+1));
	cus_read.close();
	tran_read.close();
}

void selete1(vector<Customer>& cus, vector<Transaction>& tran) {
	vector<sel1_> data;
	sel1_ sl;
	string name;
	int cin_year, cin_month, n;
	cout << "YYYY MM ：";
	cin >> cin_year >> cin_month;
	
	for (int it = 0; it < tran.size();it++) {
		if(tran[it].datecmp(cin_month, cin_year)){
			n = findID(data, tran[it].getID());
			if (n == -1) {
				sl.set(&tran[it]);
				data.push_back(sl);
			} else {
				data.at(n).Money_Add(tran[it].getMoney());
			}
		}
	}

	sel1_ save;
	if(data.size()>0) cout << "ID\tname\tage\tYYYY/MM\ttotal Money" << endl;
	for (int i = data.size() - 1; i > 0; i--) 
		for (int j = 0; j < i; j++) 
			if (data.at(j).getMoney() < data.at(j + 1).getMoney())
				swap(data.at(i), data.at(i+1));
			
	for (int i = 0; i < data.size(); i++) data[i].print();
}

void selete2(vector<Transaction>& tran) {
	cout << "ID\tname\tage\tYYYY/MM/DD\tmoney" << endl;
	int num = (int)(tran.size() / 2);
	for (vector<Transaction>::iterator it = tran.begin(); it != tran.end(); it++)
		if (it->getMoney() == tran.at(num).getMoney())
			it->print();
}

void select3(vector<Customer> cus) {
	int n;
	cout << "1大到小 2小到大" << endl;
	cin >> n;
	if (n == 1)
		sort(cus.begin(), cus.end(), sortMaxMini);
	else
		sort(cus.begin(), cus.end(), sortMiniMax);
	for (vector<Customer>::iterator it = cus.begin(); it != cus.end(); it++) {
		cout << it->getID() << "\t" << it->getName() << "\t" << it->getYear() << "/" << it->getMonth() << "/" << it->getDay() << endl;
	}
}

int main(int agc, char **agv) {
	if (agc != 3) cout << "命令語法不正確" << endl;
	else {
		vector<Customer> cus;

		vector<Transaction> tran;
		int inp;
		Data_read(agv[1], agv[2], cus, tran);
		for (vector<Customer>::iterator it = cus.begin(); it != cus.end(); it++) {
			cout << it->getID() << "\t" << it->getName() << "\t" << it->getYear() << "/" << it->getMonth() << "/" << it->getDay() << endl;
		}
		while (1) {
			cout << "1. All persons transaction data\n2. Show median value\n3. sort\nSelect：";
			cin >> inp;
			switch (inp)
			{
			case 1:
				selete1(cus, tran);
				break;
			case 2:
				selete2(tran);
				break;
			case 3:
				select3(cus);
				
				break;
			//default:
				//return 0;
			}
			cout << "========================================================================================\n" <<endl;
		}
	}
	return 0;
}