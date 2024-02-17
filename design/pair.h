#pragma once

namespace dsac::design {

template <typename A, typename B>
class pair {
  public:
    A first;
    B second;

    pair() {}

    pair(const A& a, const B& b) : first(a), second(b) {}
    
    bool operator==(const pair& other) const {
        return first == other.first && second == other.second;
    }

    bool operator!=(const pair& other) const {
        return !operator==(other);              // the opposite of ==
    }

    bool operator<(const pair& other) const {
        return (first < other.first ||
                (first == other.first && second < other.second));
    }
};

}  // namespace dsac::design
