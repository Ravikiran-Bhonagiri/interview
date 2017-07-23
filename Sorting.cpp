//============================================================================
// Name        : Searching.cpp
// Author      : Ravikiran
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int LinearSearch( int arr[], int length, int value);
int BinarySearch( int arr[] , int low, int high, int value );
int FindPivot( int arr[], int low, int high );


int main() {

	cout << "Binary Search Algorithm" << endl ;
	cout << "Please Enter Size of Array" << endl;

	int aSize;
	cin >> aSize ;
	int randArr[aSize];

    cout << "Enter the elements in the Array" << endl;

	for( int i = 0; i < aSize ; i++ )
	{
		cin >> randArr[i] ;
	}

	cout << "Displaying the contents of the array" << endl;

	for( int i = 0; i < aSize ; i++ )
	{
		cout << randArr[i] << "  ";
	}
	cout << endl;

	cout << "Input the element for which you want the index" << endl;

	int value;

	cin >> value ;

	int index = BinarySearch( randArr, 0, aSize-1, value);

	if( index != -1 ){
		cout << "Element found at " << index+1 << endl;
	} else {
		cout << "Element " << value << " is not found " << endl;
	}

	int index1 = LinearSearch( randArr, aSize, value);

	if( index1 != -1 ){
		cout << "Element found at " << index1+1 << endl;
	} else {
		cout << "Element " << value << " is not found " << endl;
	}
	
	int arr1 [] = {3, 4, 5, 6, 1, 2} ; 

    int pivotIndex = FindPivot( arr1, 0, 5);
    
    cout << "Pivot element index is " << pivotIndex << endl;

	return 0;
}

int BinarySearch( int arr[] , int low, int high, int value )
{
	int mid ;

	while( low <= high )
	{

		mid = ( low + high )/2;

		if( arr[mid] == value)
		{
		 	return mid ;
		}

		if( value < arr[mid] )
		{
			high = mid-1;
		}
		else
		{
			low = mid+1;
		}

	}

	return -1;

}


int LinearSearch( int arr[] , int length, int value )
{
	for( int i = 0; i < length ; i++ )
	{
		if( arr[i] == value )
		{
			return i;
		}
	}

	return -1;

}

int FindPivot( int arr[] , int low, int high )
{
    while( low < high )
    {
        int mid = ( low + high )/2 ;
        
        if( low < mid && arr[mid-1] > arr[mid])
        {
            return mid-1 ;
        } 
        else if( mid < high && arr[mid] > arr[mid+1] )
        {
            return mid ;
        }
        
        if( arr[low] > arr[mid] )
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
        
    }
}

