#pragma once

#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

using namespace std;
const string server = "tcp://127.0.0.1";
const string username = "root";
const string password = "";
const string DB = "Chef_povar";

sql::Connection* ConectDB();

