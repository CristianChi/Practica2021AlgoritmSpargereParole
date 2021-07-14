#include <iostream>
#include <ctime>
#include <string>
#include "sha256.h"


using namespace std;
string crackHash(string pass);
clock_t start_t, end_t;

int main() {
    string passhash;

    cout << "Hash password to crack: ";
    passhash = "5dbf18c03750f3da03bf0636dba39497d20da3d33cfdfbb56a85e6e134d84b7c";
    cout << passhash << endl;

    crackHash(passhash);

    cout << endl;
    cout << "The time it took to find possible passwords: " << (double)(end_t - start_t) / 1000 << " seconds" << endl << endl;
    return 0;
}

string crackHash(string pass) {
    int digit[5], passwordLength = 1;
    start_t = clock();

    string test, testhash, alphabet = "0123456789";

    while (1) {


        switch (passwordLength) {
        case 1:

            for (digit[0] = 1; digit[0] < 10; digit[0]++)
            {
                test = alphabet[digit[0]];
                for (int i = 1; i < passwordLength; i++)
                    test += alphabet[digit[i]];
                testhash = sha256(test);
                if (pass.compare(testhash) == 0)
                {
                    cout << endl << "Possible match found: " << test << endl;
                }
            }
            break;
        case 2:

            for (digit[1] = 0; digit[1] < 10; digit[1]++)
                for (digit[0] = 1; digit[0] < 10; digit[0]++)
                {
                    test = alphabet[digit[0]];
                    for (int i = 1; i < passwordLength; i++)
                        test += alphabet[digit[i]];
                    testhash = sha256(test);
                    if (pass.compare(testhash) == 0)
                    {
                        cout << endl << "Possible match found: " << test << endl;
                    }
                }
            break;
        case 3:

            for (digit[2] = 0; digit[2] < 10; digit[2]++)
                for (digit[1] = 0; digit[1] < 10; digit[1]++)
                    for (digit[0] = 1; digit[0] < 10; digit[0]++)
                    {
                        test = alphabet[digit[0]];
                        for (int i = 1; i < passwordLength; i++)
                            test += alphabet[digit[i]];
                        testhash = sha256(test);
                        if (pass.compare(testhash) == 0)
                        {
                            cout << endl << "Possible match found: " << test << endl;
                        }
                    }
            break;
        case 4:

            for (digit[3] = 0; digit[3] < 10; digit[3]++)
                for (digit[2] = 0; digit[2] < 10; digit[2]++)
                    for (digit[1] = 0; digit[1] < 10; digit[1]++)
                        for (digit[0] = 1; digit[0] < 10; digit[0]++)
                        {
                            test = alphabet[digit[0]];
                            for (int i = 1; i < passwordLength; i++)
                                test += alphabet[digit[i]];
                            testhash = sha256(test);
                            if (pass.compare(testhash) == 0)
                            {
                                cout << endl << "Possible match found: " << test << endl;
                            }
                        }

            break;
        case 5:

            for (digit[4] = 0; digit[4] < 10; digit[4]++)
                for (digit[3] = 0; digit[3] < 10; digit[3]++)
                    for (digit[2] = 0; digit[2] < 10; digit[2]++)
                        for (digit[1] = 0; digit[1] < 10; digit[1]++)
                            for (digit[0] = 1; digit[0] < 10; digit[0]++)
                            {
                                test = alphabet[digit[0]];
                                for (int i = 1; i < passwordLength; i++)
                                    test += alphabet[digit[i]];
                                testhash = sha256(test);
                                if (pass.compare(testhash) == 0)
                                {
                                    cout << endl << "Possible match found: " << test << endl;
                                }
                            }

            break;
        }
        if (passwordLength == 5)
        {
            end_t = clock();
            cout << endl;
            return "Program finished";
        }
        else
        {
            passwordLength++;
        }
    }
}
