#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void enemyattack (int maxhp, int maxenergy, int hp, int energy, int enmaxhp, int enhp, int t, int mov [6], int def, int endef, int endmg1, int endmg2, int endmg3, int win, float dmgmult, string move1, string move2, string move3) {
    int x, y;
    cout << "You encountered an enemy!\n\n";
    do {
            do {
        y=0;
        if (enhp>0){
        cout << "Enemy: \n";
        cout << "Hp: " << enhp << "/" << enmaxhp << endl << endl << endl << endl;

        cout << "You:" << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "Energy: " << energy << "/" << maxenergy << endl << endl;
        cout << "Choose your attack: ";
        cout << "\n1: " << move1 << "\tdamage - " << mov [0]*dmgmult << "\tenergy use - " << mov [1];
        cout << "\n2: " << move2 << "\tdamage - " << mov [2]*dmgmult << "\tenergy use - " << mov [3];
        cout << "\n3: " << move3 << "\tdamage - " << mov [4]*dmgmult << "\tenergy use - " << mov [5] << endl;
        cin >> t;


        switch (t) {
        case 1:
            if (energy>=mov [1]){
            enhp=enhp-mov [0]*dmgmult+endef;
            energy=energy-mov [1];
            }
            break;
        case 2:
            if (energy>=mov [3]){
            enhp=enhp-mov [2]*dmgmult+endef;
            energy=energy-mov [3];
            }
            break;
        case 3:
            if (energy>=mov [5]){
            enhp=enhp-mov [4]*dmgmult+endef;
            energy=energy-mov [5];
            }
            break;
        default:
            t=1;
            cout << "Wrong input!"<<endl<<endl;
        }
        }
            }while(y==1);


            if (enhp>0){
            x=rand() %2;
            x++;
            cout << "\n\n\n\n" << x << "\n\n\n\n";
        switch (x) {
        case 1:
            hp=hp-endmg1+def;
            break;
        case 2:
             hp=hp-endmg2+def;
            break;
        case 3:
            hp=hp-endmg3+def;
            break;
        default:;}}


    }while (enhp>0);
    cout << "\nEnemy: \n";
    cout << "Hp: 0/" << enmaxhp << endl << endl << endl << endl;

    cout << "You:" << endl;
    cout << "HP: " << hp << "/" << maxhp << endl;
    cout << "Energy: " << energy << "/" << maxenergy << endl << endl << endl << endl;
if (hp>0){
    cout << "\n\nYou won!\n\n";
    win=1;
}else{
cout << "You lost...";
win=0;
}
}


int main(){

    string name, cls, x, move1, move2, move3, move4;
    int maxhp, maxenergy, hp, energy, credits, level=1, exp, y, mov [6], def, endef, enmaxhp, enhp, t, endmg1, endmg2, endmg3, win;
    float dmgmult;

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
                credits=100;
                y=0;
                dmgmult=1;
                def=5;

                move2="Kick      ";
                move3="Throw rock";

                mov [0]=15;
                mov [1]=10;

                mov [2]=20;
                mov [3]=15;

                mov [4]=5;
                mov [5]=1;

                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nCredits - " << credits;

            }else if (cls == "V2" ) {
                maxhp=180;
                maxenergy=50;
                hp=maxhp;
                energy=maxenergy;
                credits=50;
                y=0;
                dmgmult=1;
                def=10;

                move1="Punch      ";
                move2="Power blast";
                move3="Ricoshot   ";

                mov [0]=10;
                mov [1]=10;

                mov [2]=15;
                mov [3]=15;

                mov [4]=5;
                mov [5]=5;

                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nCredits - " << credits;

            }else if (cls == "V1" ) {
                maxhp=70;
                maxenergy=150;
                hp=maxhp;
                energy=maxenergy;
                credits=100;
                y=0;
                dmgmult=1;
                def=0;

                move1="Slam    ";
                move2="Parry   ";
                move3="Ricoshot";

                mov [0]=20;
                mov [1]=15;

                mov [2]=25;
                mov [3]=20;

                mov [4]=10;
                mov [5]=5;

                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nCredits - " << credits;

            }else if (cls == "Sigms" ) {
                maxhp=100000;
                maxenergy=1000;
                hp=maxhp;
                energy=maxenergy;
                credits=10000;
                y=0;
                dmgmult=1;
                def=1000;

                move1="Touch of death           ";
                move2="Laser                    ";
                move3="Speed of light rock throw";

                mov [0]=15000;
                mov [1]=15;

                mov [2]=10000;
                mov [3]=10;

                mov [4]=5000;
                mov [5]=5;

                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nCredits - " << credits;
            }else {
                y=1;
            }
         }while (y==1);
    cout << "\nDo you want to be " << cls << "?\n";
    cin >> x;
    }while (x=="no");




    enmaxhp=maxhp;
    enhp=enmaxhp;
    endef=0;
    endmg1=mov[0];
    endmg2=mov[2];
    endmg3=mov[4];

    enemyattack (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg1, endmg2, endmg3, win, dmgmult, move1, move2, move3);

    hp=maxhp;
    energy=maxenergy;
    if (win>0){
        credits=credits*1,5;
        cout << "You wake up in a city and find " << credits*0.5 << "Credits. ";
    }else {
        cout << "You wake up in a city. ";
    }



    string place;
    int w, lasersword, lasergun, medpac, chargpac;
    do {
        cout << "Where would you like to go?\n\n";
        cout <<"- Shop\n- Engineer\n- Medic\n- Leave\n\n";



        cin >> place;

        if (place == "Shop" ) {
                do {
                cout<< "What would you like to buy?\n 1-Laser sword for 50 credits\n 2-Laser gun for 50 credits\n 3-Medpack for 25 credits\n 4-Charge pack for 25 credits\n 5-Leave the shop\n";
                cin >> w;
                switch (w){
            case 1:
                credits=credits-50;
                lasersword++;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 2:
                credits=credits-50;
                lasergun++;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 3:
                credits=credits-25;
                medpac++;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 4:
                credits=credits-25;
                chargpac++;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 5:
                cout << "Are you sure you want to leave?\n";
                cin >> x;
                break;
            default:
                    x="no";}
                }while(x=="no");
                    x="no";




            }else if (place == "Engineer" ) {
                do{
                cout << "What stat do you want to upgrade?\n 1- Health for 50 credits (by 25)\n 2- Energy for 50 credits (by 25)\n 3- Damage for 100 credits \n 4- Leave the upgrade shop \n";
                cin >> w;

                switch (w){

            case 1:
                credits=credits-50;
                maxhp+=25;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 2:
                credits=credits-50;
                maxenergy+=25;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 3:
                credits=credits-100;
                dmgmult+=0.5;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 4:
                cout << "Are you sure you want to leave?\n";
                cin >> x;
                break;
            default:
                x="no";}
                }while(x=="no");
                x="no";




            }else if (place == "Medic" ) {
                do{
                cout << "Do you want to heal or charge up?\n 1- Heal up for 25 credits\n 2- Charge up for 25 credits\n 3- Both for 50 credits\n 4- Leave\n";
                cin >> w;

                switch (w){

            case 1:
                credits=credits-25;
                hp=maxhp;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 2:
                credits=credits-25;
                energy=maxenergy;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 3:
                credits=credits-50;
                energy=maxenergy;
                hp=maxhp;
                cout << "\nRemaining credits - " << credits << endl;
                x="no";
                break;
            case 4:
                cout << "Are you sure you want to leave?\n";
                cin >> x;
                break;
            default:
                    x="no";}
            }while (x=="no");
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
