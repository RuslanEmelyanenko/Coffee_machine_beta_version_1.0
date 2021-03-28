// Coffee_machine_beta_version_1.0
// Developers: Stanislav-Ignatenko(user's menu) and Ruslan-Emelyanenko(service_menu)
#include <iostream>
using namespace std;
// Stanislav
#define EXPRESSO 10
#define CAPPUCCINO 5
#define LATTE 8
#define CUPS_ADD 700

int cups = CUPS_ADD;
int depositMoney;
int choice;
int bank;

//Ruslan/service_menu
#define PIN 1234
#define ATTEMPT 3

int pushButton = 0;
int cashbox = 0;

// Stanislav
void printText(string massage);
void printResult(string massage, double parametr);
double printParametr(double parametr);
void cupsCounter();
void printMenu();
void enterMoney();
int checkCups();
int checkMoney();
void printIfDepositMoneyLessPriceCoffee();
// Ruslan
int serviceMenu();
bool checkPin(int pin);
bool inputPin();
void addingCups();
void withdrawalOfProceeds();
void printOnConsole(string massage);
void printOnConsole(string massage, int parametr);

int main()
{
    while(true)
    {
        if (checkCups() == false)
        {
            break;
        }
        printMenu();
        checkMoney();
        printText("\n");
        printIfDepositMoneyLessPriceCoffee();
        printText("\n");
        printMenu();
        checkMoney();
        
    }
    return 0;
}
void printText(string massage)
{
    cout << massage;
}
void printResult(string massage, double parametr)
{
    cout << massage << parametr << endl;
}
double printParametr(double parametr)
{
    return parametr;
}
void cupsCounter()
{
    cups--;
}
void printMenu()
{
    printResult("\n 1. Deposit money: ", printParametr (depositMoney));
    printResult(" 2. Espresso (BYN) ",printParametr(EXPRESSO));
    printResult(" 3. Cappuccino (BYN) ", printParametr(CAPPUCCINO));
    printResult(" 4. Latte (BYN) ", printParametr(LATTE));
    printText(" 5. Service \n ");
    printText("Please make a selection: ");
    cin >> choice;
    
    if (choice == 5) {
        serviceMenu();
    }
}
void enterMoney()
{
    printText("\n Please deposit money. Pay attention that the coffee machine doesn’t give change\n");
    printText(" 1. 10 coins\n");
    printText(" 2. 20 coins\n");
    printText(" 3. 50 coins\n");
    printText(" 4. 1 BYN\n");
    printText(" 5. 2 BYN\n");
    printText(" Please, put in the money: ");
    cin >> bank;
}
int checkCups()
{
    if(cups > 0)
    {
        return true;
    }
    printText(" We are very sorry but there are no cups left. \n");
    printText(" 5. Service \n ");
    printText("Please, press five to Service menu: ");
    cin >> choice;
    
    if (choice == 5) {
        serviceMenu();
    }
    return false;
}
int checkMoney()
{
    if (choice == 2 and depositMoney >= EXPRESSO)
        {
            cupsCounter();
            depositMoney -= EXPRESSO;
            printText("--//--//--//--MAKING COFFEE FOR YOU--//--//--//--\n ");
            printText("Here is the best coffee in the City. Please, help yourself!\n ");
            printText("-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n\n\n\n ");
        }
        else if (choice == 3 and depositMoney >= CAPPUCCINO)
        {
            cupsCounter();
            depositMoney -= CAPPUCCINO;
            printText("--//--//--//--MAKING COFFEE FOR YOU--//--//--//--\n ");
            printText("Here is the best coffee in the City. Please, help yourself!\n ");
            printText("-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n\n\n\n ");
        }
        else if(choice == 4 and depositMoney >= LATTE)
        {
            cupsCounter();
            depositMoney -= LATTE;
            printText("--//--//--//--MAKING COFFEE FOR YOU--//--//--//--\n ");
            printText("Here is the best coffee in the City. Please, help yourself!\n ");
            printText("-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-\n\n\n\n ");
        }
    return true;
}
void printIfDepositMoneyLessPriceCoffee()
{
    if ((choice == 1)or(choice == 2 and depositMoney <= EXPRESSO)or(choice == 3 and depositMoney <= CAPPUCCINO)or(choice == 4 and depositMoney <= LATTE))
    {
        enterMoney();
        depositMoney = depositMoney + bank;
        cashbox += bank;
    }
}
// Ruslan
int serviceMenu() {
    printOnConsole("\t1. Back to Main menu \n\t2. Input PIN");
    printOnConsole("\n\nPlease select: ");
    cin >> pushButton;
    
    if(pushButton == 1) {
        return 0;
    } else if(inputPin()) {
        while (true) {
            printOnConsole("\nWelcome to service menu: \n");
            printOnConsole("\n\t1 – Add cups \n\t2 – Withdrawal of proceeds \n\t3 – Back to Main Menu");
            printOnConsole("\n\nPlease select: ");
            cin >> pushButton;
        
            if(pushButton == 1) {
                addingCups();
            } else if (pushButton == 2) {
                withdrawalOfProceeds();
            } else if(pushButton == 3){
                return 0;
            }
        }
        
    } else {
        printOnConsole("\nMachine is blocked!\n");
    }
    return 0;
}

bool checkPin (int pin) {
    if(pin == PIN) {
        return true;
    }
    return false;
}

bool inputPin() {
    int pin = 0, attempt = 1;
    
    printOnConsole("\nEnter pin: ");
    cin >> pin;
    
    while(!checkPin(pin) and attempt < ATTEMPT) {
        printOnConsole("Pin is incorrect. Try again: ");
        cin >> pin;
        attempt++;
    }
    if(checkPin(pin)) {
        return true;
    }
    return false;
}

void addingCups() {
    int cupsAdd = 0;
    
    printOnConsole("\nCups left are: ", cups);
    printOnConsole("\nСapacity of cups no more than 700");
    printOnConsole("\nHow many cups are you adding? Cups adding are: ");
    cin >> cupsAdd;
    cups += cupsAdd;
    printOnConsole("\n\t1 – Cups are: ", cups);
}

void withdrawalOfProceeds () {
    printOnConsole("\n\tCashbox: ", cashbox);
    printOnConsole("\n\t<proceeds> BYN were given away\n");
    cashbox = 0;
    printOnConsole("\n\t2 - Proceeds are BYN: ", cashbox);
}

void printOnConsole(string massage) {
    cout << massage;
}

void printOnConsole(string massage, int parametr) {
    cout << massage << parametr;
}

