/* File Name: OLList.cpp
 * Assignment: Lab 8 Exercise B
 * Lab Section: B04
 * Completed by: Sadia Khandaker
 * Submission Date: Novemeber 25, 2021
 */

#include <iostream>
#include <stdlib.h>
using namespace std;
#include "OLList.h"

OLList::OLList()
        : headM(0)
{
}

OLList::OLList(const OLList& source)
{
    copy(source);
}

OLList& OLList::operator =(const OLList& rhs)
{
    if (this != &rhs) {
        destroy();
        copy(rhs);
    }
    return *this;
}

OLList::~OLList()
{
    destroy();
}

void OLList::print() const
{
    cout << '[';
    if (headM != 0) {
        cout << ' ' << headM->item;
        for (const Node *p = headM->next; p != 0; p = p->next)
            cout << ", " << p->item;
    }
    cout << " ]\n";
}

void OLList::insert(const ListItem& itemA)
{
    Node *new_node = new Node;
    new_node->item = itemA;

    if (headM == 0 || itemA <= headM->item ) {
        new_node->next = headM;
        headM = new_node;
        // point one
    }
    else {
        Node *before = headM;      // will point to node in front of new node
        Node *after = headM->next; // will be 0 or point to node after new node
        while(after != 0 && itemA > after->item) {
            before = after;
            after = after->next;
        }
        new_node->next = after;
        before->next = new_node;
        // point two
    }
}

void OLList::remove(const ListItem& itemA)
{
    if (headM == 0 || itemA < headM->item)
        return;

    Node *doomed_node = 0;

    if (itemA == headM->item) {
        doomed_node = headM;
        headM = headM->next;
        delete doomed_node;
    }
    else {
        Node *before = headM;
        Node *maybe_doomed = headM->next;
        while(maybe_doomed != 0 && itemA > maybe_doomed->item) {
            before = maybe_doomed;
            maybe_doomed = maybe_doomed->next;
        }
        if (maybe_doomed != NULL) {
            before -> next = maybe_doomed -> next;
            delete maybe_doomed;
        }
    }
}

void OLList::destroy()
{
    Node* erase = headM;
    while(headM != NULL) {
        headM = headM ->next;
        delete headM;
        erase = headM;
    }
    headM = NULL;
}

void OLList::copy(const OLList& source)
{
    Node* current = source.headM;
    if (current != NULL)
    {
        Node *copy = new Node;
        copy->item = current->item;
        copy->next = NULL;
        headM = copy;
        current = source.headM->next;
        while (current != NULL)
        {
            Node *nn = new Node;
            nn->item = current->item;
            nn->next = NULL;
            copy->next = nn;
            copy = nn;
            current = current->next;
        }
    }
    else
    {
        headM = NULL;
    }
}




