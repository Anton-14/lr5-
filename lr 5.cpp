// lr 5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
typedef unordered_multimap<int, string>::iterator it;
int main()
{
	unordered_multimap<int, string> mymap = {{-1, "one" }, { -2, "two" }, { 3, "three" },
	{ 4, "four" }, { 5, "five" }, { 6, "six" }
};
	auto print = [](const pair<int, string> n)
	{
		cout << "<" << n.first << ", " << n.second << ">  ";
	};

	for_each(mymap.cbegin(), mymap.cend(), print);
	cout << endl;

	for (auto it = mymap.begin(); it != mymap.end();) // 1 пункт 1 задача
	{ 
		if (it->first == 6)
			it = mymap.erase(it);
		else
			++it;
	}
	for_each(mymap.cbegin(), mymap.cend(), print);
	cout << endl;

	mymap.insert(make_pair(3, "znak a")); // 2 пункт 1 задача
	mymap.insert(make_pair(3, "znak b"));
	mymap.insert(make_pair(3, "znak c"));
	mymap.insert(make_pair(3, "znak d"));
	for_each(mymap.cbegin(), mymap.cend(), print);
	cout << endl;
	map <int, string>mymap2(mymap.begin(), mymap.end()); // 3 пункт 1 задача 
	for (auto i : mymap2) 
	{
		mymap2.insert(make_pair(i.first, i.second));
	}
	for_each(mymap2.begin(), mymap2.end(), print);
	cout << endl;

	auto cnt0 = [](const pair<int,string> n) {return n.first > 0; };// 1 пункт 2 задача
	int cnt = 0;
	cnt = count_if(mymap2.cbegin(), mymap2.cend(), cnt0);
	cout << "ne otritsatelnih kluchey:" << cnt << endl;

	vector<int> vec1; // 2 пункт 2 задача
	transform(mymap2.begin(), mymap2.end(),back_inserter(vec1), [](const pair<int, string> n) {return n.first; });
		auto vec_print = [](const int& n) {cout << " " << n; };
		for_each(vec1.cbegin(), vec1.cend(), vec_print);
	     cout << endl;

		 auto findm4 = find(vec1.cbegin(), vec1.cend(), -4); // 1 пункт 3 задача
		 if (findm4 != vec1.cend())  
	     cout << "element naiden";
		 else cout << "element ne naiden";

			 replace_if(vec1.begin(), vec1.end(), // 2 пункт 3 задача
				 bind(less<int>(), placeholders::_1, 0), 5);
			 for_each(vec1.cbegin(), vec1.cend(), vec_print);
			 cout << endl;

			 sort(vec1.begin(), vec1.end(),greater<int>()); // 3 пункт 3 задача 
			 for_each(vec1.cbegin(), vec1.cend(), vec_print);
			 cout << endl;

			 set<int> set0(vec1.begin(), vec1.end()); // 4 пункт 3 задача 
			 for_each(set0.cbegin(), set0.cend(), vec_print);
			 cout << endl;
			 return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
