// project1.c++

#include "GLFWController.h"
#include "ModelView.h"
#include <fstream>
#include <iostream>

typedef float vec2[2]; 

void get_Vals(){
	std::ifstream is("ExchangeRates.csv");

	std::string date;
	float rate1, rate2, rate3, rate4;
	float rate1arr[121], rate2arr[121], rate3arr[121], rate4arr[121];
	int arr1ind = 0, arr2ind = 0, arr3ind=0 , arr4ind =0;
	char comma;
	std::cout << "First five lines:\n";
	int nLines = 0;
	while (is >> date >> rate1 >> comma >> rate2 >> comma >> rate3 >> comma >> rate4)
	{
		rate1arr[arr1ind++] = rate1;
		rate2arr[arr2ind++] = rate2;
		//std::cout <<arr2ind-1 << " "  << rate2  << std::endl;
		rate3arr[arr3ind++] = rate3;
		rate4arr[arr4ind++] = rate4;
		//if (++nLines <= 5)
			//std::cout << date << ' ' << rate1 << ' ' << rate2 << ' ' << rate3 << ' ' << rate4 << '\n';
	}
	float vertices1[121][2] = {0};
	float vertices2[121][2] = {0};
	float vertices3[121][2] = {0};
	float vertices4[121][2] = {0};


	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices1[i][j] = float(i*2);
			vertices1[i][j+1] = rate1arr[i];
			//{float(i*2), rate1arr[i]};
		}
	}

	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices2[i][j] = float(i*2);
			vertices2[i][j+1] = rate2arr[i];
			//{float(i*2), rate1arr[i]};
		}
	}

	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices3[i][j] = float(i*2);
			vertices3[i][j+1] = rate3arr[i];
			//{float(i*2), rate1arr[i]};
		}
	}

	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices4[i][j] = float(i*2);
			vertices4[i][j+1] = rate4arr[i];
			//{float(i*2), rate1arr[i]};
		}
	}

	for (int i = 0; i < 121; i++)
	{
		//std::cout << rate4arr[i] << std::endl;
		for (int j = 0; j < 1; j++)
		{
			std::cout << vertices3[i][j] << " " << vertices3[i][j + 1] << std::endl;
			//{float(i*2), rate1arr[i]};
		}
	}
}

int main(int argc, char* argv[])
{
	
	std::ifstream is("ExchangeRates.csv");

	std::string date;
	float rate1, rate2, rate3, rate4;
	float rate1arr[121], rate2arr[121], rate3arr[121], rate4arr[121];
	int arr1ind = 0, arr2ind = 0, arr3ind=0 , arr4ind =0;
	char comma;
	std::cout << "First five lines:\n";
	int nLines = 0;
	while (is >> date >> rate1 >> comma >> rate2 >> comma >> rate3 >> comma >> rate4)
	{
		rate1arr[arr1ind++] = rate1;
		rate2arr[arr2ind++] = rate2;
		//std::cout <<arr2ind-1 << " "  << rate2  << std::endl;
		rate3arr[arr3ind++] = rate3;
		rate4arr[arr4ind++] = rate4;
		//if (++nLines <= 5)
			//std::cout << date << ' ' << rate1 << ' ' << rate2 << ' ' << rate3 << ' ' << rate4 << '\n';
	}
	float vertices1[121][2] = {0};
	float vertices2[121][2] = {0};
	float vertices3[121][2] = {0};
	float vertices4[121][2] = {0};


	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices1[i][j] = float(i*2);
			vertices1[i][j+1] = rate1arr[i]/0.01329190;
			//{float(i*2), rate1arr[i]};
		}
	}

	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices2[i][j] = float(i*2);
			vertices2[i][j+1] = rate2arr[i]/0.01329190;
			//{float(i*2), rate1arr[i]};
		}
	}

	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices3[i][j] = float(i*2);
			vertices3[i][j+1] = rate3arr[i]/0.01329190;
			//{float(i*2), rate1arr[i]};
		}
	}

	for (int i = 0; i < 121; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			vertices4[i][j] = float(i*2);
			vertices4[i][j+1] = rate4arr[i]/0.01329190;
			//{float(i*2), rate1arr[i]};
		}
	}






	GLFWController c(argv[0]);
	c.reportVersions(std::cout);

	// TODO: one or more ModelView dynamic allocations, adding
	//       each to the Controller using "c.addModel(...);"
	c.addModel(new ModelView());
	c.addModel(new ModelView(vertices1));
	c.addModel(new ModelView(vertices2));
	c.addModel(new ModelView(vertices3));
	c.addModel(new ModelView(vertices4));
	// initialize 2D viewing information:
	// Get the overall scene bounding box in Model Coordinates:
	double xyz[6]; // xyz limits, even though this is 2D
	c.getOverallMCBoundingBox(xyz);
	// Simplest case: Just tell the ModelView we want to see it all:
	ModelView::setMCRegionOfInterest(xyz);


	c.run();

	return 0;
}
