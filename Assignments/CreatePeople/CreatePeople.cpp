#include <iostream>

using namespace std;

struct Person {
	char* name;
};

Person* CreatePerson();

int main() {
	int numberOfPeople{};
	cout << "How many people do you want to create?: ";
	cin >> numberOfPeople;

	Person** people = new Person*[numberOfPeople];

	for (int i = 0; i < numberOfPeople; ++i) {
		Person* person = CreatePerson();
		people[i] = person;
	}

	for (int i = 0; i < numberOfPeople-1; ++i) {
		Person person = *people[i];
		cout << person.name << ", ";
		delete people[i];
	}
	Person person = *people[numberOfPeople - 1];
	cout << person.name;
	delete people[numberOfPeople - 1];

	return 0;
}

Person* CreatePerson() {
	Person* person = new Person;

	char* name = new char[100];
	cout << "What's the next person supposed to be called?: ";
	cin >> name;

	person->name = name;
	return person;
}
