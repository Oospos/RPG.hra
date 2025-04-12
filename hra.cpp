#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){

    string name, cls, x;
    int maxhp, maxenergy, hp, energy, gold, level=1, y, meleemult, rangedmult;

    do{
         cout << "What's your name?\n";
        cin >> name;
        cout << "Is your name " << name << "?" << endl;
        cin >> x;
    }while (x=="no");
    do{

            do{
            cout << "Choose your class\n- Guy\n- V1\n- V2\n";
            cin >> cls;

            if (cls == "Guy" ) {
                maxhp=100;
                maxenergy=100;
                hp=maxhp;
                energy=maxenergy;
                gold=100;
                y=0;
                meleemult=1;
                rangedmult=1;
                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nGold - " << gold;

            }else if (cls == "V2" ) {
                maxhp=180;
                maxenergy=50;
                hp=maxhp;
                energy=maxenergy;
                gold=50;
                y=0;
                meleemult=1,5;
                rangedmult=0,5;
                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nGold - " << gold;

            }else if (cls == "V1" ) {
                maxhp=70;
                maxenergy=150;
                hp=maxhp;
                energy=maxenergy;
                gold=100;
                y=0;
                meleemult=0,5;
                rangedmult=1.5;
                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nGold - " << gold;

            }else if (cls == "Sigms" ) {
                maxhp=1000;
                maxenergy=1000;
                hp=maxhp;
                energy=maxenergy;
                gold=10000;
                y=0;
                meleemult=2;
                rangedmult=2;
                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nGold - " << gold;
            }else {
                y=1;
            }
         }while (y==1);
    cout << "\nDo you want to be " << cls << "?\n";
    cin >> x;
    }while (x=="no");

    string place;
    int w, lasersword, lasergun, medpac, chargpac;

    do {
        cout << "You find yourself in a city, where would you like to go? (You can open the inventory by typing 'inv' at any time except in combat)\n\n";
        cout <<"- Shop\n- Engineer\n- Medic\n- Leave\n\n";



        cin >> place;

        if (place == "Shop" ) {
                cout<< "What would you like to buy?\n 1-Laser sword for 50 gold\n 2-Laser gun for 50 gold\n 3-Medpack for 25 gold\n 4-Charge pack for 25 gold\n 5-\n";
                cin >> w;


                switch (w){

            case 1:
                gold=gold-50;
                lasersword++;
            case 2:
                gold=gold-50;
                lasergun++;
            case 3:
                gold=gold-25;
                medpac++;
            case 4:
                gold=gold-25;
                chargpac++;
                x=="no";

            default:
                    x="no";}
                    x="no";





            }else if (place == "Engineer" ) {
                cout << "What stat do you want to upgrade?\n 1- Health for 50 gold (by 25)\n 2- Energy for 50 gold (by 25)\n 3- Ranged damage for 100 gold \n 4- Melee damage for 100 gold \n";
                cin >> w;

                switch (w){

            case 1:
                gold=gold-50;
                maxhp+=25;
            case 2:
                gold=gold-50;
                maxenergy+=25;
            case 3:
                gold=gold-25;
                rangedmult+=0.5;
            case 4:
                gold=gold-25;
                meleemult+=0.5;
            default:
                    x="no";}
                    x="no";


            }else if (place == "Medic" ) {
                cout << "Do you want to heal or charge up?\n 1- Heal up\n 2- Charge up\n 3- Leave\n";
                cin >> w;

                switch (w){

            case 1:
                gold=gold-50;
                hp=maxhp;
            case 2:
                gold=gold-50;
                energy=maxenergy;
            case 3:

            default:
                    x="no";}
                    x="no";

            }else if (place == "Leave" ) {
                cout << "Do you really want to leave?\n";
                cin >> x;
            }else if (place == "inv"){
                x=="no";

            }else {
                x="no";

            }







    }while (x=="no");
}
