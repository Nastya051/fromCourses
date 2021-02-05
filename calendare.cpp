// calendare.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> NEXT(vector<string>& d, const vector<int>& m, int& i, vector<string>& d2)
{
	d2 = d;
	d.resize(m[i]);
	int s1 = d.size(); // size of days
	int s2 = d2.size(); // size of days2
	int delta = 0;
	if (s1 < s2)
	{
		delta = s2 - s1;
		for (int j = d2.size() - delta; j < d2.size(); j++)
		{
			d2[d2.size() - delta - 1] += d2[j];
		}
		
	}
	d2.resize(m[i]);
	i++;
	if (i == 12)
	{
		i = 0;
	}
	return d2;
}

int main()
{
	vector<int> months = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i = 1;
	int day, Q;
	string delo;
	string command;
	
	vector<string> days(months[0]);
	vector<string> days2;
	/*for (auto s : days)
	{
		cout << "Day " << s << endl;
	}
	cout << days.size() << endl;*/

	cin >> Q;
	
	while (Q > 0)
	{
		cin >> command;

		if (command == "NEXT")
		{
			NEXT(days, months, i, days2);
			days = days2;
		}

		if (command == "ADD")
		{
			cin >> day;
			cin >> delo;
			days[day-1] += delo + " ";
		}

		if (command == "DUMP")
		{
			cin >> day;
			int count = 0;
			for (int j = 0; j < days[day - 1].size(); j++)
			{
				if (days[day - 1][j] != ' ' && (days[day - 1][j + 1] == ' ' || days[day - 1][j + 1] == '\0'))
				{
					count++;
				}	
			}
			/*for (int j = 0; j < days[day - 1].size(); j++)
			{
				if ((days[day - 1][j] == ' ') && (days[day - 1][j + 1] == ' '))
				{
					days[day - 1][j] = days[day - 1][j + 1];
				}
					
			}*/
			
			cout << count << " " << days[day-1] << endl;
		}
		Q--;
	}
	
	

	system("pause");
}

