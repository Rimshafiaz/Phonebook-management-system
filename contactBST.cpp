#include "contactBST.h"
template <class t>
contactBST<t>::contactBST() {
    root = nullptr;
    favoritesRoot = nullptr;
}
template <class t>
contactBST<t>::~contactBST() {
}
template <class t>
bool contactBST<t>::BSTisEmpty() const {
    return root == nullptr;
}
template <class t>
contactNode<t>* contactBST<t>::insertNode(contactNode<t>* root, t fn, t ln, t num1, t num2, t email) {
    if (root == nullptr) {
        contactNode<t>* newNode = new contactNode<t>(fn, ln, num1, num2, email);
        return newNode;
    }

    if (fn >= root->firstName) {
        root->right = insertNode(root->right, fn, ln, num1, num2, email);
    }
    else if (fn < root->firstName) {
        root->left = insertNode(root->left, fn, ln, num1, num2, email);
    }
    else {
        cout << "---Contact with the same last name already exists---" << endl;
       
    }

    return root;
}
template <class t>
contactNode<t>* contactBST<t>::deleteNode(contactNode<t>* root, t fn) {

    if (root == nullptr) {
        return root;
    }

    if (fn < root->firstName) {
        root->left = deleteNode(root->left, fn);
    }
    else if (fn > root->firstName) {
        root->right = deleteNode(root->right, fn);
    }
    else {
        if (root->left == nullptr) {
            contactNode<t>* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            contactNode<t>* temp = root->left;
            delete root;
            return temp;
        }

        contactNode<t>* temp = minNode(root->right);

        root->firstName = temp->firstName;
        root->lastName = temp->lastName;
        root->phoneNumber1 = temp->phoneNumber1;
        root->phoneNumber2 = temp->phoneNumber2;
        root->emailAddress = temp->emailAddress;

        root->right = deleteNode(root->right, temp->firstName);
    }

    return root;

}

template <class t>
contactNode<t>* contactBST<t>::minNode(contactNode<t>* root) {
    contactNode<t>* current = root;

    while (current && current->left != nullptr) {
        current = current->left;
    }

    return current;
}
template <class t>
contactNode<t>* contactBST<t>::searchNodebyfirstname(contactNode<t>* root, t fn) {
    if (root != nullptr)
    {
        if (fn == root->firstName)
            return root;
        if (fn < root->firstName)
            return searchNodebyfirstname(root->left, fn);
        else
            return searchNodebyfirstname(root->right, fn);
    }
    else {
        return nullptr;

    }
}

template <class t>
contactNode<t>* contactBST<t>::searchNodebylastname(contactNode<t>* root, t ln) {
    if (root != nullptr)
    {
        if (ln == root->lastName)
            return root;
        if (ln < root->firstName)
            return searchNodebylastname(root->left, ln);
        else
            return searchNodebylastname(root->right, ln);
    }
    else {
        return nullptr;

    }
}


template <class t>
void contactBST<t>::inorderTraversal(contactNode<t>* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << "First Name: " << root->firstName << endl;
        cout << "Last Name: " << root->lastName << endl;
        cout << "phone number1: " << root->phoneNumber1 << endl;
        cout << "phone number2: " << root->phoneNumber2 << endl;
        cout << "Email Address: " << root->emailAddress << endl;
        cout << endl;
        inorderTraversal(root->right);
    }
}

template <class t>
void contactBST<t>::inorderTraversalforphonebook(contactNode<t>* root) {
    if (root != nullptr) {
        inorderTraversalforphonebook(root->left);
        cout << root->firstName << " "<<root->lastName << endl;

        inorderTraversalforphonebook(root->right);
    }
}
template <class t>
void contactBST<t>::insertContact(t fn, t ln, t num1, t num2, t email) {
    root = insertNode(root, fn, ln, num1, num2, email);

}


template <class t>
void contactBST<t>::deleteContact(t fn) {
    root = deleteNode(root, fn);
}

template <class t>
contactNode<t>* contactBST<t>::searchContactbyfirstname(t fn) {
    return searchNodebyfirstname(root, fn);
}
template <class t>
contactNode<t>* contactBST<t>::searchContactbylastname(t ln) {
    return searchNodebylastname(root, ln);
}


template <class t>
void contactBST<t>::displayContacts() {
    inorderTraversalforphonebook(root);
}

template <class t>
void contactBST<t>::displayContactswithdetails() {
    inorderTraversal(root);
}
template <class t>
void contactBST<t>::clear(contactNode<t>* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

template <class t>
contactNode<t>* contactBST<t>::getRoot() const {
    return root;
}

template <class t>
void contactBST<t>::updateContact(t firstName, t newlastName, t newPhoneNumber1, t newPhoneNumber2, t newEmailAddress) {
    contactNode<t>* contactToUpdate = searchNodebyfirstname(root, firstName);
    if (contactToUpdate != nullptr) {
        contactToUpdate->lastName = newlastName;
        contactToUpdate->phoneNumber1 = newPhoneNumber1;
        contactToUpdate->phoneNumber2 = newPhoneNumber2;
        contactToUpdate->emailAddress = newEmailAddress;

        cout << "Contact updated successfully." << endl;
    }
    else {
        cout << "Contact not found. Unable to update." << endl;
    }

}


template<class t>
void contactBST<t>::addToFavorites(const t& firstName) {
    contactNode<t>* contactToAdd = searchNodebyfirstname(root, firstName);
    if (contactToAdd != nullptr) {
        favoritesRoot = insertNode(favoritesRoot, firstName, contactToAdd->lastName, contactToAdd->phoneNumber1, contactToAdd->phoneNumber2, contactToAdd->emailAddress);
        cout << "Contact '" << firstName << "' added to favorites." << endl;
    }
    else {
        cout << "Contact '" << firstName << "' not found. Unable to add to favorites." << endl;
    }
}

template<class t>
void contactBST<t>::displayFavorites() {
    if (favoritesRoot != nullptr) {
        inorderTraversalforphonebook(favoritesRoot);
    }
    else {
        cout << "No favorite contacts found." << endl;
    }
}

