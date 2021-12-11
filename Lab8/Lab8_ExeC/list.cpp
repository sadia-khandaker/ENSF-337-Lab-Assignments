/* File Name: list.cpp
 * Assignment: Lab 8 Exercise C
 * Lab Section: B04
 * Completed By: Sadia Khandaker
 * Submission Date: November 25, 2021
 */


#include <iostream>
#include "list.h"
using namespace std;

FlowList::FlowList()
        : headM(0)
{
}
FlowList::~FlowList() {
    destroy();
}

int FlowList::insert(const ListItem& itemA) {
    Node* crsr = headM;
    while (crsr != 0) {
        if(crsr -> item.year == itemA.year) {
            return 0;
        }
        crsr = crsr -> next;
    }
    Node *aNode = new Node;
    aNode -> item.year = itemA.year;
    aNode -> item.flow = itemA.flow;
    if (headM == 0 || itemA.flow <= headM->item.flow) {
        aNode->next = headM;
        headM = aNode;
    }
    else {
        Node *before = headM;
        Node *after = headM->next;
        while( after != 0 && itemA.flow > after -> item.flow) {
            before = after;
            after = after -> next;
        }
            aNode -> next = after;
            before->next = aNode;
        }
        return 1;
    }


int FlowList::remove(const ListItem& itemA)
{
    if (headM == 0)
        return 0;

    Node *doomed_node = 0;

    if (itemA.year == headM->item.year) {

        doomed_node = headM;
        headM = headM->next;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;

        while(maybe_doomed != nullptr && itemA.year != maybe_doomed->item.year) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (maybe_doomed != nullptr) {
            before -> next = maybe_doomed -> next;
            delete maybe_doomed;
            return 1;
        }
    }
    return 0;
}

void FlowList::destroy() {
    Node *before = headM;
    while (before != nullptr) {
        Node *temp = before->next;
        delete before;
        before = temp;
    }
    headM = nullptr;
}