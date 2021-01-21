//Jenna Lambert
//Lab 8.2

//header files
#include "pch.h"
#include <iostream>
#include <iomanip>

//namespace
using namespace std;

//prtotypes
void getJudgeData(double *&, int);
void calcScore(double[]);
double findLowest(double[]);
double findHighest(double[]);

//~~~~~~MAIN~~~~~~
int main(){ 
	double Scores[5];
	int judge;
	double indiScore = 0.0;
	for (int i = 0; i < 5; i++) {
		judge = i + 1;
		Scores[i] = getJudgeData(indiScore, judge);
	}
	calcScore(Scores);
}

//~~getJudgeData~~
void getJudgeData(double &indiScore2, int judge) {
	cout << "Ender judge #" << judge << "'s score: ";
	while (indiScore2 <= 0 || indiScore2 > 10) {
		cin >> indiScore2;
	}
}

//~~~~calcScore~~~
void calcScore(double Scores[5]) {
	double highest = findHighest(Scores);
	double lowest = findLowest(Scores);
	double sum = 0;
	double average;
	for (int i = 0; i < 5; i++) {
		sum += Scores[i];
	}
	sum = sum - highest;
	sum = sum - lowest;
	average = sum / 3;
	cout << "The average score is: " << average << endl;
	cout << "After dropping the highest score: " << highest << " and the lowest score: " << lowest << endl;
}

//~~~findLowest~~~
double findLowest(double Scores[5]) {
	double lowest =	10;
	for (int i = 0; i < 5; i++) {
		if (lowest > Scores[i]) {
			lowest = Scores[i];
		}
	}
	return lowest;
}

//~~~findHighest~~
double findHighest(double Scores[5]) {
	double highest = 0;
	for (int i = 0; i < 5; i++) {
		if (highest < Scores[i]) {
			highest = Scores[i];
		}
	}
	return highest;
}