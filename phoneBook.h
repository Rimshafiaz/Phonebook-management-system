#include "contactBST.cpp"
template<class t>
class PhoneBook {
private:
    contactBST<t> contacts;
public:

    PhoneBook();
    ~PhoneBook();
    void addContact(const t& firstName, const t& lastName, const t& phoneNumber1, const t& phoneNumber2, const t& emailAddress);
    void removeContact(const t& firstName);
    void searchContactbyfirstname(const t& firstName);
    void searchContactbylastname(const t& lastName);
    void displayContacts();
    void displayContactswithdetails();
    void clearPhoneBook();
    void modifyContact(t firstName, t lastName, t newPhoneNumber1, t newPhoneNumber2, t newEmailAddress);
    void addToFavorites(const t& firstName);
    void displayFavorites();
};
