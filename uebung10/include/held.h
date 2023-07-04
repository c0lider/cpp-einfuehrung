#ifndef HELD_H
#define HELD_H

#include <iostream>


class Held {
private:
    std::string name;
    double groesse;
    int alter;
    int LP;
    int currentLP;
public:
    Held();
    Held(std::string name);
    Held(std::string name, double groesse, int alter);
    virtual ~Held();

    void set_name(std::string newName);
    void set_groesse(double groesse);
    void set_alter(int newAlter);

    std::string get_name() const;
    double get_groesse() const;
    int get_alter() const;
    bool getStatus() const;
    int getLP() const;
    int getCurrentLP() const;
    virtual std::string getRasse() const;
    virtual int getSchaden() const;

    void changeCurrentLP(int x);
    virtual double lebenspunkteBerechnen() const;

    friend std::ostream& operator<<(std::ostream &output, const Held& held);
    bool operator==(const Held& otherHeld) const;

};

#endif
