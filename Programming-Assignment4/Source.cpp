//Miguel Bautista
//CISP 1010-W01
//Programming asignment 4
//10 October 2025
//Description: Program will get information from Store file, then will calculate whether or not the store made a profit. Then it will calculate and print the weekyl profit, weekly cost, how muhc is owed to the company, total number of stores, total profit made by all the stores, and total owed to the company to the console and the output file.
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	//Varaibles
	double percentage, salaries, materials, revenue, weeklyCost, weeklyProfit, totalProfit = 0, owedToCompany, totalOwed = 0;
	int totalStores = 0;
	string locationName;
	ifstream storeFile;
	ofstream outputFile;

	//Get percentage
	cout << "Enter the percentage that is owed to corporate: ";
	cin >> percentage;
	 
	//Open files
	storeFile.open("Stores.txt");
	outputFile.open("Results-per-Location.txt");

	//Check for file errors
	if (!storeFile || !outputFile) {
		cout << "Error opening files." << endl;
		return 1;
	}

	//Reading from file
	while (storeFile >> locationName >> salaries >> materials >> revenue) {
		totalStores++;

		weeklyCost = salaries + materials;
		weeklyProfit = revenue - weeklyCost;

		totalProfit += weeklyProfit;

		//Print location name to console and file
		cout << locationName << endl;
		outputFile << locationName << endl;

		if (weeklyProfit > 0) {
			owedToCompany = weeklyProfit * percentage;
			totalOwed += owedToCompany;

			cout << "Total cost for this location is $" << fixed << setprecision(2) << weeklyCost << endl;
			outputFile << "Total cost for this location is $" << fixed << setprecision(2) << weeklyCost << endl;

			cout << "Total profit for this location is $" << fixed << setprecision(2) << weeklyProfit << endl;
			outputFile << "Total profit for this location is $" << fixed << setprecision(2) << weeklyProfit << endl;

			cout << "The store owes $" << fixed << setprecision(2) << owedToCompany << " to corporate" << endl;
			outputFile << "The store owes $" << fixed << setprecision(2) << owedToCompany << " to corporate" << endl;
		}
		else {
			cout << "The store did not make a profit. Location will be reevaluated." << endl;
			outputFile << "The store did not make a profit. Location will be reevaluated." << endl;
		}
		cout << endl;
		outputFile << endl;
	}

	cout << "This comapny currently has " << totalStores << " stores." << endl;
	outputFile << "This comapny currently has " << totalStores << " stores." << endl;

	cout << "The total profit for all stores is $" << fixed << setprecision(2) << totalProfit<< endl;
	outputFile << "The total profit for all stores is $" << fixed << setprecision(2) << totalProfit << endl;

	cout << "The total amoint paid to corporate is $" << fixed << setprecision(2) << totalOwed << endl;
	outputFile << "The total amoint paid to corporate is $" << fixed << setprecision(2) << totalOwed << endl;

	storeFile.close();
	outputFile.close();

	return 0;
}