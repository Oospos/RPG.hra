#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void enemyattack (int maxhp, int maxenergy, int &hp, int &energy, int enmaxhp [4], int enhp [4], int t, int mov [6], int def, int endef [4], int endmg [12], int &win, float dmgmult, int block, int enemy, string move1, string move2, string move3, string cls, string enemyn [4]) {
    int x, y, ko;
    ko=0;
    float z;
if (enemy==1) {
    cout << "\n\n\n\n\n";
    cout << " --------------------------- \n";
    cout << "|                           |\n";
    cout << "| You encountered an enemy! |\n";
    cout << "|                           |\n";
    cout << " --------------------------- \n";
    cout << "\n\n";
}else {
    cout << "\n\n\n\n\n";
    cout << " ---------------------------- \n";
    cout << "|                            |\n";
    cout << "| You encountered "<< enemy <<" enemies! |\n";
    cout << "|                            |\n";
    cout << " ---------------------------- \n";
    cout << "\n\n";
}
do {


            do {
        y=0;
        if (enhp>0){

        for (int i=0; i<=enemy-1; i++) {
        cout << enemyn[i] << ": \n";
        cout << "Hp: " << enhp [i] << "/" << enmaxhp [i] << endl << endl;

        }
        cout << "\n\n\n";





        cout << "You:" << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "Energy: " << energy << "/" << maxenergy << endl << endl;
        cout << "Choose your attack: ";
        cout << "\n1: " << move1 << "\tdamage - " << mov [0]*dmgmult << "\tenergy use - " << mov [1];
        cout << "\n2: " << move2 << "\tdamage - " << mov [2]*dmgmult << "\tenergy use - " << mov [3];
        cout << "\n3: " << move3 << "\tdamage - " << mov [4]*dmgmult << "\tenergy use - " << mov [5];

        if (cls=="V1"){
            cout << "\n4: Parry\tBlock " << block << "% of incoming damage and heal " << maxhp/4 << " hp";
        }else{
            cout << "\n4: Block\tBlock " << block << "% of incoming damage";
        }

        cout << "\n5: Recharge\tRegain " << maxenergy/2 << " energy" << endl;
        cin >> t;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            t=542;
        }




        switch (t) {
        case 1:
            if (energy>=mov [1]){
            enhp[ko]=enhp[ko]-mov [0]*dmgmult+endef[ko];
            energy=energy-mov [1];
            }
            z=1;
            break;
        case 2:
            if (energy>=mov [3]){
            enhp[ko]=enhp[ko]-mov [2]*dmgmult+endef[ko];
            energy=energy-mov [3];
            }
            z=1;
            break;
        case 3:
            if (energy>=mov [5]){
            enhp[ko]=enhp[ko]-mov [4]*dmgmult+endef[ko];
            energy=energy-mov [5];
            }
            z=1;
            break;
        case 4:
            z=1-block/100;
            if (cls=="V1"){
                hp+=maxhp/4;
            }

            break;
        case 5:
            energy+=maxenergy/2;
            z=1;

            break;
        default:
            z=1;
            y=1;
            cout << "\n\n\n\n\nWrong input!"<<endl<<endl;


        }

        if (enhp[ko]<=0){
            enhp[ko]=0;
            ko++;
        }

        }
            }while(y==1);







            if (enhp[0]>0 || enhp[1]>0 || enhp[2]>0 || enhp[3]>0){


        for (int i=0; i<=enemy-1; i++) {
            x=rand() %2;
            x++;
            cout<<endl << i<<endl;
        switch (x) {
        case 1:
            hp=hp-endmg [0+3*i]*z+def;
            break;
        case 2:
             hp=hp-endmg [1+3*i]*z+def;
            break;
        case 3:
            hp=hp-endmg [2+3*i]*z+def;
            break;
        default:;


        }



        }
        if (hp>maxhp){hp=maxhp;}
        if (energy>maxenergy){energy=maxenergy;}

        }


    }while (enhp [0]>0 || enhp [1]>0 || enhp [2] >0 || enhp [3]>0 && hp>0);



        for (int i=0; i<=enemy-1; i++) {
        cout << enemyn[i] << ": \n";
        cout << "Hp: " << enhp [i] << "/" << enmaxhp [i] << endl << endl;

        }
    cout << endl << endl << "You:" << endl;
    cout << "HP: " << hp << "/" << maxhp << endl;
    cout << "Energy: " << energy << "/" << maxenergy << endl << endl << endl << endl;
