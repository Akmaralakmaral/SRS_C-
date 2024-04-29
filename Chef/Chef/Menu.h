#pragma once
#include "Connect.h"
#include "table.h"
#include <iostream>
#include <vector>
using namespace std;
class Menu 
{
private:
	vector<int> ids;
	vector<string> date;
	vector<int> id_dish;
	vector<int> quantity;
public:

	int Get_id() {
		cout << "hello";
	}
	void Update(int id, string name);
	void Insert(string date,int id_dish,int quantity) {
		sql::PreparedStatement* pstmt;
		sql::Connection* con;

		try
		{

			con = ConectDB();
			pstmt = con->prepareStatement("INSERT INTO menu_for_day (date,id_dish,quantity) VALUES(?,?,?)");
			pstmt->setString(1, date);
			pstmt->setInt(2, id_dish);
			pstmt->setInt(3, quantity);
			pstmt->execute();
			cout << "Saved" << endl;
			delete pstmt;
			delete con;
		}
		catch (sql::SQLException e)
		{
			cout << "Cannot insert. Error message: " << e.what() << endl;
			system("pause");
		}

	}
	void Delete(int id);
	int Check(int id_dish,int quantity) {
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		int a = 0;
		con = ConectDB();
		pstmt = con->prepareStatement("Call SP_Checkprod(?,?)");
		pstmt->setInt(1, id_dish);
		pstmt->setInt(2, quantity);
		result = pstmt->executeQuery();
		if (result->next()) {
			a= result->getInt(1);
			delete pstmt;
			delete con;
			delete result;
			return  a;
		}
		else
		{
			delete pstmt;
			delete con;
			delete result;
			return 0;
		}
		

	}
	void Print() {
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		sql::ResultSet* result;
		con = ConectDB();
		pstmt = con->prepareStatement("CALL showMenu() ");
		result = pstmt->executeQuery();
		cout << endl << "Список Menu" << endl;
		cout << "Date" << "\t\tName" << "\t\tQuantity" << endl;
		while (result->next()) {

			cout << result->getString("date") <<"\t" << result->getString("name") <<"\t" << result->getInt("quantity") << endl;
		}

		delete result;
		delete pstmt;
		delete con;

		system("pause");
		system("cls");
	}
	void Print_by_id(int id);

};