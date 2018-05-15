#include "frequencyTable.h"

int FrequencyTable::findNumber(stack<char>& st, const char ch)
{
	int res = 1;
	stack<char> temp;
	while (!st.empty())
	{
		if (st.top() == ch)
		{
			res++;
		}
		else
		{
			temp.push(st.top());
		}
		st.pop();
	}

	while (!temp.empty())
	{
		st.push(temp.top());
		temp.pop();
	}

	return res;
}


vector<Node> FrequencyTable::makeTable(string text)
{
	int i = 0;
	stack<char> st;

	while (text[i])
	{
		st.push(text[i]);
		i++;
	}

	vector<Node> res;

	while (!st.empty())
	{
		char el = st.top();
		st.pop();
		int n = findNumber(st, el);
		Node p(el, n);
		res.push_back(p);
	}

	return res;
}

FrequencyTable::FrequencyTable(string text)
{
	if (text == "")
		std::cerr << "Empy Table!\n";
	v = makeTable(text);
}

void FrequencyTable::printTable()
{
	for (unsigned i = 0; i<v.size(); i++)
	{
		v[i].print();
	}
}


void FrequencyTable::sortTable()
{
	for (unsigned int i = 0; i<v.size(); i++)
		for (unsigned int j = i; j<v.size(); j++)
		{
			if (v[i].num > v[j].num)
			{
				Node temp = v[j];
				v[j] = v[i];
				v[i] = temp;
			}
		}
}
