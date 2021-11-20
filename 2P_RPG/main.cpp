#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

char p1[60],p2[60];
int p1c,p2c;
char in[5];
int p1hp=100,p2hp=100,bosshp=500,opt,p1mp=100,p2mp=100,stun=0,endd=0;

void check()
{
    if(bosshp<=0)
    {
        system("cls");
        cout<<"You win!\n";
        cout<<"You defeated the enemy!";
        Sleep(250);
        endd=1;
    }

    if(p1hp<=0)
    {
        system("cls");
        cout<<"Game Over\n";
        cout<<p1<<" died";
        Sleep(250);
        endd=1;
    }
    if(p2hp<=0)
    {
        system("cls");
        cout<<"Game Over\n";
        cout<<p2<<" died";
        Sleep(250);
        endd=1;
    }
}

void charstat()
{
    system("cls");
    cout<<"Boss HP:"<<bosshp<<"\n\n";
    cout<<p1<<" HP:"<<p1hp<<" MP:"<<p1mp<<"\n";
    cout<<p2<<" HP:"<<p2hp<<" MP:"<<p2mp<<"\n";
}

void bad_boi()
{
    srand(time(NULL));
    charstat();
    int dmg;
    if(stun)
    {
        cout<<"The enemy was unable to attack!";
        stun=0;
        Sleep(1750);
    }
    else
    {
        dmg=rand()%81-40;
        if(dmg>0)
        {
            p1hp=p1hp-dmg;
            cout<<"The enemy hit "<<p1<<" with "<<dmg<<" damage!";
            Sleep(1750);
        }
        else if(dmg<0)
        {
            p2hp=p2hp+dmg;
            cout<<"The enemy hit "<<p2<<" with "<<-dmg<<" damage!";
            Sleep(1750);
        }
        else
        {
            p1hp=p1hp-40;
            p2hp=p2hp-40;
            cout<<"The enemy used his secret move - Crossfire Hurricane!";
            cout<<"It dealt 40 damage to both "<<p1<<" and "<<p2<<" !";
        }
    }
}

