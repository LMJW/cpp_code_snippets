#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;

/**
 * Contain:
 * - example of using `map`
 * - example of implementing `trie`
 * - example of constructor of struct
 * - example of char-> string using string `=` operator overloading
 * - example of creating object on heap memory `new`
 * - example of recursive lambda expression
 */

struct tnode
{
    /// Declare variable
    string _val;
    map<string, tnode *> _children;

    /// constructor
    /// _val{} equivalent to _val("")
    /// Default constructor
    tnode() : _val{}, _children{} {}

    /// constructor with one argument
    tnode(string v) : _val(v), _children{} {}

    /// Declare method
    void insert(string word)
    {
        tnode *cur = this;
        /// Declare a string type as let with default initialization as empty string
        string let{};
        for (int i = 0; i < word.size(); i++)
        {
            let = word[i]; // string =operator will overload char to string
            /// pointer's attribute can be accessed using '->'
            /// normal object's attribute can be accessed using '.'
            if (cur->_children.find(let) == cur->_children.end())
            {
                cur->_children[let] = new tnode(let);
            }
            cur = cur->_children[let];
        }
        /// using new to create a new tnode on heap memory
        /// can cause memory leak
        cur->_children["*"] = new tnode("*");
    }
};

class Solution
{
public:
    /// const declares the method will not change the internal state of
    /// object. if no const is declared, the 'const Solution v; v.longestWord("abc")
    /// will cause compile error
    string longestWord(vector<string> &words) const
    {
        // {} default initialize
        tnode root{}; // initialize the struct parameter as default type value

        for (auto e : words)
        {
            root.insert(e);
        }

        string ans{};
        /// void is the function return
        /// tnode* is the first argument
        /// string is the second argument

        /// this is how we create a recursive lambda function
        function<void(tnode *, string)> dfs;

        /// inside [...] is the parameter that will be captured by
        /// the lambda function, &ans means the reference of ans is passed
        /// to the lambda function so it can be modified

        /// the function itself &dfs will also need to be captured
        dfs = [&ans, &dfs](tnode *n, string path) {
            // cout << ans << "|" << path << endl;

            for (auto it = n->_children.begin(); it != n->_children.end(); it++)
            {
                /// if the current node is a termination node,
                /// meaning it act as the last letter of one word
                if (it->second->_children.find("*") != it->second->_children.end())
                {
                    string np = path + it->second->_val;
                    if (ans.size() < np.size() || (ans.size() == np.size() && ans > np))
                    {
                        ans = np;
                    }
                    dfs(it->second, np);
                }
            }
        };
        dfs(&root, "");
        // cout << ans << '?' << endl;
        return ans;
    }
};

int main()
{
    Solution b;
    vector<string> a = {"w", "wo", "wor", "worl", "world"};
    vector<string> aa = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    vector<string> aaa = {"m", "mo", "moc", "moch", "mocha", "l", "la", "lat", "latt", "latte", "c", "ca", "cat"};
    cout << b.longestWord(a) << endl;
    cout << b.longestWord(aa) << endl;
    cout << b.longestWord(aaa) << endl;
}