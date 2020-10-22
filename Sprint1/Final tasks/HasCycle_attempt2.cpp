#include "solution.h"

using namespace std;

bool HasCycle(std::shared_ptr<Node> head) {
    std::shared_ptr<Node> fast_runner = head;
    std::shared_ptr<Node> slow_runner = head;

    while (!fast_runner->next.expired() && !fast_runner->next.lock()->next.expired()) {
        fast_runner = fast_runner->next.lock()->next.lock();
        slow_runner = slow_runner->next.lock();
        if (fast_runner == slow_runner) {
            return true;
        }
    }
    return false;
}