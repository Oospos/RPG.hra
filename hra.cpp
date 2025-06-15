#include <iostream>
#include <string>
using namespace std;

void rest (int maxhp, int &hp, int maxenergy, int &energy) {
    string v="bo";
    do {
        cout << "Would you like to take a rest?(yes/no)\t-recover 25% of your health and energy at no cost\n";
        cin >>v;

        if (v=="yes"){
            hp=hp+0.25*maxhp;
            energy=energy+0.25*maxenergy;
            if (hp>maxhp){hp=maxhp;}
            if (energy>maxenergy){energy=maxenergy;}
            cout << "\nHP - " << hp << "/" << maxhp << endl;
            cout << "energy - " << energy << "/" << maxenergy << endl;
        }else if (v=="no"){
        cout << "Ok...\n";
        }else {
        cout << "Wrong input!";
        v="bo";
        }
    }while (v=="bo");
}
void levelup (int &lvl, int &exp, int &lvlup, int &maxhp, int &maxenergy, int &def, float &dmgmult, string name, string move1, string move2, string move3, int mov[6]) {


    exp=exp-lvlup;
    lvl++;
    lvlup=lvl*100;

    maxhp+=20;
    maxenergy+=20;
    def+=5;
    dmgmult+=0.25;

    cout << "\n\n\nCongrats " << name << " you leveled up to level " << lvl << "!\n\n";
    cout << "Your max HP increased to " << maxhp << "!\n";
    cout << "Your max energy increased to " << maxenergy << "!\n";
    cout << "Your defense increased to " << def << "!\n\n";

    cout << move1 << " now deals " << mov [0]*dmgmult << " damage!\n";
    cout << move2 << " now deals " << mov [2]*dmgmult << " damage!\n";
    cout << move3 << " now deals " << mov [4]*dmgmult << " damage!\n\n\n\n";
}
void monster (int maxhp, int maxenergy, int &hp, int &energy, int enmaxhp [4], int enhp [4], int t, int mov [6], int def, int endef [4], int endmg [12], int &win, float dmgmult, float block, int enemy, string move1, string move2, string move3, string cls, string enemyn [4], string ent) {
    int x, y, ko, xyz=10, iw, im, ik, id, iww, imm, ikk;
    ko=0, x=0, id=0, iw=0, im=0, ik=0;
    float z;
    if (ent=="n"){
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
    cout << "\n";
}
    }else if (ent=="m"){
    cout << "\n\n\n\n\n";
    cout << " ----------------------------- \n";
    cout << "|                             |\n";
    cout << "| You encountered a miniboss! |\n";
    cout << "|                             |\n";
    cout << " ----------------------------- \n";
    cout << "\n\n";
    }
