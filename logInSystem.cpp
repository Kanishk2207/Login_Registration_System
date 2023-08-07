#include <bits/stdc++.h>
using namespace std;

void registration(string username, string password)
{
    fstream Myfile;
    string un;
    Myfile.open("password_data.txt");
    while (Myfile)
    {
        getline(Myfile, un);
        if (un == username)
        {
            cout << "User already exist\n";
            Myfile.close();
            return;
        }
    }
    Myfile.close();
    Myfile.open("password_data.txt", ios::app | ios::ate | ios::out);
    Myfile << username << endl;
    Myfile << password << endl;
    cout << "Registration successfull\n";

    Myfile.close();
}

void login(string username, string password)
{
    fstream Myfile;
    string data;
    Myfile.open("password_data.txt", ios::in);

    while (Myfile)
    {
        getline(Myfile, data);

        if (data == username)
        {
            while (Myfile)
            {
                getline(Myfile, data);
                if (data == password)
                {
                    cout << "You are logged in" << endl;
                    return;
                }
                else
                {
                    cout << "Invalid password" << endl;
                    return;
                }
            }
        }
    }
            cout << "user not found" << endl;
            return;
    Myfile.close();
}

int main()
{

    string username, password;
    int choice;

    cout << "choose\n1 for registration\n2 for login\n";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter Username: ";
        cin >> username;
        cout << endl;

        cout << "Enter Password: ";
        cin >> password;
        cout << endl;

        registration(username, password);
    }
    else if(choice == 2)
    {
        cout << "Enter Username: ";
        cin >> username;
        cout << endl;

        cout << "Enter Password: ";
        cin >> password;
        cout << endl;

        login(username, password);
    }
    else{
        cout<<"Invalid input";
    }

    return 0;
}