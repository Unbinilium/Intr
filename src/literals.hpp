#pragma once

#include <iostream>

#include "types.hpp"

namespace intr::literals {

using namespace intr::types;

std::ostream& operator<<(std::ostream& os, TokenType token_type) {
    switch (token_type) {
    case TokenType::IDENTIFIER:
        return os << "Identifier";
    case TokenType::CONSTANT:
        return os << "Constant";
    case TokenType::OPERATOR:
        return os << "Operator";
    case TokenType::LPARN:
        return os << "Left Parenthesis";
    case TokenType::RPARN:
        return os << "Right Parenthesis";
    case TokenType::FUNCTION:
        return os << "Function";
    case TokenType::TERM:
        return os << "Terminator";
    default:
        return os << static_cast<int>(token_type);
    };
}

}  // namespace intr::literals
