#include <iostream>
#include <cstdlib>

const double FIRST_BRACKET_LENGTH  = 18200;
const double SECOND_BRACKET_LENGTH = 18799;
const double THIRD_BRACKET_LENGTH  = 42999;
const double FOURTH_BRACKET_LENGTH = 100000; 

const double P_FIRST_BRACKET = 1;
const double P_SECOND_BRACKET = 0.81;
const double P_THIRD_BRACKET = 0.675;
const double P_FOURTH_BRACKET = 0.63;
const double P_LAST_BRACKET = 0.55;


double tax_money_in_year(double income){
	double money_to_tax = income;
	double taxed_money = 0;
	
	// Between $0 - $18201
	if(money_to_tax >= 0){
		//If under the first bracket, no tax is taken. 
		if(money_to_tax < FIRST_BRACKET_LENGTH){
			return money_to_tax;
		}
		taxed_money += FIRST_BRACKET_LENGTH * P_FIRST_BRACKET;
		money_to_tax -= FIRST_BRACKET_LENGTH;
	}

	// Between $18,201 - $37,000
	if(money_to_tax >= 0){
		
		if(money_to_tax < SECOND_BRACKET_LENGTH){
			return taxed_money + (money_to_tax * P_SECOND_BRACKET);
		}

		taxed_money += SECOND_BRACKET_LENGTH * P_SECOND_BRACKET;
		money_to_tax -= SECOND_BRACKET_LENGTH;
	}

	// Between $37,001 - $80,000
	if(money_to_tax >= 0){

		if(money_to_tax < THIRD_BRACKET_LENGTH){
			return taxed_money + (money_to_tax * P_THIRD_BRACKET);
		}

		taxed_money += THIRD_BRACKET_LENGTH * P_THIRD_BRACKET;
		money_to_tax -= THIRD_BRACKET_LENGTH;
	}

	// Between $80,001 - $180,000
	if(money_to_tax >= 0){

		if(money_to_tax < FOURTH_BRACKET_LENGTH){
			return taxed_money + (money_to_tax * P_FOURTH_BRACKET);
		}

		taxed_money += FOURTH_BRACKET_LENGTH * P_FOURTH_BRACKET;
		money_to_tax -= FOURTH_BRACKET_LENGTH;
	}

	// Greater than $180,000
	if(money_to_tax >= 0){
		taxed_money += money_to_tax * P_LAST_BRACKET;
		money_to_tax = 0;
	}

	return taxed_money;
}

int main(int argc, char* argv[]){

	if(argc != 4){
		std::cerr << "Usage: <y,m,w>(input) <dollars earned> <y,m,w>(output)" << std::endl;
		return 1;
	}

	const double user_input_wage = atof(argv[2]);
	double taxed_money_years;

	//Convers it to yearly for storage
	switch(*argv[1]){
		case 'y': taxed_money_years = tax_money_in_year(user_input_wage); break;
		case 'm': taxed_money_years = tax_money_in_year(user_input_wage * 12); break;
		case 'w': taxed_money_years = tax_money_in_year(user_input_wage * 52); break;
	}

	//Simply divides it back out.
	switch(*argv[3]){
		case 'y': std::cout << "Yearly earnings after tax is $" << taxed_money_years / 1.0 << std::endl; break;
		case 'm': std::cout << "Monthly earnings after tax is $" << taxed_money_years / 12.0 << std::endl; break;
		case 'w': std::cout << "Weekly earnings after tax is $" << taxed_money_years / 52.0 << std::endl; break;
	}


	switch(*argv[3]){
		case 'y': std::cout << "You lose $" << (user_input_wage	) - (taxed_money_years / 1.0) <<  " per year to the tax man" << std::endl; break;
		case 'm': std::cout << "You lose $" << (user_input_wage ) - (taxed_money_years / 12.0) << " per month to the tax man" << std::endl; break;
		case 'w': std::cout << "You lose $" << (user_input_wage ) - (taxed_money_years / 52.0) << " per week to the tax man" << std::endl; break;
	}

	std::cout << "Done by Dale Salter(the input and output y/m/w have to be the same)" << std::endl;

	return 0;
}
