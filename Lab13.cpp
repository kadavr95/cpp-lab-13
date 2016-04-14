#include <conio.h>//including input/output libraries
#include <iostream.h>
#include <string>//string type part

const MaximumRowNumber=100, MaximumColumnNumber=50;//defining maximum values of rows and column in matrix

void OutputMenu();//functions prototypes
template <class VariableClassType>//templates for matrix functions
void MatrixInput(VariableClassType** DataMatrix, int ColumnNumber, int RowNumber);
template <class VariableClassType>
void MatrixQuickSort(int FirstElement, int LastElement, VariableClassType** DataMatrix, int RowNumber);
template <class VariableClassType>
void MatrixOutput(VariableClassType** DataMatrix, int ColumnNumber, int RowNumber);

void main()//main function
{
	short OperationCode;//defining variables
	int ColumnNumber,RowNumber,Counter;
	int **iMatrix = new int*[MaximumColumnNumber];//create matrices of all three types
	float **fMatrix = new float*[MaximumColumnNumber];
	string **sMatrix = new string*[MaximumColumnNumber];
	for(Counter=0; Counter<MaximumColumnNumber; Counter++)
	{
		iMatrix[Counter] = new int[MaximumRowNumber];
		fMatrix[Counter] = new float[MaximumRowNumber];
		sMatrix[Counter] = new string[MaximumRowNumber];
	}
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
				MatrixInput(fMatrix, ColumnNumber,RowNumber);//matrix data input
				MatrixQuickSort(0, ColumnNumber-1, fMatrix, RowNumber);//matrix sort
				MatrixOutput(fMatrix, ColumnNumber,RowNumber); //matrix data output
				break;
			case 51:
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
	cout<<"Press 2 to enter float type matrix\n";
	cout<<"Press 3 to enter string type matrix\n";
}

template <class VariableClassType>
void MatrixInput(VariableClassType** DataMatrix, int ColumnNumber, int RowNumber)//matrix data input
{
int ColumnCounter,RowCounter;
   for (RowCounter = 0; RowCounter < RowNumber; RowCounter++)
   {
	  for (ColumnCounter = 0; ColumnCounter < ColumnNumber; ColumnCounter++)
	  {
		  cin>>DataMatrix[ColumnCounter][RowCounter];
	  }
   }
}

template <class VariableClassType>
void MatrixOutput(VariableClassType** DataMatrix, int ColumnNumber, int RowNumber)//matrix data output
{
int ColumnCounter,RowCounter;
   cout<<"\n";
   for (RowCounter = 0; RowCounter < RowNumber; RowCounter++)
   {
	  for (ColumnCounter = 0; ColumnCounter < ColumnNumber; ColumnCounter++)
	  {
		  cout<<DataMatrix[ColumnCounter][RowCounter]<<" ";
	  }
	  cout<<"\n";
   }
}

template <class VariableClassType>
void MatrixQuickSort(int FirstElement, int LastElement, VariableClassType** DataMatrix, int RowNumber)//matrix sort
{
	VariableClassType Pivot, TemporaryVariable; //defining variables
	int FirstSubarrayElement,LastSubarrayElement,Counter;
	FirstSubarrayElement=FirstElement;//assign data from external variables to internal counters
	LastSubarrayElement=LastElement;
	Pivot=DataMatrix[(FirstSubarrayElement+LastSubarrayElement)/2][0];//defining pivot element
	while (FirstSubarrayElement<=LastSubarrayElement)//checking counters intersection
	{
		while (DataMatrix[FirstSubarrayElement][0]>Pivot)//while element is smaller than pivot
		{
			FirstSubarrayElement++;//left counter increment
		}
		while (DataMatrix[LastSubarrayElement][0]<Pivot)//while element is bigger than pivot
		{
			LastSubarrayElement--;//right counter decrement
		}
		if (FirstSubarrayElement<=LastSubarrayElement)//in case of left counter is less than right counter
		{
			for (Counter = 0; Counter < RowNumber; Counter++)//replacement of all elements in column through temporary variable
			{
				TemporaryVariable=DataMatrix[FirstSubarrayElement][Counter];
				DataMatrix[FirstSubarrayElement][Counter]=DataMatrix[LastSubarrayElement][Counter];
				DataMatrix[LastSubarrayElement][Counter]=TemporaryVariable;
			}
			FirstSubarrayElement++;//left counter increment
			LastSubarrayElement--;//right counter decrement
		}
	}
	if (FirstElement<LastSubarrayElement)//sorting of left part of matrix
		MatrixQuickSort(FirstElement,LastSubarrayElement,DataMatrix, RowNumber);
	if (FirstSubarrayElement<LastElement)//sorting of right part of matrix
		MatrixQuickSort(FirstSubarrayElement,LastElement,DataMatrix, RowNumber);
}
