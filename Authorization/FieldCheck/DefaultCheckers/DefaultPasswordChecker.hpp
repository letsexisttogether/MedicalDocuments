#ifndef DEFAULTPASSOWORDCHECKER_HPP
#define DEFAULTPASSOWORDCHECKER_HPP

#include "Authorization/FieldCheck/FieldChecker.hpp"

class DefaultPasswordChecker : public FieldChecker
{
public:
    DefaultPasswordChecker();

    ~DefaultPasswordChecker() = default;
};

#endif // DEFAULTPASSOWORDCHECKER_HPP
