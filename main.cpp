#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int choice; //main menu selector
// variables related to damage
int damage(int,int,int,int); //variables in order: damage, toughness, armour, penetration.   returns damage as an integer in case needed for w/e
int damagecalc();
int dam;
int tough;
int armour;
int pen;
char nexthit; // another hit?
char newattack; //make a new attack (reset all inputs)

//variables for psychic charts
int psychic(); // main function
int phenom; //psychic phenomena
int peril; //perils of the warp
int range; //integer for determining range of a psychic or peril effect
int dur; //determines duration of effect
char autoeffect; // determines if a psychic effect's range and duration are auto generated

int main()
{
    srand (time(NULL)); //initialize random seed
    while (choice != 3)
    {
        cout << "Please choose an option: \n"
        << "1 - Damage Calculator \n"
        << "2 - Psychic Phenomena and Perils \n"
        << "3 - Exit Program \n";
        cin >> choice;
        cout << "\n";
        if (choice != 1 && choice != 2 && choice != 3)
        {
            cout << "not a valid option \n\n";
        }
        if (choice == 1)
        {
            damagecalc();
        }
        if (choice == 2)
        {
            psychic();
        }
    }
    return 0;
}

int damagecalc() //40k damagecalculator
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
    return 0;
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

int psychic()
{
    autoeffect = 'b';
    phenom = 0;
    peril = 0;
    while (autoeffect != 'y' && autoeffect != 'n') // option selector for automatically generating range
    {
        cout << "Auto generate effect range, duration, damages? (y/n) \n";
        cin >> autoeffect;
        cout << "\n";
        if (autoeffect != 'y' && autoeffect != 'n')
        {
            cout << "Invalid choice \n\n";
        }
    }
    if (phenom >= 4 && phenom <= 5)
    {
        cout << " \n\n";
    }
    cout << "Input Phenomena roll: ";
    cin >> phenom;
    cout << "\n";
    if (phenom >= 1 && phenom <= 3)
    {
        cout << "Dark Foreboding: A faint breeze blows past the sorcerer and those near him, and everyone gets the feeling that somewhere in the galaxy something unfortunate just happened \n\n";
    }
    if (phenom >= 4 && phenom <= 5)
    {
        cout << "Warp Echo: For a few moments, all noises cause echoes, regardless of the surroundings \n\n";
    }
    if (phenom >= 6 && phenom <= 8)
    {
        cout << "Unholy Stench: The air around the psyker becomes permeated with a bizarre and foul smell. \n\n";
    }
    if (phenom >= 9 && phenom <= 11)
    {
        cout << "Mind Warp: The psyker suffers a –5 penalty to Willpower Tests until the start of his next turn as his own inherent phobias, suspicions and hatreds surge to the surface of his mind in a wave of unbound emotion \n\n";
    }
    if (phenom >= 12 && phenom <= 14)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Hoarfrost: The temperature plummets for an instant, and a thin coating of frost covers everything within " << range << " metres \n\n";
        }
        else
        {
            cout << "Hoarfrost: The temperature plummets for an instant, and a thin coating of frost covers everything within 3d10 metres \n\n"; ;
        }
    }
    if (phenom >= 15 && phenom <= 17)
    {
        if (autoeffect == 'y')
        {
            range = rand() % 100 + 1;
            cout << "Aura of Taint: All animals within " << range << " metres become spooked and agitated; Characters with Psyniscience can pinpoint the psyker as the cause. \n\n";
        }
        else
        {
       cout << "Aura of Taint: All animals within 1d100 metres become spooked and agitated; Characters with Psyniscience can pinpoint the psyker as the cause \n\n";
        }
    }
    if (phenom >= 18 && phenom <= 20)
    {
        cout << "Memory Worm: All people within line of sight of the psyker forget something trivial. \n\n";
    }
    if (phenom >= 21 && phenom <= 23)
    {
        if (autoeffect == 'y')
        {
            range = (rand()%10 + 1) + (rand()%10 + 1) +(rand()%10 + 1) + (rand()%10 + 1) +(rand()%10 + 1);
            cout << "Spoilage: Food and drink go bad in a " << range <<" metre radius. \n\n";
        }
        else
        {
            cout << "Spoilage: Food and drink go bad in a 5d10 metre radius.\n\n";
        }
    }
    if (phenom >= 24 && phenom <= 26)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Haunting Breeze: Winds whip up around the psyker for a few moments, blowing light objects around and guttering fires within "<< range <<" metres \n\n";
        }
        else
        {
            cout << "Haunting Breeze: Winds whip up around the psyker for a few moments, blowing light objects around and guttering fires within 3d10 metres \n\n";
        }
    }
    if (phenom >= 27 && phenom <= 29)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Veil of Darkness: For a brief moment (effectively the remainder of the round), the area within "<< range<< " metres is plunged into immediate darkness.\n\n";
        }
        else
        {
            cout << "Veil of Darkness: For a brief moment (effectively the remainder of the round), the area within 3d10 metres is plunged into immediate darkness.\n\n";
        }
    }
    if (phenom >= 30 && phenom <= 32)
    {
        if (autoeffect == 'y')
        {
            range = (rand()%10 + 1) + (rand()%10 + 1) +(rand()%10 + 1) + (rand()%10 + 1) +(rand()%10 + 1);
            cout << "Distorted Reflections: Mirrors and other reflective surfaces within a radius of " << range <<" metres distort or shatter. \n\n";
        }
        else
        {
            cout << "Distorted Reflections: Mirrors and other reflective surfaces within a radius of 5d10 metres distort or shatter.\n\n";
        }
    }
    if (phenom >= 33 && phenom <= 35)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Breath Leech: Everyone (including the psyker) within a " << range <<" metre radius becomes short of breath for one round and cannot make any Run or Charge actions.\n\n";
        }
        else
        {
            cout << "Breath Leech: Everyone (including the psyker) within a 3d10 metre radius becomes short of breath for one round and cannot make any Run or Charge actions.\n\n";
        }
    }
    if (phenom >= 36 && phenom <= 38)
    {
        cout << "Daemonic Mask: For a fl eeting moment, the psyker takes on a daemonic appearance and gains a Fear rating of 1 until the start of the next turn. However, he also gains one Corruption Point. \n\n";
    }
    if (phenom >= 39 && phenom <= 41)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Unnatural Decay: All plant life within " << range << " metres of the psyker withers and dies.\n\n";
        }
        else
        {
            cout << "Unnatural Decay: All plant life within 3d10 metres of the psyker withers and dies.\n\n";
        }
    }
    if (phenom >= 42 && phenom <= 44)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1) + (rand() % 10 + 1 );
            cout << "Spectral Gale: Howling winds erupt around the psyker, requiring him and everyone within "<< range <<" metres to make an Easy (+30) Agility or Strength Test to avoid being knocked to the ground.\n\n";
        }
        else
        {
            cout << "Spectral Gale: Howling winds erupt around the psyker, requiring him and everyone within 4d10 metres to make an Easy (+30) Agility or Strength Test to avoid being knocked to the ground. \n\n";
        }
    }
    if (phenom >= 45 && phenom <= 47)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Bloody Tears: Blood weeps from stone and wood within " << range <<" metres of the psyker. If there are any pictures or statues of people inside this area, they appear to be crying blood.\n\n";
        }
        else
        {
            cout << "Bloody Tears: Blood weeps from stone and wood within 3d10 metres of the psyker. If there are any pictures or statues of people inside this area, they appear to be crying blood.\n\n";
        }
    }
    if (phenom >= 48 && phenom <= 50)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1) + (rand() % 10 + 1 )+ (rand() % 10 + 1);
            cout << "The Earth Protests: The ground suddenly shakes, and everyone (including the psyker) within a "<< range <<" metre radius must make a Routine (+10) Agility Test or be knocked down.\n\n";
        }
        else
        {
            cout << "The Earth Protests: The ground suddenly shakes, and everyone (including the psyker) within a 5d10 metre radius must make a Routine (+10) Agility Test or be knocked down.\n\n";
        }
    }
    if (phenom >= 51 && phenom <= 53)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1) + (rand() % 10 + 1 )+ (rand() % 10 + 1);
            cout << "Actinic Discharge: Static electricity fi lls the air within "<< range <<" causing hair to stand on end and unprotected electronics to short out, while the psyker is wreathed in eldritch lightning. \n\n";
        }
        else
        {
            cout << "Actinic Discharge: Static electricity fi lls the air within 5d10 metres causing hair to stand on end and unprotected electronics to short out, while the psyker is wreathed in eldritch lightning.\n\n";
        }
    }
    if (phenom >= 54 && phenom <= 56)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Warp Ghosts: Ghostly apparitions fill the air within " << range <<" metres around the psyker, flying about and howling in pain for a few brief moments. Everyone in the radius (except the psyker himself ) must test against a Fear rating of 1.\n\n";
        }
        else
        {
            cout << "Warp Ghosts: Ghostly apparitions fill the air within 3d10 metres around the psyker, flying about and howling in pain for a few brief moments. Everyone in the radius (except the psyker himself ) must test against a Fear rating of 1.\n\n";
        }
    }
    if (phenom >= 57 && phenom <= 59)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Falling Upwards: Everything within " << range << " metres around the psyker (including the psyker himself)";
            range = (rand() %10 + 1) + (rand() % 10 + 1);
            cout << " rises " << range << "metres into the air as gravity briefly ceases. Almost immediately, everything crashes back to earth, suffering falling Damage as appropriate for the distances fallen. \n\n";
        }
        else
        {
            cout << "Falling Upwards: Everything within 2d10 metres of the psyker (including the psyker himself ) rises 2d10 metres into the air as gravity briefly ceases. Almost immediately, everything crashes back to earth, suffering falling Damage as appropriate for the distances fallen.\n\n";
        }
    }
    if (phenom >= 60 && phenom <= 62)
    {
        if (autoeffect == 'y')
        {
            dur = (rand() %10 + 1);
            cout << "Banshee Howl: A shrill keening rings out across the immediate area, shattering glass and forcing every mortal creature able to hear it (including the psyker) to pass a Challenging (+0) Toughness Test or be deafened for " << dur <<" rounds.\n\n";
        }
        else
        {
            cout << "Banshee Howl: A shrill keening rings out across the immediate area, shattering glass and forcing every mortal creature able to hear it (including the psyker) to pass a Challenging (+0) Toughness Test or be deafened for 1d10 rounds.\n\n";
        }
    }
    if (phenom >= 63 && phenom <= 65)
    {
        if (autoeffect == 'y')
        {
            dam = rand() %5 +1 ;
            cout << "The Furies: The Psyker is assailed by unseen horrors. He is slammed to the ground and suffers " << dam << " wounds in Damage (ignoring armour, but not Toughness Bonus) and he must test against Fear (2).\n\n";
        }
        else
        {
            cout << "The Furies: The Psyker is assailed by unseen horrors. He is slammed to the ground and suffers 1d5 wounds in Damage (ignoring armour, but not Toughness Bonus) and he must test against Fear (2).\n\n";
        }
    }
    if (phenom >= 66 && phenom <= 68)
    {
        if (autoeffect == 'y')
        {
            range = rand() %100 + 1;
            dam = rand() % 5 + 1;
            cout << "Shadow of the Warp: For a split second, the world changes in appearance, and everyone within " << range << " metres has brief but horrific glimpse of the shadow of the warp. Everyone in the area (including the psyker) must make a Difficult (–10)Willpower Test or gain " << dam << " Corruption Points.\n\n";
        }
        else
        {
            cout << "Shadow of the Warp: For a split second, the world changes in appearance, and everyone within 1d100 metres has brief but horrific glimpse of the shadow of the warp. Everyone in the area (including the psyker) must make a Difficult (–10)Willpower Test or gain 1d5 Corruption Points.\n\n";
        }
    }
    if (phenom >= 69 && phenom <= 71)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1) + (rand() % 10 + 1 )+ (rand() % 10 + 1);
            dam = rand()%5+1;
            cout << "Tech Scorn: The machine spirits reject your unnatural ways. All un-warded technology within " << range << " metres malfunction momentarily, and all ranged weapons Jam (see Chapter I: Playing the Game), whilst characters with cybernetic implants must pass a Routine (+10) Toughness Test or suffer "<< dam << " Damage, ignoring Toughness Bonus and Armour.\n\n";
        }
        else
        {
            cout << "Tech Scorn: The machine spirits reject your unnatural ways. All un-warded technology within 5d10 metres malfunction momentarily, and all ranged weapons Jam (see Chapter I: Playing the Game), whilst characters with cybernetic implants must pass a Routine (+10) Toughness Test or suffer 1d5 Damage, ignoring Toughness Bonus and Armour.\n\n";
        }
    }
    if (phenom >= 72 && phenom <= 74)
    {
        if (autoeffect == 'y')
        {
            range = (rand() %10 + 1) + (rand() %10 + 1);
            cout << "Warp Madness: A violent ripple of tainted discord causes all creatures within " << range << " metres (with the exception of the Psyker) to become Frenzied for a Round and suffer " << dam << " Corruption Points unless they can pass a Difficult (–10) Willpower Test.\n\n";

        }
        else
        {
            cout << "Warp Madness: A violent ripple of tainted discord causes all creatures within 2d10 metres (with the exception of the Psyker) to become Frenzied for a Round and suffer 1d5 Corruption Points unless they can pass a Difficult (–10) Willpower Test.\n\n";
        }
    }
    if (phenom >= 75)
    {
        cout << "PERILS OF THE WARP \n"
             << "Input Perils roll: ";
        cin >> peril;
        cout << "\n";
    }
    if (peril >= 1 && peril <= 5)
    {
        if (autoeffect == 'y')
        {
            dur = rand() %5 + 1;
            cout << "The Gibbering: The psyker screams in pain as uncontrolled warp energies surge through his unprepared mind. He must make a Challenging (+0) Willpower Test or be stunned for  " << dur << " rounds.\n\n";
        }
        else
        {
            cout << "The Gibbering: The psyker screams in pain as uncontrolled warp energies surge through his unprepared mind. He must make a Challenging (+0) Willpower Test or be stunned for 1d5 rounds.\n\n";
        }
    }
    if (peril >= 6 && peril <= 9)
    {
        if (autoeffect == 'y')
        {
            dam = (rand()%5 + 1) + (rand()%5 + 1);
            dur = rand() %5 + 1;
            cout << "Warp Burn: A violent burst of energy from the warp smashes into the psyker’s mind, sending him reeling. He suffers "
                 << dam << " wounds, ignoring Toughness Bonus and Armour, and is stunned for " << dur << " Rounds. \n\n";
        }
        else
        {
            cout << "Warp Burn: A violent burst of energy from the warp smashes into the psyker’s mind, sending him reeling. He suffers 2d5"
                 << " wounds, ignoring Toughness Bonus and Armour, and is stunned for 1d5 Rounds.\n\n";
        }
    }
    if (peril >= 10 && peril <= 13)
    {
        if (autoeffect == 'y')
        {
            dur = rand() %5 + 1;
            range = (rand() %10 + 1) + (rand() %10 + 1) + (rand() % 10 + 1);
            cout << "Psychic Concussion: With a crack of energy, the psyker is knocked unconscious for " << dur << " rounds and everyone within " << range << " metres must make a Routine (+10) Willpower Test or be Stunned for one round.\n\n";
        }
        else
        {
            cout << "Psychic Concussion: With a crack of energy, the psyker is knocked unconscious for 1d5 rounds, and everyone within "
                 << "3d10 metres must make a Routine (+10) Willpower Test or be Stunned for one round.\n\n";
        }
    }
    if (peril >= 14 && peril <= 18)
    {
        if (autoeffect == 'y')
        {
            dam = (rand()%5 + 1) + (rand()%5 + 1);
            dur = rand() %5 + 1;
            cout << "" << dam << " .\n\n";
        }
        else
        {
            cout << " .\n\n";
        }
    }
    if (peril >= 1 && peril <= 5)
    {
        if (autoeffect == 'y')
        {
            dam = (rand()%5 + 1) + (rand()%5 + 1);
            dur = rand() %5 + 1;
            cout << "" << dam << " .\n\n";
        }
        else
        {
            cout << " .\n\n";
        }
    }
    if (peril >= 1 && peril <= 5)
    {
        if (autoeffect == 'y')
        {
            dam = (rand()%5 + 1) + (rand()%5 + 1);
            dur = rand() %5 + 1;
            cout << "" << dam << " .\n\n";
        }
        else
        {
            cout << " .\n\n";
        }
    }
    if (peril >= 1 && peril <= 5)
    {
        if (autoeffect == 'y')
        {
            dam = (rand()%5 + 1) + (rand()%5 + 1);
            dur = rand() %5 + 1;
            cout << "" << dam << " .\n\n";
        }
        else
        {
            cout << " .\n\n";
        }
    }
    if (peril >= 1 && peril <= 5)
    {
        if (autoeffect == 'y')
        {
            dam = (rand()%5 + 1) + (rand()%5 + 1);
            dur = rand() %5 + 1;
            cout << "" << dam << " .\n\n";
        }
        else
        {
            cout << " .\n\n";
        }
    }

    return 0;
}
