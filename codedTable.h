#ifndef CODEDTABLE_H_
#define CODEDTABLE_H_

#include "huffmansTree.h"


struct CodedTableNode {
	char ch;
	std::string code;
	CodedTableNode(const char sym, const string kod) : ch(sym), code(kod) {}


	void print()
	{
		cout << "Symbol: " << ch << endl;
		cout << "Code: " << code << endl;
	}
};


class CodedTable
{
private:
	vector<CodedTableNode> t;
	void makeCodedTable(treeNode* tree, string code);

public:
	vector<CodedTableNode> getTable() const { return this->t; }
	CodedTable(HuffmanTree tree);

	void printCodedTable();

	CodedTableNode operator[](int n)
	{
		return t[n];
	}
};


#endif // CODEDTABLE_H_

#pragma once
