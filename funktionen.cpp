#include <iostream>
#include <ctime>
#include <windows.h>
#include <string.h>
#include "funktionen.h"
using namespace std;

funktionen::funktionen()
{
};

//windows exklusiver cls. von http://www.cplusplus.com/forum/beginner/73214/. grob verstanden wofuer alles steht
void funktionen::cls()
{
  DWORD n;
  DWORD size;
  COORD coord = {0};
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
  GetConsoleScreenBufferInfo ( h, &csbi );
  size = csbi.dwSize.X * csbi.dwSize.Y;
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );
  SetConsoleCursorPosition ( h, coord );
}

//pausierungsfunktion. erhaelt die anzahl an millisekunden als uebergabeparameter
void funktionen::sleep(int millisekunden)
{

    //alle x millisekunden werden die prozesse pausiert
    Sleep(millisekunden);
}

//funktion um alles zeichenweise auszugeben. ausgabewort = auszugebendes wort. ausgabezaehler = millisekundenwert fuer sleep hier drueber. zeilenumbruch = ob am ende ein zeilenumbruch durchgefuehrt wird oder nicht
void funktionen::ausgabe(std::string ausgabeWort1, int ausgabeZaehler, bool zeilenumbruch)
{

    //konstante vom string um das original vor veraenderungen zu schuetzen
    std::string& ausgabeWort = ausgabeWort1;

    //schleife um string zeichenweise auszugeben. solange bis der index die laenge des strings hat
    for(int i = 0; i != ausgabeWort.length(); i++)
    {

        //gib die i te stelle des string aus
        std::cout<<ausgabeWort[i];

        //pausierfunktion
        Sleep(ausgabeZaehler);
    }

    //zeilenumbruch wenn 1 uebergeben
    if(zeilenumbruch == true)
    {
        cout<<"\n";
    }
}

//gibt den wert menueZahl aus
std::string funktionen::getMenueZahl()
{
    return std::to_string(menueZahl++);
}

//setzt den wert menueZahl
void funktionen::setMenueZahl(int menueZahl)
{
    this->menueZahl = menueZahl;
}
