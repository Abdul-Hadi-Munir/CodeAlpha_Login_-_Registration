#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

bool user_existence(const string& username)
{
    ifstream file("user.txt"); 
    string line, store_user, store_pass ;
    
    while(getline(file, line))
    {
        istringstream iss(line) ;
        iss >> store_user >> store_pass ;

        if(store_user == username)
        {
            return true;
        }  
    }

    return false;
}

bool register_user(const string& username , const string& password)
{

    if(username.empty() || password.empty())
    {
        cout <<"Username and password cannot be empty.\n";
        return false;
    }

    if(user_existence(username))
    {
        cout <<"Username already exists\n";
        return false;
    }

    ofstream file("user.txt",ios::app);
    file << username <<"  "<< password << endl ;
    cout << "Registration Successful...\n" ;
    
    return true ;
}

bool login_user(const string& username , const string& password)
{
    ifstream file("user.txt");
    string line , store_user, store_pass ;

    while(getline(file, line))
    {
        istringstream iss(line);
        iss >> store_user >> store_pass ;

        if(store_user == username && store_pass == password)
        {
            cout <<"Login Successful ....\n";
            return true ;
        }
    }

    cout << "Login failed... Invalid Password or Username\n";
    return false;
}


int main()
{
    int choice;
    string username, password ;

    while(true)
    {
        cout << "\n1. Registration" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose Option : ";
        cin >> choice ;
        cin.ignore();

        if(choice == 1)
        {
            cout << "Enter username : " ;
            getline(cin, username);

            cout << "Enter password : " ;
            getline(cin, password) ;
            
            register_user(username, password);           
        }
        
        else if(choice == 2)
        {
            cout << "Enter username : " ;
            getline(cin, username);
            
            cout << "Enter password : " ;
            getline(cin, password) ;
            
            login_user(username, password);           
        }

        else if(choice == 3)
        {
            cout << "Exiting ......" <<endl ;
            break;           
        }

        else
        {
            cout << "Invalid Choise ....." <<endl;
        }
    }

    
    return 0 ;
}
