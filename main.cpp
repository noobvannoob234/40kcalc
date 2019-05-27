#include <iostream>
using namespace std;
int dam;
int tough;
int armour;
int pen;
char nexthit; // another hit?
char newattack; //make a new attack (reset all inputs)
int damage(int,int,int,int); //variables in order: damage, toughness, armour, penetration.   returns damage as an integer in case needed for w/e

int main()
{
    while (newattack != 'n')
    {
	cout << "input Damage: ";
	cin >> dam;
	cout << "\n input Penetration: ";
	cin >> pen;
	cout << "\n input Armor: ";
	cin >> armour;
	cout << "\n input Toughness: ";
	cin >> tough;
        damage(dam, tough, armour, pen);
	nexthit = 'a'; //resets nexthit allowing re-entrance of below loop
	while (nexthit != 'n')
        {
            cout << "\n  additional hits (retain tgh, arm, and pen)? (y/n) \n";
            cin >> nexthit;
            if (nexthit != 'y' && nexthit != 'n')
                {
                    cout << "\n not a valid choice";
                }
            if (nexthit == 'y')
                {
                    cout << "\n input Damage: ";
                    cin >> dam;
                    damage(dam, tough, armour, pen);
                }
		}
		newattack = 'a'; // allows entrance of below loop if previously entered
		while (newattack != 'y' && newattack != 'n')
        {
            cout << "\n new attack? \n";
            cin >> newattack;
            if (newattack != 'y' && newattack != 'n')
                {
                    cout << "\n not a valid choice";
                }
       }
       cout << "\n";
    }
}


int damage(int d, int t, int a, int p)
{
		a = a - p;
		a = max(a,0);
		d = d - a - t;
		if (d <= 0)
		{
        cout << "\n Your target is undamaged";
		}
		else
		{
		    cout << "\n Your target receives  " << d << " damage";
		}
    return d;
}
