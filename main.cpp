#include "codedTable.h"
#include <fstream>>
#include <cstring>
#include <cmath>

void compare(string text, CodedTable t, FrequencyTable table)
{
	int n = text.size() * 8;
	int coded = 0;

	for (int i = 0; i<table.size(); i++)
	{
		for (int j = 0; j<t.getTable().size(); j++)
		{
			if (table[i].symbol == t[j].ch)
				coded += table[i].num * t[j].code.size();
		}
	}

	cout << (double)coded / n << endl;
}


void getNumbers(string text)
{
	int i = 0;
	string temp = "";
	while (text[i])
	{
		if ((i + 1) % 8 == 0)
		{
			temp += text[i];
			int num = 0;
			int j = temp.size() - 1;
			int k = 0;
			while (j >= 0)
			{
				num += (temp[j] - '0')* pow(2, k);
				k++;
				j--;
			}
			cout << num << " ";
			temp = "";
			i++;
		}
		else {
			temp += text[i];
			i++;
		}
	}

	if (temp != "")
	{
		int num = 0;
		int j = temp.size() - 1;
		int k = 0;
		while (j >= 0)
		{
			num += (temp[j] - '0')* pow(2, k);
			k++;
			j--;
		}
		cout << num << endl;
	}

}

void compressToFile(string filename)
{
	std::ifstream in;
	in.open(filename);

	std::ofstream out;
	out.open("coded.txt");

	std::ofstream outTree;
	outTree.open("printTree.txt");
	string text;
	string line;
	string myCode = "";
	while (in.good())
	{
		getline(in, line);
		text += line;

		if (in.good())
			text += '\n';
	}

	FrequencyTable t(text);
	t.sortTable();

	HuffmanTree m = m.makeTree(t);

	CodedTable table(m);

	for (int i = 0; i<text.size(); i++)
	{
		for (int j = 0; j<table.getTable().size(); j++)
			if (text[i] == table[j].ch) {
				out << table[j].code;
				myCode += table[j].code;
			}
	}
	outTree << m;

	getNumbers(myCode);
	compare(text, table, t);
}



void decode(string filename, treeNode* tree)
{
	std::ifstream in;
	in.open(filename);

	std::ofstream out;
	out.open("decode.txt");

	string text = "";
	string line = "";

	while (in.good())
	{
		getline(in, line);
		text += line;

		if (in.good())
			text += '\n';
	}

	treeNode* temp = tree;
	int i = 0;

	while (text[i])
	{
		if (text[i] == '0')
		{
			temp = temp->left;
			i++;
		}
		else if (text[i] == '1')
		{
			temp = temp->right;
			i++;
		}

		if (temp->val != '#')
		{
			out << temp->val;
			temp = tree;
		}
	}

}


int main()
{
	std::ifstream in;
	in.open("text.txt");
	string text;
	string line;
	while (in.good())
	{
		getline(in, line);
		text += line;

		if (in.good())
			text += '\n';
	}

	FrequencyTable t(text);
	t.sortTable();

	HuffmanTree tree = tree.makeTree(t);
	
	compressToFile("text.txt");

	decode("coded.txt", tree.getRoot());
	system("pause");
	return 0;
}
