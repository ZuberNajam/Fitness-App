//FinalProject
//COP3014
//20180419

#include "user.h"
#include "finalProjectExceptions.h"

User::User()
{
};
User::~User()
{
};
void User::greeting()
{
	cout << "****************************************************************************" << endl;
	cout << "** Welcome to the Workout Calculator! Answer the prompts and get results! **" << endl;
	cout << "****************************************************************************" << endl;

	cout << "\n********************************************************************************" << endl;
	cout << "** Disclaimer: This application is a programming project.                     **" << endl;
	cout << "** Although based on peer-reviewed scientific data, this product was created  **" << endl;
	cout << "** for educational purposes and it is highly recommended to speak to a doctor **" << endl;
	cout << "** before changing your diet or workout routine.                              **" << endl;
	cout << "********************************************************************************\n" << endl;


}

string User::setFName()
{
	string fName;
	cout << "Please enter your first name: ";
	cin >> fName;
	//fName = "Default";
	this->fName = fName;
	return fName;
}

string User::setLName()
{
	string lName;
	cout << "Please enter your last name: ";
	cin >> lName;
	//lName = "Name";
	this->lName = lName;
	return lName;
}


char User::getSex()
{
	char sex;
	cout << "Please enter (m) for male or (f) for female: ";
	cin >> sex;
	//sex = 'm';
	if(sex == 'm' || sex == 'M')
	{
		sex = 'm';

	}
	else if (sex == 'f' || sex == 'F')
	{
		sex = 'f';
	}
	else
		throw IllegalCharacterException();
	this->sex = sex;
	return sex;
}

int User::getAge()
{
	int age;
	cout << "Please enter your age rounded to the nearest whole number: ";
	cin >> age;
	if (age <=0)
		throw NonPositiveValueException();
	//age = 25;
	this->age = age;
	return age;
}

double User::getWeight()
{
	double pounds;
	cout << "Please enter your weight in (lbs.): ";
	cin >> pounds;
	if (pounds <=0)
		throw NonPositiveValueException();
	cout<<"We will convert this into kg."<<endl;
	
	//pounds = 175;
	weight = pounds*0.454;
	this-> weight=weight;
	return weight;
}



double User::selection()
{
	int selection;
	double activity;
	cout << "\n-----Activity Level Chart------" << endl;
	cout << "[1] Very Light-Minimal physical activity" << endl;
	cout << "[2] Light- Light Exercise" << endl;
	cout << "[3] Moderate- Housework with light exercise" << endl;
	cout << "[4] Heavy-Manual labor w/ team sports" << endl;
	cout << "-----Activity Level Chart------\n" << endl;
	cout << "Select the option that best describes your activity: ";
	cin >> selection;
	//selection = 1;
	if (selection == 1)
	{
		activity = 0.2;
	}
	else if (selection == 2)
	{
		activity = 0.3;
	}
	else if (selection == 3)
	{
		activity = 0.4;
	}
	else if (selection == 4)
	{
		activity = 0.5;
	}
	else
		throw IllegalValueException();

	this->activity = activity;
	return activity;
}

double User::calculateBMR(int age, char sex, double weight)
{
	double dBMR=0;

	if (sex == 'm')
	{
		if (age > 18 && age <= 30)
		{
			dBMR = ((15.3 * weight) + 679);
		}
		else if (age > 30 && age <= 60)
		{
			dBMR = ((11.6 * weight) + 879);
		}
		else if (age > 60)
		{
			dBMR = ((13.5 * weight) + 487);
		}
	}
	else if (sex == 'f')
	{
		if (age > 18 && age <= 30)
		{
			dBMR = ((14.7 * weight) + 496);
		}
		else if (age > 30 && age <= 60)
		{
			dBMR = ((8.7 * weight) + 829);
		}
		else if (age > 60)
		{
			dBMR = ((10.5 * weight) + 596);
		}
	}
	this->dBMR = dBMR;
	return dBMR;
}

