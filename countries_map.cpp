// countries_map.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*справочник стран
команды для консоли:
1. изменить столицу/добавить страну со столицей
2. изменить название страны
3. вывести столицу страны
4. вывести все страны со столицами*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	int Q;
	cin >> Q;
	string command, name_of_country, capital, old_capital, new_name_country;
	map<string, string> country;
	while (Q > 0) {
		cin >> command;
		
		if (command == "CHANGE_CAPITAL") {
			cin >> name_of_country >> capital;
			if (country.count(name_of_country) == 0) {
				country[name_of_country] = capital;
				cout << "Introduce new country " << name_of_country << " with capital " << capital << endl;
			}
			else {
				old_capital = country[name_of_country];
				if (capital == old_capital) {
					cout << "Country " << name_of_country << " hasn't changed its capital" << endl;
				}
				else {
					country[name_of_country] = capital;
					cout << "Country " << name_of_country << " has changed its capital from " << old_capital << " to " << capital << endl;
				}
			}
		}
		else if (command == "RENAME") {
			cin >> name_of_country >> new_name_country;
			if (name_of_country==new_name_country || country.count(name_of_country) == 0 || country.count(new_name_country) == 1) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				capital = country[name_of_country];
				country[new_name_country] = capital;
				cout << "Country " << name_of_country << " with capital " << capital << " has been renamed to " << new_name_country << endl;
				country.erase(name_of_country);
			}
		}
		else if (command == "ABOUT") {
			cin >> name_of_country;
			if (country.count(name_of_country) == 0) {
				cout << "Country " << name_of_country << " doesn't exist" << endl;
			}
			else {
				capital = country[name_of_country];
				cout << "Country " << name_of_country << " has capital " << capital << endl;
			}
		}
		else if (command == "DUMP") {
			if (country.size() == 0) {
				cout << "There are no countries in the world" << endl;
			}
			else {
				for (const auto& item : country) {
					cout << item.first << "/" << item.second << endl;
				}
			}
		}
		Q--;
	}
}