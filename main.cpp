#include "phoneBook.cpp"

int main() {
    PhoneBook<string> phoneBook;
    cout << "\n----------------CONTACT MANAGEMENT SYSTEM------------------" << endl;

    phoneBook.addContact("Mom","", "030504405050", "", "fatima22@gmail.com");
    phoneBook.addContact("Moiz", "Ahmed", "03090867550", "03044567756", "moizahmed@gmail.com");
    phoneBook.addContact("Zara", "Shokat", "03000867550", "03021567756", "zara67@gmail.com");
    phoneBook.addContact("Faiza", "Hussain", "03000869050", "", "faiza123@gmail.com");
    phoneBook.addContact("Dad", "", "03005050126", "", "dad123@gmail.com");
    cout << "      PHONE BOOK      " << endl;
    phoneBook.displayContacts();

    cout << "\n\n";
    cout << "Displaying all contants with their details" << endl;
    cout << "\n";

    phoneBook.displayContactswithdetails();
    cout << "\n\n";
    phoneBook.addToFavorites("Mom");
    phoneBook.addToFavorites("Dad");
    cout << "\n";

    cout << "      Favourites      " << endl;

    phoneBook.displayFavorites();

    cout << "\n\n";


    char choice;
    
    do {
       
        cout << "-----------------------MENU--------------------------" << endl;
        cout << "Enter 1 to insert contacts" << endl
            << "Enter 2 to search contact by first name" << endl
            << "Enter 3 to search contact by last name" << endl
            << "Enter 4 to update contact" << endl
            << "Enter 5 to delete contact" << endl
            << "Enter 6 to display all the contacts in the phonebook " << endl
            << "Enter 7 to mark your contacts as favourite " << endl
            << "Enter 8 to display your favourite contacts " << endl
            << "Enter 9 to display all the contacts with all of their details" << endl
            << "Enter 0 to exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == '1') {
            string firstName, lastName, phoneNumber1, phoneNumber2, emailAddress;
            cout << "\n---Enter contact details---" << endl;
            cout << "First Name: ";
            cin.ignore();
            getline(cin, firstName);
            cout << "Last Name: ";
            getline(cin, lastName);
            cout << "Phone Number: ";
            getline(cin, phoneNumber1);
            cout << "Phone Number: ";
            getline(cin, phoneNumber2);
            cout << "Email: ";
            getline(cin, emailAddress);
            phoneBook.addContact(firstName, lastName, phoneNumber1, phoneNumber2, emailAddress);
        }
        else if (choice == '2') {
            string firstName;
            cout << "\nEnter first name to search: ";
            cin >> firstName;
            phoneBook.searchContactbyfirstname(firstName);
        }
        else if (choice == '3') {
            string lastName;
            cout << "\nEnter last name to search: ";
            cin >> lastName;
            phoneBook.searchContactbylastname(lastName);
        }
        else if (choice == '4') {
            string firstName, lastName, phoneNumber1, phoneNumber2, emailAddress;
            cout << "\n---Enter contact details to modify if exists---" << endl;
            cout << "First Name: ";
            cin.ignore();
            getline(cin, firstName);
            cout << "Last Name: ";
            getline(cin, lastName);
            cout << "Phone Number: ";
            getline(cin, phoneNumber1);
            cout << "Phone Number: ";
            getline(cin, phoneNumber2);
            cout << "Email: ";
            getline(cin, emailAddress);
            phoneBook.modifyContact(firstName, lastName, phoneNumber1, phoneNumber2, emailAddress);

        }
        else if (choice == '5') {
            string firstName;
            cout << "\nEnter first name to Delete: ";
            cin >> firstName;
            phoneBook.removeContact(firstName);
        }
        else if (choice == '6') {
            phoneBook.displayContacts();

        }
        else if (choice == '7') {
            string firstName;
            cout << "\nEnter first name of contact to mark as favorite: ";
            cin >> firstName;
            phoneBook.addToFavorites(firstName);
        }
        else if (choice == '8') {
            cout << "      Favourites      " << endl<<endl;

            phoneBook.displayFavorites();

        }
        else if (choice == '9') {

            phoneBook.displayContactswithdetails();

        }
        else if (choice == '0') {
            cout << "---Exiting---" << endl;
        }
        else {
            cout << "Invalid choice. Do you want to enter a valid choice (Y/N)? ";
            char response;
            cin >> response;
            if (response != 'Y' && response != 'y') {
                choice = '0'; 
            }
        }
       
    } while (choice != '0');

    return 0;
}