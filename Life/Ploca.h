#pragma once
#include<vector>
class Ploca
{
public:
	Ploca::Ploca(int s, int v , int sr, char alive, char dead, int cls_g);
	int unos_int();
	void ini();
	void ispis();
	void buffer_ispis();
	void tng();//The Next Generation... Engage
	void buffer_ini();
	void clsg();
	void next_gen();
	void game_run();

private:
	//std::vector<int> ss;
	//std::vector<int> vv;
	std::vector<int> polje;
	std::vector<int> buffer;
	int gen;
	int v;
	int s;
	int v_buffer;
	int s_buffer;
	int sr;
	int cls_g;
	int random(int max, int min);
	int check(int i, int ii);
	int terminate_life;
	char alive;
	char dead;

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