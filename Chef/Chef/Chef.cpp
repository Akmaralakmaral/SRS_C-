// Chef.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <iostream>
#include "Menu.h"
#include "dish.h"
#include "ingredients.h"
#include "Products.h"

void for_Dish() {
	setlocale(LC_ALL, "ru");
	Products prod;
	ingredients ingred;
	dish dis;
	int a = 1;
	int id_prod;
	int id_dis;
	int id_ing;
	int quantity;
	string name;
	while (a != 0)
	{
		cout << "\tРабота Блюдами " << endl;
		cout << "Добавить новое Блюдо  введите 1 " << endl;
		cout << "Вывести список Блюд введите 2 " << endl;
		cout << "Удалить Блюдо введите 3 " << endl;
		cout << "Обновить имя Блюда  введите 4 " << endl;
		cout << "Высти ингредиенты для блюда  введите 5 " << endl;
		cout << "Добавить ингредиент для блюда  введите 6 " << endl;
		cout << "Удалить ингредиент для блюда  введите 7 " << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите название Блюдами " << endl;
			cout << "Name ";
			getline(cin, name);
			dis.Insert(name);
			break;
		case(2):
			if (dis.Check()) {
				
				dis.Print();
			}
			else {
				cout << "Нет Блюд " << endl;
			}
			break;
		case(3):
			if (dis.Check()) {
				id_dis = dis.Get_id();
				dis.Delete(id_dis);
			}
			else {
				cout << "Нет Блюд " << endl;
			}
			break;
		case(4):
			system("cls");
			if (dis.Check()) {
				id_dis = dis.Get_id();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Введите название  Блюда" << endl;
				cout << "Name: ";
				getline(cin, name);

				dis.Update(id_dis, name);
			}
			else {
				cout << "Нет Блюд " << endl;
			}
			break;
		case(5):
			system("cls");
			if (dis.Check()){
				id_dis = dis.Get_id();
				dis.Print_by_id(id_dis);
			}
			else {
			cout << "Нет Блюд " << endl;
			}
			break;
		case(6):
			system("cls");
			if (dis.Check()) {
				if (prod.Check()) {
					id_dis = dis.Get_id();
					id_prod = prod.Get_id();
					cout << "Введите количество пролукта для блюда: ";
					cin >> quantity;
					cout << id_dis << " " << id_prod << " " << quantity << endl;
					ingred.Insert(id_dis, id_prod, quantity);
				}
				else
				{
					cout << "Нет Продуктов" << endl;
				}

			}
			else {
				cout << "Нет Блюд " << endl;
			}

			break;
		case(7):
			system("cls");
			if (dis.Check()) {
				id_dis = dis.Get_id();
				id_ing= ingred.Get_id(id_dis);
				ingred.Delete(id_ing);				
			}
			else {
				cout << "Нет Блюд " << endl;
			}

			break;

		default:
			break;
		}
	}
}

void for_prod() {
	setlocale(LC_ALL, "ru");
	Products prod;
	int a = 1;
	int id_prod;
	int quantity,amount;
	string name;
	while (a != 0)
	{
		cout << "\tРабота Продуктвми " << endl;
		cout << "Добавить новый продукт  введите 1 " << endl;
		cout << "Вывести список продуктов введите 2 " << endl;
		cout << "Удалить продукт введите 3 " << endl;
		cout << "Обновить данные продукта  введите 4 " << endl;
		cout << "Обновить имя продукта  введите 5 " << endl;
		cout << "Обновить количество продукта  введите 6 " << endl;
		cout << "Обновить стоимость продукта  введите 7 " << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите название Продукта " << endl;
			cout << "Name ";
			getline(cin, name);
			prod.Insert(name);
			break;
		case(2):
			system("cls");
			if (prod.Check()) {
				prod.Print();
			}
			else
			{
				cout << "Нет продуктов" << endl;
			}
			break;
		case(3):
			system("cls");
			if (prod.Check()) {
				id_prod= prod.Get_id();
				prod.Delete(id_prod);
			}
			else
			{
				cout << "Нет продуктов" << endl;
			}
			break;
		case(4):
			system("cls");
			if (prod.Check()) {
				id_prod = prod.Get_id();
				cout << "Введите имя: ";
				cin >> name;
				cout << "Введите количество: ";
				cin >> quantity;
				cout << "Введите сумму: ";
				cin >> amount;
				prod.Update(id_prod,name,amount,quantity);
			}
			else
			{
				cout << "Нет продуктов" << endl;
			}
			break;
		case(5):
			system("cls");
			if (prod.Check()) {
				id_prod = prod.Get_id();
				cout << "Введите имя: ";
				cin >> name;
				prod.Update(id_prod, name);
			}
			else{
				cout << "Нет продуктов" << endl;
			}
			break;
		case(6):
			system("cls");
			if (prod.Check()) {
				id_prod = prod.Get_id();
				cout << "Введите количество: ";
				cin >> quantity;
				prod.Update_Q(id_prod, quantity);
			}
			else {
				cout << "Нет продуктов" << endl;
			}
			break;
		case(7):
			system("cls");
			if (prod.Check()) {
				id_prod = prod.Get_id();
				cout << "Введите сумму: ";
				cin >> amount;
				prod.Update_A(id_prod, amount);
			}
			else {
				cout << "Нет продуктов" << endl;
			}
			break;
		default:
			break;
		}
	}
}

void for_menu() {

	dish dis;

	Products product;
	ingredients ingredient;
	Menu menu;
	string name, date;
	int id_dis;
	int num, cnt;
	

	setlocale(LC_ALL, "ru");
	Products prod;
	int a = 1;
	int id_prod;
	int quantity, amount;
	while (a != 0)
	{
		cout << "\tРабота c Меню " << endl;
		cout << "Добавить Меню  введите 1 " << endl;
		cout << "Вывести список Меню введите 2 " << endl;
		cin >> a;
		switch (a)
		{
		case(1):
			system("cls");
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите дату: ";
			getline(cin, date);
			cout << "Введите количество Людей: ";
			cin >> cnt;
			cout << "Введите количество блюд: ";
			cin >> num;
			if (dis.cnt() >= num) {
				while (num != 0)
				{
					id_dis = dis.Get_id();

					if (menu.Check(id_dis, cnt)) {
						menu.Insert(date, id_dis, cnt);
					}
					else
					{
						cout << "Продуктов для этого блюда не достаточно для данного количества людей" << endl;
					}
					num--;
				}
			}
			else
			{
				cout << "Нужное количтво блюд больше чем есть фактически" << endl;
			}
			break;
		case(2):
			menu.Print();
			break;
		}
	}

}

int main()
{
	setlocale(LC_ALL, "ru");

	dish dis;

	Products product;
	ingredients ingredient;
	Menu menu;
	string name,date;
	int id_dis;
	int num,cnt;
	int a = 1;
	while (a != 0)
	{
		
		cout << "\tMENU";
		cout << "Выберите действие " << endl;
		cout << "Действия с блюдами " << endl;
		cout << "Действия с Продуктами введите 2 " << endl;
		cout << "Действия с Меню введите 3 " << endl;
		cout << "exit 0" << endl;
		cin >> a;
		switch (a) {
		case(1):
			for_Dish();
			break;
		case(2):
			for_prod();

			break;
		case(3):
			for_menu();
			break;
		
		}

	}
	
}
