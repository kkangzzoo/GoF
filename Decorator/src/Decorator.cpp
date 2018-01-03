//============================================================================
// Name        : Decorator.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : 객체 상태 관리를 통한 객체 기능 조정
//				   문제점)클래스에 속하는 모든 객체들에게 새로운 기능 추가
//============================================================================

#include <iostream>
using namespace std;

#define FRONT_DIRECTION 1
#define SIDE_DIRECTION 2
#define REAR_DIRECTION 4

class Item{
public:
	Item(int dir){ direction_=dir;}
	int GetDirection(){ return direction_;}

private:
	int direction_;
};

class Airplane{
public:
	void AddItem(Item* pItem){
		direction_+=pItem->GetDirection();
	}

	void Attack(){
		if(direction_ & SIDE_DIRECTION){
			cout<<"측방공격"<<endl;
		}
		if(direction_ & REAR_DIRECTION){
			cout<<"후방공격"<<endl;
		}

		cout<<"전방공격"<<endl;
	}

private:
	int direction_;
};

int main() {
	Item side(SIDE_DIRECTION);
	Airplane onePlayer;

	onePlayer.AddItem(&side);
	onePlayer.Attack();
	return 0;
}
