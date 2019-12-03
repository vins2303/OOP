#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Polynomial {
public:
    int a, b;
    vector<Polynomial*> pol;

    bool compare(Polynomial*p1, Polynomial*p2) {
        return p1->b > p2->b;
    }

    friend ostream& operator<<(ostream& out, const Polynomial& data) {
        for (unsigned int i = 0; i < data.pol.size(); i++) {
            out << data.pol[i]->a << "x^" << data.pol[i]->b;
            if (i != data.pol.size() - 1) out << "+";
        }
        return out;
    }

    friend istream& operator>>(istream& input, Polynomial& data) {
        int size;
        int aa, bb;
        Polynomial* p1;
        input >> size;

        //cout << a ^ b;
        for (int i = 0; i < size; i++) {
            p1 = new Polynomial();
            input >> p1->a;
            input >> p1->b;
            data.pol.push_back(p1);
        }
        return input;
    }

    int find(vector<Polynomial*>v, int b) {
        for (int i = 0; i < v.size(); i++)
            if (v[i]->b == b)
                return i;
        return -1;
    }
    
    Polynomial operator+( Polynomial &p2 ) {
        bool is = false;
        Polynomial out;
        int n;
        for (vector<Polynomial*>::iterator it = this->pol.begin(); it != this->pol.end(); it++) {
            if ((n = find(out.pol, (*it)->b)) == -1) 
                out.pol.push_back(*it);
            else 
                out.pol[n]->a += (*it)->a;
        }

        for (vector<Polynomial*>::iterator it = p2.pol.begin(); it != p2.pol.end(); it++) {
            if ((n = find(out.pol, (*it)->b)) == -1)
                out.pol.push_back(*it);
            else 
                out.pol[n]->a += (*it)->a;
        }
       
        return out;
    }


};


int main() {
    Polynomial p1, p2;
    cin >> p1 >> p2;
    cout << (p1 + p2) <<endl;

    system("pause");
    return 0;
}