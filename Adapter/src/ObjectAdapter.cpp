/*
 * ObjectAdapter.cpp
 *
 *  Created on: 2018. 1. 2.
 *      Author: daum
 *      Description: Object Adapter 패턴에 의한 TextShape 클래스의 구현 및 활용 예
 *      				nonAdapter) 객체의 자료형이 다름. -> 객체의 자료형 통일 -> Shape클래스의 자료형으로 통일
 *      							 TextShape와 같은 이름으로 Shape클래스의 하위 클래스로 정의 -> Shape 클래스와 동일한 인터페이스를 갖음.
 *
 *      							 >> Object Adapter 이용
 *      								내부에서 TextView 클래스 호출. > pText_
 *
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

class TextShape:public Shape{
public:
	TextShape(){
		pText_=new TextView;
	}
	Rectangle BoundingBox(){
		return pText_->GetExtent();
	}

private:
	TextView *pText_;
};


void DisplayBoundingBox(Shape *pSelectedShape){
	(pSelectedShape->BoundingBox()).Draw();
}

int main(){
	TextShape text;
	DisplayBoundingBox(&text);
}





