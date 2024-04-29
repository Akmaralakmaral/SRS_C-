#include "Products.h"

int Products::Get_id()
{
	setlocale(LC_ALL, "ru");

	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;
	int id_prod;
	int id;
	string name;
	con = ConectDB();
	pstmt = con->prepareStatement("SELECT * FROM products; ");
	result = pstmt->executeQuery();
	cout << endl << "Списко  Продуктов" << endl;
	int num = 1;
	while (result->next()) {
		id = result->getInt("id");
		name = result->getString("Name");
		this->ids.push_back(id);
		this->names.push_back(name);
		std::cout << "№ " << num << ", Name: " << name << std::endl;
		num++;
	}


	cout << "Выберите номер Продукта ";
	cin >> id_prod;
	if (id_prod - 1 >= 0 && (id_prod - 1) < ids.size()) {
		int chosenId = ids[id_prod - 1];

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

void Products::Update(int id, string name)
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

void Products::Update_A(int id, int amount)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	con = ConectDB();
	pstmt = con->prepareStatement("UPDATE dish SET amount = ? WHERE id = ?");
	pstmt->setInt(1, amount);
	pstmt->setInt(2, id);
	pstmt->execute();
	cout << "Updated" << endl;
	delete pstmt;
	delete con;

}

void Products::Update_Q(int id, int quantiyt)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	con = ConectDB();
	pstmt = con->prepareStatement("UPDATE dish SET quantiyt = ? WHERE id = ?");
	pstmt->setInt(1, quantiyt);
	pstmt->setInt(2, id);
	pstmt->execute();
	cout << "Updated" << endl;
	delete pstmt;
	delete con;

}

void Products::Update(int id, string name, int amount, int quantiyt)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	con = ConectDB();
	pstmt = con->prepareStatement("UPDATE products SET Name = ?, amount = ?, quantity = ?  WHERE id = ?");
	pstmt->setString(1, name);
	pstmt->setInt(2, amount);
	pstmt->setInt(3, quantiyt);
	pstmt->setInt(4, id);
	pstmt->execute();
	cout << "Updated" << endl;
	delete pstmt;
	delete con;


}

void Products::Insert(string name)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	con = ConectDB();
	pstmt = con->prepareStatement("INSERT INTO products (Name) VALUES(?)");
	pstmt->setString(1, name);
	pstmt->execute();
	cout << "Saved" << endl;
	delete pstmt;
	delete con;
}

void Products::Insert(string name, int amount, int quantity)
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	con = ConectDB();
	pstmt = con->prepareStatement("INSERT INTO products (Name, amount,quantity) VALUES(?,?,?)");
	pstmt->setString(1, name);
	pstmt->setInt(2, amount);	
	pstmt->setInt(3, quantity);
	pstmt->execute();
	cout << "Saved" << endl;
	delete pstmt;
	delete con;
}

void Products::Delete(int id)
{

	sql::PreparedStatement* pstmt;
	sql::Connection* con;

	try
	{
		con = ConectDB();
		pstmt = con->prepareStatement("DELETE FROM products WHERE id = ?");
		pstmt->setInt(1, id);
		pstmt->execute();
		cout << "Deleted" << endl;
		delete pstmt;
		delete con;
	}
	catch (sql::SQLException e)
	{
		cout << "Can not delete. Error message: " << e.what() << endl;
		system("pause");
	}


}

int Products::Check()
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;

	con = ConectDB();
	pstmt = con->prepareStatement("select EXISTS(SELECT * FROM products) as chck ");
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



void Products::Print()
{
	sql::PreparedStatement* pstmt;
	sql::Connection* con;
	sql::ResultSet* result;
	int num = 1;
	con = ConectDB();
	pstmt = con->prepareStatement("SELECT * FROM products; ");
	result = pstmt->executeQuery();
	cout << endl << "Список Поржуктов" << endl;
	while (result->next()) {
		cout << "\t№ " << num << ", Name: " << result->getString(2) <<", amount: " << result->getInt(3) <<", quantity: " <<result->getInt(4)<< endl;
		num++;
	}

	delete result;
	delete pstmt;
	delete con;

	system("pause");
	system("cls");
}

void Products::Print_by_id(int id)
{
	cout << "Hello";
}
