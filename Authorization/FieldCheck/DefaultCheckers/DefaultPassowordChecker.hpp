#ifndef DEFAULTPASSOWORDCHECKER_HPP
#define DEFAULTPASSOWORDCHECKER_HPP

#include "Authorization/FieldCheck/FieldChecker.hpp"

class DefaultPassowordChecker : public FieldChecker
{
public:
    DefaultPassowordChecker();

    ~DefaultPassowordChecker() = default;
};

#endif // DEFAULTPASSOWORDCHECKER_HPP
