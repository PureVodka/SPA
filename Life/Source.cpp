#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "Ploca.h"
#include "Postavke.h"
int debug = 1;
int main_visit = 0;
int terminate_program = 0;
Postavke settings;

void ini() {
	//std::string boja = "COLOR 07";
	system("COLOR 07");
	settings.s_set(40);
	settings.v_set(40);
	settings.sr_set(35);
	settings.alive_set('1');
	settings.dead_set('0');
	settings.boja_set('0', '7');
	settings.cls_m_set(0);
	settings.cls_g_set(0);
}

int unos_int(int o) {
	int temp;
	char temp2;


	if (o == 1) { // default int unos
		std::cin >> temp;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Molim unesite pozitivan cijeli broj!" << std::endl;
			unos_int(o);
		}
		std::cin.ignore();
		return temp;

	}
	else if (o == 0) { // special
		std::cin >> temp;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			temp = 0;
		}
		return temp;

	}
	else if (o == 2) { // unos za boje... ogranicen
		std::cin >> temp2;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Molim unesite samo jedan znak" << std::endl;
			unos_int(o);
		}
		std::cin.ignore();
		if (temp2 == '1' || temp2 == '2' || temp2 == '3' || temp2 == '4' || temp2 == '5' || temp2 == '6' || temp2 == '7' || temp2 == '8' || temp2 == '9' || temp2 == 'A' || temp2 == 'B' || temp2 == 'C' || temp2 == 'D' || temp2 == 'E' || temp2 == 'F') {

		}
		else {
			std::cout << "Molim unesite jedan od ponudenih mogucnosti." << std::endl;
			unos_int(o);
		}
		return temp2;
	}
	else if (o == 3) { // unos charova neogranicen
		std::cin >> temp2;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Molim unesite samo jedan znak!" << std::endl;
			unos_int(o);
		}
		std::cin.ignore();
		return temp2;

	}
	if (o == 4) { // int unos za cls ONLY
		std::cin >> temp;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Molim unesite jedan od ponudenih brojeva (0,1,2)!" << std::endl;
			unos_int(o);
		}
		if (temp == 0 || temp == 1 || temp == 2) {

		}
		else {
			std::cout << "Molim odaberite jedan od ponudenih brojeva (0,1,2)" << std::endl;
		}
		std::cin.ignore();
		return temp;

	}
	

}
void postavke_main();
void postavke_boja();
void postavke_cls();
void postavke_uvjeti();
void igra();
void cls_screen(int clsm) {
	int terminate_cls_screen = 0;
	for(;terminate_cls_screen == 0;){
	if (clsm == 0) {
		terminate_cls_screen = 1;
	}
	else if (clsm == 1) {
		system("cls");
		terminate_cls_screen = 1;
	}
	else if (clsm == 2) {
		system("cls");
		terminate_cls_screen = 1;
	}
	}
}

int main() {
	if(main_visit == 0){ ini(); }
	main_visit++;
	if (debug == 1) {

		std::cout << settings.s_get() << "," << settings.v_get() << ", " << settings.sr_get() << std::endl;
	}
	for(;terminate_program == 0;){
	int q;
	std::cout << "Glavni izbornik: " << std::endl << "1. Pocetak igre" << std::endl  << "2. Postavke" << std::endl << "3. Credits???" << std::endl << "4. Izlaz" << std::endl;
	q = unos_int(1);

	if (q == 1) {
		igra();
		main();
	}
	else if (q == 2) {
		postavke_main();

	}
	else if (q == 3) {
		std::cout << "lol netko zapravo otvara \"Credits\" u igrici?";

	}
	else if (q == 4) {
		std::cout << "END" <<std::endl;
		terminate_program = 1;
		break;
	
	}
	else {
		std::cout << "Krivi odabir, probajte ponovno" << std::endl;
	}

//std::cout << *l;	

	}
	return 0;
}

void igra() {
	Ploca life(settings.s_get(), settings.v_get(), settings.sr_get(), settings.alive_get(), settings.dead_get(), settings.cls_g_get());
	life.ini();
	life.game_run();


	std::cout << std::endl << std::endl;
	
	main();
}

void postavke_main() {
	int c;
	std::cout << "Odabir postavka: "<<std::endl << "1. Postavljanje uvjeta igre" << std::endl << "2. Odabir brisanja ekrana" << std::endl << "3. Odabir boje ekrana i teksta" << std::endl << "0. Povratak na glavni izbornik" << std::endl;
	c = unos_int(1);
	if (c == 1) {
		postavke_uvjeti();
		return;
	}
	else if (c == 2) {
		postavke_cls();
		return;
	}
	else if (c == 3) {
		postavke_boja();
		return;
	}
	else if (c == 0) {
		main();
		return;
	}
	else {
		std::cout << "Krivi odabir, probajte ponovno"<<std::endl;
		postavke_main();
		return;
	}
}

