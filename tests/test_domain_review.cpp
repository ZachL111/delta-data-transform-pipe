#include "domain_review.hpp"
#include <cassert>

int main() {
    DomainReview item{46, 23, 27, 77};
    assert(domain_review_score(item) == 111);
    assert(domain_review_lane(item) == "watch");
}