double User::calculateCalorieNeeds(double dBMR, double activity)
{
	double activityNeeds;
	double nutrientCals;
	double totalCalorieNeeds;

	activityNeeds=dBMR*activity;
	nutrientCals = (.10*activityNeeds);
	totalCalorieNeeds = (activityNeeds + nutrientCals + dBMR);
	totalCalorieNeeds = totalCalorieNeeds;
	this->totalCalorieNeeds = totalCalorieNeeds;
	return totalCalorieNeeds;
}

double User::dietaryIntake()
{
	double intake;
	cout << "How many calories do you take in daily? ";
	cin >>intake;
	//intake = 4000;
	if (intake <=0)
		throw NonPositiveValueException();
	this->intake = intake;
	return intake;
}
double User::calculateDeficit(double totalCalorieNeeds, double intake)
{
	double deficit;
	deficit = (intake) - totalCalorieNeeds;
	this->deficit = deficit;
	return deficit;

}

void User::test()
{
	User a;
	a.greeting();
	a.setFName();
	a.setLName();
	a.getSex();
	a.getAge();
	a.getWeight();
	a.selection();
	a.calculateBMR(26, 'm', 90);
	a.calculateCalorieNeeds(2056,0.5);
	a.dietaryIntake();
	a.calculateDeficit(3056,4000);
	a.print();

}

void User::process()
{
	User a;
	a.greeting();
	string first=a.setFName();
	string second=a.setLName();
	char sex=a.getSex();
	int age=a.getAge();
	double weight=a.getWeight();
	double activity=a.selection();
	double aBMR=a.calculateBMR(age, sex, weight);
	double calculateCalorie=a.calculateCalorieNeeds(aBMR, activity);
	double intake=a.dietaryIntake();
	a.calculateDeficit(calculateCalorie, intake);
	a.print();
}

void User::print()
{
	cout << endl;
	cout << "First Name           : " << fName << endl;
	cout << "Last Name            : " << lName << endl;
	cout << "Sex                  : " << sex << endl;
	cout << "Age                  : " << age << endl;
	cout << "Weight(kgs)          : " << weight << endl;
	cout << "Activity Factor      : " << activity << endl;
	cout << "BMR                  : " << dBMR << endl;
	cout << "==============================================================" << endl;
	cout << "BMR is your Basal Metabolic Rate." << endl;
	cout << "It represents the hypothetical number" << endl;
	cout << "of calories(energy) your body would need" << endl;
	cout << "to support vital functions while resting" << endl;
	cout << "for 24 hours." << endl;
	cout << "==============================================================" << endl;

	cout << "****************************************************************" << endl;
	cout << "Total Calorie intake (cals) : " << intake << endl;
	cout << "*Total Calorie Needs (cals)  : " << totalCalorieNeeds << endl;
	cout << "\n*This number represents the number of calories that you require"<<endl;
	cout << "daily to maintain your current weight." << endl;
	cout << "****************************************************************" << endl;
	cout << "Extra Calories       : " << deficit << endl;
}

//Exercise Class functions

Exercise::Exercise()
{


}

Exercise::~Exercise()
{

}

void Exercise::greeting()
{
	cout << "****************************************************************************" << endl;
	cout << "** Just by inputting your weight in pounds,  **" << endl;
	cout <<"** you can find the perfect workout for you! **"<<endl; cout<<cout<<"****************************************************************************" << endl;

	cout << "\n******************************************************************************" << endl;
	cout << "** Disclaimer: This application is a programming project.                     **" << endl;
	cout << "** Although based on peer-reviewed scientific data, this product was created  **" << endl;
	cout << "** for educational purposes and it is highly recommended to speak to a doctor **" << endl;
	cout << "** before changing your diet or workout routine.                              **" << endl;
	cout << "********************************************************************************\n" << endl;

}

