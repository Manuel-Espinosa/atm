#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
//menu function
void menu(class Account myAccount);
//Account object
class Account
{
private:
    // Private attribute
    double mySavings;

public:
    // A vector for keep a log of all operations done
    vector<string> log;
    // Setter
    void setSavings(double s)
    {
        mySavings = s;
    }
    // Getter
    double getSavings()
    {
        return mySavings;
    }

    // Check Balance is a method for get the balance of the account
    void checkBalance()
    {
        cout << "Saldo: $" << getSavings() << endl;
        string toLog = "Consulta de saldo Fecha: " + currentDateTime();
        log.push_back(toLog);
    }

    // Withdraw takes the current balance and substracts a value 

    void withdraw(double w)
    {
        try
        {
            if (w <= getSavings())
            {
                double newBalance = getSavings() - w;
                cout << "Ha retirado: $" << w << endl;
                setSavings(newBalance);
                string ws = to_string(w);
                string toLog = "Retiro por " + ws + " Fecha: " + currentDateTime();
                log.push_back(toLog);
                cout << "Nuevo saldo: $" << getSavings() << endl;
            }
            else
            {
                throw(getSavings());
            }
        }
        catch (double savings)
        {
            cout << "Saldo Insuficiente" << endl;
        }
    }

    //Transference is a method working like withdraw
    void transference(double t)
    {
        try
        {
            if (t <= getSavings())
            {
                double newBalance = getSavings() - t;
                cout << "Ha trasnferido: $" << t << endl;
                setSavings(newBalance);
                string ts = to_string(t);
                string toLog = "Tranferencia por " + ts + " Fecha: " + currentDateTime();
                log.push_back(toLog);
                cout << "Nuevo saldo: $" << getSavings() << endl;
            }
            else
            {
                throw(getSavings());
            }
        }
        catch (double savings)
        {
            cout << "Saldo Insuficiente" << endl;
        }
    }

    //Check Operations, this method prints all elements in log vector

    void checkOp()
    {
        for (int i = 0; i < log.size(); ++i)
        {
            cout << log[i] << endl;
        }
    }

    //getTime just for saving the time each a method is called

    const std::string currentDateTime()
    {
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

        return buf;
    }
};

int main(int argc, char const *argv[])
{
    //Creating a new account
    Account myAccount;
    //Setting account balance;
    myAccount.setSavings(520364);

    menu(myAccount);

    return 0;
}
//menu function definition
void menu(class Account myAccount)
{

    int option;
    char retry;
    char c;

    cout << "Bienvenido a CitiBanamex" << endl;
    cout << "1. Consulta de saldo" << endl;
    cout << "2. Retiro" << endl;
    cout << "3. Transferencia" << endl;
    cout << "4. Consultar movimientos" << endl;
    cout << "Ingrese una opcion" << endl;
    cin >> option;

    try
    {
        if (option == (int)option)
        {
            switch (option)
            {
            case 1:
                myAccount.checkBalance();
                cout << "Realizar otra operacion s/n" << endl;
                cin >> retry;
                if (retry == 's')
                {
                    system("clear");
                    menu(myAccount);
                }
                cout << "Vuelva pronto" << endl;
                break;
            case 2:
                double w;
                cout << "Ingrese monto del retiro: ";
                cin >> w;
                cout << "El monto que desea retirar es: " << w << endl;
                cout << "Confirmar s/n" << endl;
                cin >> c;
                if (c == 's')
                {
                    system("clear");
                    myAccount.withdraw(w);
                }
                cout << "Realizar otra operacion s/n" << endl;
                cin >> retry;
                if (retry == 's')
                {
                    system("clear");
                    menu(myAccount);
                }
                cout << "Vuelva pronto" << endl;
                break;
            case 3:
                double t;
                cout << "Ingrese monto de la transferencia: ";
                cin >> t;
                cout << "El monto que desea retirar es: " << t << endl;
                cout << "Confirmar s/n" << endl;
                cin >> c;
                if (c == 's')
                {
                    system("clear");
                    myAccount.transference(t);
                }
                cout << "Realizar otra operacion s/n" << endl;
                cin >> retry;
                if (retry == 's')
                {
                    system("clear");
                    menu(myAccount);
                }
                cout << "Vuelva pronto" << endl;
                break;
            case 4:
                myAccount.checkOp();
                cout << "Realizar otra operacion s/n" << endl;
                cin >> retry;
                if (retry == 's')
                {
                    system("clear");
                    menu(myAccount);
                }
                cout << "Vuelva pronto" << endl;
                break;
            }
        }
        else
        {
            throw(option);
        }
    }
    catch (int myOption)
    {
        cout << "Ingrese solo numeros" << endl;
    }
}
