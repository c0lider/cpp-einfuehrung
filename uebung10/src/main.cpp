#include "../include/held.h"
#include "../include/elf.h"
#include "../include/mensch.h"
#include "../include/zwerg.h"


#include <iostream>
#include <iomanip>

using namespace std;

//Allgemeine Funktionen
void einleitung()
{
	cout << "Es waren einmal drei Helden. Leider koennen diese sich teilweise nicht mal mehr an ihren Namen erinnern." << endl;
	cout << "Das liegt wohl vor allem an der letzten Nacht im Wirtshaus zur Baertigen Barbara" << endl;
	cout << endl;

	cout << "Enter druecken" << endl;
	cin.get();

	cout << endl;
	cout << "Doch bevor sich unsere Helden in ein Abenteuer stuerzen koennen," << endl;
	cout << "sollten sie sich wieder an die wichtigsten Dinge erinnern." << endl;
	cout << endl;

	cout << "Enter druecken" << endl;
	cin.get();

	cout << endl;
	cout << "Ich hoffe hier koennen Sie helfen." << endl;
	cout << endl;
	cout << "Enter druecken" << endl;
	cin.get();
}


void elfErstellen(Elf& held)	//Hier muss die referenz auf das Elfen Objekt genutzt werden. Vermutung: Bei der Zuweisung (held = held2) wird sonst nur der Helden Teil und nicht der Elfen �berschrieben
{
	string name;

	cout << "Geben Sie einen Namen fuer Ihren Helden ein: " << endl;
	getline(cin, name);
	Elf held2(name); //Held 2 - Alter und Groesse sind Default-Werte
	held = held2;
}

Zwerg zwergErstellen()
{
	string name;
	int alter;
	double groesse;

	cout << "Geben Sie einen Namen fuer Ihren Helden ein: " << endl;
	getline(cin, name);
	cout << "Geben Sie das Alter fuer Ihren Held ein: " << endl;
	cin >> alter;
	cin.get();
	cout << "Geben Sie die Groesse (in Metern) fuer Ihren Helden ein: " << endl;
	cin >> groesse;
	cin.get();

	Zwerg held3(name, groesse, alter);

	return held3;
}

//Damit �nderungen der aktuellen Lebenspunkte auch auf die Main-Funktion bzw gespraech() uebertragen werden
//muss hier mit Referenzen gearbeitet werden.
void kampf_ergebnis(Held& h) {

	cout << endl;
	/*Da die Helden 150 Lebenspunkte verlieren sollen, muss die Variable fuer die aktuellen
	Lebenspunkte um 150 reduziert werden. Sollten die aktuellen Lebenspunkte weniger als 250, dann
	werden sie auf 0 fallen.*/
	h.changeCurrentLP(-150);
	/*Falls noch Lebenspunkte uebrig sind, trifft dieser Fall ein */
	if (h.getCurrentLP()>0)
	{
		cout << h.get_name() << ":" << " Hat mit " << h.getCurrentLP() << " Lebenspunkten ueberlebt" << endl;
	}

	else
	{
		cout << h.get_name() << ":" << "OHHHH NEIN! Ich sterbe! Vielleicht ist die Wildnis einfach nichts fuer Babys und Kinder" << endl;
		cout << h.get_name() << " ist damit leider Tot" << endl;
	}
	cout << endl;

	cout << "Enter druecken";
	cin.get();
}

void linieZiehen() {
	for (int i = 0; i<70; ++i) {
		cout << '_';
	}
	cout << endl;
}

//Virtuelle Funktionen sollen benutzt werden -> mit pointern arbeiten sonst werden die Funktionen der Klasse Held aufgerufen
//const zum �berpr�fen ob alle entsprechenden Funktionen auf const gesetzt wurden
void heldAnsehen(const Held& h) 
{
	linieZiehen();
	cout << h << endl;
	if (h.getStatus() == 0) {	//Held ist Tod
		cout << "Status: Verstorben." << endl;
	}
	else {
		cout << "Status: Lebendig." << endl;
	}
	cout << "Rasse: " << h.getRasse() << endl;
	cout << "Schaden: " << h.getSchaden() << endl;

	linieZiehen();

	cout << endl;
}

