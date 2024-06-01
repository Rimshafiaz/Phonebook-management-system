#include "contactNode.cpp"
template <class t>
class contactBST {
private:
	contactNode<t>* root;
	contactNode<t>* favoritesRoot;
	contactNode<t>* insertNode(contactNode<t>* root, t fn, t ln, t num1, t num2, t email);
	contactNode<t>* deleteNode(contactNode<t>* root, t fn);
	contactNode<t>* searchNodebyfirstname(contactNode<t>* root, t fn);
	contactNode<t>* searchNodebylastname(contactNode<t>* root, t ln);


	contactNode<t>* minNode(contactNode<t>* root);
	bool BSTisEmpty()const;
public:
	contactBST();
	~contactBST();
	void insertContact(t fn, t ln, t num1, t num2, t email);
	void deleteContact(t fn);
	contactNode<t>* searchContactbyfirstname(t fn);
	contactNode<t>* searchContactbylastname(t ln);

	void inorderTraversal(contactNode<t>* root);
	void inorderTraversalforphonebook(contactNode<t>* root);
	void displayContacts();
	void displayContactswithdetails();

	void clear(contactNode<t>* node);
	contactNode<t>* getRoot() const;
	void updateContact(t firstName, t lastName, t newPhoneNumber1, t newPhoneNumber2, t newEmailAddress);
	void addToFavorites(const t& firstName);
	void displayFavorites();
};