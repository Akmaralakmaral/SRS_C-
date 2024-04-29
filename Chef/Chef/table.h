#pragma once
#include  <iostream>
using namespace std;
class tables
{
	virtual int Get_id() = 0;
	virtual void Insert(string name) = 0;
	virtual void Update(int id, string name) = 0;
	virtual void Delete(int id) = 0;
	virtual int Check() = 0;
	virtual void Print() = 0;
	virtual void Print_by_id(int id) = 0;


};