//Damit �nderungen der aktuellen Lebenspunkte auch auf die Main-Funktion uebertragen werden
//muss hier mit Referenzen gearbeitet werden.
void kapitel1(Held& h1, Held& h2, Held& h3)
{
	cout << "----------Kapitel I------------" << endl;
	cin.get();
	cout << "Die 3 Helden treffen sich mit dickem Kopf an einem Lagerfeuer" << endl;
	cout << endl;

	cout << "Enter druecken" << endl;
	cin.get();

	cout << h1.get_name() << ":" << "Haha ihr Luschen koennt euch an nix mehr erinnern!\nIch weiss noch, dass mein Name " << h1.get_name();
	cout << " ist und ich " << h1.get_alter() << " Jahre alt bin, " << "ausserdem bin ich " << h1.get_groesse() << "m gross" << endl;
	cout << endl;

	cout << "Enter druecken" << endl;
	cin.get();

	cout << endl;
	cout << h2.get_name() << ":" << "Boah mein Kopf! Ich glaube mein Name war " << h2.get_name();
	cout << " und ich bin wohl " << h2.get_alter() << " Jahre alt und " << h2.get_groesse() << "m gross" << endl;
	cout << endl;

	cout << "Enter druecken" << endl;
	cin.get();

	cout << endl;
	cout << h3.get_name() << ":" << "Ich glaube ich bin jetzt noch nicht mal nuechtern *hicks*." << endl;
	cout << "Aber mein Name war glaube ich " << h3.get_name() << " und ich bin " << h3.get_alter() << " Jahre alt." << endl;
	cout << endl;

	cout << "Enter druecken";
	cin.get();

	cout << endl;
	cout << "AH! Moment ich bin " << h3.get_groesse() << "m gross" << endl << endl;
	cout << endl;

	cout << "Enter druecken";
	cin.get();

	cout << endl;
	cout << "Ploetzlich taucht ein wildes Monster auf. Da die Reaktionsgeschwindigkeit unserer Helden gegen 0 geht," << endl;
	cout << "kann das Monster unsere Helden ohne Gegenwehr angreifen" << endl;
	cout << endl;

	cout << "Alle Helden verlieren 150 Lebenspunkte" << endl;
	cout << endl;

	cout << "Enter druecken";
	cin.get();

	kampf_ergebnis(h1);
	kampf_ergebnis(h2);
	kampf_ergebnis(h3);

	cout << endl;
	cout << "Schnell klaut das Monster die Rucksaecke der Helden." << endl;
	cout << "Nachdem das Monster allerdings die alkoholischen Ausduenstungen der verbliebenen Helden riecht,\nmacht es sich lieber ganz schnell aus dem Staub." << endl;
	cout << endl;

	cout << "Enter druecken";
	cin.get();

	cout << endl;
	cout << "Unsere guten, mutigen, wackeren und total verkaterten Helden liegen bewusstlos oder tot um das Lagerfeuer." << endl;
	cout << endl;

	cout << "Werfen wir einen genaueren Blick auf unsere Helden!" << endl;
	cout << endl;
	cin.get();
	heldAnsehen(h1);
	cin.get();
	heldAnsehen(h2);
	cin.get();
	heldAnsehen(h3);

	cout << "Wie man sehen kann ist Grosses von ihnen zu erwarten!" << endl;
	cout << endl;

	cout << "Enter druecken";
	cin.get();
	cout << "An dieser Stelle wuerde natuerlich dramatische Musik einsetzen.";
	cout << "Diese muessen Sie sich leider selber vorstellen." << endl;
	cout << endl;

	cout << "Enter druecken";
	cin.get();

	cout << endl;
	cout << "Fortsetzung folgt..." << endl;

	cout << endl;
	cout << "Enter druecken";
	cin.get();

	cout << endl;
}

void addLebenspunkte(Held& h, int anz) //Lebenspunkte hinzuf�gen sofern der Held noch Lebt
{
	if (h.getStatus() == 1) //Held Lebt
	{
		h.changeCurrentLP(anz);
		cout << h << endl;
		cout << h.get_name() << " hat " << anz << " Lebenspunkte erhalten" << endl;
		cin.get();
	}

	else //Held ist Tot
	{
		cout << h << endl;
		cout << "Er ist leider schon Tot" << endl;
		cin.get();
	}
}

bool heldenVergleichen(Held held1, Held held2) {

	return (held1 == held2);

}

int entscheidungen(int anz)
{
	int entscheidung = 0;
	bool cf = 0;

	do {
		cout << "Es gibt also " << anz << " Varianten" << endl;
		cout << "Fuer Variante 1 geben Sie bitte eine 1 und fuer 2 eine 2 ein usw. : " << endl;
		cin >> entscheidung;
		cin.get();

		if (entscheidung < 1)
		{
			cout << "Nein es gibt keine Variante 0 oder kleiner 0" << endl;
			cin.get();
		}

		else if (entscheidung > anz)
		{
			cout << "Nein es gibt keine Variante " << entscheidung << endl;
			cin.get();
		}
	  cf = cin.fail();
	} while ((entscheidung < 1 || entscheidung > anz) && (!cf));

	return entscheidung;
}

