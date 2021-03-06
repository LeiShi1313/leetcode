//
// Created by Dicky Shi on 6/13/17.
//

#ifndef PROJECT_UTILS_H
#define PROJECT_UTILS_H

#include <iostream>
#include <vector>

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {};
    ListNode(void) : val(0), next(NULL) {};
    ListNode* getNodesFromInteger(std::vector<int>&);
    int getVal();
    friend std::ostream& operator<<(std::ostream&, ListNode*);
};

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(void) : val(0), left(NULL), right(NULL) {}
    TreeNode* getRoot(std::vector<int> &);
    friend std::ostream& operator<<(std::ostream&, TreeNode*);
};

class UndirectedGraphNode {
public:
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class RandomListNode {
public:
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Interval {
public:
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
    friend std::ostream& operator<<(std::ostream&, Interval);
};

template<typename T>
void printVector(const T& t) {
    std::copy(t.cbegin(), t.cend(), std::ostream_iterator<typename T::value_type>(std::cout, ", "));
}

template<typename T>
void printVectorInVector(const T& t) {
    std::for_each(t.cbegin(), t.cend(), printVector<typename T::value_type>);
}

template<typename T1>
std::ostream& operator <<( std::ostream& out, const std::vector<T1>& object )
{
    out << "[";
    if ( !object.empty() )
    {
        //std::copy( object.begin(), --object.end(), std::ostream_iterator<T1>( out, ", " ) );
        for(typename std::vector<T1>::const_iterator t = object.begin(); t != object.end() - 1; ++t) {
            out << *t << ", ";
        }
        out << *--object.end(); // print the last element separately to avoid the extra characters following it.
    }
    out << "]";
    return out;
}

std::vector<std::vector<char> > string_to_vector_of_char(std::vector<std::string>);

#endif //PROJECT_UTILS_H



