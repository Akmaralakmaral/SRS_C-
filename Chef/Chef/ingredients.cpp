#include "ingredients.h"



int ingredients::Get_id(int id_dish)
{
	setlocale(LC_ALL, "ru");

	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;

	int id_ingred;
	int id_ing;
	string product;
	int guantity;
	con = ConectDB();
	pstmt = con->prepareStatement("CALL SP_Ingredients(?)");
	pstmt->setInt(1, id_dish);
	result = pstmt->executeQuery();
	cout << endl << "Списко  ингредиентов" << endl;
	int num = 1;
	while (result->next()) {
		id_ing = result->getInt("id");
		this->ids.push_back(id_ing);
		product = result->getString("Name");
		guantity = result->getInt("quantity");
		std::cout << "№ " << num << ", Name: " << product<<", Quantity: "<< guantity << std::endl;
		num++;
	}
	cout << "Выберите номер Ингредиента ";
	cin >> id_ingred;
	if (id_ingred - 1 >= 0 && (id_ingred - 1) < ids.size()) {
		int chosenId = ids[id_ingred - 1];

		delete pstmt;
		delete con;
		delete result;

		this->ids.clear();
		return chosenId;
	}
	else {
		delete pstmt;
		delete con;
		delete result;

		this->ids.clear();
		cout << "Invalid choice." << endl;
		return -1;

	}
}

void ingredients::Update(int id_ing, int id_prod, int quantity)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	try
	{
	
		con = ConectDB();
		pstmt = con->prepareStatement("UPDATE ingredients SET id_product = ? Set quantity = ? WHERE id = ?");
		pstmt->setInt(1, id_prod);
		pstmt->setInt(2, quantity);
		pstmt->setInt(3, id_ing);
		pstmt->execute();
		cout << "Updated" << endl;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException e)
	{
		cout << "Cannot Update. Error message: " << e.what() << endl;
		system("pause");
		delete pstmt;
		delete con;
	}
	
}

void ingredients::Insert(int id_dish, int id_prod, int quantity)
{
	try {
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		con = ConectDB();
		pstmt = con->prepareStatement("INSERT INTO ingredients (id_dish,id_product,quantity) VALUES(?,?,?)");
		pstmt->setInt(1, id_dish);
		pstmt->setInt(2, id_prod);
		pstmt->setInt(3, quantity);
		pstmt->execute();
		cout << "Saved" << endl;
		delete pstmt;
		delete con;
	}catch (sql::SQLException e)
		{
			cout << "Cannot Insert. Error message: " << e.what() << endl;
			system("pause");
		}

}

void ingredients::Delete(int id_ing)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	con = ConectDB();
	pstmt = con->prepareStatement("DELETE FROM ingredients WHERE id = ?");
	pstmt->setInt(1, id_ing);
	pstmt->execute();
	cout << "Deleted" << endl;
	delete pstmt;
	delete con;
}