double Exercise::getWeight()
{
	double weight;
	cout << "Please enter your weight in (lbs.): ";
	cin >> weight;
	if(weight<=0)
		throw NonPositiveValueException();
	//weight=180;
	weight = weight*0.454;
	this-> weight=weight;
	cout<<weight<<endl;
	return weight;
}

void Exercise::setLift(double weight)
{
	
	
	if (weight<=56.699)
	{
		liftCals= 90;
	}
	else if (weight <= 70.368)
	{
		liftCals= 112;
	}
	else
	{
		liftCals= 133;
	}

	this->liftCals = liftCals;
	//cout<<liftCals;
}

void Exercise::setBike(double weight)
{
	
	
	if (weight<=56.699)
	{
		bikeCals= 210;
	}
	else if (weight <= 70.368)
	{
		bikeCals= 260;
	}
	else
	{
		bikeCals= 311;
	}

	this->bikeCals = bikeCals;
	//cout<<bikeCals;
}

void Exercise::setWalk(double weight)
{
	
	
	if (weight<=56.699)
	{
		walkCals= 150;
	}
	else if (weight <= 70.368)
	{
		walkCals= 186;
	}
	else
	{
		walkCals= 222;
	}

	this->walkCals = walkCals;
	//cout<<cals;
}

void Exercise::setSwim(double weight)
{
	
	
	if (weight<=56.699)
	{
		swimCals= 180;
	}
	else if (weight <= 70.368)
	{
		swimCals= 223;
	}
	else
	{
		swimCals= 266;
	}

	this->swimCals = swimCals;
	//cout<<swimCals;
}

void Exercise::setRun(double weight)
{
	
	
	if (weight<=56.699)
	{
		runCals= 300;
	}
	else if (weight <= 70.368)
	{
		runCals= 372;
	}
	else
	{
		runCals= 444;
	}

	this->runCals = runCals;
	//cout<<runCals;
}



void Exercise::test() 
{
	
	Exercise b;
	double mass=b.getWeight();
	b.setLift(mass);
	b.setBike(mass);
	b.setWalk(mass);
	b.setSwim(mass);
	b.setRun(mass);
	b.print();
}

void Exercise::process()
{
	Exercise b;
	double mass=b.getWeight();
	b.setLift(mass);
	b.setBike(mass);
	b.setWalk(mass);
	b.setSwim(mass);
	b.setRun(mass);
	b.print();
}

void Exercise::print()
{
	cout << "****************************************************************" << endl;
	cout<<"Based on what you have entered, the number of calories burned"<<endl;
	cout<<"during a 30 minute session for select exercises are printed below.\n"<<endl;
	cout<<"Weight Lifting (general)               : " <<liftCals<<" calories"<<endl;
	cout<<"Bicycling, Stationary(moderate)        : " <<bikeCals<<" calories"<<endl;
	cout<<"Walking (4.5mph)                       : " <<walkCals<<" calories"<<endl;
	cout<<"Swimming (general)                     : " <<swimCals<<" calories"<<endl;
	cout<<"Running (6 mph)                        : " <<runCals<<" calories"<<endl;
	cout << "****************************************************************" << endl;
}


void Diet::getMaintain(double totalCalorieNeeds)
{
	cout <<		"**************************************************************************" 
	<< endl;
	cout<<"Based on your weight class and activity level, "<<endl;
	cout<<"We have calculated your maintenance level "<<endl;
	cout<<"caloric breakdown for the major macronutrients:"<<endl;
	//cout<<totalCalorieNeeds<<endl;
	cout <<		"**************************************************************************" 
	<< endl;
	double lowcarbs=0.4*totalCalorieNeeds;
	double highcarbs=0.6*totalCalorieNeeds;
	cout<<"You should have between "<< lowcarbs<<" and "<< highcarbs
	<<" of your calories from carbohydrates."<<endl; 
	double lowproteins=0.25*totalCalorieNeeds;
	double highproteins=0.35*totalCalorieNeeds;
	cout<<"You should have between "<< lowproteins<<" and "<< highproteins 
	<<" of your calories from protein."<<endl;
	double lowfat=0.25*totalCalorieNeeds;
	double highfat=0.35*totalCalorieNeeds;
	cout<<"You should have between "<< lowfat<<" and "<< highfat 
	<<" of your calories from fats."<<endl;
	cout <<		"**************************************************************************" 
	<< endl;
	
}

