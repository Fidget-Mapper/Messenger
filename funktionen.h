#ifndef FUNKTIONEN_H
#define FUNKTIONEN_H
#include <string.h>

//sammlung an funktionen fuer allgemeine sachen wie dem leeren des bildschirms
class funktionen
{
    protected:

    private:
        int menueZahl = 1;

    public:
        //standardkonstruktor
        funktionen();

        //bildschirminhalt loeschen
        void cls();

        //nicht zu verwechseln mit Sleep(). verwendet diese funktion um das program fuer den uebergebenen zeitraum in millisekunden zu pausieren
        void sleep(int millisekunden);

        //um uebergebenen string (ausgabeWort1) zeichenweise auszugeben. mit ausgabeZaehler millisekunden abstand. optional mit zeilenumbruch
        void ausgabe(std::string ausgabeWort1, int ausgabeZaehler, bool zeilenumbruch);

        //gibt den wert menueZahl aus
        std::string getMenueZahl();

        //setzt den wert menueZahl
        void setMenueZahl(int menueZahl);
};

#endif // FUNKTIONEN_H

