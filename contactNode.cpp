#include "contactNode.h"
template <class t>
contactNode<t>::contactNode() {
	left = nullptr;
	right = nullptr;
}
template <class t>
contactNode<t>::contactNode(t fn, t ln, t num1, t num2, t email) {
	firstName = fn;
	lastName = ln;
	phoneNumber1 = num1;
	phoneNumber2 = num2;
	emailAddress = email;
	left = nullptr;
	right = nullptr;
	if (num2.empty()) {
		phoneNumber2 = "";
	}
}
template <class t>
contactNode<t>::contactNode(const contactNode<t>& other) {
	firstName = other.firstName;
	lastName = other.lastName;
	phoneNumber1 = other.phoneNumber1;
	phoneNumber2 = other.phoneNumber2;
	emailAddress = other.emailAddress;
	left = nullptr;
	right = nullptr;
}
template <class t>
contactNode<t>::~contactNode() {

}
template <class t>
bool contactNode<t>::isEmpty(const t& str) {
	return str.empty();

}
template <class t>
bool contactNode<t>::isValidPhoneNumber(const t& phoneNumber) {
	if (phoneNumber.length() != 11) {
		return false;
	}

	for (int i = 0; i < phoneNumber.length(); i++) {
		if (!isdigit(phoneNumber[i])) {
			return false;
		}
	}

	return true;


}

template <class t>
bool contactNode<t>::validateData(t fn, t ln, t num1, t num2, t email) {
	if (isEmpty(fn) || isEmpty(num1) || !isValidPhoneNumber(num1) ||
		(!isEmpty(num2) && !isValidPhoneNumber(num2))) {
		return false;
	}
	return true;
}