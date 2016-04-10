#include <conio.h>//including input/output libraries
#include <iostream.h>
#include <string>//string type part

using namespace std;//using namespace for easy usage of string library

const MaximumRowNumber=100, MaximumColumnNumber=50;//defining maximum values of rows and column in matrix

void OutputMenu();//functions prototypes
void MatrixInput(int iMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber);
void MatrixInput(string sMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber);
void MatrixOutput(int iMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber);
void MatrixOutput(string sMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber);
void MatrixQuickSort(int FirstElement, int LastElement, int iMatrix[][MaximumRowNumber], int RowNumber);
void MatrixQuickSort(int FirstElement, int LastElement, string sMatrix[][MaximumRowNumber], int RowNumber);




void main()//main function
{
	short OperationCode;//defining variables
	int iMatrix[MaximumColumnNumber][MaximumRowNumber];
	string sMatrix[MaximumColumnNumber][MaximumRowNumber];
	int ColumnNumber,RowNumber;
	OutputMenu();//show menu of available commands
	while(1)//endless repeat
	{
		OperationCode=getch();//get command
		system("cls");//clear console screen
		switch (OperationCode)//command choice
		{
			case 49:
				cout<<"Enter number of columns in matrix: ";//request to enter quantity of columns in rows in matrix
				cin>>ColumnNumber;
				cout<<"Enter number of rows in matrix: ";
				cin>>RowNumber;
				MatrixInput(iMatrix, ColumnNumber,RowNumber);//matrix data input
				MatrixQuickSort(0, ColumnNumber-1, iMatrix, RowNumber);//matrix sort
				MatrixOutput(iMatrix, ColumnNumber,RowNumber);//matrix data output
				break;
			case 50:
				cout<<"Enter number of columns in matrix: ";//request to enter quantity of columns in rows in matrix
				cin>>ColumnNumber;
				cout<<"Enter number of rows in matrix: ";
				cin>>RowNumber;
				MatrixInput(sMatrix, ColumnNumber,RowNumber);//matrix data input
				MatrixQuickSort(0, ColumnNumber-1, sMatrix, RowNumber);//matrix sort
				MatrixOutput(sMatrix, ColumnNumber,RowNumber); //matrix data output
				break;
			default://case of pressing button not assigned to commands
				OutputMenu();//show menu of available commands
		}
	}
}

void OutputMenu()//show menu of available commands
{
	cout<<"Choose matrix type:\n";
	cout<<"Press 1 to enter integer type matrix\n";
	cout<<"Press 2 to enter string type matrix\n";
}

void MatrixInput(int iMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber)//integer matrix data input
{
int ColumnCounter,RowCounter;
   for (RowCounter = 0; RowCounter < RowNumber; RowCounter++)
   {
	  for (ColumnCounter = 0; ColumnCounter < ColumnNumber; ColumnCounter++)
	  {
		  cin>>iMatrix[ColumnCounter][RowCounter];
	  }
   }
}

void MatrixInput(string sMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber)//string matrix data input
{
int ColumnCounter,RowCounter;
   for (RowCounter = 0; RowCounter < RowNumber; RowCounter++)
   {
	  for (ColumnCounter = 0; ColumnCounter < ColumnNumber; ColumnCounter++)
	  {
		  cin>>sMatrix[ColumnCounter][RowCounter];
	  }
   }
}

void MatrixOutput(int iMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber)//integer matrix data output
{
int ColumnCounter,RowCounter;
   cout<<"\n";
   for (RowCounter = 0; RowCounter < RowNumber; RowCounter++)
   {
	  for (ColumnCounter = 0; ColumnCounter < ColumnNumber; ColumnCounter++)
	  {
		  cout<<iMatrix[ColumnCounter][RowCounter]<<" ";
	  }
	  cout<<"\n";
   }
}

void MatrixOutput(string sMatrix[][MaximumRowNumber], int ColumnNumber, int RowNumber)//string matrix data output
{
int ColumnCounter,RowCounter;
   cout<<"\n";
   for (RowCounter = 0; RowCounter < RowNumber; RowCounter++)
   {
	  for (ColumnCounter = 0; ColumnCounter < ColumnNumber; ColumnCounter++)
	  {
		  cout<<sMatrix[ColumnCounter][RowCounter]<<" ";
	  }
	  cout<<"\n";
   }
}

