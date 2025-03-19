//copyright crb27 2024
// MonetaryUnit.h

#ifndef MONETARY_UNIT_H
#define MONETARY_UNIT_H

#include <string>

class MonetaryUnit {
private:
    std::string name;
    std::string symbol;
    double amountEquivalentTo1Dollar;

public:
    MonetaryUnit(const std::string& n = "US dollars", const std::string& s = "$", double amount = 1.0);
    const std::string& GetName() const;
    const std::string& GetSymbol() const;
    double GetAmountEquivalentTo1Dollar() const;
    bool operator==(const MonetaryUnit& other) const;
};

#endif // MONETARY_UNIT_H
