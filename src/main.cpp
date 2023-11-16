#include <credit_card/credit_card.hpp>
#include <iostream>
#include <list>
#include <memory>

using namespace std;

template<typename T>
void swapOwners(T* first_owner, T* second_owner) {
    T* temp = first_owner;
    first_owner = second_owner;
    second_owner = temp;
}

int main() {
    // using the normal constructor
    credit_card::CreditCard<char> ingCard(
        "1111 2222 3333 4444",
        "08/27",
        "Costel",
        "000"
    );
    cout<<"The owner of the ingCard is: "<<ingCard.get_owner()<<endl;
    // using the copy constructor
    credit_card::CreditCard bcrCard = ingCard;
    cout<<"The owner of the bcrCard is: "<<bcrCard.get_owner()<<endl;

    credit_card::CreditCard<char> brdCard(
        "4444 3333 2222 1111",
        "07/26",
        "Marian",
        "000"
    );
    // using the overloaded assignment operator ( = )
    bcrCard = brdCard;
    cout<<"The new owner of the bcrCard is: "<<bcrCard.get_owner()<<endl;
    // using the move constructor
    credit_card::CreditCard movedCard(move(ingCard));
    cout << "The owner of the moved card is: " << movedCard.get_owner() << endl;

    // swaping the owners
    cout << "Current owners: BCR - " << bcrCard.get_owner() << ", ING - " << ingCard.get_owner() << endl;
    swapOwners(bcrCard.get_owner(), ingCard.get_owner());
    cout << "Current owners: BCR - " << bcrCard.get_owner() << ", ING - " << ingCard.get_owner() << endl;

    // creating a list
    list<credit_card::CreditCard<char>> myList;
    myList.push_back(bcrCard);
    myList.push_back(ingCard);
    cout << "Elements in the list have the following numbers: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        cout << *it->get_number() << endl;
    }

    // using an unique pointer
    if(true) {
        cout << "By being fancy, I can tell the bcrCard has the following owner by talking to someone who knows him: ";
        unique_ptr<credit_card::CreditCard<char>> ptr(&bcrCard);
        cout << ptr->get_owner() << endl;
    }

    // unfortunately, the bcrCard is deleted now
    shared_ptr<credit_card::CreditCard<char>> ptr1(&ingCard);
    shared_ptr<credit_card::CreditCard<char>> ptr2 = ptr1;

    cout << "Lastly, the ingCard is owned by the same guy twice! " << ptr1->get_owner() << " and " << ptr2->get_owner();

    return 0;
}