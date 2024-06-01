#include "phoneBook.h"
template<class t>
PhoneBook<t>::PhoneBook() {}

template<class t>
PhoneBook<t>::~PhoneBook() {}


template<class t>
void PhoneBook<t>::addContact(const t& firstName, const t& lastName, const t& phoneNumber1, const t& phoneNumber2, const t& emailAddress) {
    contacts.insertContact(firstName, lastName, phoneNumber1, phoneNumber2, emailAddress);
}

template<class t>
void PhoneBook<t>::removeContact(const t& firstName) {
    contacts.deleteContact(firstName);
}
template<class t>
void PhoneBook<t>::searchContactbyfirstname(const t& firstName) {
    contactNode<t>* contact = contacts.searchContactbyfirstname(firstName);
    if (contact != nullptr) {
       cout << "Contact Found" << endl;
       cout << "First Name: " << contact->firstName << endl;
       cout << "Last Name: " << contact->lastName << endl;
        cout << "Phone Number 1: " << contact->phoneNumber1 << endl;
        cout << "Phone Number 2: " << contact->phoneNumber2 << endl;
         cout << "Email Address: " << contact->emailAddress << endl;
    }
    else {
        cout << "Contact not found." << endl;
    }
}
template<class t>
void PhoneBook<t>::searchContactbylastname(const t& lastName) {
    contactNode<t>* contact = contacts.searchContactbylastname(lastName);
    if (contact != nullptr) {
        cout << "Contact Found" << endl;
        cout << "First Name: " << contact->firstName << endl;
        cout << "Last Name: " << contact->lastName << endl;
        cout << "Phone Number 1: " << contact->phoneNumber1 << endl;
        cout << "Phone Number 2: " << contact->phoneNumber2 << endl;
        cout << "Email Address: " << contact->emailAddress << endl;
    }
    else {
        cout << "Contact not found." << endl;
    }
}

template<class t>
void PhoneBook<t>::displayContacts() {
    contacts.displayContacts();
}


template<class t>
void PhoneBook<t>::clearPhoneBook() {
    contacts.clear(contacts.getRoot());
}

template<class t>
void PhoneBook<t>::modifyContact(t firstName, t lastName, t newPhoneNumber1, t newPhoneNumber2, t newEmailAddress) {
    contacts.updateContact(firstName, lastName, newPhoneNumber1, newPhoneNumber2, newEmailAddress);
}


template<class t>
void PhoneBook<t>::addToFavorites(const t& firstName) {
    contacts.addToFavorites(firstName);
}
template<class t>
void PhoneBook<t>::displayFavorites() {
    contacts.displayFavorites();
}



template<class t>
void PhoneBook<t>::displayContactswithdetails() {
    contacts.displayContactswithdetails();
}