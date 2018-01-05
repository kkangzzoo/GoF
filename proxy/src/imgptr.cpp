/*
 * imgptr.cpp
 *
 *  Created on: 2018. 1. 5.
 *      Author: daum
 *      Description : 연산자 오버로딩으로 객체가 참조 될 때마다 추가적인 작업 실행
 *
 */


#include <iostream>
#include <string>

using namespace std;

class Point{
public:
	Point(int x, int y){ x_=x; y_=y; }
	int x_, y_;
};

class Image{
public:
	Image(const char* pFn){ fn_=pFn; }
	void Draw(Point p){ cout<<fn_ <<":"<<p.x_<<","<<p.y_<<endl; }
private:
	string fn_;
};

Image* LoadAnImageFile(const char* pFn) { return new Image(pFn); }

class ImagePtr{
public:
	ImagePtr(const char* pFn){pImage_=0; fn_=pFn; }
	virtual ~ImagePtr(){}

	virtual Image* operator->() {return LoadImage(); }
	virtual Image& operator*() {return *LoadImage(); }

private:
	Image* LoadImage(){
		if(pImage_==0)	pImage_=LoadAnImageFile(fn_.data());
		return pImage_;
	}

	Image* pImage_;
	string fn_;
};

int main(){
	ImagePtr image = ImagePtr("anImageFileName");
	image->Draw(Point(50,100));
}
