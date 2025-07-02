#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// ---------- tokenisation ----------
enum class TokType { NUM, OP, LP, RP };

struct Token {
    TokType type;
    std::string lex; // raw text
};

std::vector<Token> lex(const std::string& s) {
    std::vector<Token> out;
    for (size_t i = 0; i < s.size();) {
        if (std::isspace(s[i])) { ++i; continue; }

        if (std::isdigit(s[i])) {                 // number
            size_t j = i;
            while (j < s.size() && std::isdigit(s[j])) ++j;
            out.push_back({TokType::NUM, s.substr(i, j - i)});
            i = j;
        } else {
            char c = s[i++];
            if (c == '(')      out.push_back({TokType::LP, "("});
            else if (c == ')') out.push_back({TokType::RP, ")"});
            else               out.push_back({TokType::OP, std::string(1, c)});
        }
    }
    return out;
}

// ---------- precedence / associativity ----------
struct OpInfo { int prec; bool rightAssoc; };

const std::unordered_map<std::string, OpInfo> kOp =
{
    {"+",{2,false}}, {"-",{2,false}},
    {"*",{3,false}}, {"/",{3,false}}, {"%",{3,false}},
    {"^",{4,true}}
};

// ---------- shunting-yard core ----------
std::vector<Token> infixToPostfix(const std::vector<Token>& in)
{
    std::vector<Token> output;
    std::stack<Token>  opstack;

    for (const Token& t : in)
    {
        if (t.type == TokType::NUM) {
            output.push_back(t);                       // rule 1
        }
        else if (t.type == TokType::OP) {              // rule 2
            const auto& o1 = kOp.at(t.lex);
            while (!opstack.empty() && opstack.top().type == TokType::OP) {
                const auto& o2 = kOp.at(opstack.top().lex);
                bool higherPrec   = o2.prec > o1.prec;
                bool equalLeft    = o2.prec == o1.prec && !o1.rightAssoc;
                if (higherPrec || equalLeft) {
                    output.push_back(opstack.top());
                    opstack.pop();
                } else break;
            }
            opstack.push(t);
        }
        else if (t.type == TokType::LP) {              // rule 3
            opstack.push(t);
        }
        else if (t.type == TokType::RP) {              // rule 4
            while (!opstack.empty() && opstack.top().type != TokType::LP) {
                output.push_back(opstack.top());
                opstack.pop();
            }
            if (opstack.empty())
                throw std::runtime_error("Mismatched ')'");
            opstack.pop(); // discard '('
        }
    }

    // drain remainder
    while (!opstack.empty()) {
        if (opstack.top().type == TokType::LP)
            throw std::runtime_error("Mismatched '('");
        output.push_back(opstack.top());
        opstack.pop();
    }
    return output;
}

// ---------- driver / demo ----------
int main() {
    std::string line;
    std::cout << "Enter infix: ";
    std::getline(std::cin, line);

    try {
        auto tokens  = lex(line);
        auto postfix = infixToPostfix(tokens);

        std::cout << "Postfix: ";
        for (const auto& tk : postfix) std::cout << tk.lex << ' ';
        std::cout << '\n';
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << '\n';
    }
}
