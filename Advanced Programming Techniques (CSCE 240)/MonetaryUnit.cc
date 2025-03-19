//copyright crb27 2024
// MonetaryUnit.cc

#include "MonetaryUnit.h"

MonetaryUnit::MonetaryUnit(const std::string& n, const std::string& s, double amount) : 
    name(n), symbol(s), amountEquivalentTo1Dollar(amount) {}

const std::string& MonetaryUnit::GetName() const {
    return name;
}

const std::string& MonetaryUnit::GetSymbol() const {
    return symbol;
}

double MonetaryUnit::GetAmountEquivalentTo1Dollar() const {
    return amountEquivalentTo1Dollar;
}

bool MonetaryUnit::operator==(const MonetaryUnit& other) const {
    return name == other.name && symbol == other.symbol && amountEquivalentTo1Dollar == other.amountEquivalentTo1Dollar;
}
