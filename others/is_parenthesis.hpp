#pragma once

#include <string>

/**
 * @brief 括弧列判定
 */
bool is_parenthesis(std::string& parenthesis) {
    int depth = 0;
    for (int i = 0; i < (int)(parenthesis.size()); i++) {
        if (parenthesis[i] == '(') depth++;
        if (parenthesis[i] == ')') depth--;
        if (depth < 0) return false;
    }
    return (depth == 0);
}
