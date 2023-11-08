#ifndef CREDIT_CARD_HPP
#define CREDIT_CARD_HPP
#include <payment_method/payment_method.hpp>

namespace credit_card {

class CreditCard : public payment_method::PaymentMethod{
private:
    char* number;
    char* expiry_date;
    char* owner;
    char* cvv;

public:
    CreditCard(const char* given_number, const char* given_expiry_date, const char* given_owner, const char* given_cvv);  

    ~CreditCard();

    CreditCard(const CreditCard& another_card);

    CreditCard& operator=(const CreditCard& another_card);

    CreditCard* move(CreditCard&& other);

public:
    char* get_number() override;

    char* get_expiry_date() override;

    char* get_owner() override;

    char* get_cvv() override;
};

} // namespace credit_card

#endif



