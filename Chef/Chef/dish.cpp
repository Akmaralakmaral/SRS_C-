#include "dish.h"

int dish::Get_id()
{
	setlocale(LC_ALL, "ru");

	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;
	int id_dish;
	int id;
	string name;
	con = ConectDB();
	pstmt = con->prepareStatement("SELECT * FROM dish; ");
	result = pstmt->executeQuery();
	cout << endl << "Списко  Блюд" << endl;
	int num = 1;
	while (result->next()) {
		id = result->getInt("id");
		name = result->getString("Name");
		this->ids.push_back(id);
		this->names.push_back(name);
		std::cout << "№ " << num << ", Name: " << name << std::endl;
		num++;
	}


	cout << "Выберите номер Блюда ";
	cin >> id_dish;
	if (id_dish - 1 >= 0 && (id_dish - 1) < ids.size()) {
		int chosenId = ids[id_dish - 1];

		delete pstmt;
		delete con;
		delete result;

		this->ids.clear();
		this->names.clear();
		return chosenId;
	}
	else {
		delete pstmt;
		delete con;
		delete result;

		this->ids.clear();
		this->names.clear();
		cout << "Invalid choice." << endl;
		return -1;

	}
}

void dish::Update(int id, string name)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	con = ConectDB();
	pstmt = con->prepareStatement("UPDATE dish SET name = ? WHERE id = ?");
	pstmt->setString(1, name);
	pstmt->setInt(2, id);
	pstmt->execute();
	cout << "Updated" << endl;
	delete pstmt;
	delete con;
}

void dish::Insert(string name)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	con = ConectDB();
	pstmt = con->prepareStatement("INSERT INTO dish (Name) VALUES(?)");
	pstmt->setString(1, name);
	pstmt->execute();
	cout << "Saved" << endl;
	delete pstmt;
	delete con;

}

void dish::Delete(int id)
{


	try
	{
		sql::PreparedStatement* pstmt;
		sql::Connection* con;
		con = ConectDB();
		pstmt = con->prepareStatement("DELETE FROM dish WHERE id = ?");
		pstmt->setInt(1, id);
		pstmt->execute();
		cout << "Deleted" << endl;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException e)
	{
		cout << "Cannot delete. Error message: " << e.what() << endl;
		system("pause");
	}
	
}

int dish::Check()
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;

	con = ConectDB();
	pstmt = con->prepareStatement("select EXISTS(SELECT * FROM dish) as chck ");
	result = pstmt->executeQuery();
	if (result->next()) {
		return result->getInt(1); ;
	}
	else
	{
		return 0;
	}
	delete pstmt;
	delete con;
	delete result;
}

void dish::Print()
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;
	int num = 1;
	con = ConectDB();
	pstmt = con->prepareStatement("SELECT * FROM dish; ");
	result = pstmt->executeQuery();
	cout << endl << "Список Блюд" << endl;
	while (result->next()) {
		cout << "\t№ " << num << ", Name: " << result->getString(2) << endl;
		num++;
	}

	delete result;
	delete pstmt;
	delete con;

	system("pause");
	system("cls");
}

void dish::Print_by_id(int id)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;

	con = ConectDB();
	pstmt = con->prepareStatement(" SELECT products.Name ,ingredients.quantity FROM products INNER JOIN ingredients ON ingredients.id_product = products.id WHERE ingredients.id_dish = ?;");
	pstmt->setInt(1, id);
	result = pstmt->executeQuery();

	cout << "Ingredients" << endl;
	while (result->next()) {
		string song_name = result->getString("Name");
		string disk_name = result->getString("quantity");
		cout << "\tProduct: " << song_name << ", quantity: " << disk_name << endl;
	}

	// Освобождение ресурсов
	delete result;
	delete pstmt;
	delete con;

	system("pause");
	system("cls");
}

int dish::cnt()
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;
	int res;
	con = ConectDB();
	pstmt = con->prepareStatement("Select COUNT(id) from dish");
	result = pstmt->executeQuery();

	if (result->next())
	{
		res = result->getInt(1);

	} 
	delete pstmt;
	delete con;
	delete result;
	return res;
}
