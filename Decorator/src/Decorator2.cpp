//============================================================================
// Name        : Decorator.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : 객체 상태 관리를 통한 객체 기능 조정 -> 클래스 상속 이용
//============================================================================

#include <iostream>
using namespace std;

#define FRONT_DIRECTION 1
#define SIDE_DIRECTION 2
#define REAR_DIRECTION 4
#define ALL_DIRECTION 6


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

	virtual void Attack(){
		cout<<"전방공격"<<endl;
	}

private:
	int direction_;
};

class SideAttackAplane:public Airplane{
public:
	void Attack(){
		cout<<"측방공격"<<endl;
		cout<<"전방공격"<<endl;
	}
};

class RearAttackAplane:public Airplane{
public:
	void Attack(){
		cout<<"후방공격"<<endl;
		cout<<"전방공격"<<endl;
	}
};

class AllAttackArplane:public Airplane{
public:
	void Attack(){
		cout<<"측,후방공격"<<endl;
		cout<<"전방공격"<<endl;
	}
};


int main() {
	Item side(SIDE_DIRECTION);
	Airplane onePlayer;

	SideAttackAplane sPlayer;
	RearAttackAplane rPlayer;
	AllAttackArplane aPlayer;

	onePlayer.AddItem(&side);
	if(side.GetDirection()==SIDE_DIRECTION)	onePlayer=sPlayer;
	else if(side.GetDirection()==REAR_DIRECTION)	onePlayer=rPlayer;
	else onePlayer=aPlayer;


	return 0;
}
