/*
 * ClassAdapter.cpp
 *
 *  Created on: 2018. 1. 2.
 *      Author: daum
 *      Description: Object Adapter 패턴에 의한 TextShape 클래스의 구현 및 활용 예
 *      				TextShape클래스를 정의하되 Shape 클래스와 TextView 클래스로부터 동시에 상속.
 *      				인터페이스는 외부에 숨겨질 수 있게 private로 상속.
 */


#include <iostream>
using namespace std;

class Rectangle{
public:
	Rectangle(int x1, int y1, int x2, int y2){
		x1_=x1; y1_=y1; x2_=x2; y2_=y2;
	}

	void Draw(){}

private:
	int x1_, y1_, x2_, y2_;
};

class TextView{
public:
	Rectangle GetExtent(){
		return Rectangle(x1_, y1_, x1_+width_,y1_+height_);
	}

private:
	int x1_,y1_;
	int width_, height_;
};

class Shape{
public:
	virtual Rectangle BoundingBox()=0;
};

class LineShape:public Shape{
public:
	Rectangle BoundingBox(){
		return Rectangle(x1_,y1_,x2_,y2_);
	}

private:
	int x1_, y1_, x2_, y2_;
};

class TextShape:public Shape, private TextView{
public:
	Rectangle BoundingBox(){
		return GetExtent();
	}
};


void DisplayBoundingBox(Shape *pSelectedShape){
	(pSelectedShape->BoundingBox()).Draw();
}

int main(){
	TextShape text;
	DisplayBoundingBox(&text);
}



