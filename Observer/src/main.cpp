//============================================================================
// Name        : Observer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include "scorecard.h"
#include "subject.h"
#include "observer.h"

using namespace std;

int main(){
	ScoreData termScore;
	BarGraph bar(&termScore);
	LineGraph line(&termScore);

	ScoreCard stu1, stu2, stu3;
	stu1.name_="철수";
	stu1.motherLangScore_=70;
	stu1.englishScore_=60;
	stu1.mathScore_=90;

	stu2.name_ = "영희";
	stu2.motherLangScore_ = 70;
	stu2.englishScore_ = 80;
	stu2.mathScore_ = 50;

	stu3.name_ = "순희";
	stu3.motherLangScore_ = 95;
	stu3.englishScore_ = 90;
	stu3.mathScore_ = 85;

	termScore.AddScore(&stu1);
	termScore.AddScore(&stu2);
	termScore.AddScore(&stu3);

	cout<<"-----------"<<endl;
	bar.PrintOut();

	cout<<"-----------"<<endl;
	line.PrintOut();

	bar.ChangScore("철수",ENGLISH_SUBJECT, 85);

	cout<<"------------"<<endl;
	bar.PrintOut();
	cout<<"-------------"<<endl;
	line.PrintOut();

}