void postavke_uvjeti() {
	int terminate_uvjeti = 0;
	for(;terminate_uvjeti == 0;){
	std::cout << "Trenutne postavke polja te opcije: " << std::endl << "1. Sirina: " << settings.s_get() << std::endl << "2. Visina: " << settings.v_get() << std::endl << "3. Sanas za nastajanjem \"zive\" celije: " << settings.sr_get() << std::endl << "4. Prikaz \"zive\" celije: " << settings.alive_get() << std::endl << "5. Prikaz \"mrtve\" celije: " << settings.dead_get() << std::endl << "6. Povratak na prosli meni (Postavke)" << std::endl << "0. Povratak na glavni meni";
	std::cout << "Odaberite koju od gore navedenih postavki:" << std::endl;
	int x;
	x = unos_int(1);
	if(x == 1){
	std::cout << "Unesite zeljenu sirinu polja: ";
	int s;
	s = unos_int(1);
	settings.s_set(s);

	}
	else if(x == 2){
	std::cout << "Unesite zeljenu visinu polja: ";
	int v;
	v = unos_int(1);
	settings.v_set(v);

	}
	else if (x == 3) {
	std::cout << "Unesite zeljenu vjerojatnost nastanka zivota: ";
	int sr;
	sr = unos_int(1);
	settings.sr_set(sr);

	}
	else if (x == 4) {
		std::cout << "Unesite zeljeni prikaz \"zive\" celije: ";
		char alive;
		alive = unos_int(3);
		settings.alive_set(alive);


	}
	else if (x == 5) {
		std::cout << "Unesite zeljeni prikaz \"mrtve\" celije: ";
		char dead;
		dead = unos_int(3);
		settings.dead_set(dead);

	
	}
	else if (x == 6) {
		postavke_main();
		terminate_uvjeti = 1;

	}
	else if (x == 0) {
		main();
		terminate_uvjeti = 1;
	}
	else {
		std::cout << "Krivi odabir, probajte ponovno" << std::endl;

	}
	}


}

void postavke_cls() {
	//int terminate_cls = 0;
	//for (; terminate_cls == 0;) {
		std::cout << "Trenutno stanje brisanja: " << "";
		std::cout << "Moguce opcije: " << std::endl << "1. Brisanje menija" << std::endl << "2. Brisanje za vrijeme igre" << std::endl << "3. Povratak na prosli meni (Postavke)" << std::endl << "0. Povratak na glavni meni" << std::endl;
		int k;
		k = unos_int(1);
		if (k == 1) {
			std::cout << "Odaberite jednu opcijue: " << std::endl << "0. Meni se nikada ne brise" << std::endl << "1. Meni se uvijek brise" << std::endl << "2. Meni se brise na upit";
			int z;
			z = unos_int(4);
			settings.cls_m_set(z);
		}
		else if (k == 2) {
			std::cout << "Odaberite jednu opcijue: " << std::endl << "0. Zaslon igre se nikada ne brise" << std::endl << "1. Zaslon igre se uvijek brise" << std::endl << "2. Zaslon igre se brise na upit";
			int z;
			z = unos_int(4);
			settings.cls_g_set(z);
		}
	//}

}

void postavke_boja() {
	int terminate_boja = 0;
	for(;terminate_boja == 0;){
	std::cout << "Trenutne postavke boja te opcije: ";
	settings.boja_ispis();
	std::cout <<std::endl << "Izmjenite boju: " << std::endl << "1. Pozadine" << std::endl << "2. Slova " << std::endl << "3. Povratak na prosli meni (Postavke)" << std::endl << "0. Povratak na GLAVNI meni" << std::endl;
	int k;
	k = unos_int(1);
	if (k == 1) {
		std::cout << "MIJENJANJE BOJE POZADINE" << std::endl << "Boje su sljedece: " << std::endl << "0 = Crna" << std::endl << "1 = Plava" << std::endl << "2 = Zelena" << std::endl << "3 = Cijan" << std::endl << "4 = Crvena" << std::endl << "5 = Magenta" << std::endl << "6 = Smedja" << std::endl << "7 = Bijela" << std::endl << "8 = Siva" << std::endl << "9 = Svijetlo plava" << std::endl << "A = Svijetlo zelena" << std::endl << "B = Svijetlo cijan???" << std::endl << "C = Svijetlo crvena" << std::endl << "D = Svijetlo magenta" << std::endl << "E = Svijetlo zuta" << std::endl << "F = Bijela" << std::endl;
		char poz;
		poz = unos_int(2);
		char boja[9] = { 'C', 'O', 'L', 'O', 'R', ' ', poz, settings.slova_get(), '\0' };
		settings.boja_set(poz, settings.slova_get());
		system(boja);


	}
	else if (k == 2) {
		std::cout << "MIJENJANJE BOJE SLOVA" << std::endl << "Boje su sljedece: " << std::endl << "0 = Crna" << std::endl << "1 = Plava" << std::endl << "2 = Zelena" << std::endl << "3 = Cijan" << std::endl << "4 = Crvena" << std::endl << "5 = Magenta" << std::endl << "6 = Smedja" << std::endl << "7 = Bijela" << std::endl << "8 = Siva" << std::endl << "9 = Svijetlo plava" << std::endl << "A = Svijetlo zelena" << std::endl << "B = Svijetlo cijan???" << std::endl << "C = Svijetlo crvena" << std::endl << "D = Svijetlo magenta" << std::endl << "E = Svijetlo zuta" << std::endl << "F = Bijela" << std::endl;
		char slova;
		slova = unos_int(2);
		char boja[9] = { 'C', 'O', 'L', 'O', 'R', ' ', settings.poz_get(), slova, '\0' };
		settings.boja_set(settings.poz_get(), slova);
		system(boja);


	}
	else if (k == 3) {
		postavke_main();
		terminate_boja = 1;

	}
	else if (k == 0) {
		main();
		terminate_boja = 1;

	}
	else {
		std::cout << "Krivi odabir, probajte ponovno" << std::endl;

	}
	}


}