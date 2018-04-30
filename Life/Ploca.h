#pragma once
#include<vector>
class Ploca
{
public:
	Ploca::Ploca(int s, int v , int sr, char alive, char dead, int cls_g);
	void timer_set(int timer);
	int unos_int(int q);
	void ai();
	void aigame();
	void petlja_predicta(); // Uistinu vise ne znam koje ime bi dao, glava me boli malo, jos nisam ni probao je li ovo radi.
	int predict();
	void predict_nextstep();
	void ini(int i);
	void ispis();
	void ispisai();
	void buffer_ispis();
	void igrac();
	void tng();//The Next Generation... Engage
	void tng_ai();
	void buffer_ini();
	void buffer_ini_ai(int j);
	void clsg();
	void next_gen();
	void game_run();

private:
	//std::vector<int> ss;
	//std::vector<int> vv;
	std::vector<int> polje;
	std::vector<int> poljeai;
	std::vector<int> ai_trenutni_predict;
	std::vector<int> total;
	std::vector<std::vector<int>> ngen_p1;
	std::vector<std::vector<int>> ngen_p2;
	std::vector<std::vector<int>> ngen_p3;
	std::vector<int> buffer;
	int gen;
	int v;
	int s;
	int timer;
	int phase;
	int v_buffer;
	int s_buffer;
	int sr;
	int cls_g;
	int random(int max, int min);
	int check(int i, int ii);
	int terminate_life;
	char alive;
	char dead;
	int zbroj;
	int lok;
	int stanje = 0;
	int best;
	int best_value = -1;
	int best2 = -1;
	int best3;
	int fair;
	std::vector<int> bestting;
	void lines();



};

/*	for (;;) {
		life.ispis();
		life.tng();
		life.ispis();
		std::cout << std::endl;
		std::string again;
		next_gen();
		std::string again;
		std::cout << "Zelite li stvoriti novu generaciju?(Y za da ili bilo koja tipka za prekid)" << std::endl;
		std::getline(std::cin, again);
		std::cout << std::endl;
		if (again == "Y" || again == "y" || again == "yes" || again == "d" || again == "D") {

		}
		else if (again == "cls" && debug == 1) {
		system("cls");
		std::cout << "Sirina je:" << settings.s_get() << std::endl;
		std::cout << "Visina je:" << settings.v_get() << std::endl;
		}
		else {

		}
		}*/