#include <iostream>
#include <windows.h>
#include "funktionen.h"
#include "kommandobruecke.h"
#include "datenbankobjekt.h"
#include "mysql.h"
using namespace std;

//hier findet alles statt
kommandobruecke::kommandobruecke(const char* host, const char* nutzername, const char* passwort, const char* tabelle, unsigned int port, const char* unix_socket, unsigned long flags, const int verzoegerung)
{
    funktion(host, nutzername, passwort, tabelle, port, unix_socket, flags, verzoegerung);
}

//macht die ganzen datenbankabfragen etc.
void kommandobruecke::funktion(const char* host, const char* nutzername, const char* passwort, const char* tabelle, unsigned int port, const char* unix_socket, unsigned long flags, const int verzoegerung)
{

    //erstellung eines werkzeugobjektes.
    funktionen werkzeuge;

    //erstellung eines datenbankobjektes
    datenbankobjekt datei;

    //entscheidet bei der ausgabefunktion im werkzeugobjekt, wieviele millisekunden zwischen jeder zeichenausgabe vergehen
    datei.setVerzoegerung(verzoegerung);

    //auf -1 damit es weiter unten beim switch case zu keinen problemen kommt
    datei.setAuswahl(-1);

    //initialisiert ein fuer mysql_real_connect verwendbares objekt
    datei.setConn(mysql_init(0));

    //erstellt eine verbindung zur datenbank
    datei.setConn(mysql_real_connect(datei.getConn(), host, nutzername, passwort, tabelle, port, unix_socket, flags));

    //wenn die verbindung erfolgreich ist
    if(datei.getConn())
    {

        //wird solange ausgefuehrt bis die nutzereingabe 0 ist
        while(datei.getAuswahl() != 0)
        {

            //zusaetzliche pruefung, ob der nutzer eingeloggt ist. wenn der nutzer noch nicht eingeloggt ist werden einloggen und registrieren ausgegeben.
            if(datei.getEingeloggt() == 0)
            {

                //verwendung einer zaehlerfunktion um die auflistung zu vereinfachen
                werkzeuge.ausgabe(werkzeuge.getMenueZahl(), datei.getVerzoegerung(), 0);
                werkzeuge.ausgabe(") Einloggen", datei.getVerzoegerung(), 1);
                werkzeuge.ausgabe(werkzeuge.getMenueZahl(), datei.getVerzoegerung(), 0);
                werkzeuge.ausgabe(") Registrieren", datei.getVerzoegerung(), 1);
            }

            //wenn der nutzer eingeloggt ist werden die unten genannten optionen ausgegeben
            if(datei.getEingeloggt() > 0)
            {
                werkzeuge.ausgabe(werkzeuge.getMenueZahl(), datei.getVerzoegerung(), 0);
                werkzeuge.ausgabe(") Nutzerliste ausgeben", datei.getVerzoegerung(), 1);
                werkzeuge.ausgabe(werkzeuge.getMenueZahl(), datei.getVerzoegerung(), 0);
                werkzeuge.ausgabe(") Nachrichten ausgeben", datei.getVerzoegerung(), 1);
                werkzeuge.ausgabe(werkzeuge.getMenueZahl(), datei.getVerzoegerung(), 0);
                werkzeuge.ausgabe(") Nachricht verschicken", datei.getVerzoegerung(), 1);
                werkzeuge.ausgabe(werkzeuge.getMenueZahl(), datei.getVerzoegerung(), 0);
                werkzeuge.ausgabe(") Nachrichten loeschen", datei.getVerzoegerung(), 1);
            }
            werkzeuge.ausgabe(werkzeuge.getMenueZahl(), datei.getVerzoegerung(), 0);
            werkzeuge.ausgabe(") Auswahl treffen: ", datei.getVerzoegerung(), 0);

            //auflistungszaehler zuruecksetzen
            werkzeuge.setMenueZahl(1);

            //nutzereingabe um zu entscheiden was aufgerufen wird
            std::cin >>eingabe;

            //setzt die nutzerauswahl
            datei.setAuswahl(eingabe);

            //leert den bildschirm
            werkzeuge.cls();

            //switch case anweisung mit der vorher festgelegten anweisung
            switch(datei.getAuswahl())
            {

                //wenn die nutzerauswahl 1 ist
                case 1:

                    //wenn der nutzer noch nicht eingeloggt ist
                    if(datei.getEingeloggt() == 0)
                    {

                        //ruft einlogfunktion vom datenbankobjekt auf
                        datei.einloggen();
                    }

                    //unterbrich das switch statement
                    break;

                //wenn die nutzerauswahl 2 ist
                case 2:

                    //wenn der nutzer nicht eingeloggt ist
                    if(datei.getEingeloggt() == 0)
                    {

                        //ruft die registrierfunktion vom datenbankobjekt auf
                        datei.registrieren();
                    }
                    //unterbrich das switch statement
                    break;

                //wenn die nutzerauswahl 3 ist
                case 3:

                    //wenn der nutzer eingeloggt ist
                    if(datei.getEingeloggt() == 1)
                    {

                        //ruft die adressbuchfunktion vom datenbankobjekt auf
                        datei.nutzerAusgabe();
                    }

                    //unterbrich das switch statement
                    break;

                //wenn die nutzerauswahk 4 ist
                case 4:

                    //wenn der nutzer eingeloggt ist
                    if(datei.getEingeloggt() == 1)
                    {

                        //rufe die nachrichtenaufruffunktion vom datenbankobjekt auf
                        datei.nachrichtEmpfangen();
                    }

                    //unterbrich das switch statement
                    break;

                //wenn die nutzerauswahl 5 ist
                case 5:

                    //wenn der nutzer eingeloggt ist
                    if(datei.getEingeloggt() == 1)
                    {

                        //rufe die nachrichtenverschickfunktion vom datenbankobjekt auf
                        datei.nachrichtSenden();
                    }

                    //unterbrich das switch statement
                    break;

                //wenn die nutzerauswahl 6 ist
                case 6:

                    //wenn der nutzer eingeloggt ist
                    if(datei.getEingeloggt() == 1)
                    {

                        //rufe die nachrichtenloeschfunktion vom datenbankobjekt auf
                        datei.nachrichtLoeschen();
                    }

                    //unterbrich das switch statement
                    break;

            }
        }

    //wenn die verbindung zur datenbank nicht hergestellt werden konnte
    }else
    {

        //gib den fehler aus
        cout << "Abfrageproblem: " << mysql_error(datei.getConn()) <<endl;
    }
}
