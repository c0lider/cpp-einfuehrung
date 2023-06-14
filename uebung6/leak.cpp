#include <iostream>
#include <string>
#include <new>

using namespace std;

// Blueprint for Person class
class Person
{
public:
  Person();
  Person(const Person& originalPerson);
  Person& operator=(const Person& otherPerson);
  ~Person();
  void n_ausgabe() const;

private:
  char *vorname;
  int vlaenge;
  char *nachname;
  int nlaenge;

  friend class Kunde;
};

// Blueprint for Kunde class
class Kunde
{
  Person kunde;
  const long kundennummer;

public:
  Kunde(long nummer);
  Kunde(const Kunde& originalKunde);
  Kunde(Person neukunde, long nummer);
  ~Kunde();
  Kunde& operator=(const Kunde& otherKunde);
  void print() const;
};


// Get Person first and last name from user input
Person::Person()
{
  string v;
  string n;

  cout << "Vorname: ";
  getline(cin, v);

  cout << "Nachname: ";
  getline(cin, n);

  vlaenge = v.length() + 1;
  nlaenge = n.length() + 1;

  vorname = new char[vlaenge];

  int i;
  for (i = 0; i < v.length(); i++)
  {
    vorname[i] = v[i];
  }
  vorname[i] = '\0';

  nachname = new char[nlaenge];

  for (i = 0; i < n.length(); i++)
  {

    nachname[i] = n[i];
  }
  nachname[i] = '\0';

  cout << "Personen Objekt " << vorname << " " << nachname << " erstellt." << endl;
}

// Explicit copy constructor, that performs a deep copy of all memory allocated members
Person::Person(const Person& originalPerson) {
  vlaenge = originalPerson.vlaenge;
  nlaenge = originalPerson.nlaenge;

  vorname = new char[vlaenge];
  nachname = new char[nlaenge];

  int i;
  // Perform deep copy of the strings to prevent double deletion of memory
  for (i=0; i<vlaenge; i++) {
    vorname[i] = originalPerson.vorname[i];
  }
  vorname[i] = '\0';

  for (int i=0; i<nlaenge; i++) {
    nachname[i] = originalPerson.nachname[i];
  }
  nachname[i] = '\0';
}

Person& Person::operator=(const Person& otherPerson) {

  cout << vorname << " " << nachname << " wurde zu "; //Indikatorsatzbeginn (alter Name)
  
  char* tempv = vorname;
  char* tempn = nachname;
  
  int i =0;
  
   if(this != &otherPerson) {
     
    vorname = new char [otherPerson.vlaenge]; //neuen Speicherplatz für Array anlegen
  
    for(i=0; i < (otherPerson.vlaenge-1); i++){  //hier alternativ mit memcpy(vorname, orginal.vorname, vlaenge)
   
      vorname[i] = otherPerson.vorname[i]; 
    }
  
    vorname[i] = '\0'; 
  
    nachname = new char [otherPerson.nlaenge];
    
    for(i=0; i < (otherPerson.nlaenge-1); i++){ 
   
      nachname[i] = otherPerson.nachname[i]; 
    }
  
    nachname[i] ='\0'; 
    
    delete[] tempv; //Allokierten Speicher auf altes Array löschen!
    delete[] tempn;
     
     cout << vorname << " " << nachname << ". Zuweisung erfolgt!"  << endl; //Indikatorsatzende (neuer Name)
     
   }
    
  return *this;
}

// Destructor for class Person
Person::~Person() {
  cout << "Personen Objekt " << vorname << " " << nachname << " zerstoert." << endl;

  // free allocated memory, if the deletion is not performed, it can cause memory leaks
  delete[] vorname;
  delete[] nachname;
}

// Prints Person first and last name to the console
void Person::n_ausgabe() const
{
  cout << "Name: " << vorname << " " << nachname << endl;
}

// constructor that only takes a customer "id"
Kunde::Kunde(long nummer) : kundennummer(nummer) {}

Kunde::Kunde(const Kunde& originalKunde) : kundennummer(originalKunde.kundennummer) {
    kunde = Person(originalKunde.kunde);
}

// constructor that takes a Person and an "id"
// !!! Creates a shallow copy of "neukunde", causing the vorname and nachname members to have the same pointer
Kunde::Kunde(Person neukunde, long nummer) : kunde(neukunde), kundennummer(nummer)
{
}

Kunde::~Kunde() {
  cout << "Der Kunde " << kunde.vlaenge << " " << kunde.vorname << " mit Kundennummer " << kundennummer << " wurde gelöscht." << endl;
}

// make the customer id stay the same even after assigning another customer object
Kunde& Kunde::operator=(const Kunde& otherKunde) {
  kunde = otherKunde.kunde; // TODO maybe
  return *this;
}

// Prints the customer first and last name + their id
void Kunde::print() const
{
  cout << "Die Kundennummer des Kunden " << kunde.vorname << " " << kunde.nachname << " lautet: " << kundennummer << endl;
}

// Creates a new Person (user enters first and last name), then asks for the customer
// id and creates a new customer from that information
Kunde kunde_anlegen()
{
  long nr;
  cout << "Neuen Kunden anlegen!" << endl;
  Person neu;
  cout << "Bitte geben Sie die Kundennummer ein: ";
  cin >> nr;
  cin.ignore();

  Kunde k{neu, nr};

  return k;
}

// Create two distinct customer objects and print their information
// assigns one object to the other and prints their information again
int main()
{
  const Kunde neuer{kunde_anlegen()};

  Kunde dagobert{9999};

  neuer.print();
  dagobert.print();

  dagobert = neuer;

  neuer.print();
  dagobert.print();
}