//============================================================================
// Name        : Flyweight.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : Flyweight 패턴(이미지 정보를 개별 객체들이 공유)
//				   1. 공유 가능한 정보와 불가능한 정보 구분
//				   2. 정보들을 저장, 관리할 객체를 정의 -> 공유 가능한 정보 별도 저장.
//============================================================================

#include <iostream>
using namespace std;

class EnemyImage{
public:
	virtual void Display(int x, int y)=0;
protected:
	EnemyImage(){}
	EnemyImage(const EnemyImage& rhs);
};

class EnemyNoActionImge: public EnemyImage{
public:
	static EnemyImage* CreateInstance(){
		if(pInstance_==0){
			pInstance_=new EnemyNoActionImge;
			cout<<"EnemyNoActionImage"<<endl;
		}
		return pInstance_;
	}

	void Display(int x, int y){
		//x, y 위치에 이미지 표시
	}

protected:
	EnemyNoActionImge(){}
	EnemyNoActionImge(const EnemyNoActionImge& rhs);
	static EnemyImage *pInstance_;
};

EnemyImage* EnemyNoActionImge::pInstance_=0;

class EnemyMoveImg: public EnemyImage{
public:
	static EnemyImage* CreateInstance(){
		if(pInstance_==0){
			pInstance_=new EnemyMoveImg;
			cout<<"EnemyMoveImg"<<endl;
		}
		return pInstance_;
	}

	void Display(int x, int y){
		//x, y 위치에 이미지 표시
	}

protected:
	EnemyMoveImg(){}
	EnemyMoveImg(const EnemyMoveImg& rhs);
	static EnemyImage *pInstance_;
};

EnemyImage* EnemyMoveImg::pInstance_=0;

class EnemyAttackImg: public EnemyImage{
public:
	static EnemyImage* CreateInstance(){
		if(pInstance_==0){
			pInstance_=new EnemyAttackImg;
			cout<<"EnemyAttackImg"<<endl;
		}
		return pInstance_;
	}

	void Display(int x, int y){
		//x, y 위치에 이미지 표시
	}

protected:
	EnemyAttackImg(){}
	EnemyAttackImg(const EnemyAttackImg& rhs);
	static EnemyImage *pInstance_;
};

EnemyImage* EnemyAttackImg::pInstance_=0;

class EnemyDieImg: public EnemyImage{
public:
	static EnemyImage* CreateInstance(){
		if(pInstance_==0){
			pInstance_=new EnemyDieImg;
			cout<<"EnemyDieImg"<<endl;
		}
		return pInstance_;
	}

	void Display(int x, int y){
		//x, y 위치에 이미지 표시
	}

protected:
	EnemyDieImg(){}
	EnemyDieImg(const EnemyDieImg& rhs);
	static EnemyImage *pInstance_;
};

EnemyImage* EnemyDieImg::pInstance_=0;

class Enemy{
public:
	Enemy(int x, int y){
		curX_=x; curY_=y;
		pCurImage_=EnemyNoActionImge::CreateInstance();
	}

	void Move(int x, int y){
		curX_=x; curY_=y;
		pCurImage_=EnemyMoveImg::CreateInstance();
	}

	void Attack(){
		pCurImage_=EnemyAttackImg::CreateInstance();
	}
	void Display(){
		pCurImage_->Display(curX_, curY_);
	}

private:
	int curX_, curY_;
	EnemyImage *pCurImage_;
};

int main() {
	Enemy e1(10,10), e2(20,20);

	e1.Move(30,30);
	e2.Attack();
	e2.Move(40,40);
	return 0;
}