void Diet::getLoss(double totalCalorieNeeds)
{
	cout <<		"**************************************************************************" 
	<< endl;
	cout<<"Based on your weight class and activity level, "<<endl;
	cout<<"We have calculated your FatLoss level "<<endl;
	cout<<"caloric breakdown for the major macronutrients:"<<endl;
	//cout<<totalCalorieNeeds<<endl;
	cout <<		"**************************************************************************" 
	<< endl;
	double lowcarbs=0.10*totalCalorieNeeds;
	double highcarbs=0.30*totalCalorieNeeds;
	cout<<"You should have between "<< lowcarbs<<" and "<< highcarbs
	<<" of your calories from carbohydrates."<<endl; 
	double lowproteins=0.40*totalCalorieNeeds;
	double highproteins=0.50*totalCalorieNeeds;
	cout<<"You should have between "<< lowproteins<<" and "<< highproteins 
	<<" of your calories from protein."<<endl;
	double lowfat=0.30*totalCalorieNeeds;
	double highfat=0.40*totalCalorieNeeds;
	cout<<"You should have between "<< lowfat<<" and "<< highfat 
	<<" of your calories from fats."<<endl;
cout <<		"**************************************************************************" 
	<< endl;
	
}

void Diet::getMuscle(double totalCalorieNeeds)
{
	cout <<		"**************************************************************************" 
	<< endl;
	cout<<"Based on your weight class and activity level, "<<endl;
	cout<<"We have calculated your Bodybuilding level "<<endl;
	cout<<"caloric breakdown for the major macronutrients:"<<endl;
	//cout<<totalCalorieNeeds<<endl;
	cout <<		"**************************************************************************" 
	<< endl;
	double lowcarbs=0.40*totalCalorieNeeds;
	double highcarbs=0.60*totalCalorieNeeds;
	cout<<"You should have between "<< lowcarbs<<" and "<< highcarbs
	<<" of your calories from carbohydrates."<<endl; 
	double lowproteins=0.25*totalCalorieNeeds;
	double highproteins=0.35*totalCalorieNeeds;
	cout<<"You should have between "<< lowproteins<<" and "<< highproteins 
	<<" of your calories from protein."<<endl;
	double lowfat=0.15*totalCalorieNeeds;
	double highfat=0.25*totalCalorieNeeds;
	cout<<"You should have between "<< lowfat<<" and "<< highfat 
	<<" of your calories from fats."<<endl;
cout <<		"**************************************************************************" 
	<< endl;
	
}

void Diet::test()
	{
		
	Diet a;
	a.greeting();
	a.setFName();
	a.setLName();
	a.getSex();
	a.getAge();
	a.getWeight();
	a.selection();
	a.calculateBMR(26, 'm', 90);
	a.calculateCalorieNeeds(2056,0.5);
	a.getMaintain(3000);
	a.getLoss(3000);
	a.getMuscle(3000);
		
}
void Diet::process()
{
	Diet c;
	c.greeting();
	string first=c.setFName();
	string second=c.setLName();
	char sex=c.getSex();
	int age=c.getAge();
	double weight=c.getWeight();
	double activity=c.selection();
	double aBMR=c.calculateBMR(age, sex, weight);
	double calculateCalorie=c.calculateCalorieNeeds(aBMR, activity);
	//cout<<calculateCalorie<<endl;
	c.getMaintain(calculateCalorie);
	c.getLoss(calculateCalorie);
	c.getMuscle(calculateCalorie);
}