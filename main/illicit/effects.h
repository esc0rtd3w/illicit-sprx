#ifndef __EFFECTS_H
#define __EFFECTS_H


#define PI (3.14159265359)

float DegreesToRadians(float Degrees)
{
	return (Degrees/180.0f) * PI;
}

float Factorial(int Value)
{
	int Ret = 1;
	for(int i = Value; i > 0; i--)
		Ret = Ret * i;
	return Ret;
}

float myPow(float Value, int Pow)
{
	float Ret = 1;
	for(int i = 0; i < Pow; i++)
		Ret = Ret * Value;
	return Ret;
}

float mySin(float AnglesRad, int Accuracy)
{
	float i = AnglesRad; float Ret = 0;
	bool Minus = false;
	for(int j = 1; j <= Accuracy; j += 2)
	{
		if(!Minus)
			Ret += myPow(i,j)/Factorial(j);
		else
			Ret -= myPow(i,j)/Factorial(j);
		Minus = !Minus;
	}
	return Ret;
}

float myCos(float AnglesRad, int Accuracy)
{
	float Rad = (PI/2)-AnglesRad;
	return mySin(Rad, Accuracy);
}

float myTan(float AnglesRad, int Accuracy)
{
	float sinus = mySin(AnglesRad, Accuracy);
	float cosinus = myCos(AnglesRad, Accuracy);
	return sinus/cosinus;
}


#endif

