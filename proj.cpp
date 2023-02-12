#include <iostream>
#include <conio.h>
using namespace std;
//  ForAdmin
//   varaibles&Arrays
 const int size = 10; 
int counter = 0;
int option;
int count;
string model[size];
string color[size];
string price[size];
string name[size];
bool loggedInUser=false;
int a = 0;
string Username[size];
string Password[size];
string Role[size];
string role;
//  functions
void printheader();
int SubMenuForLogging();
bool SignUp(string username, string password, string role);
string SignIn(string username, string password);
int MainMenuScreenForAdmin();
int MainMenuScreenForCustomer();
int ScreenForCreatingList();
int ListOfCars();
int AddNewCarToList();
int updatedlist();
int ScreenForDeletingCarFromList();
int updatedlist2();
int UpdateThePriceOfCar();
int SeeTheListOfCustomersAndPlacedOrder();
int RecomandBestItemToCustomer();
void LogOutToExit();
//  ForCustomer
//  Variables
string Order;
string payedprice;
int choice;
string comment;
// functions
int ListOfAvailableCars();
int SelectTheCar();
int SelectConditionOfCar();
int PayPrice();
int DisplayBill();
int GiveFeedBack();
int CancelOrder();
int LogOut();
main()
{
    printheader();
   
    while (option != 3)
    {
         option = SubMenuForLogging();
       
        if (option == 1)
        {
            string username;
            string password, role;
             printheader();
             system("cls");
            cout << "enter the username:";
            cin >> username;
            cout << "enter the password:";
            cin >> password;
            cout << "enter the role:";
            cin >> role;
            bool isvalid = SignUp(username, password, role);
            if (isvalid)
            {
               
                cout << "SIGNED UP SUCCESFULLY!!";
            }
            if (!isvalid)
            {
                cout << "INVALID USERNAME OR PASSWORD!";
            }
        }
        system("cls");
        if (option == 2)
        {
            
            if(loggedInUser==false)
            {
                
            string username;
            string password;
            loggedInUser=true;
            
            printheader();
            cout << "enter the username:";
            cin >> username;
            cout << "enter the password:";
            cin >> password;
            role = SignIn(username, password);
            }
            
            if (role == "admin")
            {
               while(option!=8)
            {
                 system("cls");  
                option = MainMenuScreenForAdmin();
                printheader();
                system("cls");
                if (option == 1)
                {
                    ScreenForCreatingList();
                     ListOfCars();
                     system("cls");
                      printheader();
                     option = MainMenuScreenForAdmin();
                      
                    
                }
                
                if (option == 2)
                {
                    AddNewCarToList();
                    updatedlist();
                    option = MainMenuScreenForAdmin();
                }
                
                if (option == 3)
                {
                   
                    ScreenForDeletingCarFromList();
                    option = MainMenuScreenForAdmin();
                     printheader();
                }
                
                 if(option==4)
                 {
                   UpdateThePriceOfCar();
                   option = MainMenuScreenForAdmin();
                     system("cls");
                     printheader();
                 }
                
                if (option == 5)
                {
                    SeeTheListOfCustomersAndPlacedOrder();
                    option = MainMenuScreenForAdmin();
                }
                if (option == 7)
                {
                    RecomandBestItemToCustomer();
                    option = MainMenuScreenForAdmin();
                }
                if (option == 8)
                {
                    LogOutToExit();
                    system("cls");
                }
                
               }
            }

            else if (role == "customer")
            {
                option = MainMenuScreenForCustomer();
                printheader();
                system("cls");
                if(option==1)
                {
                    ListOfAvailableCars();
                }
                if(option==2)
                {
                    SelectTheCar();
                }
                if(option==3)
                {
                    SelectConditionOfCar();
                }
                if(option==4)
                {
                     PayPrice();
                }
                if(option==5)
                {
                 DisplayBill();
                }
                if(option==6)
                {
                   GiveFeedBack();  
                }
                if(option==7)
                {
                     CancelOrder();
                }
                if(option==8)
                {
                     LogOut();
                }

            }
        
            
        }
    
        
    }
    
    system("cls");
    
}


