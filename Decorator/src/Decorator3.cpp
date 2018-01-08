//============================================================================
// Name        : Decorator.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : 객체 상태 관리를 통한 객체 기능 조정 -> Decorator 패턴 적용
//				   >>특정 객체에만 기능 조정
//					객체 차원에서 기능을 추가하거나 삭제할 수있는 방법 -> 다른 객체를 꾸며주기
//
//				  정리) 특정 객체에게 동적으로 새로운 기능 추가, 추가한 기능 다른 객체 참조.
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
	virtual void Attack()=0;
};

class FrontAttackplane:public Airplane{
public:
	void Attack(){
		cout<<"전방공격"<<endl;
	}
};

class Decorator:public Airplane{
public:
	Decorator(Airplane* pObj){ pComponent_=pObj;}
	virtual ~Decorator()=0;

	void Attack(){
		if(pComponent_!=0) pComponent_->Attack();
	}

private:
	Airplane* pComponent_;
};

Decorator::~Decorator(){}

class SideAttackAirplane: public Decorator{
public:
	SideAttackAirplane(Airplane* pObj):Decorator(pObj){}

	void Attack(){
		Decorator::Attack();
		cout<<"측방공격"<<endl;
	}
};

class RearAttackAirplane: public Decorator{
public:
	RearAttackAirplane(Airplane* pObj):Decorator(pObj){}

	void Attack(){
		Decorator::Attack();
		cout<<"후방공격"<<endl;
	}
};


int main() {
	Airplane* pFrontAttackAirplane=new FrontAttackplane;
	Airplane* pSideAttackAirplane=new SideAttackAirplane(pFrontAttackAirplane);
	Airplane* pRearAttackAirplane=new RearAttackAirplane(pFrontAttackAirplane);

	pRearAttackAirplane->Attack();
	delete pRearAttackAirplane;

	pSideAttackAirplane->Attack();

	return 0;
}
