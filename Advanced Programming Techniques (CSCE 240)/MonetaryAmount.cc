// MonetaryAmount.cc

#include "MonetaryAmount.h"

bool MonetaryAmount::display_unit_name = false;

MonetaryAmount::MonetaryAmount(double val, const MonetaryUnit& u) : value(val), unit(u) {}

double MonetaryAmount::GetValue() const {
    return value;
}

MonetaryUnit MonetaryAmount::GetUnit() const {
    return unit;
}

void MonetaryAmount::ConvertToUnit(const MonetaryUnit& newUnit) {
    value *= unit.GetAmountEquivalentTo1Dollar() / newUnit.GetAmountEquivalentTo1Dollar();
    unit = newUnit;
}

bool MonetaryAmount::operator==(const MonetaryAmount& other) const {
    return value == other.value && unit == other.unit;
}

bool MonetaryAmount::operator<(const MonetaryAmount& other) const {
    return value < other.value;
}

bool MonetaryAmount::operator>(const MonetaryAmount& other) const {
    return value > other.value;
}

std::ostream& operator<<(std::ostream& os, const MonetaryAmount& ma) {
    if (MonetaryAmount::display_unit_name) {
        os << ma.value << " " << ma.unit.GetName();
    } else {
        os << ma.unit.GetSymbol() << ma.value;
    }
    return os;
}

MonetaryAmount operator+(const MonetaryAmount& lhs, const MonetaryAmount& rhs) {
    if (lhs.unit == rhs.unit) {
        return MonetaryAmount(lhs.value + rhs.value, lhs.unit);
    } else {
        // You may want to handle this case differently based on specifications
        return MonetaryAmount();
    }
}
