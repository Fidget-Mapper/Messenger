#ifndef KOMMANDOBRUECKE_H_INCLUDED
#define KOMMANDOBRUECKE_H_INCLUDED

class kommandobruecke{
    protected:

        //eingabe = variable fuer die eingabe des nutzers
        int eingabe;
    private:

    public:

        //mir faellt der begriff nicht ein. die erhaelt datenbanknamen etc. und ruft mit diesen die datenbankfunktion auf
        kommandobruecke(const char* host, const char* nutzername, const char* passwort, const char* tabelle, unsigned int port, const char* unix_socket, unsigned long flags, const int verzoegerung);

        //alles was die datenbank betrifft
        void funktion(const char* host, const char* nutzername, const char* passwort, const char* tabelle, unsigned int port, const char* unix_socket, unsigned long flags, const int verzoegerung);
};

#endif // KOMMANDOBRUECKE_H_INCLUDED
