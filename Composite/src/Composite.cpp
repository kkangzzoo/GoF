//============================================================================
// Name        : Composite.cpp
// Author      : kkangzzoo
// Version     :
// Copyright   : Your copyright notice
// Description : Composite패턴  -> 객체는 트리구조로 생성됨.
//				   1.기본 객체에 대한 클래스들과 구성 객체에 대한 클래스가 동일한 상속 구조 아래에 둔다.
//				   2. 기본 객체에 대한 클래스와 구성 객체에 대한 클래스를 공통으로 대표할 수 있는 클래스를 구성 객체가 참조하도록 한다.
//
//				   목적> client입장에서 기본 객체와 구성 객체를 특별한 구분없이 사용.
//============================================================================

#include <iostream>
#include <list>
#include <iterator>
#include <map>
using namespace std;

class Graphic{
public:
	virtual void Draw()=0;
	virtual void Add(Graphic* pObj){} //triangle, rectangle에서 무조건 구현을 하지 않기 위해 pure로 정의 x
	virtual void Remove(Graphic* pObj){}
	virtual Graphic* GetChild(int nth){ return 0;}
};


class Line: public Graphic{
public:
	void Draw(){
		cout<<"라인그리기"<<endl;
	}
};

class Triangle : public Graphic {
public:
	void Draw(){
		cout<<"삼각형 그리기"<<endl;
	}
};

class Rectangle : public Graphic {
public:
	void Draw(){
		cout<<"사각형 그리기"<<endl;
	}
};

class ComposedGraphic: public Graphic{  //인터페이스
public:
	void Draw(){
		list<Graphic*>::iterator iter1;
		for(iter1=components_.begin(); iter1 !=components_.end(); iter1++)	(*iter1)->Draw();
	}

	void Add(Graphic *pObj){
		components_.push_front(pObj);
	}

	void remove(Graphic *pObj) {
		list<Graphic*>::iterator iter1;
		for (iter1 = components_.begin(); iter1 != components_.end(); iter1++){
			if(*iter1==pObj)	components_.erase(iter1);
		}
	}

	Graphic* GetChild(int nth){ //외부에서 원할 경우 객체를 구성하는 세부 객체를 찾을 수 있음.
		int i;
		list<Graphic*>::iterator iter1;
		for(i=0, iter1=components_.begin(); iter1!=components_.end(); iter1++, i++){
			if(i==nth) return *iter1;
		}

		return 0;
	}

private:
	list<Graphic*> components_;
};

class Palette{
public:
	Palette(){
		Graphic* pGraphic=new Triangle;
		items_[1]=pGraphic;

		Graphic* pGraphic=new Rectangle;
		items_[2]=pGraphic;

		//도형 기록
	}

	void RegisterNewGraphic(Graphic* pGraphic){
		items_[items_.size()+1]=pGraphic;
	}

private:
	map<int, Graphic*> items_;
};

int main() {
	Triangle aTriangle;
	Rectangle aRectangle;
	ComposedGraphic aCompositedGraphic2;

	aCompositedGraphic2.Add(&aTriangle);
	aCompositedGraphic2.Add(&aRectangle);

	Line aLine;
	Rectangle aRectangle2;
	ComposedGraphic aCompositedGraphic;

	aCompositedGraphic.Add(&aCompositedGraphic2);
	aCompositedGraphic.Add(&aLine);
	aCompositedGraphic.Add(&aRectangle2);

	return 0;
}
