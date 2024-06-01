#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class t>
class contactNode {
public:
    t firstName;
    t lastName;
    t phoneNumber1;
    t phoneNumber2;
    t emailAddress;
    contactNode<t>* left;
    contactNode<t>* right;
    contactNode();
    contactNode(t fn, t ln, t num1, t num2, t email);
    contactNode(const contactNode<t>& other);
    ~contactNode();
    bool validateData(t fn, t ln, t num1, t num2, t email);
    bool isValidPhoneNumber(const t& phoneNumber);
    bool isEmpty(const t& str);

};