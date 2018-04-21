#include "Postavke.h"
#include <string>
#include <iostream>


Postavke::Postavke()
{
}

void Postavke::s_set(int s)
{
	this->s = s;
}

void Postavke::v_set(int v)
{
	this->v = v;
}

void Postavke::sr_set(int sr)
{
	this->sr = sr;
}
void Postavke::alive_set(char alive)
{
	this->alive = alive;
}
void Postavke::dead_set(char dead)
{
	this->dead = dead;
}
void Postavke::boja_set(char poz, char slova)
{
	this->poz = poz;
	this->slova = slova;
}

void Postavke::cls_m_set(int cls_m)
{
	this->cls_m = cls_m;
}

void Postavke::cls_g_set(int cls_g)
{
	this->cls_g = cls_g;
}

int Postavke::s_get()
{
	return s;
}

int Postavke::cls_g_get()
{
	return cls_g;
}

int Postavke::v_get()
{
	return v;
}

char Postavke::alive_get()
{
	return alive;
}

char Postavke::dead_get()
{
	return dead;
}

int Postavke::sr_get()
{
	return sr;
}

char Postavke::poz_get()
{
	return poz;
}

char Postavke::slova_get()
{
	return slova;
}

void Postavke::boja_ispis()
{
	if (poz == '0') {
		std::cout <<"Crna pozadina";
	}
	else if (poz == '1') {
		std::cout <<"Plava pozadina";
	}
	else if (poz == '2') {
		std::cout <<"Zelena pozadina";
	}
	else if (poz == '3') {
		std::cout <<"Cijan pozadina";
	}
	else if (poz == '4') {
		std::cout <<"Crvena pozadina";
	}
	else if (poz == '5') {
		std::cout <<"Magenta pozadina";
	}
	else if (poz == '6') {
		std::cout <<"Smedja pozadina";
	}
	else if (poz == '7') {
		std::cout <<"Bijela pozadina";
	}
	else if (poz == '8') {
		std::cout <<"Siva pozadina";
	}
	else if (poz == '9') {
		std::cout <<"Svijetlo plava pozadina";
	}
	else if (poz == 'A') {
		std::cout <<"Svijetlo zelena pozadina";
	}
	else if (poz == 'B') {
		std::cout <<"Svijetlo cijan??? pozadina";
	}
	else if (poz == 'C') {
		std::cout <<"Svijetlo crvena pozadina";

	}
	else if (poz == 'D') {
		std::cout <<"Svijetlo magenta pozadina";
	}
	else if (poz == 'E') {
		std::cout <<"Zuta pozadina";
	}
	else if (poz == 'F') {
		std::cout <<"Bijela pozadina";
	}
	else{}
	std::cout << " i ";
	if (slova == '0') {
		std::cout <<"Crna slova";
	}
	else if (slova == '1') {
		std::cout <<"Plava slova";
	}
	else if (slova == '2') {
		std::cout <<"Zelena slova";
	}
	else if (slova == '3') {
		std::cout <<"Cijan slova";
	}
	else if (slova == '4') {
		std::cout <<"Crvena slova";
	}
	else if (slova == '5') {
		std::cout <<"Magenta slova";
	}
	else if (slova == '6') {
		std::cout <<"Smedja slova";
	}
	else if (slova == '7') {
		std::cout <<"Bijela slova";
	}
	else if (slova == '8') {
		std::cout <<"Siva slova";
	}
	else if (slova == '9') {
		std::cout <<"Svijetlo plava slova";
	}
	else if (slova == 'A') {
		std::cout <<"Svijetlo zelena slova";
	}
	else if (slova == 'B') {
		std::cout <<"Svijetlo cijan??? slova";
	}
	else if (slova == 'C') {
		std::cout <<"Svijetlo crvena slova";

	}
	else if (slova == 'D') {
		std::cout <<"Svijetlo magenta slova";
	}
	else if (slova == 'E') {
		std::cout <<"Zuta slova";
	}
	else if (slova == 'F') {
		std::cout <<"Bijela slova";
	}
	std::cout << std::endl;
	;
}

void Postavke::cls_ispis()
{
	if (cls_m == 0) {
		std::cout << "Meni se nikada ne brise";
	}
	else if (cls_m == 1) {
		std::cout << "Meni se brise izmedu svakog prelaska";
	}
	else if (cls_m == 2) {
		std::cout << "Meni se brise na upit izmedu svakog prelaska";
	}
	std::cout << " te se za vrijeme igre ekran ";
	if (cls_g == 0) {
		std::cout << "ne brise";
	}
	else if (cls_g == 1) {
		std::cout << "brise izmedu svake generacije";
	}
	else if (cls_g == 2) {
		std::cout << "brise na upit izmedu svake generacije";
	}
}

/*
0	black
1	blue
2	green
3	cyan
4	red
5	magenta
6	yellow/brown
7	white
8	gray
9	bright blue
A	bright green
B	bright cyan
C	bright red
D	bright magenta
E	bright yellow
F	white*/

