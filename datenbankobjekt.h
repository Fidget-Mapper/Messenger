#ifndef DATENBANKOBJEKT_H
#define DATENBANKOBJEKT_H
#include <iostream>
#include <windows.h>
#include <mysql.h>
class datenbankobjekt
{
    protected:

    private:
        //datenbankvariablen
        MYSQL* conn;
        MYSQL_ROW row;
        MYSQL_RES* res;
        //eingeloggt = loginstatus
        int absenderID = 0, eingeloggt = 0, auswahl = -1, verzoegerung, qstate, qstate2;     //qstate = speichert abfragestatus nach ausfuehrung 0 wenn fehler und andere werte wenns erfolgreich ist
        std::string name, nameEingeloggt, passwort, passwortEingeloggt, idEingeloggt;
        const char* q;
        const char* q2;
    public:
        datenbankobjekt();
        //gibt nur hallo welt aus
        void ausgabe();

        //funktion fuers einloggen
        void einloggen();

        //funktion fuers registrieren
        void registrieren();

        //funktion fuer die nutzerausgabe
        void nutzerAusgabe();

        //sucht den absendernamen aus der datenbank. wird bei der nachrichtenausgabe benoetigt
        std::string absenderSuchen(int absenderID);

        //zum abschicken von nachrichten
        void nachrichtSenden();

        //zum leeren des eigenen posteingangs
        void nachrichtLoeschen();

        //gibt timestamp als datum aus
        std::string zeitstempelZuDatum(std::string zeit);

        //um nachrichten auszugeben
        void nachrichtEmpfangen();

        //getter und setter fuer variablen
        void setConn(MYSQL* conn);
        MYSQL* getConn();
        void setRow(MYSQL_ROW row);
        MYSQL_ROW getRow();
        void setRes(MYSQL_RES* res);
        int getAbsenderID();
        void setAbsenderID(int absenderID);
        int getEingeloggt();
        void setEingeloggt(int eingeloggt);
        int getAuswahl();
        void setAuswahl(int auswahl);
        int getVerzoegerung();
        void setVerzoegerung(int verzoegerung);
        int getQstate();
        void setQstate(int qstate);
        std::string getName();
        void setName(std::string name);
        std::string getNameEingeloggt();
        void setNameEingeloggt(std::string nameEingeloggt);
        std::string getPasswort();
        void setPasswort(std::string passwort);
        std::string getPasswortEingeloggt();
        void setPasswortEingeloggt(std::string passwortEingeloggt);
        std::string getIdEingeloggt();
        void setIdEingeloggt(std::string idEingeloggt);

};

#endif // DATENBANKOBJEKT_H
