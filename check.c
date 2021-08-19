//
//  check.c
//  CheckingAcc
//
//  Created by Liz Vigil on 10/23/20.
//  Copyright © 2020 Liz Vigil. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(void);
void outputHeaders(void);
void initialBalance(double amount, double* balance, double* service, double* openBalance);
void deposit(double amount, double* balance, double* service, int* numDeposit, double* amtDeposit);
void check(double amount, double* balance, double* service, int* numCheck, double* amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance);

FILE *fpIn, *fpOut;


int main(void)
{
    char code;
    double amount, service, balance;
    double amtCheck, amtDeposit, openBalance, closeBalance;
    int numCheck, numDeposit;
    
    fpIn = fopen("account.txt", "r");
    if (fpIn == NULL)
    {
        printf("account.txt could not be opened for input.");
        exit(1);
    }
    
    fpOut = fopen("csis.txt", "w");
    if (fpOut == NULL)
    {
        printf("csis.txt could not be opened for output.");
        exit(1);
    }
    
    amount = 0.0;
    service = 0.0;
    balance = 0.0;
    amtCheck = 0.0;
    amtDeposit = 0.0;
    openBalance = 0.0;
    closeBalance = 0.0;
    numCheck = 0;
    numDeposit = 0;
    
    outputHeaders();
    
    while (!feof(fpIn))
    {
        fscanf(fpIn, "%c %lf\n", &code, &amount);
        if (code == 'I')
        {
            initialBalance(amount, &balance, &service, &openBalance);
        }
        else if (code == 'D')
        {
            deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
        }
        else
        {
            check(amount, &balance, &service, &numCheck, &amtCheck);
        }
    }
    
    closeBalance = balance - service;
    outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);
    
    fclose(fpIn);
    fclose(fpOut);
    return 0;
}

void outputHeaders(void)
{
    printf("%-18s  %7s  %10s  %12s\n", "TRANSACTION", "DEPOSIT", "CHECK", "BALANCE");
    fprintf(fpOut, "%-18s  %7s  %10s  %12s\n", "TRANSACTION", "DEPOSIT", "CHECK", "BALANCE");
    printf("%-18s  %7s  %10s  %12s\n", "-----------", "-------", "-----", "-------");
    fprintf(fpOut, "%-18s  %7s  %10s  %12s\n", "-----------", "-------", "-----", "-------");
}

void initialBalance(double amount, double* balance, double* service, double* openBalance)
{
    *balance = amount;
    *openBalance = amount;
    *service += 3.00;
    
    printf("Initial Balance %37.2lf\n", *balance);
    fprintf(fpOut, "Initial Balance %37.2lf\n", *balance);
    
}

void deposit(double amount, double* balance, double* service, int* numDeposit, double* amtDeposit)
{
    *balance += amount;
    *service += 0.03;
    *amtDeposit += amount;
    ++*numDeposit;
    
    printf("Deposit %19.2lf %25.2lf\n", amount, *balance);
    fprintf(fpOut, "Deposit %19.2lf %25.2lf\n", amount, *balance);
}

void check(double amount, double* balance, double* service, int* numCheck, double* amtCheck)
{
    if ((*balance - amount) >= 0)
    {
        *balance -= amount;
    }
    else
    {
        *balance -= amount;
        *service += 5.00;
    }
    
    *service += 0.06;
    *amtCheck += amount;
    ++*numCheck;
    
    printf("Check %33.2lf %13.2lf\n", amount, *balance);
    fprintf(fpOut,"Check %33.2lf %13.2lf\n", amount, *balance);
}

void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance)
{
    printf("\n");
    fprintf(fpOut, "\n");
    printf("\n");
    fprintf(fpOut, "\n");
    printf("Total number deposits: %d\n", numDeposit);
    fprintf(fpOut, "Total number deposits: %d\n", numDeposit);
    printf("Total amount deposits: %.2lf\n", amtDeposit);
    fprintf(fpOut, "Total amount deposits: %.2lf\n", amtDeposit);
    printf("\n");
    fprintf(fpOut, "\n");
    printf("Total number checks: %d\n", numCheck);
    fprintf(fpOut, "Total number checks: %d\n", numCheck);
    printf("Total amount checks: %.2lf\n", amtCheck);
    fprintf(fpOut, "Total amount checks: %.2lf\n", amtCheck);
    printf("\n");
    fprintf(fpOut, "\n");
    printf("Total service charge: %.2lf\n", service);
    fprintf(fpOut, "Total service charge: %.2lf\n", service);
    printf("\n");
    fprintf(fpOut, "\n");
    printf("Opening balance: %.2lf\n", openBalance);
    fprintf(fpOut, "Opening balance: %.2lf\n", openBalance);
    printf("Closing balance: %.2lf\n", closeBalance);
    fprintf(fpOut, "Closing balance: %.2lf\n", closeBalance);
    printf("\n");
    fprintf(fpOut, "\n");
}



