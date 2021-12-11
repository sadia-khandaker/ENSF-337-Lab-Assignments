/* File Name: list.h
 * Assignment: Lab 8 Exercise C
 * Lab Section: B04
 * Completed By: Sadia Khandaker
 * Submission Date: November 25, 2021
 */
#ifndef LIST_H
#define LIST_H

struct ListItem {
    int year;
    double flow;
};
struct Node {
    ListItem item;
    Node *next;
};
class FlowList {
public:
    FlowList();
    ~FlowList();
    int insert(const ListItem& itemA);
    int remove(const ListItem& itemA);
    Node* headM;

private:
    void destroy();
};
#endif