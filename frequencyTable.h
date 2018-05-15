#ifndef FREQUENCYTABLE_H_
#define FREQUENCYTABLE_H_

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using std::vector;
using std::stack;
using std::cout;
using std::endl;
using std::string;

struct Node
{
	char symbol;
	unsigned int num;
	Node(const char t, unsigned int n) : symbol(t), num(n) {}

	void print()
	{
		cout << "Symbol: " << symbol << endl;
		cout << "Frequency: " << num << endl;
	}
};



class FrequencyTable
{
private:
	vector<Node> v;

	int findNumber(stack<char>& st, const char ch);
	vector<Node> makeTable(string text);

public:
	FrequencyTable(string text);

	void printTable();
	void sortTable();

	int size()
	{
		return v.size();
	}

	Node operator[](int n)
	{
		return v[n];
	}
};


#endif // FREQUENCYTABLE_H_

#pragma once
