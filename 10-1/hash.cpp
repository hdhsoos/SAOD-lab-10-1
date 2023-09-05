#include "hash.h"
using namespace std;


namespace words {
	string keys[MAX_SIZE]{
		"auto",
		"union",
		"constexpr",
		"volatile",
		"explicit",
		"friend",
		"inline",
		"virtual",
		"for",
		"template"
	};
}

int hash_func(const string str) {
	int res{ 0 };

	for (const int& a : str) {
		res += a;
	}

	return res % 10;
}

bool is_key_valid(const string& value) {
	for (const string& key : words::keys)
		if (key == value)
			return true;

	return false;
}


void add_value(HashTable& table, const string str) {
	if (!is_key_valid(str)) {
		cout << "Такого значения нет в списке ключей" << endl;
		return;
	}

	int find_index = find(table, str);
	if (find_index != -1) {
		cout << "Значение найдено под индексом" << find_index << endl;
		return;
	}

	int index{ hash_func(str) };
	table.arr[index] = str;
}

int find(const HashTable& table, const string str) {
	int index{ hash_func(str) };
	if (str == table.arr[index]) {
		cout << "Ключ найден под индексом " << index << endl;
		return index;
	}
	return -1;
}

void remove(HashTable& table, const string str) {
	if (!is_key_valid(str)) {
		cout << "Такого значения нет в списке ключей" << endl;
		return;
	}

	int find_index = find(table, str);
	if (find_index != -1) {
		cout << "Значение найдено под индексом" << find_index << endl;
		return;
	}

	int index{ hash_func(str) };
	table.arr[index] = "EMPTY";
}

void fill_table(HashTable& table) {
	for (const string& key : words::keys)
		add_value(table, key);
}

void output_hash_table(const HashTable& table) {
	for (int i{ 0 }; i < 10; i++) {
		cout << i << ") " << table.arr[i] << endl;
	}
}