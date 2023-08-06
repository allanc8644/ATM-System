#pragma once
class Account
{
	private:
		double balance;
		double interestRate;
		double interest;
		int transactions;

	public:
		Account(double iR = 0.045, double b = 0) {
			balance = b;
			interestRate = iR;
			interest = 0;
			transactions = 0;
		};
		void setInterestRate(double iR) {
			interestRate = iR;
		};
		void makeDeposit(double d) {
			balance += d;
			transactions++;
		};

		bool withdraw(double d);
		
		void calcInterest() {
			interest = interestRate * balance; balance += interest;
		};
		double getInterestRate() {
			return interestRate;
		};
		double getBalance() {
			return balance;
		};
		double getInterest() {
			return interest;
		};
		int getTransactions() {
			return transactions;
		};
};

