// bus_stop.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main()
{
	map<string, vector<string>> bus_stop;// словарь: название маршрута - остановки
	vector<string> ost;// вектор со всеми названиями остановок
	vector<string> save;
	int q, stop_count;// счётчик команд, кол-во остановок
	string command, bus, stop;// команда, название маршрута, название остановки
	cin >> q;

	while (q!=0) {
		cin >> command;
		if (command == "NEW_BUS") {
			cin >> bus;
			cin >> stop_count;

			if (!bus_stop.empty()) {
				ost.clear();
			for (auto item : bus_stop) {
				if (bus != item.first && stop_count > 0) {
					for (int i = 0; i < stop_count; i++) {
						cin >> stop;
						ost.push_back(stop);
					}	
				}
				bus_stop.insert(make_pair(bus, ost));
				save.push_back(bus);
				break;
				}
			}
			else {
				
				if (stop_count > 0) {
					for (int i = 0; i < stop_count; i++) {
						cin >> stop;
						ost.push_back(stop);
					}
				}
				bus_stop.insert(make_pair(bus, ost));
				save.push_back(bus);
			}
		}
		else if (command == "BUSES_FOR_STOP") {
			cin >> stop;
			bool x = false;
			vector<string> name_m;//здесь сохраняем названия маршрутов
			for (auto sav : save) {
				for (auto q : bus_stop[sav]) {
					if (q == stop) {
						name_m.push_back(sav);
						x = true;
					}
				}
			}
			
			if (x == false) {
				cout << "No stop" << endl;
			}
			else {
				
				for (const auto &c : name_m) {
					cout << c << " ";
				}
				cout << endl;
			}
		
		}
		else if (command == "STOPS_FOR_BUS") {
			cin >> bus;
			vector<string> v;
			int count = 0;
			map <string, vector <string>> ::iterator it;
			it = bus_stop.find(bus);
			if (it == bus_stop.end()) {
				cout << "No bus" << endl;
			}
			else {
				ost.clear();
				ost = bus_stop[bus];
				
				for (auto os : ost) {
					cout << "Stop " << os << ": ";
					for (auto sav : save) {
						for (auto q : bus_stop[sav]) {
							
								if (os == q) {
									v.push_back(sav);
									count++;
								}
							
						}
					}
					/*for (const auto &item : bus_stop) {
							for (const auto &i : item.second) {
								if (os == i) {
									v.push_back(item.first);
									count++;
								}
							}
					}*/
					if (count == 1) {
						cout << "no interchange";
					}
					else if (count > 1) {
						/*for (auto n : v) {
							string tmp;
							for (int a = 0; a < v.size() - 1; a++) {
								if (v[a] > v[a + 1]) {
									tmp = v[a];
									v[a] = v[a + 1];
									v[a + 1] = tmp;
								}
							}
						}*/
						string d;
						for (int n = 0; n < v.size(); n++) {
							if (v[n] != bus) {
								//d = v[0];
								cout << v[n] << " ";
							}
						}//cout << d << " ";
							
						
					}
					v.clear();
					count = 0;
					cout << endl;
				}
			}
		}
		else if (command == "ALL_BUSES") {
			if (bus_stop.empty()) {
				cout << "No buses" << endl;
			}
			else {
				vector<string> vec, bec;
				for (auto i : bus_stop) {
					vec.push_back(i.first);
				}
				for (auto b : vec) {
					cout << "Bus " << b << ": ";
					bec = bus_stop[b];
					for (auto x : bec) {
						cout << x << " ";
					}
					cout << endl;

				/*string tmp;
				vector<string> vec, bec;
				for (auto i : bus_stop) {
					vec.push_back(i.first);
					}
				for (int a = 0; a < vec.size()-1; a++) {
					if (vec[a] > vec[a + 1]) {
						tmp = vec[a];
						vec[a] = vec[a + 1];
						vec[a + 1] = tmp;
					}
				}
				for (auto b : vec) {
					cout << "Bus " << b << ": ";
					bec = bus_stop[b];
					for (auto x : bec) {
						cout << x << " ";
					}
					cout << endl;*/
				}
			}
		}
		q--;
	}
}

