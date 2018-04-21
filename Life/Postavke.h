#pragma once
#include<string>
class Postavke
{
public:
	Postavke();
	void s_set(int s);
	void v_set(int v);
	void sr_set(int sr);
	void alive_set(char alive);
	void dead_set(char dead);
	void boja_set(char poz, char slova);
	void cls_m_set(int cls_m);
	void cls_g_set(int cls_g);
	int s_get();
	int v_get();
	char alive_get();
	char dead_get();
	int sr_get();
	char poz_get();
	char slova_get();
	void boja_ispis();
	void cls_ispis();//Ironic isnt it?
	int cls_g_get();



private:
	int s;
	int v;
	int sr;
	int cls_m;
	int cls_g;
	char alive;
	char dead;
	char poz;
	char slova;
};

