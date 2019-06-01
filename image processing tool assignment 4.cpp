// image processing tool assignment 4.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.h"


using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
void loadImage();
void loadImage2();
void saveImage();
void doSomethingForImage();
void Merge();
void Rotate();

int main()
{
	loadImage();

	Rotate();
	saveImage();
	return 0;
}

//_________________________________________
void loadImage()
{
	char imageFileName[100];

	// Get gray scale image file name
	cout << "Enter the source image file name: ";
	cin >> imageFileName;

	// Add to it .bmp extension and load image
	
	readGSBMP(imageFileName, image);
}
void loadImage2()
{
	char imageFileName2[100];

	// Get gray scale image file name
	cout << "Enter the source image file name: ";
	cin >> imageFileName2;

	// Add to it .bmp extension and load image
	
	readGSBMP(imageFileName2, image2);
}
//_________________________________________
void saveImage()
{
	char imageFileName[100];

	// Get gray scale image target file name
	cout << "Enter the target image file name: ";
	cin >> imageFileName;

	// Add to it .bmp extension and load image
	
	writeGSBMP(imageFileName, image);
}

//_________________________________________
void Merge()
{
	loadImage2();
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j< SIZE; j += 2)
		{
			image[i][j] = image2[i][j];
		}
	}
}
void Rotate()
{
	cout << "1-90" << " 2-180" << " 3-270";
	int cho;
	cin >> cho;
	if (cho == 1)
	{
		int temp;
		int cont = 0;
		for (int i = 0; i < SIZE; i++)
		{
			for (int j = 0; j< SIZE; j += 2)
			{
				image[i][j - cont] = temp;
				image[i][j - cont] = image[SIZE - i][j];
				image[SIZE - i][j] = temp;

			}
		}cont++;
	}
}
