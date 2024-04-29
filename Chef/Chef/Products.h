#pragma once
#include "Connect.h"
#include "table.h"
#include <iostream>
#include <vector>
using namespace std;
class Products :public tables
{
private:
	vector<int> ids;
	vector<string> names; 
	vector<int> amount;
	vector<int> quantity;
public:



		int Get_id();
		void Update(int id, string name);
		void Update_A(int id, int amount);
		void Update_Q(int id, int quantiyt);
		void Update(int id, string name, int amount, int quantiyt);
		void Insert(string name);
		void Insert(string name,int amount,int quntity);
		void Delete(int id);
		int Check();
		void Print();
		void Print_by_id(int id);

};