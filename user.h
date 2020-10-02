//FinalProject
//COP3014
//20180419

#ifndef _USER_H_
#define _USER_H_

#define _CRT_SECURE_NO_WARNINGS


#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
using namespace std;

class User
{
public:
	User();
	~User();
	void greeting();
	//char menu();
	//void selection(char enter);
	//void initialize();
	string setFName();
	string setLName();
	char getSex();
	int getAge();
	double getWeight();
	//void printWeight(double weight);
	double selection();
	double calculateBMR(int age, char sex, double weight);
	double calculateCalorieNeeds(double dBMR, double activity);
	double dietaryIntake();
	double calculateDeficit(double totalCalorieNeeds, double intake);
	void process();
	static void test();
	void print();
	friend class Exercise;
	friend class Diet;

private:
	//char enter;
	string fName;
	string lName;
	char sex;
	int age;
	double weight;
	double activity;
	double dBMR;
	double totalCalorieNeeds;
	double intake;
	double deficit;
};

class Exercise: public User
{
public:
	Exercise();
	~Exercise();
	void greeting();
	double getWeight();
	void setLift(double mass);
	void setBike(double mass);
	void setWalk(double mass);
	void setSwim(double mass);
	void setRun(double mass);
	static void test();
	void process();
	void print();	


private:
	double weight;
	double liftCals;
	double bikeCals;
	double walkCals;
	double swimCals;
	double runCals;
};

class Diet: public User
{
public:
	
	int getGoal();
	void routine(int goal, double totalCalorieNeeds);
	void getMaintain(double totalCalorieNeeds);
	void getLoss(double totalCalorieNeeds);
	void getMuscle(double totalCalorieNeeds);
	//double getCarbs(double totalCalorieNeeds);
	//double getProtein(double totalCalorieNeeds);
	//double getFats(double totalCalorieNeeds);
	void process();
	static void test();
private:
	double totalCalorieNeeds;
	int goal;
	double carbs;
	double protein;
	double fats;
};

#endif


/****************************************************************************
Note** all of the calculations done in this program are from outside sources. I implemented their formulas in a C++ language program. All sources have been cited below.
//User Class
"The Calorie Counter For Dummies" by Rosanne Rust, Meri Raffetto.
// Exercise Class
"Calories Burned in 30 Minutes For People of Three Different Weights". By Harvard Medical Publishing: Harvard Medical School.
URL: https//www.health.harvard.edu/diet-and-weight-loss/calories-burned-in-30-minutes-of-leisure-and-routine-activities
//Diet Class
"How To Calculate Your MacroNutrients Intake" by Wiktoria Banda
URL: https://shapescale.com/blog/health/nutrition/calculate-macronutrient-ratio/
********************************************************************************/

