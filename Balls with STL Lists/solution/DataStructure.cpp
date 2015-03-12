//Nehemiah Chong Song Yan
//A0111966A
//Lab Group 5
//Lab 05 - Linked Lists

#include "DataStructure.h"
#include <sstream>

using namespace std;

DataStructure::DataStructure(int n)
{
	for(int i=1; i<=n; i++)
		_balls.push_back(i);
	_size = n;
}

int DataStructure::_locate(int target)
{
	list<int>::iterator iter = _balls.begin();
	for(int i=0; i<_size; i++)
	{
		if(*iter == target)
			return i;
		iter++;
	}
	return -1;
}

string DataStructure::toString()
{
	ostringstream oss;
	list<int>::iterator iter=_balls.begin();
	while(iter!=_balls.end())
	{
		oss << *iter;
		iter++;
		if(iter!=_balls.end())
			oss << " ";
	}
	oss << endl;
	return oss.str();
}

void DataStructure::A(int x, int y)
{
	int posX = _locate(x);
	int posY = _locate(y);

	if (posX == -1 || posY == -1 || x == y || posX < posY)
		return;
	
	R(x);
	
	list<int>::iterator iter=_balls.begin();
	for (int i=0; i<posY; i++)
		iter++;
	
	_balls.list::insert(iter,x);
	_size = _balls.list::size();
}

void DataStructure::B(int x, int y)
{
	int posX = _locate(x);
	int posY = _locate(y);

	if (posX == -1 || posY == -1 || x == y || posX > posY)
		return;
	
	R(x);
	
	list<int>::iterator iter=_balls.begin();
	for (int i=0; i<posY; i++)
		iter++;
	
	_balls.list::insert(iter,x);
	_size = _balls.list::size();
}

void DataStructure::R(int x)
{
	list<int>::iterator iter=_balls.begin();
	for (int i=0; i<(_locate(x)); i++)
		iter++;
	_balls.list::erase(iter);
	_size = _balls.list::size();
}