void battle2()
{
    srand(time(NULL));
    int dmg,crit=0;
    charstat();
    if(p2c==1){
    cout<<"****************************\n";
    cout<<"* 1. Combo hit-20dmg/hit   *\n";
    cout<<"*   cost:0mp 1-3 hits      *\n";
    cout<<"* 2. Electro-punch-~45dmg  *\n";
    cout<<"* cost:30mp may stun enemy *\n";
    cout<<"* 3. Hi jump kick-~55dmg   *\n";
    cout<<"*cost:40mp High crit power *\n";
    cout<<"* 4. Lightspeed kick-125dmg*\n";
    cout<<"*      cost:70mp           *\n";
    cout<<"****************************\n\n";

    cout<<p2<<"'s move:";
    cin>>opt;
    cout<<"\n\n";
    if(opt==1)
    {
        charstat();
        Sleep(1750);
        dmg=rand()%3+1;
        bosshp=bosshp-dmg*20;
        charstat();
        cout<<p2<<" hit the enemy "<<dmg<<" time(s)";
        Sleep(1750);
    }
    else if(opt==2)
    {
        if(p2mp>=30)
        {
        p2mp=p2mp-30;
        charstat();
        Sleep(1750);
        dmg=rand()%15+41;
        stun=(rand()%100)<20;
        bosshp=bosshp-dmg;
        charstat();
        cout<<p2<<" hit the enemy with "<<dmg<<" damage\n";
        if(stun)
        {
            cout<<"The enemy was stunned!";
        }

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }
    }
    else if(opt==3)
    {
        if(p2mp>=40)
        {
        p2mp=p2mp-40;
        charstat();
        Sleep(1750);
        dmg=rand()%15+51;
        crit=(rand()%100)<20;
        if(crit)
        {
            dmg=dmg+35;
        }
        bosshp=bosshp-dmg;
        charstat();
        cout<<p2<<" hit the enemy with "<<dmg<<" damage\n";
        if(crit)
        {
            cout<<"Critical Hit!";
        }

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }

    }
    else if(opt==4)
    {
        if(p2mp>=70)
        {
        p2mp=p2mp-70;
        charstat();
        Sleep(1750);
        dmg=125;
        bosshp=bosshp-dmg;
        charstat();
        Sleep(1750);
        cout<<p2<<" hit the enemy with "<<dmg<<" damage\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }
    }
    }
    else if(p2c==2){
    cout<<"****************************\n";
    cout<<"* 1. Tackle-15dmg          *\n";
    cout<<"*   cost:0mp 1 hit         *\n";
    cout<<"* 2. Heal teammate-~40hp   *\n";
    cout<<"*     cost:30mp            *\n";
    cout<<"* 3. Heal self-~30hp       *\n";
    cout<<"*     cost:40mp            *\n";
    cout<<"* 4. Barrier               *\n";
    cout<<"*  cost:50mp Blocks 1 atk  *\n";
    cout<<"****************************\n\n";

    cout<<p2<<"'s move:";
    cin>>opt;
    cout<<"\n\n";
    if(opt==1)
    {
        charstat();
        Sleep(1750);
        bosshp=bosshp-15;
        charstat();
        cout<<p2<<" hit the enemy with 15 damage";
        Sleep(1750);
    }
    else if(opt==2)
    {
        if(p2mp>=30)
        {
        p2mp=p2mp-30;
        charstat();
        Sleep(1750);
        dmg=rand()%15+36;
        p1hp=(p1hp+dmg)-(p1hp+dmg)%100*(p1hp+dmg>100);
        charstat();
        cout<<p2<<" healed "<<p1<<" "<<dmg<<" hp\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }
    }
    else if(opt==3)
    {
        if(p2mp>=40)
        {
        p2mp=p2mp-40;
        charstat();
        Sleep(1750);
        dmg=rand()%15+36;
        p2hp=(p2hp+dmg)-(p2hp+dmg)%100*(p2hp+dmg>100);
        charstat();
        cout<<p2<<" healed himself "<<dmg<<" hp\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }

    }
    else if(opt==4)
    {
        if(p2mp>=50)
        {
        p2mp=p2mp-50;
        charstat();
        Sleep(1750);
        stun=1;
        Sleep(1750);
        cout<<p2<<" made a magic barrier. The enemy can't attack 1 turn";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }
    }
    }
    else if(p2c==3){
    cout<<"****************************\n";
    cout<<"* 1. Shuriken throw-25dmg  *\n";
    cout<<"*   cost:0mp 1 hit         *\n";
    cout<<"* 2. 9mm -7dmg/hit         *\n";
    cout<<"*  cost:30mp 1-17 hits     *\n";
    cout<<"* 3. Grenade-~60dmg        *\n";
    cout<<"*     cost:50mp            *\n";
    cout<<"* 4. AK47 -16dmg/hit       *\n";
    cout<<"*  cost:90mp 1-30 hits     *\n";
    cout<<"****************************\n\n";

    cout<<p2<<"'s move:";
    cin>>opt;
    cout<<"\n\n";
    if(opt==1)
    {
        charstat();
        Sleep(1750);
        bosshp=bosshp-25;
        charstat();
        cout<<p2<<" hit the enemy with 25 damage";
        Sleep(1750);
    }
    else if(opt==2)
    {
        if(p2mp>=30)
        {
        p2mp=p2mp-30;
        charstat();
        Sleep(1750);
        dmg=rand()%17+1;
        bosshp=bosshp-dmg*7;
        charstat();
        cout<<p2<<" hit the enemy "<<dmg<<" time(s)";
        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }
    }
    else if(opt==3)
    {
        if(p2mp>=40)
        {
        p2mp=p2mp-40;
        charstat();
        Sleep(1750);
        dmg=rand()%20+51;
        bosshp=bosshp-dmg;
        charstat();
        cout<<p2<<" hit the enemy with "<<dmg<<" damage\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }

    }
    else if(opt==4)
    {
        if(p2mp>=90)
        {
        p2mp=p2mp-90;
        charstat();
        Sleep(1750);
        dmg=rand()%30+1;
        bosshp=bosshp-dmg*16;
        charstat();
        cout<<p2<<" hit the enemy "<<dmg<<" time(s)";
        Sleep(1750);
        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle2();
        }
    }
    }
}

void battle1()
{
    srand(time(NULL));
    int dmg,crit=0;
    charstat();
    if(p1c==1){
    cout<<"****************************\n";
    cout<<"* 1. Combo hit-20dmg/hit   *\n";
    cout<<"*   cost:0mp 1-3 hits      *\n";
    cout<<"* 2. Electro-punch-~45dmg  *\n";
    cout<<"* cost:30mp may stun enemy *\n";
    cout<<"* 3. Hi jump kick-~55dmg   *\n";
    cout<<"*cost:40mp High crit power *\n";
    cout<<"* 4. Lightspeed kick-125dmg*\n";
    cout<<"*      cost:70mp           *\n";
    cout<<"****************************\n\n";

    cout<<p1<<"'s move:";
    cin>>opt;
    cout<<"\n\n";
    if(opt==1)
    {
        charstat();
        Sleep(1750);
        dmg=rand()%3+1;
        bosshp=bosshp-dmg*20;
        charstat();
        cout<<p1<<" hit the enemy "<<dmg<<" time(s)";
        Sleep(1750);
    }
    else if(opt==2)
    {
        if(p1mp>=30)
        {
        p1mp=p1mp-30;
        charstat();
        Sleep(1750);
        dmg=rand()%15+41;
        stun=(rand()%100)<20;
        bosshp=bosshp-dmg;
        charstat();
        cout<<p1<<" hit the enemy with "<<dmg<<" damage\n";
        if(stun)
        {
            cout<<"The enemy was stunned!";
        }

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }
    }
    else if(opt==3)
    {
        if(p1mp>=40)
        {
        p1mp=p1mp-40;
        charstat();
        Sleep(1750);
        dmg=rand()%15+51;
        crit=(rand()%100)<20;
        if(crit)
        {
            dmg=dmg+35;
        }
        bosshp=bosshp-dmg;
        charstat();
        cout<<p1<<" hit the enemy with "<<dmg<<" damage\n";
        if(crit)
        {
            cout<<"Critical Hit!";
        }

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }

    }
    else if(opt==4)
    {
        if(p1mp>=70)
        {
        p1mp=p1mp-70;
        charstat();
        Sleep(1750);
        dmg=125;
        bosshp=bosshp-dmg;
        charstat();
        Sleep(1750);
        cout<<p1<<" hit the enemy with "<<dmg<<" damage\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }
    }
    }
    else if(p1c==2){
    cout<<"****************************\n";
    cout<<"* 1. Tackle-15dmg          *\n";
    cout<<"*   cost:0mp 1 hit         *\n";
    cout<<"* 2. Heal teammate-~40hp   *\n";
    cout<<"*     cost:30mp            *\n";
    cout<<"* 3. Heal self-~30hp       *\n";
    cout<<"*     cost:40mp            *\n";
    cout<<"* 4. Barrier               *\n";
    cout<<"*  cost:50mp Blocks 1 atk  *\n";
    cout<<"****************************\n\n";

    cout<<p1<<"'s move:";
    cin>>opt;
    cout<<"\n\n";
    if(opt==1)
    {
        charstat();
        Sleep(1750);
        bosshp=bosshp-15;
        charstat();
        cout<<p1<<" hit the enemy with 15 damage";
        Sleep(1750);
    }
    else if(opt==2)
    {
        if(p1mp>=30)
        {
        p1mp=p1mp-30;
        charstat();
        Sleep(1750);
        dmg=rand()%15+36;
        p2hp=(p2hp+dmg)-(p2hp+dmg)%100*(p2hp+dmg>100);
        charstat();
        cout<<p1<<" healed "<<p2<<" "<<dmg<<" hp\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }
    }
    else if(opt==3)
    {
        if(p1mp>=40)
        {
        p1mp=p1mp-40;
        charstat();
        Sleep(1750);
        dmg=rand()%15+36;
        p1hp=(p1hp+dmg)-(p1hp+dmg)%100*(p1hp+dmg>100);
        charstat();
        cout<<p1<<" healed himself "<<dmg<<" hp\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }

    }
    else if(opt==4)
    {
        if(p1mp>=50)
        {
        p1mp=p1mp-50;
        charstat();
        Sleep(1750);
        stun=1;
        Sleep(1750);
        cout<<p1<<" made a magic barrier. The enemy can't attack 1 turn";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }
    }
    }
    else if(p1c==3){
    cout<<"****************************\n";
    cout<<"* 1. Shuriken throw-25dmg  *\n";
    cout<<"*   cost:0mp 1 hit         *\n";
    cout<<"* 2. 9mm -7dmg/hit         *\n";
    cout<<"*  cost:30mp 1-17 hits     *\n";
    cout<<"* 3. Grenade-~60dmg        *\n";
    cout<<"*     cost:50mp            *\n";
    cout<<"* 4. AK47 -16dmg/hit       *\n";
    cout<<"*  cost:90mp 1-30 hits     *\n";
    cout<<"****************************\n\n";

    cout<<p1<<"'s move:";
    cin>>opt;
    cout<<"\n\n";
    if(opt==1)
    {
        charstat();
        Sleep(1750);
        bosshp=bosshp-25;
        charstat();
        cout<<p1<<" hit the enemy with 25 damage";
        Sleep(1750);
    }
    else if(opt==2)
    {
        if(p1mp>=30)
        {
        p1mp=p1mp-30;
        charstat();
        Sleep(1750);
        dmg=rand()%17+1;
        bosshp=bosshp-dmg*7;
        charstat();
        cout<<p1<<" hit the enemy "<<dmg<<" time(s)";
        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }
    }
    else if(opt==3)
    {
        if(p1mp>=40)
        {
        p1mp=p1mp-40;
        charstat();
        Sleep(1750);
        dmg=rand()%20+51;
        bosshp=bosshp-dmg;
        charstat();
        cout<<p1<<" hit the enemy with "<<dmg<<" damage\n";

        Sleep(1750);

        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }

    }
    else if(opt==4)
    {
        if(p1mp>=90)
        {
        p1mp=p1mp-90;
        charstat();
        Sleep(1750);
        dmg=rand()%30+1;
        bosshp=bosshp-dmg*16;
        charstat();
        cout<<p1<<" hit the enemy "<<dmg<<" time(s)";
        Sleep(1750);
        }
        else
        {
            cout<<"Not enough MP!";
            Sleep(1750);
            battle1();
        }
    }
    }
    check();
    if(endd==0)
    battle2();
    check();
    if(endd==0)
    bad_boi();
    check();
    if(p1mp<100)
    p1mp+=10;
    if(p2mp<100)
    p2mp+=10;
    if(endd==0)
    battle1();
}


void charscrn()
{
    //tutorial
    {
        system("cls");

    cout<<"********************\n";
    cout<<"* Player classes:  *\n";
    cout<<"*  1.Close-range   * - Has a lot of destructive power,\n";
    cout<<"*  2.Assist/Healer *         but lacks evasiveness\n";
    cout<<"*  3.Long-range    *\n";
    cout<<"********************\n";
    Sleep(500);
    cout<<"\npress the return key\n";
    cout<<"    to continue";

    cin.getline(in,5);
        system("cls");

    cout<<"********************\n";
    cout<<"* Player classes:  *\n";
    cout<<"*  1.Close-range   *\n";
    cout<<"*  2.Assist/Healer * - Can help others by healing them and using\n";
    cout<<"*  3.Long-range    *   magic barriers, but is very bad in combat\n";
    cout<<"********************\n";
    Sleep(500);
    cout<<"\npress the return key\n";
    cout<<"    to continue";

    cin.getline(in,5);

        system("cls");

    cout<<"********************\n";
    cout<<"* Player classes:  *\n";
    cout<<"*  1.Close-range   *\n";
    cout<<"*  2.Assist/Healer *\n";
    cout<<"*  3.Long-range    * - Its evasiveness is outstanding, but its accuracy \n";
    cout<<"********************                    is lower than others'\n";
    Sleep(500);
    cout<<"\npress the return key\n";
    cout<<"    to continue";

    cin.getline(in,5);
    }

    system("cls");

    cout<<"********************\n";
    cout<<"* Player classes:  *\n";
    cout<<"*  1.Close-range   *\n";
    cout<<"*  2.Assist/Healer *\n";
    cout<<"*  3.Long-range    *\n";
    cout<<"********************\n\n";

    cout<<"P1 Name:";
    cin.getline(p1,50);
    Sleep(100);
    cout<<"P1 Class:";
    cin>>p1c;
Sleep(100);
    system("cls");
    cout<<"********************\n";
    cout<<"* Player classes:  *\n";
    cout<<"*  1.Close-range   *\n";
    cout<<"*  2.Assist/Healer *\n";
    cout<<"*  3.Long-range    *\n";
    cout<<"********************\n\n";

    cout<<"P2 Name:";
    cin.get();
    cin.getline(p2,50);
    Sleep(100);
    cout<<"P2 Class:";
    cin>>p2c;
    Sleep(100);
    battle1();
}

int main()
{
    cout<<"********************\n";
    cout<<"* Welcome to 2pRPG *\n";
    cout<<"*                  *\n";
    cout<<"* press return key *\n";
    cout<<"*    to enter      *\n";
    cout<<"********************\n";
    cin.getline(in,5);
    charscrn();
}
