// ContactService.cpp

#include "ContactService.hpp"


string ContactService::addContact(const string& firstName,
	const string& lastName,
	const string& number,
	const string& address) {
	Contact c(firstName, lastName, number, address);
	contacts_.emplace(c.getContactID(), c); // Insert contact into the unordered map with contactID as the key
	return c.getContactID();
}

void ContactService::deleteContact(const string& contactID) {
	if (contacts_.erase(contactID) == 0) { // erase returns the number of elements removed, which will be 0 if the contactID was not found
		throw NotFoundError("Contact with ID " + contactID + " not found.");
		}
	}


Contact& ContactService::findOrThrow(const string& contactID) {
	auto it = contacts_.find(contactID);
	if (it == contacts_.end()) {
		throw NotFoundError("Contact with ID " + contactID + " not found.");
	}
	return it->second;
}

const Contact& ContactService::findOrThrow(const string& contactID) const {
	auto it = contacts_.find(contactID);
	if (it == contacts_.end()) {
		throw NotFoundError("Contact with ID " + contactID + " not found.");
	}
	return it->second;
}

void ContactService::updateFirstName(const string& contactID, const string& updated) {
	Contact& contact = findOrThrow(contactID);
	contact.setFirstName(updated);
}

void ContactService::updateLastName(const string& contactID, const string& updated) {
	Contact& contact = findOrThrow(contactID);
	contact.setLastName(updated);
}

void ContactService::updatePhoneNumber(const string& contactID, const string& updated) {
	Contact& contact = findOrThrow(contactID);
	contact.setPhoneNumber(updated);
}

void ContactService::updateAddress(const string& contactID, const string& updated) {
	Contact& contact = findOrThrow(contactID);
	contact.setAddress(updated);
}

const Contact& ContactService::getContactorThrow(const string& contactID) const {
	return findOrThrow(contactID);
}

size_t ContactService::size() const {
	return contacts_.size();
}