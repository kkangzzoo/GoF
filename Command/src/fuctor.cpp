/*
 * fuctor.cpp
 *
 *  Created on: 2018. 1. 9.
 *      Author: daum
 */
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class FunctorBase { //일반함수 또는 멤버함수에 대한 포인터와 멤버 함수의 경우 객체에 대한 포인터를 데이터 멤버로 저장, 관리할 수 있게 정의된 함수.
public:
	typedef void (FunctorBase::*_MemFunc)();
	FunctorBase():callee(0),func(0){}
	FunctorBase(const void *c, const void *f, size_t sz){
		if(c){
			callee=(void*) c;
			memcpy(memFunc, f, sz);
		}else{
			func=f;
		}
	}

	operator int() const{ return func|| callee; }
	class DummyInit{};

	union{ //일반함수나 멤버함수에 포인터 저장.
		const void *func;
		char memFunc[sizeof(_MemFunc)];
	};

	void *callee; //멤버함수가 함수 포인터에 저장될 경우 객체에 대한 정보 저장.
};

class Functor0 : protected FunctorBase{  //하위 클래스에 의해서만 생성 가능.
public:
	Functor0(DummyInit * = 0){ }
	void operator() ( ) const { thunk(*this); }
	FunctorBase::operator int;
protected:
	typedef void (*Thunk) (const FunctorBase&);
	Functor0 (Thunk t, const void *c, const void *f, size_t sz) : FunctorBase( c, f, sz), thunk(t){ }
private:
	Thunk thunk;
};

template<class P1>
class Functor1: protected FunctorBase {
public:
	Functor1(DummyInit * = 0) {}
	void operator()(P1 p1) const {
		thunk(*this, p1);
	}
	FunctorBase::operator int;
protected:
	typedef void (*Thunk)(const FunctorBase&, P1);
	Functor1 (Thunk t, const void *c, const void *f, size_t sz) : FunctorBase( c, f, sz), thunk(t) {}
private:
	Thunk thunk;
};

template <class Func>
class FunctionTranslator0 : public Functor0{ //일반 함수에 대한 포인터를 가지는 객체 정의
public:
	FunctionTranslator0 (Func f): Functor0 (thunk, 0, (const void*)f, 0){}
	static void thunk (const FunctorBase &ftor){
		(Func (ftor.func)) ();
	}
};

template <class Callee, class MemFunc>
class MemberTranslator0 : public Functor0{ //객체 정보와 멤버 함수에 대한 포인터를 가지는 객체 정의
public:
	MemberTranslator0(Callee &c, const MemFunc &m): Functor0(thunk, &c, &m, sizeof(MemFunc)){}
	static void thunk(const FunctorBase &ftor){
		Callee *callee = (Callee *)ftor.callee;
		MemFunc &memFunc (*(MemFunc*)(void *)(ftor.memFunc));

		(callee->*memFunc)();
	}
};

template <class P1, class Func>
class FunctionTranslator1 : public Functor1<P1>{
public:
	FunctionTranslator1(Func f): Functor1<P1>(thunk, 0, (const void*)f, 0){}
	static void thunk(const FunctorBase &ftor, P1 p1){
		(Func (ftor.func))(p1);
	}
};

template <class P1, class Callee, class MemFunc>
class MemberTranslator1: public Functor1<P1> {
public:
	MemberTranslator1(Callee &c, const MemFunc &m) :
			Functor1<P1>(thunk, &c, &m, sizeof(MemFunc)) {
	}
	static void thunk(const FunctorBase &ftor, P1 p1) {
		Callee *callee = (Callee *) ftor.callee;
		MemFunc &memFunc(*(MemFunc*) (void *) (ftor.memFunc));

		(callee->*memFunc)(p1);
	}
};

//makeFunctor > 일반함수에 대한 Functor객체를 생성, const 멤버 함수와 non-const 멤버함수에 대한  Functor 객체 생성.

template <class TRT>
inline FunctionTranslator0<TRT (*) ()>
makeFunctor(Functor0 *, TRT (*f)()){
	return FunctionTranslator0<TRT(*) ()> (f);
}

template <class Callee, class TRT, class CallType>
inline MemberTranslator0<Callee, TRT(CallType::*)()>
makeFunctor(Functor0 *, Callee &c, TRT(CallType::* const &f)()){
	typedef TRT(CallType::*MemFunc)();
	return MemberTranslator0<Callee, MemFunc> (c, f);
}


template <class Callee, class TRT, class CallType>
inline MemberTranslator0<const Callee, TRT(CallType::*)()const>
makeFunctor(Functor0 *, const Callee &c, TRT(CallType::* const &f)() const){
	typedef TRT(CallType::*MemFunc)()const;
	return MemberTranslator0<const Callee, MemFunc> (c, f);
}

template<class P1, class TRT, class TP1>
inline FunctionTranslator1<P1, TRT(*) (TP1)>
makeFunctor(Functor1<P1>, TRT(*f)(TP1)){
	return FunctionTranslator1<P1, TRT(*)(TP1)>(f);
}

template <class P1, class Callee, class TRT, class CallType, class TP1>
inline MemberTranslator1<P1, Callee, TRT(CallType::*)(TP1)>
makeFunctor(Functor1<P1>,Callee &c, TRT(CallType::* const &f)(TP1)){
	typedef TRT(CallType::*MemFunc)(TP1);
	return MemberTranslator1<P1, Callee, MemFunc> (c, f);
}

template <class P1, class Callee, class TRT, class CallType, class TP1>
inline MemberTranslator1<P1, const Callee, TRT(CallType::*)(TP1)const>
makeFunctor(Functor1<P1> *,const Callee &c, TRT(CallType::* const &f)(TP1) const){
	typedef TRT(CallType::*MemFunc)(TP1)const;
	return MemberTranslator1<P1, Callee, MemFunc> (c, f);
}

class Button{
public:
	Button(const Functor0 & uponClickDoThis): notify(uponClickDoThis){}
	void click(){notify();}
private:
	Functor0 notify;
};

class CDPlayer{
public:
	void play(){cout<<"Playing"<<endl;}
	void stop(){cout<<"Stopped"<<endl;}
};

void wow(){
	cout<<"wow!"<<endl;
}

int main(){
	CDPlayer cd;

	Button playButton(makeFunctor((Functor0 *)0, cd, &CDPlayer::play));
	Button stopButton(makeFunctor((Functor0 *)0, cd, &CDPlayer::stop));

	Button wowButton(makeFunctor((Functor0 *)0, &wow));

	playButton.click();
	stopButton.click();
	wowButton.click();

}
