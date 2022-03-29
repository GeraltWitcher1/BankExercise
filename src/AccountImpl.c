//
// Created by Deniss on 22/03/2022.
//

#include <stdlib.h>
#include "Account.h"

typedef struct Account {
    int AccountNo;
    double creditLimit;
    double balance;
} Account;

account_t account_create(int accountNo, double creditLimit) {
    account_t _newAccount = calloc(1, sizeof(Account));

    if (NULL == _newAccount) {
        return NULL;
    }

    _newAccount->AccountNo = accountNo;
    _newAccount->balance = 0;
    _newAccount->creditLimit = creditLimit;
    return _newAccount;
}

void account_destroy(account_t* self) {
    if (NULL != *self) {
        free(*self);
        *self = NULL;
    }
}

AccountStatus account_withDraw(account_t self, double amount) {

    if (self == NULL) {
        return ACCOUNT_NOT_INSTANTIATED;
    }

    double balance = self->balance;

    if (balance - amount < (-1)*self->creditLimit) {
        return OVER_MAX_CREDIT_LIMIT;
    } else {
        self->balance-=amount;
        return OK;
    }

}

AccountStatus account_deposit(account_t self, double amount) {

    if (self == NULL) {
        return ACCOUNT_NOT_INSTANTIATED;
    }

    self->balance += amount;
    return OK;
}

double account_getBalance(account_t self) {
    return self->balance;
}

double account_getCreditLimit(account_t self) {
    return self->creditLimit;
}

int account_getAccountNo(account_t self) {
    return self->creditLimit;
}