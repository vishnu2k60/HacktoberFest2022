// This code is for range updates and range queries

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int inf = 1e9 + 7;
vector<ll int> tree, lazy;

void propagate(ll int node, ll int node_low, ll int node_high)
{
    if (lazy[node] == 0)
    {
        return;
    }
    if (node_low == node_high)
    {
        tree[node] += lazy[node];
        lazy[node] = 0;
        return;
    }
    tree[node] += lazy[node] * (node_high - node_low + 1);
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
    return;
}

void update(ll int node, ll int node_low, ll int node_high, ll int range_low, ll int range_high, ll int value)
{
    // here we need to propagate cause if we leave some range then we need value of tree updated as we need it in updating nodes above it..
    // propagate
    propagate(node, node_low, node_high);
    if (node_high < range_low || node_low > range_high)
    {
        return;
    }
    if (node_low >= range_low && node_high <= range_high)
    {
        lazy[node] += value;
        // propagate
        // like we are given [4 ,7] so when we make lazy[node] += val then tree[0] is unupdated so we need to propagate so values can be updated
        propagate(node, node_low, node_high);
        return;
    }
    ll int left_child_right = (node_low + node_high) / 2;
    update(2 * node, node_low, left_child_right, range_low, range_high, value);
    update(2 * node + 1, left_child_right + 1, node_high, range_low, range_high, value);

    // finally update the nodes in the call as tree[node] is changed and we need to update all above nodes also..

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll int find(ll int node, ll int node_low, ll int node_high, ll int range_low, ll int range_high)
{
    // propagate
    // here firsty we need to propagate every node cause we need updated value os all nodes which we are taking into account
    // propagate(node, node_low, node_high);
    if (node_high < range_low || node_low > range_high)
    {
        return 0;
    }
    propagate(node, node_low, node_high);
    // propagate (propagation here is not a problem cause we need values to be updated which are in range not outside as they dont affect results)
    // propagate(node, node_low, node_high);
    if (node_low >= range_low && node_high <= range_high)
    {
        return tree[node];
    }

    ll int left_child_right = (node_low + node_high) / 2;
    return find(2 * node, node_low, left_child_right, range_low, range_high) +
           find(2 * node + 1, left_child_right + 1, node_high, range_low, range_high);
}

void check_tree()
{
    cout << "check tree: " << endl;
    for (int i = 0; i < tree.size(); i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}

void check_lazy()
{
    cout << "check lazy tree: " << endl;
    for (int i = 0; i < lazy.size(); i++)
    {
        cout << lazy[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec{2, 5, 8, 9, 10, 3, 4};
    int n = vec.size();
    while (__builtin_popcount(n) != 1)
    {
        n++;
    }
    tree.resize(2 * n);
    lazy.resize(2 * n);

    for (int i = 0; i < (int)vec.size(); i++)
    {
        tree[n + i] = vec[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
    update(1, 0, n - 1, 0, 3, 3);
    check_tree();
    check_lazy();

    cout << "value from [0,1] is: " << find(1, 0, n - 1, 0, 1) << endl;
    check_tree();
    check_lazy();
    return 0;
}
