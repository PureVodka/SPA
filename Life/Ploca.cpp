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
	this->timer = timer;
}

void Ploca::timer_set(int timer)
{
	this->timer = timer;
}



int Ploca::unos_int(int q)
{
	{
		int term = 0;
		for(;term == 0;){
		int temp;

		std::cin >> temp;

		if(q ==0){
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Molim unesite pozitivan cijeli broj!" << std::endl;
			term = 1;
			unos_int(0);
		}
		return temp;
		}
		else if (q == 1) {
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Molim unesite pozitivan cijeli broj!" << std::endl;
				term = 1;
				unos_int(1);
			}
			else if (temp > v*s || temp < 0){
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Molim unesite jedan od navedenih brojeva!" << std::endl;

				term = 1;
				unos_int(1);
			}
			else if (polje[temp] == 1) {
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Na toj lokaciji vec postoji zivot, probajte drugi broj!" << std::endl;
				term = 1;
				unos_int(1);
			}
			return temp;
		}

	}
	}
}
void Ploca::ai()
{
	phase = 0;
	best = 0;
	best2 = 0;
	best3 = 0;
	ai_trenutni_predict = poljeai;
	bestting.resize(3);
	stanje = 0;
	best_value = -1;
	petlja_predicta();
	best_value = -1;
	stanje = 0;
	phase = 1;
	//Sada imam 3 lokacije u vektoru bestting. Trebao bi sada svaku provuci kroz gornji proces.
	for (stanje; stanje < 3; stanje++) {
		if (stanje == 0) {
			ai_trenutni_predict[bestting[stanje]] = 1;
			predict_nextstep();
			petlja_predicta();
			ai_trenutni_predict = poljeai;
		}
		else if (stanje == 1) {
			ai_trenutni_predict[bestting[stanje]] = 1;
			predict_nextstep();
			petlja_predicta();
			ai_trenutni_predict = poljeai;
		}
		else if (stanje == 2) {
			ai_trenutni_predict[bestting[stanje]] = 1;
			predict_nextstep();
			petlja_predicta();
			ai_trenutni_predict = poljeai;
		}
		else{}
	}
	if (best >= best2 && best >= best3) {
		ai_trenutni_predict[bestting[0]] = 1;
		fair = bestting[0];

	}
	else if (best2 >= best && best >= best3) {
		ai_trenutni_predict[bestting[1]] = 1;
		fair = bestting[1];
	}
	else if (best3 >= best && best >= best2) {
		ai_trenutni_predict[bestting[2]] = 1;
		fair = bestting[2];
	}
	poljeai = ai_trenutni_predict;
	tng_ai();
}
void Ploca::aigame()
{
	int pocetak = 0;
	for (; terminate_life == 0;) {
		for(int tcount = 0; tcount < timer; tcount++){
		if(pocetak == 0){
		std::cout << "Pocetno stanje" << std::endl;
		ispis();
		pocetak = 1;
		}
		else{}
		ai();
		igrac();
		tng();
		std::cout << "AI je odabrao celiju " << fair << std::endl;
		lines();
		ispis();
		ispisai();
		lines();
		std::cout << std::endl;
		}
		int zbroj_polje=0;
		int zbroj_ai=0;

		for (int final_countdown = 0; final_countdown < v*s; final_countdown++) {
			zbroj_polje = zbroj_polje + polje[final_countdown];
			zbroj_ai = zbroj_ai + poljeai[final_countdown];
			terminate_life = 1;

		}
		if (zbroj_polje > zbroj_ai) {
			std::cout << "Cestitam! Pobjedili ste kompjuter: " << zbroj_polje << ":" << zbroj_ai << std::endl;
		}
		else if (zbroj_polje < zbroj_ai) {
			std::cout << "Nazalost ste izgubili od kompjutera: " << zbroj_polje << ":" << zbroj_ai << std::endl;
		}
		else if (zbroj_polje == zbroj_ai) {
			std::cout << "Izjednacili ste: " << zbroj_polje << ":" << zbroj_ai << std::endl;
		}
		else {

		}

	}
}
void Ploca::petlja_predicta()
{	
	for (stanje; stanje < v*s; stanje++) {
		if (ai_trenutni_predict[stanje] != 1) {
			ai_trenutni_predict[stanje] = 1;
			total[stanje] = predict();
			ai_trenutni_predict = poljeai;
		}
		else {}
	}
	if(phase == 0){
	for (int i = 0; i < v*s; i++) {
		if (total[i] > best_value) {
			bestting[0] = i;
			best_value = total[i];
			total[i] = -1;

		}
		else if (total[i] == best_value) {
			bestting[0] = i;
			bestting[1] = i - 1;
			total[i] = -1;
		}
		else {}
	}
	for (int i = 0; i < v*s; i++) {
		if (total[i] > best_value) {
			bestting[2] = i;
			best_value = total[i];
			total[i] = -1;
		}

		else {}
	}
	}
	else if (phase == 1) {
		for (int i = 0; i < v*s; i++) {
			if (total[i] > best_value) {
				if (stanje == 0) { best = total[i];		best_value = total[i];; }
				else if (stanje == 1) { best2 = total[i];			best_value = total[i];; }
				else if (stanje == 2) { best3 = total[i];		best_value = total[i];; }
				else{}

			}

			else {}
		}
	}
}
int Ploca::predict()
{

	buffer_ini_ai(0);
	zbroj = 0;
	for (int i = 1; i <= v; i++) {
		for (int ii = 1; ii <= s; ii++) {
			int z = (i - 1) * s + (ii - 1);
			int c = check(i, ii);
			if (c == 2 || c == 3) {

			}
			else { ai_trenutni_predict[z] = 0; }
			if (c == 3) {
				ai_trenutni_predict[z] = 1;
			}



		}


	}
	for (int o = 0; o < v*s; o++) {
		zbroj = zbroj + ai_trenutni_predict[o];
		}
	return zbroj;
}
void Ploca::predict_nextstep()
{

	buffer_ini_ai(0);
	zbroj = 0;
	for (int i = 1; i <= v; i++) {
		for (int ii = 1; ii <= s; ii++) {
			int z = (i - 1) * s + (ii - 1);
			int c = check(i, ii);
			if (c == 2 || c == 3) {

			}
			else { ai_trenutni_predict[z] = 0; }
			if (c == 3) {
				ai_trenutni_predict[z] = 1;
			}



		}


	}


}
void Ploca::ini(int i)
{
	/*ss.resize(s);
	for (int i = 0; i < ss.size(); i++) {
		ss[i] = i + 1;
	}
	vv.resize(v);
	for (int i = 0; i < vv.size(); i++) {
		vv[i] = i + 1;
	}*/
	if(i == 0){
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
	else {
		gen = 0;
		terminate_life = 0;
		polje.resize(v*s);
		poljeai.resize(v*s);
		total.resize(v*s);
		for (int l = 0; l < v*s; l++) {
			total[l] = 0;
		}
		srand(time(nullptr));
		int max = 100;
		int min = 1;
		for (int i = 0; i < polje.size(); ++i) {
			int sansa = random(max, min);
			if (sansa < sr + 1) {
				polje[i] = 1;
				poljeai[i] = 1;
			}
			else {
				polje[i] = 0;
				poljeai[i] = 0;
			}
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
void Ploca::ispisai()
{
	std::cout << "AI polje: " << gen << std::endl;
	for (int i = 1; i <= v; i++) {
		for (int ii = 1; ii <= s; ii++) {
			int z = (i - 1) * s + (ii - 1);
			if (poljeai[z] == 1) {
				std::cout << alive;
			}
			else if (poljeai[z] == 0) {
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
void Ploca::igrac()
{
	int m;
	for (int i = 1; i <= v; i++) {
		for (int ii = 1; ii <= s; ii++) {
			int z = (i - 1) * s + (ii - 1);
			std::cout << z << ",";

		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Brojem odabeerite gdje biste zeljeli umetnuti zivu celiju: ";
	m = unos_int(1);
	polje[m] = 1;

}
void Ploca::tng(){
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
void Ploca::tng_ai() {
	buffer_ini_ai(1);
	for (int i = 1; i <= v; i++) {
		for (int ii = 1; ii <= s; ii++) {
			int z = (i - 1) * s + (ii - 1);
			int c = check(i, ii);
			if (c == 2 || c == 3) {

			}
			else { poljeai[z] = 0; }
			if (c == 3) {
				poljeai[z] = 1;
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
void Ploca::lines()
{
	for (int u = 0; u < 30; u++) {
		std::cout << "==";
	}
	std::cout << std::endl;
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
void Ploca::buffer_ini_ai(int j)
{
	if (j == 0){
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
				int zz = (i - 2) * s + (ii - 2);
				buffer[z] = ai_trenutni_predict[zz];
			}


		}


	}
	}
	else if (j == 1) {
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
					int zz = (i - 2) * s + (ii - 2);
					buffer[z] = poljeai[zz];
				}


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


