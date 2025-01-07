#ifndef DEFAULTEMAILCHECKER_HPP
#define DEFAULTEMAILCHECKER_HPP

#include "Authorization/FieldCheck/FieldChecker.hpp"

class DefaultEmailChecker : public FieldChecker
{
public:
    DefaultEmailChecker();

    ~DefaultEmailChecker() = default;
};

#endif // DEFAULTEMAILCHECKER_HPP
