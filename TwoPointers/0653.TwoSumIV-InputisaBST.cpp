/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <coroutine>
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        auto iterator = [root](bool from_begin) -> Generator {
            std::stack<TreeNode*> paths;
            TreeNode* node = root;
            while (node || !paths.empty()) {
                while (node) {
                    paths.push(node);
                    node = from_begin ? node->left : node->right;
                }
                co_yield paths.top();
                node = from_begin ? paths.top()->right : paths.top()->left;
                paths.pop();
            }
        };

        Generator iter_from_begin = iterator(true);
        Generator iter_from_end = iterator(false);

        while (!iter_from_begin.done() && !iter_from_end.done()) {
            if (iter_from_begin.current_value() == iter_from_end.current_value()) {
                return false;
            }
            const int sum = iter_from_begin.current_value()->val + iter_from_end.current_value()->val;
            if (sum == k) {
                return true;
            }
            if (sum < k) {
                iter_from_begin.next();
            } else {
                iter_from_end.next();
            }
        }
        return false;
    }
private:
    class Generator {
    public:
        struct promise_type {
            Generator get_return_object() {
                return {std::coroutine_handle<promise_type>::from_promise(*this)};
            }

            std::suspend_never initial_suspend() noexcept { return {}; }
            std::suspend_always final_suspend() noexcept { return {}; }
            std::suspend_always yield_value(TreeNode* value) {
                current_value_ = value;
                return {};
            }
            void return_void() {}
            void unhandled_exception() {}

            TreeNode* current_value_ = nullptr;
        };

        Generator(Generator&& rhs) noexcept : coro_handle_(std::exchange(rhs.coro_handle_, {})) {}

        ~Generator() {
            if (coro_handle_) {
                coro_handle_.destroy();
            }
        }

        void next() { return coro_handle_.resume(); }
        bool done() { return coro_handle_.done(); }
        TreeNode* current_value() { return coro_handle_.promise().current_value_; }

    private:
        Generator(std::coroutine_handle<promise_type> h) : coro_handle_(h) {}
    
        std::coroutine_handle<promise_type> coro_handle_;
    };
};
