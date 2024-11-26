#include <iostream>
#include <cmath> 
using namespace std;

class Polynomial {
private:
    int* coef; 
    int degree;        

public:
    Polynomial() : coef(nullptr), degree(0) {}//預先將coef指標指向null以及最高次方預設為0
    ~Polynomial() {
        delete[] coef; 
    }

    friend istream& operator>>(istream& in, Polynomial& poly) {//輸入運算子多載
        cout << "輸入多項式的最高次方: ";
        in >> poly.degree;

        delete[] poly.coef;
        poly.coef = new int[poly.degree + 1];

        cout << "輸入多項式的最高次方的係數到最低次方的係數" << endl;
        for (int i = poly.degree; i >= 0; --i) {
            cout << "x^" << i << "係數 :";
            in >> poly.coef[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {//輸出運算子多載
        bool first = true;//first是控制第一項會不會輸出 + 及 - 符號的變數
        for (int i = poly.degree; i >= 0; --i) {
            if (poly.coef[i] != 0) {
                
                if (!first && poly.coef[i] > 0) {
                    out << " + ";//不是第一項 係數為正時要加 + 號
                }
                else if (poly.coef[i] < 0) {
                    out << " - ";//係數為負時要加 - 號
                }

                if (abs(poly.coef[i]) != 1 || i == 0) {
                    cout << abs(poly.coef[i]);
                }
                if (i > 0) {
                    out << "x";
                    if (i > 1) cout << "^" << i;
                }
                first = false;
            }
        }
        if (first) out << "0"; 
        return out;
    }
};

int main() {
    Polynomial p;
    cin >> p;

    cout << "多項式為:" << endl;
    cout << p << endl;

    return 0;
}
