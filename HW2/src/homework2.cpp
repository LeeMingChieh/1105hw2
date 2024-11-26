#include <iostream>
#include <cmath> 
using namespace std;

class Polynomial {
private:
    int* coef; 
    int degree;        

public:
    Polynomial() : coef(nullptr), degree(0) {}//�w���Ncoef���Ы��Vnull�H�γ̰�����w�]��0
    ~Polynomial() {
        delete[] coef; 
    }

    friend istream& operator>>(istream& in, Polynomial& poly) {//��J�B��l�h��
        cout << "��J�h�������̰�����: ";
        in >> poly.degree;

        delete[] poly.coef;
        poly.coef = new int[poly.degree + 1];

        cout << "��J�h�������̰����誺�Y�ƨ�̧C���誺�Y��" << endl;
        for (int i = poly.degree; i >= 0; --i) {
            cout << "x^" << i << "�Y�� :";
            in >> poly.coef[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, const Polynomial& poly) {//��X�B��l�h��
        bool first = true;//first�O����Ĥ@���|���|��X + �� - �Ÿ����ܼ�
        for (int i = poly.degree; i >= 0; --i) {
            if (poly.coef[i] != 0) {
                
                if (!first && poly.coef[i] > 0) {
                    out << " + ";//���O�Ĥ@�� �Y�Ƭ����ɭn�[ + ��
                }
                else if (poly.coef[i] < 0) {
                    out << " - ";//�Y�Ƭ��t�ɭn�[ - ��
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

    cout << "�h������:" << endl;
    cout << p << endl;

    return 0;
}
