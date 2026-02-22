// Contact.hpp

#include <string>
using namespace std;

class Contact {
public:
	Contact(const string& firstName,
		const string& lastName,
		const string& phoneNumber,
		const string& address);

	// Accessors

	const string& getContactID() const;
	const string& getFirstName() const;
	const string& getLastName() const;
	const string& getPhoneNumber() const;
	const string& getAddress() const;

	// Mutators
	void setFirstName(const string& firstName);
	void setLastName(const string& lastName);
	void setPhoneNumber(const string& phoneNumber);
	void setAddress(const string& address);

private:

	string contactID_;
	string firstName_;
	string lastName_;
	string phoneNumber_;
	string address_;

	static string normalizeName(const string& name); // For Null or truncates to 20 letters
	static string normalizePhoneNumber(const string& phoneNumber); // For Null, invalid, or not 10 digits
	static string normalizeAddress(const string& address); // For Null or truncates to 50 letters
};

