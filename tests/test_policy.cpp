#include "policy.hpp"
#include <cassert>

int main() {
    Signal signal_case_1{60, 81, 9, 14, 4};
    assert(score_signal(signal_case_1) == 119);
    assert(classify_signal(signal_case_1) == "review");
    Signal signal_case_2{64, 80, 22, 15, 13};
    assert(score_signal(signal_case_2) == 139);
    assert(classify_signal(signal_case_2) == "review");
    Signal signal_case_3{75, 87, 9, 19, 5};
    assert(score_signal(signal_case_3) == 130);
    assert(classify_signal(signal_case_3) == "review");
}
