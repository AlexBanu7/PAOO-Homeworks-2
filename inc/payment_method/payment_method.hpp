#ifndef PAYMENT_METHOD_HPP
#define PAYMENT_METHOD_HPP

namespace payment_method {

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;
    virtual char* get_number() = 0;
    virtual char* get_expiry_date() = 0;
    virtual char* get_owner() = 0;
    virtual char* get_cvv() = 0;
};

} // namespace payment_method

#endif