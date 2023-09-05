#pragma once
#include <string>
#include <iostream>
#include "hash.cpp"
#define MAX_SIZE 10

struct HashTable {
	string arr[MAX_SIZE]{};
};

int find(const HashTable& table, const string str);
void add_value(HashTable& table, const string str);
bool is_key_valid(const string& value);
int hash_func(const string str);
void fill_table(HashTable& table);
void output_hash_table(const HashTable& table);
void menu();
void remove(HashTable& table, const string str);