void printheader()
{
    cout << "            " << "^Welcome to:^" << endl;
    cout << "*******************************************************" << endl;
    cout << "**********                 **********" << endl;
    cout << "*********** WHEELS AND DEALS**********" << endl;
    cout << "**********                 **********" << endl;
    cout << "*******************************************************" << endl;
    cout << "^A place where you can buy car of your dreams^" << endl;
}
int SubMenuForLogging()
{
    int option;
    cout << "  "<< " Logging Menu:" << endl;
    cout << "---------------------" << endl;
    cout << "Options:" << endl;
    cout << "1. SignUP to continue:" << endl;
    cout << "   "<< "or" << endl;
    cout << "2. SignIn to continue:" << endl;
    cout << "3. Exit" << endl;
    cout << "enter your option:" << endl;
    cin >> option;
    return option;
    system("cls");
     
}
bool SignUp(string username, string password, string role)
{
    bool isPresent = false;
    for (int x = 0; x < counter; x++)
    {
        if (Username[x] == username && Password[x] == password)
        {
            isPresent = true;
            break;
        }
    }
    if (isPresent == true)
    {
        return 0;
        cout << "USER ALREADY EXISTS!!";
    }
    else if (counter < size)
    {
        Username[counter] = username;
        Password[counter] = password;
        Role[counter] = role;
        counter++;
        return true;
    }
    else
    {
        return false;
    }
    system("cls");
}

string SignIn(string username, string password)
{
    for (int i = 0; i < counter; i++)
    {
        if (Username[i] == username && Password[i] == password)
        {
            return Role[i];
        }
        else
        {
            return "WRONG USERNAME OR PASSWORD";
        }
    }
    return "undefined";
    system("cls");
}

int MainMenuScreenForAdmin()
{
    int option;
    cout << "** MENU SCREEN FOR ADMIN**" << endl;
    cout << "Option 1: Creat list of cars" << endl;
    cout << "Option 2: Add a new car " << endl;
    cout << "Option 3: Delete a previous car" << endl;
    cout << "Option 4: Update the price of car" << endl;
    cout << "Option 5: See the list of customers" << endl;
    cout << "Option 6: See the orders of customers" << endl;
    cout << "Option 7: Recomand the best item to customer" << endl;
    cout << "Option 8: Log out " << endl;

    cout << "enter your option:" << endl;
    cin >> option;
    return option;
    system("cls");
}

int MainMenuScreenForCustomer()
{
    int option;
    cout << "** MENU SCREEN FOR CUSTOMER**" << endl;
    cout << "Option 1: See list of cars" << endl;
    cout << "Option 2: Select the car" << endl;
    cout << "Option 3: Select the condition  of car" << endl;
    cout << "Option 4: pay the price" << endl;
    cout << "Option 5: Select the way of paying" << endl;
    cout<<  "Option 6: GiveFeed back"<<endl;
    cout << "Option 7: Cancel order" << endl;
    cout << "Option 8: Log out " << endl;
    cout << "enter your option:" << endl;
    cin >> option;
    return option;
    system("cls");
}

int ScreenForCreatingList()
{
    cout << "enter the number of cars you want to add:";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "enter the name of car:" << endl;
        cin >> name[a];
        cout << "enter the model of car:" << endl;
        cin >> model[a];
        cout << "enter the color of car:" << endl;
        cin >> color[a];
        cout << "enter the price of car:" << endl;
        cin >> price[a];
        a++;
    }
    return 0;
    system("cls");
}
    
