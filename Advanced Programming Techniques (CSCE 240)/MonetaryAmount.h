// MonetaryAmount.h

#ifndef MONETARY_AMOUNT_H
#define MONETARY_AMOUNT_H

#include "MonetaryUnit.h"
#include <iostream>

class MonetaryAmount {
private:
    double value;
    MonetaryUnit unit;
    static bool display_unit_name;

public:
    MonetaryAmount(double val = 0.0, const MonetaryUnit& u = MonetaryUnit("US dollars", "$", 1));
    double GetValue() const;
    MonetaryUnit GetUnit() const;
    void ConvertToUnit(const MonetaryUnit& newUnit);

    // Overloaded operators
    bool operator==(const MonetaryAmount& other) const;
    bool operator<(const MonetaryAmount& other) const;
    bool operator>(const MonetaryAmount& other) const;

    friend std::ostream& operator<<(std::ostream& os, const MonetaryAmount& ma);
    friend MonetaryAmount operator+(const MonetaryAmount& lhs, const MonetaryAmount& rhs);
};

#endif // MONETARY_AMOUNT_H
