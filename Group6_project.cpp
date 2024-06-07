#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Login{
public:
    string  username;
	string  password;

    Login(){
	
	}
	
 bool	doLogin(){
		cout<<"Enter Username : " <<endl;
	cin>>username;
	cout<<"Enter Password :" <<endl;
	cin>>password;
	
	
	if(username=="muneeb" && password == "12345"){
		cout<<"Login successfully";
return true;
	}
	else {
		cout<<"Login failed";
		return false;
	}
	return false;
	}
	
	
};

const int MAX_SPORTS = 100;
class Sports {
	private:
    string sportsList[MAX_SPORTS];
  
    int sportsCount=0;
public:
    Sports()  {
	sportsCount=0;
	}
  
  void readFile(string sports){
  	 ofstream fout("sports.txt", ios::app);
      fout<<sports<<endl;  
      fout.close();
      
  }
    
 void   addSport() {
    if (sportsCount >= MAX_SPORTS) {
        cout << "Cannot add more sports, list is full." << endl;
        return;
    }
    string sport;
    cout << "Enter the name of the sport to add: ";
    cin>>sport; 
    
  		readFile(sport);
    sportsList[sportsCount++] = sport;
    cout << sport << " has been added." << endl;
}
void editSport() {
    int index;
    string newSport;
    displayAllSports();
    cout << "Enter the number of the sport to edit: ";
    cin >> index;
    if (index > 0 && index <= sportsCount) {
        cout << "Enter the new name of the sport: ";
        cin>>newSport;
        

        sportsList[index - 1] = newSport;
        cout << "Sport has been updated to " << newSport << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void deleteSport() {
    int index;
    displayAllSports();
    cout << "Enter the number of the sport to delete: ";
    cin >> index;
    if (index > 0 && index <= sportsCount) {
        for (int i = index - 1; i < sportsCount - 1; ++i) {
            sportsList[i] = sportsList[i + 1];
        }
        --sportsCount;
        cout << "Sport has been deleted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void displayAllSports() {
    if (sportsCount == 0) {
        cout << "No sports available." << endl;
    } else {
    	cout << "======= List of Sports ==========" << endl;
    	
        for (int i = 0; i < sportsCount; ++i) {
            cout << i + 1 << ". " << sportsList[i] << endl;
        }
        
        
    }
}
  
    
};

const int MAX_GROUNDS = 10;
class Grounds {
	private:
    string groundsList[MAX_SPORTS][2];
    int groundsCount;
    
public:
    Grounds() {
	 groundsCount=0;
	 }
  
    
 void   addGround() {
    if (groundsCount >= MAX_GROUNDS) {
        cout << "Cannot add more grounds, list is full." << endl;
        return;
    }
    string ground;
    cout << "Enter the name of the ground to add: ";
    cin>>ground;  // to clear the input buffer
   
    groundsList[groundsCount][0]= ground;
    groundsList[groundsCount][1]= "Available";
    groundsCount=groundsCount+1;
    cout << ground << " has been added." << endl;
}
void editGround() {
    int index;
    string newGround;
    displayAllGrounds();
    cout << "Enter the number of the ground to edit: ";
    cin >> index;
    if (index > 0 && index <= groundsCount) {
        cout << "Enter the new name of the ground: ";
        cin>>newGround;
       
       groundsList[index - 1][0] = newGround;
        cout << "Ground has been updated to " << newGround << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void deleteGround() {
    int index;
    displayAllGrounds();
    cout << "Enter the number of the ground to delete: ";
    cin >> index;
    if (index > 0 && index <= groundsCount) {
        for (int i = index - 1; i <groundsCount - 1; ++i) {
           groundsList[i][0] = groundsList[i + 1][0];
        }
        --groundsCount;
        cout << "Ground has been deleted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void reservedGround() {
    int index;
    string newGround;
    displayAllGrounds();
    cout << "Enter the number of the ground to reserved: ";
    cin >> index;
    if (index > 0 && index <= groundsCount) {
       
       groundsList[index - 1][1] =  "Reserved";
        cout <<   groundsList[index - 1][0] <<" Ground has been Reserved " << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void cancelReservedGround() {
    int index;
    string newGround;
    displayAllGrounds();
    cout << "Enter the number of the ground to cancel reservation: ";
    cin >> index;
    if (index > 0 && index <= groundsCount) {
        
       groundsList[index - 1][1] = "Available" ;
        cout <<  groundsList[index - 1][0] <<" Ground reservation has been cancelled " << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}


void displayAllGrounds() {
    if (groundsCount == 0) {
        cout << "No grounds available." << endl;
    } else {
    	cout << "======= List of grounds ==========" << endl;
    	
        for (int i = 0; i < groundsCount; ++i) {
            cout << i + 1 << ". " << groundsList[i][0] <<"-"<<groundsList[i][1]<< endl;
        }
    }
}



    
    
};

const int MAX_Inventory = 100;
class Inventory {
	
	private:
    int   inventoryCount;
public:
		string   inventoryList[MAX_Inventory][2];
     Inventory()  {
	inventoryCount=0;
	}
  
    
 void   addInventory() {
    if (inventoryCount >= MAX_Inventory) {
        cout << "Cannot add more Inventory, list is full." << endl;
        return;
    }
    string inventory,quantity;
    cout << "Enter the name of the inventory to add: ";
    cin>>inventory; 
	cout << "Enter the quantity of the inventory to add: ";
    cin>>quantity; 
     
  inventoryList[inventoryCount][0]=inventory;
   inventoryList[inventoryCount][1]=quantity;
    
    inventoryCount=inventoryCount+1;
    cout << inventory << " has been added." << endl;
}
void editInventory() {
    int index;
    string newInventory;
    
    displayAllInventory();
    cout << "Enter the number of the Inventory to edit: ";
    cin >> index;
    if (index > 0 && index <= inventoryCount) {
        cout << "Enter the new name of the Inventory: ";
        cin>>newInventory;


        inventoryList[index - 1][0] = newInventory;
        cout << "  Inventory has been updated to " << newInventory << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void deleteInventory() {
    int index;
    displayAllInventory();
    cout << "Enter the number of the Inventory to delete: ";
    cin >> index;
    if (index > 0 && index <= inventoryCount) {
        for (int i = index - 1; i < inventoryCount - 1; ++i) {
            inventoryList[i][0] = inventoryList[i + 1][0];
        }
        --  inventoryCount;
        cout << "  Inventory has been deleted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void displayAllInventory() {
    if (  inventoryCount == 0) {
        cout << "No   Inventory available." << endl;
    } else {
    	cout << "======= List of Inventory ==========" << endl;
    	
        for (int i = 0; i <  inventoryCount; ++i) {
            cout << i + 1 << ". " <<  inventoryList[i][0] << "--"<<   inventoryList[i][1] << endl;
        }
        
        
    }
}



    
  
    
};

const int MAX_Members = 100;
class Members {
	
	private:
    string   membersList[MAX_Members];
    string   membersListTest[MAX_Members][2];
    int   membersCount;
public:

     Members()  {
	membersCount=0;
	}
  
    
 void   addMember() {
    if (membersCount >= MAX_Members) {
        cout << "Cannot add more members, list is full." << endl;
        return;
    }
    string member;
    cout << "Enter the name of the member to add: ";
    cin>>member;  

    membersList[membersCount] = member;
    membersCount=membersCount+1;
    cout << member << " has been added." << endl;
}
void editMember() {
    int index;
    string newMember;
    displayAllMembers();
    cout << "Enter the number of the Member to edit: ";
    cin >> index;
    if (index > 0 && index <= membersCount) {
        cout << "Enter the new name of the Member: ";
        cin>>newMember;


        membersList[index - 1] = newMember;
        cout << "  member has been updated to " << newMember << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void deleteMember() {
    int index;
    displayAllMembers();
    cout << "Enter the number of the member to delete: ";
    cin >> index;
    if (index > 0 && index <= membersCount) {
        for (int i = index - 1; i < membersCount - 1; ++i) {
            membersList[i] = membersList[i + 1];
        }
        --  membersCount;
        cout << "  member has been deleted." << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}

void displayAllMembers() {
    if (  membersCount == 0) {
        cout << "No   members available." << endl;
    } else {
    	cout << "======= List of members ==========" << endl;
    	
        for (int i = 0; i <  membersCount; ++i) {
            cout << i + 1 << ". " <<   membersList[i] << endl;
        }
        
    }
    
    
    
    
}


void reservedInventory() {
    int index;
    int inventoryIndex;
      int inventoryQuantity;
    Inventory obj;
    obj.displayAllInventory();
    
    string newMember;
    displayAllMembers();
    
    cout << "Enter the number of the Member to borrow: ";
    cin >> index;
    if (index > 0 && index <= membersCount) {
        cout << "Enter the number of the inventory to borrow ";
        cin >> inventoryIndex;
        
        cout << "Enter the quantity of the inventory to borrow ";
         cin >> inventoryQuantity;
       // obj.inventoryList[index - 1][1]= stoi(obj.inventoryList[index - 1][1])-inventoryQuantity;
        
        //membersList[index - 1] = newMember;
        //cout << "  member has been updated to " << newMember << endl;
    } else {
        cout << "Invalid index!" << endl;
    }
}


    
    
    
};





int main(){
	
	Login objlogin;
bool login=	objlogin.doLogin();

int choice;
	if(login==true){
		jump:
		cout<<"Select among the following options 1 to 4" <<endl;
		cout<<"1. Sports"<<endl;
		cout<<"2. Grounds"<<endl;
		cout<<"3. Members"<<endl;
		cout<<"4.Inventory"<<endl;
		cin>>choice;
		
		switch(choice) {
  case 1:
  	{
  	Sports sports;
    int choice;

    while (true) {
    	
        cout << "Select among the following options 1 to 5" << endl;
        cout << "1. Add new Sports" << endl;
        cout << "2. Edit Sports" << endl;
        cout << "3. Delete Sports" << endl;
        
        cout << "4. Display All Sports" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                sports.addSport();
                break;
            case 2:
                sports.editSport();
                break;
            case 3:
                sports.deleteSport();
                break;
            case 4:
                sports.displayAllSports();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                goto jump;
                return 0;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
}
    break;
}
  case 2:
  	{
  	Grounds grounds;
    int choice;

    while (true) {
    	
        cout << "Select among the following options 1 to 7" << endl;
        cout << "1. Add new Grounds" << endl;
        cout << "2. Edit Grounds" << endl;
        cout << "3. Delete Grounds" << endl;
        cout << "4. Display All Grounds" << endl;
          cout << "5. Reserved Ground" << endl;
           cout << "6. Cancel Ground Reservation" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                grounds.addGround();
                break;
            case 2:
                grounds.editGround();
                break;
            case 3:
                grounds.deleteGround();
                break;
            case 4:
                grounds.displayAllGrounds();
                break;
                  case 5:
                grounds.reservedGround();
                break;
                 case 6:
                grounds.cancelReservedGround();
                break;
            case 7:
                cout << "Exiting the program." << endl;
                goto jump;
                return 0;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
}
    break;
}
     case 3:
     	
    	{
  	Members members;
    int choice;

    while (true) {
    	
        cout << "Select among the following options 1 to 6" << endl;
        cout << "1. Add new Members" << endl;
        cout << "2. Edit Members" << endl;
        cout << "3. Delete Members" << endl;
        
        cout << "4. Display All Members" << endl;
        cout << "5. Reserved Inventory" << endl;
        cout << "6. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                members.addMember();
                break;
            case 2:
                members.editMember();
                break;
            case 3:
                members.deleteMember();
                break;
            case 4:
                members.displayAllMembers();
                break;
                case 5:
                members.reservedInventory();
                break;
                
            case 6:
                cout << "Exiting the program." << endl;
                goto jump;
                return 0;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }
}
   
    break;
}

     case 4:
     	
    	{
  	Inventory inventory;
    int choice;

    while (true) {
    	
        cout << "Select among the following options 1 to 5" << endl;
        cout << "1. Add new Inventory" << endl;
        cout << "2. Edit Inventory" << endl;
        cout << "3. Delete Inventory" << endl;
        
        cout << "4. Display All Inventory" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addInventory();
                break;
            case 2:
                inventory.editInventory();
                break;
            case 3:
                inventory.deleteInventory();
                break;
            case 4:
                inventory.displayAllInventory();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                goto jump;
                return 0;
            default:
                cout << "Invalid choice! Please select again." << endl;
                break;
        }

}
    break;

}
  default:
  	cout<<"123";
  
}
	}
	
	return 1;

}


