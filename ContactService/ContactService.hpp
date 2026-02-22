// ContactService.hpp

#include "Contact.hpp"
#include "Exceptions.hpp"
#include <unordered_map> // Changed from <vector> to <unordered_map> for better performance in lookups
#include <string>
using namespace std;

class ContactService {
public:
	string addContact(const string& firstName,
		const string& lastName,
		const string& number,
		const string& address);

	void deleteContact(const string& contactID);

	void updateFirstName(const string& contactID, const string& updated);
	void updateLastName(const string& contactID, const string& updated);
	void updatePhoneNumber(const string& contactID, const string& updated);
	void updateAddress(const string& contactID, const string& updated);


	//Contact test & throw
	const Contact& getContactorThrow(const string& contactID) const; // throws ContactNotFoundException
	size_t size() const;

private:
	unordered_map<string, Contact> contacts_; // New Unordered Map to store contacts by their ID for O(1) average time complexity in lookups

	Contact& findOrThrow(const string& contactID); // throws ContactNotFoundException
	const Contact& findOrThrow(const string& contactID) const; // throws ContactNotFoundException
};

