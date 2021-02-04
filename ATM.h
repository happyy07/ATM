#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct User
{
	string Client;
	string Nip;
	string Numero;
	int Solde;
};

void displayTitle(string title)
{
	cout << "\t";
	for (short i = 0; i < title.length(); i++)
	{
		cout << (char)towupper(title[i]);
	}
	cout << "\n\t";
	for (short i = 0; i < title.length(); i++)
	{
		cout << "-";
	}
	cout << "\n\n";
}

void DisplayChoiceTitle(string anyTitle)
{

	for (short i = 0; i < anyTitle.length(); i++)
	{
		cout << (char)towupper(anyTitle[i]);
	}
	cout << "\n";

}

short getNumero(User arr[], short nb)
{
	string numero;
	short st = 1;

	cout << "Entrez votre numero de compte: ";
	cin >> numero;

	for (short i = 0; i < nb; i++)
	{
		if (numero == arr[i].Numero)
		{
			return i;
			st = st + 1;
		}
	}
	if (st == 1)
	{
		cout << "Numero is not found\n";
		return -1;
	}
}

short getNip(User arr[], short i)
{
	string Nip;
	short foundIndex = -1;

	cout << "Entrez votre nip: ";
	cin >> Nip;

	if (Nip == arr[i].Nip)
	{
		foundIndex = 1;
	}

	if (foundIndex == -1)
	{
		cout << "invalid nip \n\n";
		return -1;
	}

}

short getChoice()
{
	short choice;
	do
	{
		cout << "Enterez votre choix(1-3) : ";
		cin >> choice;
	} while (choice > 3 or choice < 1);
	return choice;
}

short openFile(User arr[])
{
	User ur;
	short nb;

	/*Open a file for reading*/
	fstream MyFile;
	MyFile.open("ATM.txt", ios::in);
	short i = 0;

	/*Read the contents of the file and Store it in the array*/
	while (!MyFile.eof())
	{
		char tmp[10];
		User ur;
		getline(MyFile, ur.Numero);
		getline(MyFile, ur.Client);
		getline(MyFile, ur.Nip);
		MyFile.getline(tmp, 10);
		ur.Solde = atoi(tmp);

		arr[i] = ur;
		i++;
	}
	nb = i;
	MyFile.close();
	return nb;
}

int getDeposer(User arr[], short foundIndex)
{
	int deposer, total;
	User ur;
	short nb;
	string income;

	cout << "\nEntrez le montant a deposer $ : ";
	cin >> deposer;

	total = arr[foundIndex].Solde + deposer;

	return total;
}

int getRetirer(User arr[], short foundIndex)
{
	int deposer, total;
	User ur;
	short nb;
	string income;

	cout << "\nEntrez le montant a deposer $ : ";
	cin >> deposer;

	total = arr[foundIndex].Solde - deposer;

	return total;
}


void getUpdate(User arr[], short foundIndex, int final_income)
{
	arr[foundIndex].Solde = final_income;
	cout << "\n--- la transaction a reussi ---" << endl;
	cout << endl;
	cout << "Les infos du compte" << endl;
	cout << "\tNumero: " << arr[foundIndex].Numero << endl;
	cout << "\tClient: " << arr[foundIndex].Client << endl;
	cout << "\tNip: " << arr[foundIndex].Nip << endl;
	cout << "\tSolde: " << arr[foundIndex].Solde << endl;
}

void getConsulter(User arr[], short i)
{
	cout << "\tNumero: " << arr[i].Numero << endl;
	cout << "\tClient: " << arr[i].Client << endl;
	cout << "\tNip: " << arr[i].Nip << endl;
	cout << "\tSolde: " << arr[i].Solde << endl;
}


void overwriteFile(User arr[], short foundIndex, short nb)
{
	fstream MyFile;

	/*Write the content of the array into our file*/
	if (foundIndex != -1)//Modify the text file only if change was made
	{
		//open the file for writing
		MyFile.open("ATM.txt", ios::out);
		for (short i = 0; i < nb; i++)
		{
			MyFile << arr[i].Numero << endl
				<< arr[i].Client << endl
				<< arr[i].Nip << endl
				<< arr[i].Solde << ((i == (nb - 1)) ? "" : "\n");
		}
		MyFile.close();
	}
}