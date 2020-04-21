#include <iostream>
#include <windows.h>
#include "kommandobruecke.h"
#include "mysql.h"
#include "main.h"
using namespace std;

//hier beginnt der ganze spaﬂ
int main()
{
    //der zu verwendende server
    const char* host = "localhost";

    //datenbanknutzername
    const char* nutzername = "root";

    //datenbankpasswort
    const char* passwort = "";

    //tabellenname datenbank
    const char* tabelle = "nutzerdaten";

    //der zu verwendende port
    unsigned int port = 0;

    //der zu verwendende socket
    const char* unix_socket = "NULL";

    const int verzoegerung = 10;
    //hiermit sind verbindungseinstellungen moeglich
    unsigned long flags = 0;
    kommandobruecke enterprise(host, nutzername, passwort, tabelle, port, unix_socket, flags, verzoegerung);
    return 0;
}
