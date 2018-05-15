#include "codedTable.h"

void CodedTable::makeCodedTable(treeNode* tree, string code)
{
	if (tree->left == nullptr && tree->right == nullptr) {
		CodedTableNode p(tree->val, code);
		this->t.push_back(p);
		return;
	}


	makeCodedTable(tree->left, code + '0');
	makeCodedTable(tree->right, code + '1');
}


CodedTable::CodedTable(HuffmanTree tree)
{
	if (tree.getRoot() == nullptr)
		std::cerr << "Empy Table!\n";

	this->makeCodedTable(tree.getRoot(), "");
}

void CodedTable::printCodedTable()
{
	for (unsigned i = 0; i<t.size(); i++)
	{
		t[i].print();
	}
}

