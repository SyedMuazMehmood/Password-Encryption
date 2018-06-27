#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
class Encryption
{
    public:
        void setPassword(string x);
        string getPassword();
        string encryptString(string password);

    private:
        string password;
};
void Encryption::setPassword(string x)
{
    password=x;
}
string Encryption::getPassword()
{
    return password;
}
string Encryption::encryptString(string password)
{
    for(int i=0 ;i<password.length();i++)
    {
        password[i]=char((password[i]+10)%255);
    }
    return password;
}
int main()
{
    Encryption encrypt;
    cout<<"Enter your password-->";
    string  password="";
    for (int i=0;;i++)
    {
        char a=getch();

        if(a=='\b'&& i>=1) //backspace ki logic hai
        {
            cout<<"\b \b";
            password=password.substr(0,password.size()-1);
            continue;
        }
        if(a=='\r') //enter press krne ki logic hai ye
            break;
        password+=a;
        cout<<"*";
    }
    encrypt.setPassword(password);
    string encrypted=encrypt.encryptString(password);
    cout<<"\nYour encrypted string is-->"<<encrypted<<endl;
    cout<<"Enter your password again-->";
    cin>>password;
    if(encrypt.encryptString(password)==encrypted)
        cout<<"Correct password.."<<endl;
    else
        cout<<"Incorrect password.."<<endl;
}
