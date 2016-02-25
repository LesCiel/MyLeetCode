#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;

struct Node {
    bool has_image;
    int len;

    Node(int _l) {
        len = _l;
        has_image = false;
    }
};

const int MOD = 1000000007;

bool is_d(const string &fn) {
    return fn.find('.') == -1;
}

bool ends_with(const string &str, const string &suffix) {
    return str.size() >= suffix.size() &&
           str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}

bool is_img(const string &fn) {
    return ends_with(fn, ".jpeg") ||
           ends_with(fn, ".png") ||
           ends_with(fn, ".gif");
}

int solution(string &S) {
    stringstream in;
    in << S;
    string line;
    stack<Node> stk;
    stk.push(Node(0));

    int ans = 0;

    while (getline(in, line)) {
        int ns = 0;
        while (line[ns] == ' ') ns ++;
        string fname = line.substr(ns, -1);

//        cout << ns << "; " << fname  << " " << is_d(fname) << " " << is_img(fname) << endl;

        while (stk.size() - 1 > ns) {
            if (stk.top().has_image) {
                ans = (ans + stk.top().len) % MOD;
            }
            stk.pop();
        }

        if (is_d(fname)) {
            stk.push(Node(stk.top().len + 1 + fname.length()));
        } else if (is_img(fname)) {
            stk.top().has_image = true;
        }
    }

    while (stk.size() > 0) {
        if (stk.top().has_image) {
            if (stk.size() == 1) ans ++;
            ans = (ans + stk.top().len) % MOD;
        }
        stk.pop();
    }

    return ans;
}