void kapitel2(Held& h1, Held& h2, Held& h3)
{
	cout << endl;
	cout << "-------------Kapitel II---------------" << endl;
	cin.get();
	cout << "An dieser Stelle waere wohl wieder dramatische Musik angebracht" << endl;
	cin.get();
	cout << "Da wir diese immer nocht nicht haben machen wir jetzt einfach mit unseren gloreichen Helden weiter" << endl;
	cin.get();
	cout << "Langsam erholen sich unsere Helden vom gemeinen Angriff des boesen Monsters." << endl;
	cin.get();
	cout << "Nach einer kurzen Beratung wie es jetzte weiter gehen soll," << endl;
	cout << "sind sich die Helden einig das es eigentlich nur zwei Moeglichkeiten gibt." << endl;
	cin.get();
	cout << "Natuerlich muessen Sie jetzt ma wieder aushelfen und entscheiden wie es weiter geht" << endl;
	cin.get();
	cout << "Die erste Moeglichkeit waere das Monster sofort zu Verfolgen. \nOder sollen unsere Helden erstmal ihren Rausch fertig ausschlafen?" << endl;
	cin.get();

	int entscheidung = 0;
	entscheidung = entscheidungen(2);

	if (entscheidung == 1)
	{
		cout << "Na ob das so weise ist werden wir wohl noch sehen muessen" << endl;
		cin.get();
		//Ein Goblin als Gegener hinzuf�gen

		cout << "Unsere Helden brechen recht wakelig auf den Beinen auf um das Monster zu verfolgen" << endl;
		cin.get();
		cout << "Nach einem laengern Fussmarsch an der frischen Luft fuehlen sie sich etwas besser und erhalten 20 Lebenspunkte" << endl;
		cout << "Vorausgesetzt sie haben es ueberhaupt bis hierher ueberlebt" << endl;
		cin.get();

		addLebenspunkte(h1, 20);
		cout << endl;
		addLebenspunkte(h2, 20);
		cout << endl;
		addLebenspunkte(h3, 20);
		cout << endl;
	}

	else if (entscheidung == 2)
	{
		cout << "Das ist wohl eine sehr weise Entscheidung, in ihnen steckt wohl ein kleiner Zen Meister" << endl;
		cin.get();
		//Ein Ork als Gegener hinzuf�gen
		cout << "Durch diese weise Entscheidung erholen sich unsere Helden ein bisschen und gewinnen alle 60 Lebenspunkte dazu." << endl;
		cout << "Vorausgesetzt sie haben es ueberhaupt bis hierher ueberlebt" << endl;
		cin.get();

		addLebenspunkte(h1, 60);
		cout << endl;
		addLebenspunkte(h2, 60);
		cout << endl;
		addLebenspunkte(h3, 60);
		cout << endl;
	}

	cout << endl;
	cout << endl;

	cout << "Nachdem unsere Helden eine laengere Zeit unterwegs sind, kommen Sie an eine Weggabelung und beginnen darueber zu diskutieren was nun zu tun ist" << endl;
	cin.get();
	cout << "Natuerlich hat jeder unserer tollen Helden eine eigene Meinung" << endl;
	cout << endl;
	cin.get();
	cout << "Unser " << h1.getRasse() << ", " << h1.get_name() << " ,sagt: " << endl;
	cout << "Ey yo Brueders wir sollten rechts lang gehen, da siehts voll chillig aus LAN " << endl;
	cin.get();
	cout << endl;
	cout << "Unser " << h3.getRasse() << ", " << h3.get_name() << " ,sagt: " << endl;
	cout << "Ne digger, da ist ein Schild das es links zu einem Gasthaus geht. Und da gibts Essen und Bier!" << endl;
	cin.get();
	cout << "Nachdem unser " << h2.getRasse() << ", " << h2.get_name() << " ,beide moeglichkeiten abgewogen hat sagt er: " << endl;
	cin.get();
	cout << "Aber Freunde wir muessen doch nicht streiten. Lasst uns einfach hier ne Runde chilln, einen rauchen und uns vom Wald inspirieren lassen was zu tun ist." << endl;
	cin.get();
	cout << "Da sich unsere drei Experten eh nicht entscheiden koennen duerfen Sie das wieder uebernehmen." << endl;
	cin.get();
	cout << endl;
	entscheidung = entscheidungen(3);

	if (entscheidung == 1)
	{
		cin.get();
		cout << "Der rechte Weg wird schnell zu einem Trampelpfad und ist ueberwuchert mit Straeuchern." << endl;
		cout << "Unsere dollen Helden finden ein paar nahrhafte Beeren und essen sie gluecklich." << endl;
		cin.get();
		cout << endl;

		addLebenspunkte(h1, 60);
		cout << endl;
		addLebenspunkte(h2, 60);
		cout << endl;
		addLebenspunkte(h3, 60);
		cout << endl;
	}

	else if (entscheidung == 2)
	{
		cin.get();
		cout << "Schnell kommen unsere Helden an das versprochene Gasthaus." << endl;
		cout << "Nach einem ausgiebigen Mahl mit reichlich Bier fuehlen sich unsere Helden gestaerkt." << endl;
		cin.get();
		cout << endl;

		addLebenspunkte(h1, 70);
		cout << endl;
		addLebenspunkte(h2, 70);
		cout << endl;
		addLebenspunkte(h3, 70);
		cout << endl;
	}

	else if (entscheidung == 3)
	{
		cin.get();
		cout << "Unsere Helden machen es sich gemuetlich und ziehen ordentlich einen durch." << endl;
		cout << "Nachdem sie total inspiriert eingeschalfen sind, fuehlen sie sich erholt." << endl;
		cin.get();
		cout << endl;

		addLebenspunkte(h1, 50);
		cout << endl;
		addLebenspunkte(h2, 50);
		cout << endl;
		addLebenspunkte(h3, 50);
		cout << endl;

		cout << "Den Helden faellt ein dritter Weg in der Mitte auf, welchen sie einschlagen." << endl;
		cin.get();
	}

	cout << endl;
	cout << "So nach so vielen Entscheidungen muss aber auch mal wieder ne Pause sein." << endl;
	cin.get();
	cout << "Aber zunaechst sehen wir uns unsere Helden nochmal an : " << endl;
	cin.get();

	heldAnsehen(h1);
	cin.get();
	heldAnsehen(h2);
	cin.get();
	heldAnsehen(h3);
	cout << endl;

	cin.get();
	cout << "*Dramatische Musik spielt in Ihrem Kopf*" << endl;
	cout << "Fortsetzung folgt..." << endl;
	cin.get();
}

