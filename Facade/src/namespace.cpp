/*
 * namespace.cpp
 *
 *  Created on: 2018. 1. 4.
 *      Author: daum
 *      Description: 서브 시스템 내의 클래스들이 제공하는 인터페이스 모두 사용 -> 전역적 관리
 *      				보완) namespace 선언해 사용 -> 외부에서알 필요가없는 클래스들에 대해서는 서브 시스템과 관련된 namespace 내부로 숨김 가능
 *
 *      				>> 서브시스템별로 namespace를 지정해두고 서브시스템 내의 모든 클래스들은 각 서브시스템별 namespace에 속하게 하면,
 *      				   의도치 않은 참조 방지.
 *       */

#include <iostream>
using namespace std;

namespace X{
class Y{
	static int i;
public:
	void f(){ cout<<"X::Y::f()"<<endl;}
};

class Z;
void foo(){ cout <<"X::foo()"<<endl;}
}

int X::Y::i =9;

class X::Z{
	int u, v,w;
public:
	Z(int i){u=v=w=i;}
	int g(){cout<<u<<endl;}
};

int main(){
	X::Z z(10);

	z.g();
}




