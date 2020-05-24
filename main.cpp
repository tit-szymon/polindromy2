#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
fstream odczyt;
int x,y;
int z=0;
string a;
bool palindrom (string s1)
{
    int dl=s1.size();
    for (int i=0; i<dl/2; i++)
        if (s1[i]!=s1[dl-i-1])
        return false;
    return true;
}
void sprawdzb()
{
    odczyt.open("dane.txt",ios::in);
    while(odczyt.good())
    {
        odczyt >> a;
        if(palindrom(a)==true && a[0]=='S')
        {
            x++;
            z++;
            cout <<z<<". "<< a << endl;
        }
    }
    cout <<"Liczba palindromow: "<<x<<endl;
    odczyt.close();
}
void parzyste()
{
    odczyt.open("dane.txt",ios::in);
    while(odczyt.good())
    {
        odczyt >> a;
        if(palindrom(a)==true)
        {
            int dlugosc=a.length();
            if(dlugosc%2==0)
            {
                x++;
                z++;
                cout <<z<<". "<<a<<endl;
            }
        }
    }
    cout <<"Liczba palindromow: "<<x<<endl;
    odczyt.close();
}
void nieparzyste()
{
    odczyt.open("dane.txt",ios::in);
    while(odczyt.good())
    {
        odczyt >> a;
        if(palindrom(a)==true)
        {
            int dlugosc=a.length();
            if(dlugosc%2!=0)
            {
                x++;
                z++;
                cout <<z<<". "<<a<<endl;
            }
        }
    }
    cout <<"Liczba palindromow: "<<x<<endl;
    odczyt.close();
}

void trzya()
{
    odczyt.open("dane.txt",ios::in);
    while(odczyt.good())
    {
        odczyt >> a;
        if(palindrom(a)==true)
        {
            if(count(a.begin(), a.end(), 'A')>=3)
            {
                x++;
                z++;
                cout <<z<<". "<< a << endl;
            }
        }
    }
    cout<<"Liczba palindromow: "<<x<<endl;
    odczyt.close();
}
int main()
{
    cout<<"Wybierz opcje z menu"<<endl;
    cout<<"1. aby zobaczyc palindromy zaczynajace sie na S oraz ich liczbe" << endl;
    cout<<"2. aby zobaczyc palindromy parzyste literami oraz ich liczbe" << endl;
    cout<<"3. aby zobaczyc palindromy nieparzyste literami oraz ich liczbe" << endl;
    cout<<"4. aby zobaczyc palondromy, ktore zawieraja minimum trzy litery A oraz ich liczbe" << endl;
    cin>>y;
    cout<<"Wybrales opcje numer "<<y<<endl;
    cout<<endl;
    cout<<"Lista palindormow:"<<endl;
    switch(y)
    {
    case 1:
        sprawdzb();
        break;
    case 2:
        parzyste();
        break;
    case 3:
        nieparzyste();
        break;
    case 4:
        trzya();
        break;
    default:
        cout << "Wybrales nie istniejaca opcje";
        break;
    }
    return 0;
}
