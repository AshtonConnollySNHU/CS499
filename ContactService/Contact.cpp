// Contact.cpp

#include "Contact.hpp"
#include "HashUtil.hpp"
#include <chrono>
#include <random>

#include <atomic>


namespace {  // C++ version of AtomicLong
	atomic<long long> g_idCounter{ 0 };

	bool isEmpty(const string& s) {
		return s.empty();
	}
}


Contact::Contact(const string& firstName,
	const string& lastName,
	const string& phoneNumber,
	const string& address)

{
	auto counter = g_idCounter.fetch_add(1); // Generate unique ID through incrementation.

	auto now = chrono::high_resolution_clock::now().time_since_epoch().count();
	random_device rd;
	auto salt = rd();

	string raw = to_string(counter) + to_string(now) + to_string(salt);

	contactID_ = HashUtil::sha256Hex(raw); // Generate unique ID using SHA-256 hash of the combined string.


	firstName_ = normalizeName(firstName);
	lastName_ = normalizeName(lastName);
	phoneNumber_ = normalizePhoneNumber(phoneNumber);
	address_ = normalizeAddress(address); // Fixed typo from Java
}

// Accessors
const string& Contact::getContactID() const {
	return contactID_;
}

const string& Contact::getFirstName() const {
	return firstName_;
}

const string& Contact::getLastName() const {
	return lastName_;
}

const string& Contact::getPhoneNumber() const {
	return phoneNumber_;
}

const string& Contact::getAddress() const {
	return address_;
}

// Mutators
void Contact::setFirstName(const string& firstName) {
	firstName_ = normalizeName(firstName);
}

void Contact::setLastName(const string& lastName) {
	lastName_ = normalizeName(lastName);
}

void Contact::setPhoneNumber(const string& phoneNumber) {
	phoneNumber_ = normalizePhoneNumber(phoneNumber);
}

void Contact::setAddress(const string& address) {
	address_ = normalizeAddress(address);
}

// Validation rules (Matching Java implementation for easy translation will be modified in the future).

string Contact::normalizeName(const string& s) {
	if (isEmpty(s)) return "NULL";
	if (s.size() > 20) return s.substr(0, 20);
	return s;
}

string Contact::normalizePhoneNumber(const string& s) {
	if (isEmpty(s) || s.size() != 10) return "0000000000";
	return s;
}

string Contact::normalizeAddress(const string& s) {
	if (isEmpty(s)) return "NULL";
	if (s.size() > 50) return s.substr(0, 50);
	return s;
}
