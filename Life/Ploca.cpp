#include "Ploca.h"
#include "Postavke.h"
#include<iostream>
#include <vector>
#include <ctime>
#include <string>







Ploca::Ploca(int s, int v, int sr,char alive, char dead, int cls_g)
{
	this->s = s; //mogao sam stvoriti set funkciju, ali tokom igre nikada vise ne bi trebala se mijenjati velicina ploce
	this->v = v;
	this->sr = sr;
	this->alive = alive;
	this->dead = dead;
}



int Ploca::unos_int()
{
	{
		int temp;
		std::cin >> temp;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Molim unesite pozitivan cijeli broj!" << std::endl;
			unos_int();
		}



		return temp;
	}
}

void Ploca::ini()
{
	/*ss.resize(s);
	for (int i = 0; i < ss.size(); i++) {
		ss[i] = i + 1;
	}
	vv.resize(v);
	for (int i = 0; i < vv.size(); i++) {
		vv[i] = i + 1;
	}*/
	gen = 0;
	terminate_life = 0;
	polje.resize(v*s);
	srand(time(nullptr));
	int max = 100;
	int min = 1;
	for (int i = 0; i < polje.size(); ++i) {
		int sansa = random(max, min);
		if (sansa < sr + 1) {
			polje[i] = 1;
		}
		else {
			polje[i] = 0;
		}
	}
}

void Ploca::ispis()
{
	std::cout << "Generacije: " << gen << std::endl;
	for (int i = 1; i <= v; i++) {
		for (int ii = 1; ii <= s; ii++) {
			int z = (i - 1) * s + (ii - 1);
			if (polje[z] == 1) {
				std::cout << alive;
			}
			else if (polje[z] == 0) {
				std::cout << dead;
			}
			else {
				std::cout << "SOMETHING WENT TERRIBLY WRONG!!! *in the distance you hear: \"LEEEEEEEEROYYY!!!!!\"";
			}

		}
		std::cout << std::endl;

	}
}
void Ploca::buffer_ispis()
{

	for (int i = 1; i <= v + 2; i++) {
		for (int ii = 1; ii <= s + 2; ii++) {
			int z = (i - 1) * (s+2) + (ii - 1);
			std::cout << buffer[z];

		}
		std::cout << std::endl;

	}
}

void Ploca::tng()
{
	gen++;
	buffer_ini();
	for (int i = 1; i <= v; i++) {
		for (int ii = 1; ii <= s; ii++) {
			int z = (i - 1) * s + (ii - 1);
				int c = check(i, ii);
				if (c == 2 || c == 3) {

				}
				else{ polje[z] = 0; }
				if (c == 3) {
					polje[z] = 1;
				}



		}


	}
}

int Ploca::check(int i, int ii)
{
	int ic = i + 1;
	int iic = ii + 1;
	int ostali_oblici_zivota = 0;
	int po = (ic - 2) * s_buffer + (iic - 2);
	for (int k = 0; k < 8; k++) {
		if (k == 0) {
			po = (ic - 2) * s_buffer + (iic - 2);
		}
		else if (k == 1) {
			po = (ic - 2) * s_buffer + (iic - 1);
		}
		else if (k == 2) {
			po = (ic - 2) * s_buffer + (iic);
		}
		else if (k == 3) {
			po = (ic - 1) * s_buffer + (iic);
		}
		else if (k == 4) {
			po = (ic) * s_buffer + (iic);
		}
		else if (k == 5) {
			po = (ic)* s_buffer + (iic - 1);
		}
		else if (k == 6) {
			po = (ic)* s_buffer + (iic - 2);
		}
		else if (k == 7) {
			po = (ic - 1)* s_buffer + (iic - 2);
		}
		else { std::cout << "Biggest rip"; }

		ostali_oblici_zivota = ostali_oblici_zivota + buffer[po];
	}
	

	return ostali_oblici_zivota;
}

void Ploca::buffer_ini()
{
	v_buffer = v + 2;
	s_buffer = s + 2;
	buffer.resize(v_buffer*s_buffer);
	for (int i = 1; i <= v_buffer; i++) {
		for (int ii = 1; ii <= s_buffer; ii++) {
			int z = (i - 1) * s_buffer + (ii - 1);
			if (ii == 1 || ii == s_buffer) {
				buffer[z] = 0;
			}
			else if (i == 1 || i == v_buffer) {
				buffer[z] = 0;
			}
			else {
				int zz = (i-2) * s + (ii-2);
				buffer[z] = polje[zz];
			}


		}


	}
}

void Ploca::clsg()
{
	if (cls_g == 0) {

	}
	else if (cls_g == 1) {
		system("cls");
	}
}

void Ploca::next_gen()
{
	int terminate_nextg = 0;
	for(;terminate_nextg == 0;){
	std::string again;
	std::cout << "Zelite li stvoriti novu generaciju?(Y za da ili N za prekid)" << std::endl;
	std::getline(std::cin, again);
	std::cout << std::endl;
	if (again == "Y" || again == "y" || again == "yes" || again == "d" || again == "D") {
		terminate_nextg = 1;
		return;
	}
	else if (again == "N" || again == "n") {
		terminate_nextg = 1;
		terminate_life = 1;
		
	}
	else {
		std::cout << "Krivo ste unjeli, molim probajte ponovno." << std::endl;
	}
	}
}

void Ploca::game_run()
{
	for (;terminate_life == 0;) {
		ispis();
		tng();
		std::cout << std::endl;
		next_gen();
	}
}

int Ploca::random(int max, int min)
{
	int kraj = rand() % (max - min + 1) + min;
	return kraj ;
}


