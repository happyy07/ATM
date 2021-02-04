#include"ATM.h"

void main()
{
	
	User tabUser[25];
	User ur;
	short nb, choice, i,cpin;
	int final_income;
	string Nip;

	while(true) {
		system("cls");
		displayTitle("banque royale");
		displayTitle("guichet automatique bancaire");

		nb = openFile(tabUser);
		i = getNumero(tabUser, nb);

		if (i == -1) { continue; system("pause");}
		cout << "\n\tBienvenue " << tabUser[i].Client << "\n";

		cpin = getNip(tabUser, i);
		if (cpin == -1) { continue; system("pause"); }

		DisplayChoiceTitle("\nChoisir votre Transaction");
		DisplayChoiceTitle("\t1-Pour Deposer");
		DisplayChoiceTitle("\t2-Pour Retirer");
		DisplayChoiceTitle("\t3-Pour Consulter");

		choice = getChoice();

		switch (choice)
		{
		case 1:
			final_income = getDeposer(tabUser, i);
			getUpdate(tabUser, i, final_income);
			overwriteFile(tabUser, i, nb);
			break;
		case 2:
			final_income = getRetirer(tabUser, i);
			getUpdate(tabUser, i, final_income);
			overwriteFile(tabUser, i, nb);
			break;
		case 3:
			getConsulter(tabUser,i);
			break;
		}
	}
}