int main()
{
	einleitung();

	Mensch held1;//Helden mit default Konstruktor erstellen
	Elf held2;
	Zwerg held3;  
	cout << "Ab jetzt haben unsere Helden sogar Rassen. Held 1 ist ein Mensch. Er wird per Default erstellt." << endl;
	cin.get();
	cout << "Fuer den 2. Helden, ein Elf, muss der Name eingegeben werden " << endl;

	bool cf = 0; /*Um zu verhindern, dass eine Endlosschleife entsteht, falls der Benutzer eine falsche
				 Eingabe bei einer cin Anweisung verwendet, benutzen wir cf als Pruefvariable*/
	bool gleich1, gleich2, gleich3; //Vergleichsvariablen

	do {
		elfErstellen(held2); //Da hier mit referenz gearbeitet wird, haette heldErstellen1 sogar funktioniert, aber wir wollen die Lebenspunkte doch richtig zuordnen.
		gleich3 = heldenVergleichen(held1, held2); /*Damit wir Menschen mit Zwergen, Elfen etc vergleichen koennen, muessen wir eine
												   Funktion verwenden, die aus unseren erweiterten Heldenklassen nur die Basis Heldeninformationen kopiert */

		if (gleich3) {
			cout << "Dieser Name ist bereits im Gebrauch. Bitte aendern Sie ihre Eingabe!" << endl;
		}
		cf = cin.fail();
	} while (gleich3 && !cf);

	cout << "Fuer den 3. Helden, ein Zwerg, muessen alle 3 Daten eingegeben werden. " << endl;

	do {
		held3 = zwergErstellen();

		gleich1 = heldenVergleichen(held3, held1);
		gleich2 = heldenVergleichen(held3, held2);
		if (gleich1 || gleich2) {
			cout << "Ein Held mit diesen Eigenschaften existiert bereits. Bitte aendern Sie ihre Eingabe!" << endl;
		}
		cf = cin.fail();
	} while ((gleich1 || gleich2) && (!cf));

	kapitel1(held1, held2, held3);

	kapitel2(held1, held2, held3);

	return 0;
}
