/*
 * man.cpp
 *
 *  Created on: 2018. 1. 10.
 *      Author: daum
 */

#include <iostream>
#include "item.h"
#include "list.h"
#include "iter.h"

using namespace std;

void PrintData(Iterator* pIter){
	for(pIter->First() ; ! pIter->IsDone() ; pIter->Next()){
		cout<< pIter->GetCurItem()->data_<<endl;
	}
}

int main(){
	Item item1("A"), item2("B"), item3("B"), item4("C");

	LinkedList list;
	list.AddNext(&item1);


	ListIterator *pListIter2=(ListIterator*)list.CreateIterator();
	PrintData(pListIter2);
	cout << "--4545--------------------------" << endl;

	list.AddNext(&item2, &item1);



	list.AddNext(&item3, &item2);


	list.AddNext(&item4, &item3);

	ListIterator *pListIter=(ListIterator*)list.CreateIterator();
	PrintData(pListIter);

	cout << "----------------------------" << endl;

	TreeList tree;
	tree.AddNext(&item1);
	tree.AddNext(&item2, &item1);
	tree.AddNext(&item3, &item2);
	tree.AddNext(&item4, &item3);

	TreeIterator *pTreeIter = (TreeIterator*) tree.CreateIterator();
	PrintData(pTreeIter);
}
