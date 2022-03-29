#include <stdio.h>
#include "Account.h"

int main() {

    account_t myAccount;

    static const char *_account_status_text[] = {"OK", "OVER_MAX_CREDIT_LIMIT",
                                            "ACCOUNT_NOT_INSTANTIATED"
    };



    myAccount = account_create(12345, 100);

    account_deposit(myAccount, 50);

    printf("%s \n", _account_status_text[account_deposit(myAccount,100)]);

    printf("%s \n", _account_status_text[account_withDraw(myAccount,300)]);

    printf("%d \n", myAccount);

    account_destroy(&myAccount);
//    myAccount = NULL;

    printf("%d \n", myAccount);

    printf("%s \n", _account_status_text[account_deposit(myAccount,100)]);

    return 0;
}
