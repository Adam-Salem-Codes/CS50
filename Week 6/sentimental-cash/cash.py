from cs50 import get_float

quarter_amount = 25
# Quarters in the USA are 25¢
dime_amount = 10
# Dimes in the USA are 10¢
nickel_amount = 5
# Nickels in the USA are 5¢
penny_amount = 1
# Pennies in the USA are 1¢

# Making sure you can't enter something like -1¢
while True:
    amount_owed = get_float("Change owed: ")
    if amount_owed > 0:
        break


to_coins = round(amount_owed * 100)
# Since coins in the USA are fractions of one dollar we will have to convert dollars to coins

amount = 0
# counter

while to_coins > 0:
    # While the amount of coins isn't 0 then keep adding coins until it is... When it is we are done

    if to_coins >= quarter_amount:

        to_coins -= quarter_amount

    elif to_coins >= dime_amount:

        to_coins -= dime_amount

    elif to_coins >= nickel_amount:

        to_coins -= nickel_amount

    elif to_coins >= penny_amount:

        to_coins -= penny_amount
    else:
        print("Something has gone tremendously wrong")
    amount += 1

print(amount)
