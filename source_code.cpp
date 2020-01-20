#include<iostream>
#include<conio.h>
#include<math.h>
#include <sstream>
#include<windows.h>

using namespace std;

long int digitToNumber(int *inputArray , int arrayCount)      //transfer the array containing the digits with the count
{
	long int sum = 0;
	int tempArray[100];
	for(int i=0 ; i<arrayCount ; i++)
	{
		tempArray[i] = *inputArray;
		*inputArray++;
	}
	
		for(int i=0 ; i<arrayCount ; i++)
	{
		int x = arrayCount - (1 + i) ;
		sum = sum + (tempArray[i]*(pow(10,x)));
	}
	return sum;
}


void allToInteger( double number , long int &integerPart , long int &decimalPart)       
//declare long int integerPart and long int decimalPart in main also as zero intialised and then transfer them to this function 
{
	double temp;
	temp = number;
	std::ostringstream str1;
	str1 << temp;
	string numString = str1.str();
	int stringLength = 0;
	stringLength = numString.size();
	long int sumForInt=0 , sumForDec=0; 
	int temp2[20] , temp4[20] , temp3=0 ;
	int m=0 , n=0 ;

	for(int i = 0 ; i <= stringLength-1 ; i++ )
	{
		if(numString[i]=='.')
		{
			temp3++;
		}
		else
			{
				if(temp3==0)
				{
					
					switch(numString[i])
				{
					case '1' : temp2[n] = 1 ; break;
					case '2' : temp2[n] = 2 ; break;
					case '3' : temp2[n] = 3 ; break;
					case '4' : temp2[n] = 4 ; break;
					case '5' : temp2[n] = 5 ; break;
					case '6' : temp2[n] = 6 ; break;
					case '7' : temp2[n] = 7 ; break;
					case '8' : temp2[n] = 8 ; break;
					case '9' : temp2[n] = 9 ; break;
					case '0' : temp2[n] = 0 ; break;
					default : system("cls"); cout<<" :( extremely sorry for the error"; getch(); exit(1);		//include windows.h
				}
				n++;
				}
				else
				if(temp3==1)
				{
				switch(numString[i])
				{
					case '1' : temp4[m] = 1 ; break;
					case '2' : temp4[m] = 2 ; break;
					case '3' : temp4[m] = 3 ; break;
					case '4' : temp4[m] = 4 ; break;
					case '5' : temp4[m] = 5 ; break;
					case '6' : temp4[m] = 6 ; break;
					case '7' : temp4[m] = 7 ; break;
					case '8' : temp4[m] = 8 ; break;
					case '9' : temp4[m] = 9 ; break;
					case '0' : temp4[m] = 0 ; break;
					default : system("cls"); cout<<" :( extremely sorry for the error"; getch(); exit(1);		//include windows.h
				}
				m++;
				}
				else
				{
					system("cls"); cout<<" :( extremely sorry for the error"; getch(); exit(1);		//include windows.h
				}
		   }
		
	}
	
	integerPart = digitToNumber(temp2,n);
	decimalPart = digitToNumber(temp4,m);
}


double minuteAdder(double *inputArrayMin , int count)
{
	
	double tempArrayMin[100];
	for(int i=0 ; i<100 ; i++)
	{
		tempArrayMin[i]=0;
	}
	
	for(int i=0 ; i<count ; i++)
	{
		tempArrayMin[i] = *inputArrayMin;
		*inputArrayMin++;
	}
	
	long int integerPart=0 , decimalPart=0;
	double sumINT=0,sumDEC=0,sum=0;
	
	for(int i=0 ; i<count ; i++)
	{
		integerPart = decimalPart = 0;
		allToInteger(tempArrayMin[i],integerPart,decimalPart);
		sumINT = sumINT + integerPart;
		sumDEC = sumDEC + decimalPart;
		if(sumDEC>=60)
		{
			sumINT = sumINT + 1;
			sumDEC = sumDEC - 60;
		}
	}
	sum = sumINT + (sumDEC/100);
	return sum;
}

int main()
{
	//FONT SIZE CHANGE 
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = 24;                  // Height
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	
	
	
	
	
			cout<<"ENTER 0.99 FOR STOPPING THE ENTRY OF NUMBERS"<<endl<<endl;
			cout<<"Here 2.59 refers to 2 mins and 0.59 secs"<<endl;
			double input[100];
			int count=0,i=0;
			
			for(i=0;i<100;i++) 					//initialising to zero 
			{
				input[i]=0;
			}
		
		while(1)			//technically infinite loop
		{
			
			cout<<"Enter the minute with secs after decimal point - ";
			cin>>input[count];
			system("cls");
			if(input[count]==(0.99))
			{
				break;
			}
			count++;
		}
		
		double result=0;
		
		result = minuteAdder(input,count);
		long int integerPart=0 , decimalPart=0;
		
		allToInteger(result,integerPart,decimalPart);
		
		system("cls");
		cout<<result<<endl;
		cout<<integerPart<<" mins & "<<decimalPart<<" secs";
		getch();
		
		return 0;
}
