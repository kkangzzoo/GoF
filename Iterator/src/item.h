//============================================================================
// Name        : item.h
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : Linkedlist와 TreeList에 대해 Iterator 패턴 적용
//============================================================================


#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item{
public:
	Item(string str) : data_(str){}
	string data_;
};

#endif