if (hp>0){
    cout << "\n\nYou won!\n\n";
    win=1;
}else{
cout << "You lost...\n\n";
win=0;
}
}


int main(){

    string name, cls, x, move1, move2, move3, move4, enemyn [4];
    int maxhp, maxenergy, hp, energy, credits, level=1, exp, y, mov [6], def, endef [4], enmaxhp [4], enhp [4], t, endmg[12], win, block, enemy;
    float dmgmult;

    do{
         cout << "What's your name?\n";
        cin >> name;
        cout << "Is your name " << name << "?" << endl;
        cin >> x;
    }while (x=="no");
    do{

            do{
            cout << "Choose your character\n- Guy\n- V1\n- V2\n";
            cin >> cls;

            if (cls == "Guy" ) {
                maxhp=150;
                maxenergy=100;
                hp=maxhp;
                energy=maxenergy;
                credits=100;
                y=0;
                dmgmult=1;
                def=5;
                block=75;

                move1="Punch     ";
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
                maxhp=200;
                maxenergy=50;
                hp=maxhp;
                energy=maxenergy;
                credits=50;
                y=0;
                dmgmult=1;
                def=10;
                block=25;

                move1="Shoot      ";
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
                maxhp=100;
                maxenergy=150;
                hp=maxhp;
                energy=maxenergy;
                credits=100;
                y=0;
                dmgmult=1;
                def=0;
                block=50;

                move1="Slam    ";
                move2="Shotgun ";
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
                block=100;

                move1="DIE!!!         ";
                move2="Crush!!!       ";
                move3="Prepare thyself";

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




    enemyn [0]="You?";

    enmaxhp [0]=maxhp;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef [0]=0;
    endmg[0]=mov[0];
    endmg[1]=mov[2];
    endmg[2]=mov[4];
    enemy=1;

    enemyattack (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn);

    hp=maxhp;
    energy=maxenergy;
    if (win>0){
        cout << "You wake up in a city and find " << credits/2 << " Credits. ";
        credits=credits+credits/2;
    }else {
        cout << "You wake up in a city. ";
    }

    int w, lasersword, lasergun, medpac, chargpac, place;
    do {
        cout << "Where would you like to go?\n\n";
        cout <<"1-Shop\n2-Engineer\n3-Medic\n4-Leave\n\n";



        cin >> place;
            if (cin.fail()){
            cin.clear();
            cin.ignore();
            place=542;
        }
        switch (place){
        case 1:
                do {
                cout << "Remaining Credits: " << credits << "\n\n";
                cout<< "What would you like to buy?\n 1-Laser sword for 50 credits\n 2-Laser gun for 50 credits\n 3-Medpack for 25 credits\n 4-Charge pack for 25 credits\n 5-Leave the shop\n";
                cin >> w;cin >> t;

                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    x="no";
                }

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
                    break;




            case 2:
                do{
                cout << "Remaining Credits: " << credits << "\n\n";
                cout << "What stat do you want to upgrade?\n 1- Health for 50 credits (by 25)\n 2- Energy for 50 credits (by 25)\n 3- Damage for 100 credits \n 4- Leave the upgrade shop \n";
                cin >> w;

                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    x="no";
                }

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
                break;




            case 3:
                do{
                cout << "Remaining Credits: " << credits << "\n\n";
                cout << "Do you want to heal or charge up?\n 1- Heal up for 25 credits\n 2- Charge up for 25 credits\n 3- Both for 50 credits\n 4- Leave\n";
                cin >> w;

                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    x="no";
                }

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
            break;



            case 4:
                cout << "Do you really want to leave?\n";
                cin >> x;
                break;

            default:
                cout << "\n\nWrong input!\n\n";
                x="no";
            break;
            }
    }while (x=="no");
}
