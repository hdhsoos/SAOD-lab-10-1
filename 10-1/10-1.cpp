#include "hash.h"
#include "hash.cpp"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	menu();
	return 0;
}

void menu() {
	HashTable table{};
	int choice;
	string str;
	while (true) {
		cout << "Выберите пункт меню:" << endl;
		cout << "0 - выйти из программы" << endl;
		cout << "1 - найти ключ в таблице" << endl;
		cout << "2 - вставить ключ" << endl;
		cout << "3 - удалить ключ" << endl;
		cout << "4 - вывести таблицу" << endl;
		cout << "5 - заполнить таблицу" << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			return;
			break;
		case 1:
			cout << "Введите ключ, который хотите найти" << endl;
			cin >> str;
			if (find(table, str) == -1) {
				cout << "Ключ не найден в таблицу" << endl;
			}
			break;
		case 2:
			cout << "Введите ключ, который хотите вставить в таблицу" << endl;
			cin >> str;
			add_value(table, str);
			break;
		case 3:
			cout << "Введите ключ, который хотите удалить из таблицы" << endl;
			cin >> str;
			remove(table, str);
			break;
		case 4:
			output_hash_table(table);
			break;
		case 5:
			fill_table(table);
			break;
		}
	}
}