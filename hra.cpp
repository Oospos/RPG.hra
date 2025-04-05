#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){

    string name, cls, x;
    int maxhp, maxmana, hp, mana, gold, level=1, y;

    do{
         cout << "Jak se jmenujete?\n";
        cin >> name;
        cout << "Je vase jmeno " << name << "?" << endl;
        cin >> x;
    }while (x=="ne");
    do{

            do{
            cout << "Chcete byt Chlapek, V1 nebo V2?\n";
            cin >> cls;

            if (cls == "Chlapek" ) {
                maxhp=100;
                maxmana=100;
                hp=maxhp;
                mana=maxmana;
                gold=100;
                y=0;
                cout << "\nHP - " << maxhp <<
                        "\nMana - " << maxmana <<
                        "\nZlato - " << gold;

            }else if (cls == "V2" ) {
                maxhp=150;
                maxmana=50;
                hp=maxhp;
                mana=maxmana;
                gold=100;
                y=0;
                cout << "\nHP - " << maxhp <<
                        "\nMana - " << maxmana <<
                        "\nZlato - " << gold;

            }else if (cls == "V1" ) {
                maxhp=70;
                maxmana=150;
                hp=maxhp;
                mana=maxmana;
                gold=100;
                y=0;
                cout << "\nHP - " << maxhp <<
                        "\nMana - " << maxmana <<
                        "\nZlato - " << gold;

            }else if (cls == "Sigma" ) {
                maxhp=1000;
                maxmana=1000;
                hp=maxhp;
                mana=maxmana;
                gold=10000;
                y=0;
                cout << "\nHP - " << maxhp <<
                        "\nMana - " << maxmana <<
                        "\nZlato - " << gold;
            }else {
                y=1;
            }
         }while (y==1);
    cout << "\nChcete byt " << cls << "?\n";
    cin >> x;
    }while (x=="ne");
}