do {


            do {
        y=0;

        if (enemy==1){cout << "\nenemy:";}
        if (enemy>1){cout << "\nenemies:";}
        for (int i=0; i<=enemy-1; i++) {
        cout << "\n\n" << enemyn[i] << ": \n";
        cout << "Hp: " << enhp [i] << "/" << enmaxhp [i] << endl << endl;

        }
        cout << "\n\n\n\n\n\n\n";





        cout << "You:" << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "Energy: " << energy << "/" << maxenergy << endl << endl;
        cout << "Choose your attack: ";
        cout << "\n1: " << move1 << "\tdamage - " << mov [0]*dmgmult << "\tenergy use - " << mov [1];
        cout << "\n2: " << move2 << "\tdamage - " << mov [2]*dmgmult << "\tenergy use - " << mov [3];
        cout << "\n3: " << move3 << "\tdamage - " << mov [4]*dmgmult << "\tenergy use - " << mov [5];

        if (cls=="Cyborg"){
            cout << "\n4: Parry\tBlock " << block << "% of incoming damage and heal " << maxhp/4 << " hp";
        }else if (cls=="Guy"){
            cout << "\n4: Block\tBlock " << block << "% of incoming damage and regain " << maxenergy*0.05 << " energy";
        }else {
            cout << "\n4: Block\tBlock " << block << "% of incoming damage and regain " << maxenergy*0.3 << " energy";
        }

        cout << "\n5: Recharge\tRegain " << maxenergy/2 << " energy" << endl;
        cin >> t;
        if (cin.fail()){
            cin.clear();
            cin.ignore();
            t=542;
        }
        iww=iw;
        imm=im;
        ikk=ik;




        switch (t) {
        case 1:
            if (energy>=mov [1]){
            enhp[ko]=enhp[ko]-mov [0]*dmgmult+endef[ko];
            energy=energy-mov [1];
            iw++;
            } else {cout << "\n\n\nNot enough energy\n\n\n"; y=1;}
            z=1;
            break;
        case 2:
            if (energy>=mov [3]){
            enhp[ko]=enhp[ko]-mov [2]*dmgmult+endef[ko];
            energy=energy-mov [3];
            im++;
            } else {cout << "\n\n\nNot enough energy\n\n\n"; y=1;}
            z=1;
            break;
        case 3:
            if (energy>=mov [5]){
            enhp[ko]=enhp[ko]-mov [4]*dmgmult+endef[ko];
            energy=energy-mov [5];
            ik++;
            } else {cout << "\n\n\nNot enough energy\n\n\n"; y=1;}
            z=1;
            break;
        case 4:
            z=1-block/100;
            if (cls=="Cyborg"){
                hp+=maxhp/4;
            }else if (cls=="Guy") {
                energy+=maxenergy*0.05;
            }else {
                energy+=maxenergy*0.3;
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
            break;


        }
        if (iww==iw){iww,iw=0;}
        if (imm==im){imm,im=0;}
        if (ikk==ik){ik=0;}
        if (cls== "Android"){

                if (ikk==1&&iw==1){
                    enhp[ko]=enhp[ko]-mov [0]*dmgmult+endef[ko];
                    energy=energy-mov [1];
                    iw, im, ik=0;
                    cout << "\n\nwowo\n\n";
                }

        }


        if (enhp[ko]<=0){
            enhp[ko]=0;
            ko++;
        }


            }while(y==1);


            if (enhp[0]>0 || enhp[1]>0 || enhp[2]>0 || enhp[3]>0){

        if (ent=="n") {
        for (int i=0; i<=enemy-1; i++) {
            x=rand() %3;
            x++;
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


        }else if (ent=="m")
        for (int i=0; i<=enemy-1; i++) {
            x=rand() %5;
            x++;
        switch (x) {
        case 1:
            hp=hp-endmg [0+5*i]*z+def;
            break;
        case 2:
             hp=hp-endmg [1+5*i]*z+def;
            break;
        case 3:
            hp=hp-endmg [2+5*i]*z+def;
            break;
        case 4:
            hp=hp-endmg [3+5*i]*z+def;
            break;
        case 5:
            hp=hp-endmg [4+5*i]*z+def;
            break;
        default:;
        }
        }



        if (hp>maxhp){hp=maxhp;}
        if (energy>maxenergy){energy=maxenergy;}

        }

        if (enhp [0]<=0 && enhp [1]<=0 && enhp [2]<=0 && enhp [3]<=0){xyz=0;}
        if (hp<=0){xyz=0;}


    }while (xyz>0);




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
void bigboss (int maxhp, int maxenergy, int &hp, int &energy, int enmaxhp [4], int enhp [4], int t, int mov [6], int def, int endef [4], int endmg [12], int &win, float dmgmult, float block, int enemy, string move1, string move2, string move3, string cls, string enemyn [4], string ent) {
    int x, y, ko, xyz=10, iw, im, is, ik, id, iww, imm, ikk;
    ko=0, x=0, id=0, iw=0, im=0, is=0, ik=0;
    float z;
    cout << "\n\n\n\n\n";
    cout << " ---------------------- \n";
    cout << "|                      |\n";
    cout << "| You found Chronobot! |\n";
    cout << "|                      |\n";
    cout << " ---------------------- \n";
    cout << "\n\n";

do {


            do {
        y=0;
        if (enhp>0){

        for (int i=0; i<=enemy-1; i++) {
        cout << "\n\nChronobot: \n";
        cout << "Hp: " << enhp [i] << "/" << enmaxhp [i] << endl << endl;

        }
        cout << "\n\n\n\n\n\n\n";





        cout << "You:" << endl;
        cout << "HP: " << hp << "/" << maxhp << endl;
        cout << "Energy: " << energy << "/" << maxenergy << endl << endl;
        cout << "Choose your attack: ";
        cout << "\n1: " << move1 << "\tdamage - " << mov [0]*dmgmult << "\tenergy use - " << mov [1];
        cout << "\n2: " << move2 << "\tdamage - " << mov [2]*dmgmult << "\tenergy use - " << mov [3];
        cout << "\n3: " << move3 << "\tdamage - " << mov [4]*dmgmult << "\tenergy use - " << mov [5];

        if (cls=="Cyborg"){
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
        iww=iw;
        imm=im;
        ikk=ik;




    switch (t) {
        case 1:
            if (energy>=mov [1]){
            enhp[ko]=enhp[ko]-mov [0]*dmgmult+endef[ko];
            energy=energy-mov [1];
            iw++;
            } else {cout << "\n\n\nNot enough energy\n\n\n"; }
            z=1;
            break;
        case 2:
            if (energy>=mov [3]){
            enhp[ko]=enhp[ko]-mov [2]*dmgmult+endef[ko];
            energy=energy-mov [3];
            im++;
            } else {cout << "\n\n\nNot enough energy\n\n\n"; }
            z=1;
            break;
        case 3:
            if (energy>=mov [5]){
            enhp[ko]=enhp[ko]-mov [4]*dmgmult+endef[ko];
            energy=energy-mov [5];
            ik++;
            } else {cout << "\n\n\nNot enough energy\n\n\n"; }
            z=1;
            break;
        case 4:
            z=1-block/100;
            if (cls=="Cyborg"){
                hp+=maxhp/4;
            }else {
                energy+=maxenergy*0.2;
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
            break;

        }
        if (iww==iw){iww,iw=0;}
        if (imm==im){imm,im=0;}
        if (ikk==ik){ikk,ik=0;}
        }
            }while(y==1);



        if (enhp[0]>0){
                id++;
                is++;
                if (is==5) {
                    hp=(hp-40-id*10)*z+def;
                   is=0;
                }

                if (id==1){
                    hp=(hp-40-id*10)*z+def;

                    }else if (id==2){
                        hp=(hp-40-id*10)*z+def;

                    }else if (id==3){
                        hp=(hp-40-id*10)*z+def;

                    }else if (id==4){
                        hp=(hp-40-id*10)*z+def;

                }

                if (iw==3) {
                    hp=hp-mov [0]*dmgmult+def;
                }
                if (im==3) {
                    hp=hp-mov [2]*dmgmult+def;
                }
                if (ik==3) {
                    hp=hp-mov [4]*dmgmult+def;
                }
        }








        if (hp>maxhp){hp=maxhp;}
        if (energy>maxenergy){energy=maxenergy;}



        if (enhp [0]<=0 && enhp [1]<=0 && enhp [2]<=0 && enhp [3]<=0){xyz=0;}
        if (hp<=0){xyz=0;}


    }while (xyz>0);




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
void healup (string x, int h, int c, int y, int maxhp, int &hp, int maxenergy, int &energy, int &medpac, int &chargpac){
    do {
    cout << "Would you like like to heal or charge up?";
    cout << "\n1 - Heal with Medpac          - Medpacs left - " << medpac;
    cout << "\n2 - Charge with Chargepac    - Chargepacs left - " << chargpac;
    cout << "\n3 - Nothing\n";
    cin >> y;
        if (cin.fail()){
                cin.clear();
                cin.ignore();
                y=14532;
        }

    switch (y) {
    case 1:

        if (medpac>1) {
        if (maxhp-hp<25){
        cout << "You regained " << maxhp-hp << "of your HP";

    }else{
        cout << "You regained " << h << " of your HP";
    }
        medpac--;
        hp+=25;
        }else {cout << "\nNot enough Medpacs!\n";}
        break;
    case 2:
        if (chargpac>1){
        if (maxenergy-energy<25){
        cout << "You regained " << maxenergy-energy << " energy";
            }else{
        cout << "You regained " << c << " energy";
    }
        chargpac--;
        energy+=25;
        }else {cout << "\nNot enough Medpacs!\n";}
    case 3:
        cout << "You do nothing";
        break;
    default:
        cout << "\n\nWrong input!\n\n";
        x="no";
        break;
    }

    if(hp>maxhp){hp=maxhp;}
    if(energy>maxenergy){energy=maxenergy;}


    do{
    cout << "\n\nDo you want to go further or stay a bit longer?";
    cout << "\n1 - Go";
    cout << "\n2 - Stay\n";
    cin >> y;
        if (cin.fail()){
                cin.clear();
                cin.ignore();
                y=14532;
        }
    switch (y) {
    case 1:
        x="yes";
        break;
    case 2:
        x="no";
        break;
    default:
        cout << "\n\nWrong input!\n\n";
        x="not";
        }
        }while (x=="not");
    } while (x=="no");

    }
void village (int &place, int &w, int &credits, int &lasersword, int &lasergun, int &medpac, int &chargpac, int &maxhp, int &hp, int &maxenergy, int &energy, float &dmgmult, string &x, int h, int c, float &cost1, float &cost2, float &cost3) {
    int gfh;
    do{
    cout << "\n\nWhere would you like to go?\n\n";
    cout <<"1-Shop\n2-Upgrade shop\n3-Medic\n4-Leave\n\n";
     cin >> place;
            if (cin.fail()){
            cin.clear();
            cin.ignore();
            place=542;
        }
        switch (place){
        case 1:
                do {
                cout << "Remaining credits:  " << credits << "\n\n";
                cout<< "What would you like to buy?\n 1-Medpack for 25 credits allows healing in between fights\n 2-Charge pack for 25 credits allows charging in between fights\n 3-Leave the shop\n";
                cin >> w;

                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    x="no";
                }

                switch (w){
            case 1:
                if (credits>=25){
                credits=credits-25;
                medpac++;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 2:
                if (credits>=25){
                credits=credits-25;
                chargpac++;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 3:
                cout << "Are you sure you want to leave? (yes/no)\n";
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
                cout << "What stat do you want to upgrade?\n 1- Health for " << 50*cost1 << " credits (by 25)\n 2- Energy for " << 50*cost2 << " credits (by 25)\n 3- Damage for " << 100*cost3 << " credits \n 4- Leave the upgrade shop \n";
                cin >> w;

                if (cin.fail()){
                    cin.clear();
                    cin.ignore();
                    x="no";
                }

                switch (w){

            case 1:
                if (credits>=50){
                credits=credits-50*cost1;
                cost1+=0.5;
                maxhp+=25;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 2:
                if (credits>=50){
                credits=credits-50*cost2;
                cost2+=0.5;
                maxenergy+=25;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 3:
                if (credits>=100){
                credits=credits-100*cost3;
                cost3+=0.5;
                dmgmult+=0.5;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 4:
                cout << "Are you sure you want to leave? (yes/no)\n";
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
                if (credits>=25){
                credits=credits-25;
                hp=maxhp;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 2:
                if (credits>=25){
                credits=credits-25;
                energy=maxenergy;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 3:
                if (credits>=50){
                credits=credits-50;
                energy=maxenergy;
                hp=maxhp;
                cout << "\n Remaining credits: " << credits << endl;
                }else {cout << "Not enough credits!!!";}
                x="no";
                break;
            case 4:
                cout << "Are you sure you want to leave? (yes/no)\n";
                cin >> x;
                break;
            default:
                cout << "\n\n Wrong input!\n\n";
                x="no";
                break;

            }

                }while (x=="no");

        case 4:
                cout << "Are you sure you want to leave? (yes/no)\n";
                cin >> x;
                break;

        default:
                cout << "\n\n Wrong input!\n\n";
                x="no";
                break;




        }
    }while (x=="no");
}




int main(){

    string name, cls, x, move1, move2, move3, move4, enemyn [4], ent;
    int lvl, exp, lvlup, maxhp, maxenergy, hp, energy, credits, h, y, c, v, mov [6], def, endef [4], enmaxhp [4], enhp [4], t, endmg[12], win, enemy;
    float dmgmult, block, cost1=1, cost2=1, cost3=1;
    lvl=1;
    exp=0;
    lvlup=lvl*100;

    do{
         cout << "What's your name?\n";
        cin >> name;
        cout << "Is your name " << name << "? (yes/no)" << endl;
        cin >> x;
    }while (x=="no");
    do{

            do{
            cout << "Choose your character\n1 - Guy\n2 - Cyborg\n3 - Android\n";
            cin >> cls;

            if (cls == "1" ) {
                cls="Guy";
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
                mov [1]=5;

                mov [2]=20;
                mov [3]=10;

                mov [4]=5;
                mov [5]=0;

                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nDefense - " << def <<
                        "\nCredits - " << credits <<
                        "\n\nAttacks: \n" <<
                        move1 << " - deals " << mov [0]*dmgmult << " damage\n" <<
                        move2 << " - deals " << mov [2]*dmgmult << " damage\n" <<
                        move3 << " - deals " << mov [4]*dmgmult << " damage\n\n\n\n";

            }else if (cls == "3" ) {
                cls="Android";
                maxhp=250;
                maxenergy=60;
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

                mov [0]=15;
                mov [1]=10;

                mov [2]=20;
                mov [3]=15;

                mov [4]=10;
                mov [5]=5;

                cout << "\nHP - " << maxhp <<
                        "\nEnergy - " << maxenergy <<
                        "\nDefense - " << def <<
                        "\nCredits - " << credits <<
                        "\n\nAttacks: \n" <<
                        move1 << " - deals " << mov [0]*dmgmult << " damage\n" <<
                        move2 << " - deals " << mov [2]*dmgmult << " damage\n" <<
                        move3 << " - deals " << mov [4]*dmgmult << " damage\n\n\n\n";

            }else if (cls == "2" ) {
                cls="Cyborg";
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
                        "\nDefense - " << def <<
                        "\nCredits - " << credits <<
                        "\n\nAttacks: \n" <<
                        move1 << " - deals " << mov [0]*dmgmult << " damage\n" <<
                        move2 << " - deals " << mov [2]*dmgmult << " damage\n" <<
                        move3 << " - deals " << mov [4]*dmgmult << " damage\n\n\n\n";

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
                        "\nDefense - " << def <<
                        "\nCredits - " << credits <<
                        "\n\nAttacks: \n" <<
                        move1 << " - deals " << mov [0]*dmgmult << " damage\n" <<
                        move2 << " - deals " << mov [2]*dmgmult << " damage\n" <<
                        move3 << " - deals " << mov [4]*dmgmult << " damage\n\n\n\n";
            }else {
                cout << "\n\nWrong input!\n\n";
                y=1;
            }
         }while (y==1);
    cout << "\nDo you want to be " << cls << "? (yes/no)\n";
    cin >> x;
    }while (x=="no");




    enemyn [0]="You?";
    ent="n";

    enmaxhp [0]=maxhp;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=0;
    endmg[0]=mov[0];
    endmg[1]=mov[2];
    endmg[2]=mov[4];
    enemy=1;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);

    hp=maxhp;
    energy=maxenergy;
    if (win>0){
        cout << "You wake up in a city and realize it was just a nightmare and you're not hurt at all.\n\n";
        cout << "HP: " << hp << "/" << maxhp;
        cout << "\nEnergy: " << energy << "/" << maxenergy;
        cout << "\n\nYou find " << credits/2 << " Credits. You now have " << credits+credits/2 << " Credits";
        credits=credits+credits/2;
    }else {
        cout << "You wake up in a city and realize it as just a nightmare and your not hurt at all.";
        cout << "HP: " << hp << "/" << maxhp;
        cout << "Energy: " << energy << "/" << maxenergy;
    }

    int w=0, lasersword=0, lasergun=0, medpac=0, chargpac=0, place=0;

    village (place, w, credits, lasersword, lasergun, medpac, chargpac, maxhp, hp, maxenergy, energy, dmgmult, x, h, c, cost1, cost2, cost3);


    enemyn [0]="Drone";
    ent="n";

    enmaxhp [0]=50;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=10;
    endmg[0]=30;
    endmg[1]=10;
    endmg[2]=5;
    enemy=1;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %26+25;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %16+25;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=25;
    c=25;
    healup (x, h, c, y, maxhp, hp, maxenergy, energy, medpac, chargpac);



    enemyn [0]="Soldier";
    ent="n";

    enmaxhp [0]=80;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=5;
    endmg[0]=25;
    endmg[1]=10;
    endmg[2]=10;
    enemy=1;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %21+30;
        if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %16+25;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
        levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=25;
    c=25;
    rest (maxhp, hp, maxenergy, energy);


    enemyn [0]="Sentry";
    enemyn [1]="Drone";
    ent="n";

    enmaxhp [0]=100;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=80;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=0;
    endef[1]=10;

    endmg[0]=20;
    endmg[1]=10;
    endmg[2]=15;

    endmg[3]=20;
    endmg[4]=15;
    endmg[5]=5;
    enemy=2;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %31+45;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %16+25;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %16+25;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=25;
    c=25;
    healup (x, h, c, y, maxhp, hp, maxenergy, energy, medpac, chargpac);



    enemyn [0]="Big Johninator";
    ent="m";

    enmaxhp [0]=300;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=10;

    endmg[0]=25;
    endmg[1]=15;
    endmg[2]=20;
    endmg[3]=35;
    endmg[4]=15;
    enemy=1;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %101+40;
    if (win>0){
            v=credits;
            credits=credits+rand() %46+25;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=35;
    c=35;
    rest (maxhp, hp, maxenergy, energy);


    village (place, w, credits, lasersword, lasergun, medpac, chargpac, maxhp, hp, maxenergy, energy, dmgmult, x, h, c, cost1, cost2, cost3);


    enemyn [0]="Sentry";
    enemyn [1]="Drone";
    enemyn [2]="Soldier";
    ent="n";

    enmaxhp [0]=100;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=50;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=80;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=0;
    endef[1]=10;
    endef[2]=5;

    endmg[0]=25;
    endmg[1]=5;
    endmg[2]=15;

    endmg[3]=25;
    endmg[4]=5;
    endmg[5]=10;

    endmg[6]=20;
    endmg[7]=15;
    endmg[8]=5;
    enemy=3;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %61+50;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %16+30;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %16+25;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %21+30;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=35;
    c=35;
    healup (x, h, c, y, maxhp, hp, maxenergy, energy, medpac, chargpac);



    enemyn [0]="Sentry";
    ent="n";

    enmaxhp [0]=100;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=10;
    endmg[0]=35;
    endmg[1]=10;
    endmg[2]=15;
    enemy=1;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %26+35;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %21+30;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=35;
    c=35;
    rest (maxhp, hp, maxenergy, energy);


    enemyn [0]="Drone";
    enemyn [1]="Drone";
    ent="n";

    enmaxhp [0]=100;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=100;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=15;
    endef[1]=15;

    endmg[0]=30;
    endmg[1]=25;
    endmg[2]=15;

    endmg[3]=30;
    endmg[4]=25;
    endmg[5]=15;
    enemy=2;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %51+45;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %26+30;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %26+30;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=35;
    c=35;
    healup (x, h, c, y, maxhp, hp, maxenergy, energy, medpac, chargpac);


    enemyn [0]="Gutterman";
    ent="n";

    enmaxhp [0]=200;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=25;
    endmg[0]=15;
    endmg[1]=20;
    endmg[2]=10;
    enemy=1;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %51+45;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %21+30;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %21+30;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=45;
    c=45;
    rest (maxhp, hp, maxenergy, energy);




    enemyn [0]="Excavator";
    ent="m";

    enmaxhp [0]=400;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=20;
    endmg[0]=20;
    endmg[1]=20;
    endmg[2]=20;
    endmg[3]=50;
    endmg[4]=60;
    enemy=1;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %101+40;
    if (win>0){
            v=credits;
            credits=credits+rand() %46+25;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=45;
    c=45;
    rest (maxhp, hp, maxenergy, energy);

    village (place, w, credits, lasersword, lasergun, medpac, chargpac, maxhp, hp, maxenergy, energy, dmgmult, x, h, c, cost1, cost2, cost3);



    enemyn [0]="Gutterman";
    enemyn [1]="Sentry";
    ent="n";

    enmaxhp [0]=150;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=120;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];


    endef[0]=20;
    endef[1]=15;

    endmg[0]=25;
    endmg[1]=40;
    endmg[2]=25;

    endmg[3]=30;
    endmg[4]=25;
    endmg[5]=50;
    enemy=2;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %51+55;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %36+35;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %36+35;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=45;
    c=45;
    healup (x, h, c, y, maxhp, hp, maxenergy, energy, medpac, chargpac);



    enemyn [0]="Drone";
    enemyn [1]="Drone";
    enemyn [2]="Drone";
    enemyn [3]="Drone";
    ent="n";

    enmaxhp [0]=100;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=100;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=100;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=100;
    enhp [3]=enmaxhp [3];


    endef[0]=15;
    endef[1]=15;
    endef[2]=15;
    endef[3]=15;

    endmg[0]=35;
    endmg[1]=25;
    endmg[2]=25;

    endmg[3]=40;
    endmg[4]=25;
    endmg[5]=30;

    endmg[6]=30;
    endmg[7]=35;
    endmg[8]=25;

    endmg[9]=20;
    endmg[10]=30;
    endmg[11]=30;
    enemy=4;

    monster (maxhp, maxenergy, hp, energy, enmaxhp, enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    exp+=rand() %51+55;
    if (win>0){
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %36+35;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
            if(rand() %2==0){
            v=credits;
            credits=credits+rand() %36+35;
            cout << "\n\nYou gained " << credits-v << " Credits!\n\n";
            }
    }else {
        return 0;
    }
    if (exp>=lvlup){
    levelup (lvl, exp, lvlup, maxhp, maxenergy, def, dmgmult, name, move1, move2, move3, mov);
    }
    h=45;
    c=45;
    rest (maxhp, hp, maxenergy, energy);


    village (place, w, credits, lasersword, lasergun, medpac, chargpac, maxhp, hp, maxenergy, energy, dmgmult, x, h, c, cost1, cost2, cost3);


    enmaxhp [0]=700;
    enhp [0]=enmaxhp [0];

    enmaxhp [1]=0;
    enhp [1]=enmaxhp [1];

    enmaxhp [2]=0;
    enhp [2]=enmaxhp [2];

    enmaxhp [3]=0;
    enhp [3]=enmaxhp [3];

    endef[0]=25;
    enemy=1;


    bigboss (maxhp, maxenergy,hp, energy, enmaxhp , enhp, t, mov, def, endef, endmg, win, dmgmult, block, enemy, move1, move2, move3, cls, enemyn, ent);
    if (win>0){
            cout << "Congratulations you won!";
    }else {
        return 0;
    }



}
