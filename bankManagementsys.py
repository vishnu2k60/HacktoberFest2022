"""
 Bank management system with python
 Coded by @cyberGenie
 Github repo: https://github.io/cybergeni/bank-management
 No copyright violations
 Treasure Ajefu, Software developer
 Started writing this code on the 13th February, 2021. 4:50pm
 Ended this code on the 16th February, 2021. 1:55am.
"""

import time
print("____________________________")
print("WELCOME TO GENIEBANK")
print("____________________________")
time.sleep(0.45)


account_balance= 0

def exit_sys():
	time.sleep(0.75)
	print("THANKS FOR USING GENIEBANK. SEE YOU SOON")
	time.sleep(0.50)
	exit()
def main_menu():
	print("__________MAIN MENU_________")
	print("1. Create a new GenieBank account \n2. Deposit funds \n3. Withdraw funds \n4. Account balance \n5. Exit")
	menu_option = int(input("Enter menu option: "))
	if menu_option == 1:
		f_name = input("Enter your first name: ")
		time.sleep(0.1)
		l_name = input("Enter your last name: ")
		list = (f_name, l_name)
		title = input("Enter your title: (Mr, Mrs, Miss, Mister)\n")
		global name
		name = title + "_" + list[0][0] + "_" + list[1][0] + ".txt"
		account_balance = 0
		file = open("C:/Users/Tresh/Codes/Personal_Projects/Python"+name, "a")
		file.write(f'{"First name : " + f_name  + "Last name : " + l_name  + "Account balance : N" + str(account_balance)}')
		file.close()
		time.sleep(0.1)
		user_acct = input("Account successfully created. Return to main menu? \n(yes or no)\n")
		try:
			if user_acct == "yes":
				time.sleep(0.50)
				main_menu()
		except:
			exit_sys()
			print("Invalid Details")
			main_menu()
	elif menu_option == 2:
		def deposit():
			deposit_amount = int(input("Enter amount to deposit: "))
			global account_balance
			account_balance = 0
			if deposit_amount in range(0, 100000):
				account_balance = account_balance + deposit_amount
			else:
				print("Please enter a digit only!. We only accept deposits of N100, 000 at a go.")
				deposit()
			print("N" + str(deposit_amount) + " has been successfully deposited into your account.")
			option = input("Do you want tp perform another transaction? (yes or no)")
			if option == "yes":
				main_menu()
			elif option == "no":
				exit_sys()
		deposit()

	elif menu_option == 3:
		def withdraw():
			withdraw_amount = int(input("Enter amount to withdraw: "))
			global account_balance
			account_balance = 0
			if withdraw_amount > account_balance:
				print("Insuffucient funds. You will be redirected back to the to main menu.")
				time.sleep(0.5)
				main_menu()
			elif withdraw_amount <= account_balance:
				account_balance -= withdraw_amount
				print("N" + str(withdraw_amount) + " has been successfully withdrawn from your account.")
				option = input("Do you want to perform another transaction? (yes or no)")
				if option == "yes":
					main_menu()
				elif option == "no":
					exit_sys()
		withdraw()
	elif menu_option == 4:
		try:
			print("Your account balance is N" + str(account_balance))
		except:
			print("You do not have an account with us. Head on to the main menu to create one.")
			time.sleep(0.5)
		finally:
			print("You have unlocked the developer options. This code is available to fork on github. Report this bug if you can, and try help fix it!")
	elif menu_option == 5:
		exit_sys()
	else:
		print("Invalid Option.")
		main_menu()
main_menu()