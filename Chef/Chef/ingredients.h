#pragma once
#include "Connect.h"
#include "table.h"
#include <iostream>
#include <vector>
using namespace std;
class ingredients 
{
private:
	vector<int> ids;
	vector<int> id_prod;
	vector<int> id_dish;
	vector<int> quantity;
public:
	int Get_id(int id_dish);
	void Update(int id_ing,int id_prod, int quantity);
	void Insert(int id_ing,int id_prod,int quantity);
	void Delete(int id_ing);
	int Check();
	void Print();
	void Print_by_id(int id);

};