void MatrixQuickSort(int FirstElement, int LastElement, int iMatrix[][MaximumRowNumber], int RowNumber)//integer matrix sort
{
	int Pivot; //defining variables
	int FirstSubarrayElement,LastSubarrayElement,Counter,TemporaryVariable;
	FirstSubarrayElement=FirstElement;//assign data from external variables to internal counters
	LastSubarrayElement=LastElement;
	Pivot=iMatrix[(FirstSubarrayElement+LastSubarrayElement)/2][0];//defining pivot element
	while (FirstSubarrayElement<=LastSubarrayElement)//checking counters intersection
	{
		while (iMatrix[FirstSubarrayElement][0]<Pivot)//while element is smaller than pivot
		{
			FirstSubarrayElement++;//left counter increment
		}
		while (iMatrix[LastSubarrayElement][0]>Pivot)//while element is bigger than pivot
		{
			LastSubarrayElement--;//right counter decrement
		}
		if (FirstSubarrayElement<=LastSubarrayElement)//in case of left counter is less than right counter
		{
			for (Counter = 0; Counter < RowNumber; Counter++)//replacement of all elements in column through temporary variable
			{
				TemporaryVariable=iMatrix[FirstSubarrayElement][Counter];
				iMatrix[FirstSubarrayElement][Counter]=iMatrix[LastSubarrayElement][Counter];
				iMatrix[LastSubarrayElement][Counter]=TemporaryVariable;
			}
			FirstSubarrayElement++;//left counter increment
			LastSubarrayElement--;//right counter decrement
		}
	}
	if (FirstElement<LastSubarrayElement)//sorting of left part of matrix
		MatrixQuickSort(FirstElement,LastSubarrayElement,iMatrix, RowNumber);
	if (FirstSubarrayElement<LastElement)//sorting of right part of matrix
		MatrixQuickSort(FirstSubarrayElement,LastElement,iMatrix, RowNumber);
}

void MatrixQuickSort(int FirstElement, int LastElement, string sMatrix[][MaximumRowNumber], int RowNumber)//string matrix sort
{
	string Pivot, TemporaryVariable; //defining variables
	int FirstSubarrayElement,LastSubarrayElement,Counter;
	FirstSubarrayElement=FirstElement;//assign data from external variables to internal counters
	LastSubarrayElement=LastElement;
	Pivot=sMatrix[(FirstSubarrayElement+LastSubarrayElement)/2][0];//defining pivot element
	while (FirstSubarrayElement<=LastSubarrayElement)//checking counters intersection
	{
		while (sMatrix[FirstSubarrayElement][0]<Pivot)//while element is smaller than pivot
		{
			FirstSubarrayElement++;//left counter increment
		}
		while (sMatrix[LastSubarrayElement][0]>Pivot)//while element is bigger than pivot
		{
			LastSubarrayElement--;//right counter decrement
		}
		if (FirstSubarrayElement<=LastSubarrayElement)//in case of left counter is less than right counter
		{
			for (Counter = 0; Counter < RowNumber; Counter++)//replacement of all elements in column through temporary variable
			{
				TemporaryVariable=sMatrix[FirstSubarrayElement][Counter];
				sMatrix[FirstSubarrayElement][Counter]=sMatrix[LastSubarrayElement][Counter];
				sMatrix[LastSubarrayElement][Counter]=TemporaryVariable;
			}
			FirstSubarrayElement++;//left counter increment
			LastSubarrayElement--;//right counter decrement
		}
	}
	if (FirstElement<LastSubarrayElement)//sorting of left part of matrix
		MatrixQuickSort(FirstElement,LastSubarrayElement,sMatrix, RowNumber);
	if (FirstSubarrayElement<LastElement)//sorting of right part of matrix
		MatrixQuickSort(FirstSubarrayElement,LastElement,sMatrix,RowNumber);
}
