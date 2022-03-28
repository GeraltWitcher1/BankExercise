//
// Created by Deniss on 22/03/2022.
//

#pragma once

typedef struct Account* account_t;

typedef enum AccountStatus{
    OK,
    OVER_MAX_CREDIT_LIMIT,
    ACCOUNT_NOT_INSTANTIATED
} AccountStatus;

account_t account_create(int accountNo, double creditLimit);

void account_destroy(account_t self);

AccountStatus account_withDraw(account_t self, double amount);

AccountStatus account_deposit(account_t self,double amount);

double account_getBalance(account_t self);

double account_getCreditLimit(account_t self);

int account_getAccountNo(account_t self);