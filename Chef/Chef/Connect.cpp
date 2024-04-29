#include "Connect.h"
sql::Driver* driver;
sql::Connection* con;
sql::ConnectOptionsMap connection_properties;

sql::Connection* ConectDB()
{
	connection_properties["hostName"] = server;
	connection_properties["userName"] = username;
	connection_properties["password"] = password;
	connection_properties["schema"] = DB;
	connection_properties["port"] = 3307;
	try
	{
		driver = get_driver_instance();
		con = driver->connect(connection_properties);

		return con;
	}
	catch (sql::SQLException e)
	{
		cout << "Could not connect to server. Error message: " << e.what() << endl;
		system("pause");
		exit(1);
	}
}
