#pragma once

#include "date.h"
#include "token.h"
#include <memory>

using namespace std;

template <typename T> 
bool Compare(Comparison cmp, const T& outer, const T& inner) {
    switch (cmp) {
        case (Comparison::Less):
            return outer < inner;
        
        case (Comparison::LessOrEqual):
            return outer <= inner;
        
        case (Comparison::Greater):
            return outer > inner;

        case (Comparison::GreaterOrEqual):
            return outer >= inner;

        case (Comparison::Equal):
            return outer == inner;

        case (Comparison::NotEqual):
            return outer != inner;
    }
}

struct Node {
  virtual bool Evaluate(const Date& dateIn, const string& eventIn) const = 0;
};

struct EmptyNode : public Node {
    bool Evaluate(const Date& dateIn, const string& eventIn) const override { 
        return true; 
    }
};

struct DateComparisonNode : public Node {
    DateComparisonNode(Comparison cmpIn, const Date& dateIn) : 
        cmp(cmpIn), date(dateIn) {}

    bool Evaluate(const Date& dateIn, const string& eventIn) const override { 
        return Compare(this->cmp, dateIn, this->date);
    }

private:
    const Date date;
    const Comparison cmp;
};

struct EventComparisonNode : public Node {
    EventComparisonNode(Comparison cmpIn, const string& eventIn) : 
        cmp(cmpIn), event(eventIn) {}

    bool Evaluate(const Date& dateIn, const string& eventIn) const override { 
        return Compare(this->cmp, eventIn, this->event);
    }

private:
    const string event;
    const Comparison cmp;
};

struct LogicalOperationNode : public Node {
    LogicalOperationNode(LogicalOperation opIn, const shared_ptr<Node>& left, const shared_ptr<Node>& right) : 
        op(opIn), _left(left), _right(right) {}

    bool Evaluate(const Date& dateIn, const string& eventIn) const override { 
        switch (this->op)
        {
        case (LogicalOperation::And):
            return this->_left->Evaluate(dateIn, eventIn) && this->_right->Evaluate(dateIn, eventIn);
        
        case (LogicalOperation::Or):
            return this->_left->Evaluate(dateIn, eventIn) || this->_right->Evaluate(dateIn, eventIn);
        }
    }

private:
    LogicalOperation op;
    shared_ptr<const Node> _left, _right;
};

