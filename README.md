# Intr

A simple interpreter writtern in C++.

```cpp
#include <iostream>
#include <fmt/format.h>

#include "lexer.hpp"
#include "literals.hpp"
#include "nodes.hpp"
#include "parser.hpp"

using namespace intr;
using namespace intr::literals;

int main() {
    std::string input = "1 + 7 + (3 * (1 + 5)) + abs(-1) - pow(2, 3)";

    {
        Lexer lexer(input);
        while (1) {
            if (const Token& token = lexer.get_next_token(); token.type != TokenType::TERM)
                std::cout << "Type: " << token.type << ", Value: " << token.value << std::endl;
            else break;
        }
    }

    Mutables fvmap{};
    Lexer    lexer{input};
    Parser   parser{lexer, fvmap};

    ASTNode* root = parser.parse();
    if (!root) {
        fmt::println("Parsing expression {} failed!", input);
        return 0;
    }

    Result res = root->evaluate([&](NodeType, const std::string& str) -> Result {
        fmt::println("Node: {} -> {}", []{ static size_t i{0}; return ++i; }(), str);
        return Result{.status = EvalStatus::OK, .value = 0};
    });
    delete root;

    if (res.status == EvalStatus::OK) fmt::println("Result: {}", res.value);

    return 0;
}
```
