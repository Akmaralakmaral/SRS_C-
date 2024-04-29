#pragma once
#include "Connect.h"
#include "table.h"
#include <iostream>
#include <vector>
using namespace std;

class dish :public tables
{
private:
	vector<int> ids;
	vector<string> names;
	
public:

	int Get_id();
	void Update(int id, string name);
	void Insert(string name);
	void Delete(int id);
	int Check();
	void Print();
	void Print_by_id(int id);
	int cnt();

};