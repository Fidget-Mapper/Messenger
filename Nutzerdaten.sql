DROP DATABASE IF EXISTS Nutzerdaten;
CREATE DATABASE Nutzerdaten;
USE Nutzerdaten;

--posteingang
CREATE TABLE `EmpfangeneNachricht` (
	`AbsenderID` 	int(11) DEFAULT NULL,
	`EmpfaengerID` 	int(11) DEFAULT NULL,
	`Nachricht` 	varchar(255) DEFAULT NULL,
	`Zeit` 		int(11) DEFAULT NULL
);

--geplantes gruppenfeature
CREATE TABLE `gruppe` (
	GruppeNutzerID	int(11),
	GruppenID	varchar(30)
);


CREATE TABLE `GruppeNachrichten` (
	`GAbsenderID`	int(11) DEFAULT NULL,
	`GNachricht` 	varchar(255) DEFAULT NULL,
	`GZeit`		int(11) DEFAULT NULL,
	`GID`		varchar(30) DEFAULT "gruppe",
	`GFuehrer`	int(11) DEFAULT NULL
);

CREATE TABLE `Nutzer` (
	`Name` 		varchar(20) DEFAULT NULL,
	`Passwort` 	varchar(50) DEFAULT NULL,
	`NutzerID` 	int(11) AUTO_INCREMENT,
	`GruppenID`	int(3) DEFAULT NULL,
	PRIMARY KEY(NutzerID)
)