int ListOfCars()
{ 
    cout <<"CarNumber"<< "    " << "Name:" << "    " << "    "<< "Model"<< "   "<< "    "<< "Color"<< "    "<< "   "<< ""<< "    "<< "    "<<"Price" << endl;
    cout<< a;
    for (int i = 0; i < a; i++)
    {
        
        cout<< "    " << i+1<< "    " << name[i] << "    " << model[i] << "  " << color[i] << "  " << price[i] << endl;
       
    }
    return 0;
    system("cls");
}
int AddNewCarToList()
{
    
   
        cout << "Enter the name of  new car:" << endl;
        cin >> name[a];
        cout << "enter the model of new car:" << endl;
        cin >> model[a];
        cout << "enter the color of new car:" << endl;
        cin >> color[a];
        cout << "enter the price of new  car:" << endl;
        cin >> price[a];
        a++;
        system("cls");
}
int updatedlist()
{
    ListOfCars();
    return 0;
    system("cls");
}
int ScreenForDeletingCarFromList()
{
                    int numberOfCar;
                    ListOfCars();
                    cout << "enter the number of car you want to Delete:" << endl;
                    cin >> numberOfCar;
                     
                    for(int i=0; i<a; i++)
                {
                if(i==(numberOfCar-1))
                {
                        for(int j=i; j<(a-1); j++)
                        {
                                model[j]=model[j+1];
                                name[j]=name[j+1];
                                color[j]=price[j+1];
                                price[j]=color[j+1];
                                
                        }
                        a--;
                        break;
                }
                   }
                   cout << "After Deleting remaining cars" << endl;
                   ListOfCars();
                   system("cls");
   
}
int updatedlist2()
{
    cout << "The New List Is:" << endl;
    cout << "Name:"<< "    "<< "Model" << "   " << "Color" << "   " << "Price" << endl;
    cout << name[a] << "    " << model[a] << "  " << color[a] << "  " << price[a] << endl;
    system("cls");
}

int UpdateThePriceOfCar()
{
    int numberOfCar;
    cout << "enter the numberOfCar of car whose price you want to update:" << endl;
    cin >> numberOfCar;
    
    string newPrice;
    cout << "enter the new price of car" << endl;
     cin >> newPrice;
    
   
    
    for (int i=0;i<a;i++)
    {
        if((numberOfCar-1)==i)
         price[i]=newPrice;
    }
    
    ListOfCars();
    system("cls");
}

int SeeTheListOfCustomersAndPlacedOrder()
{
    cout<<" lIST OF customer" << endl;
   for( int i=0; i<counter;i++ )
   {
       if(Role[i]=="customer")
       {
           cout<<" "<<Username[i] <<endl;
       }
   }
}

int RecomandBestItemToCustomer()
{
    cout << "Recommanded Car:" << endl;
    cout << "Audi" << endl;
    cout << "Due to Best ratings and it is our most sold car" << endl;
    system("cls");
}
void LogOutToExit()
{
    abort();
}
int ListOfAvailableCars()
{
   ListOfCars();
}
int SelectTheCar()
{
    cout<<"Enter the number of Car you want to select"<<endl;
    cin>>Order;
    cout<<"Order is"<<Order;

}
 int SelectConditionOfCar()
{
     cout<<"SELECT THE CONDITION OF CAR(NEW or OLD)"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
}
 int PayPrice()
 {
    cout<<"SELECT THE WAY OF PAYING(by cash or card)"<<endl;
    cout<<"enter your choice"<<endl;
    cin>>choice;
    cout<<"enter the price payed"<<endl;
    cin>>payedprice;
      
}
int DisplayBill()
{
   cout<<"******************BILL******************"<<endl;
   cout<<Order;
   cout<<payedprice;
}
int GiveFeedBack()
{
    string name;
    cout<<"enter your name:"<<endl;
    cin>>name;
    cout<<"enter your comment:"<<endl;
    cin>>comment;
}
int CancelOrder()
{
    cout<<"DO YOU WANT TO CANCEL ORDER?"<<endl;
    cout<<"enter your choice:";
    cin>>choice;
    cout<<"ORDER CANCELED"<<endl;
}
int LogOut()
{
    abort();
}





