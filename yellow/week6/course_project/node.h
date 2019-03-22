#pragma once

#include "date.h"
#include "logical_operation.h"
#include "comparison.h"

#include <memory>
#include <string>

using namespace std;

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode : public Node {
public:
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode : public Node {
public:
    DateComparisonNode(Comparison comparison, const Date& date);

    Comparison Comparison;
    Date Value;

    bool Evaluate(const Date& date, const string& event) const override;

};

class EventComparisonNode : public Node {
public:
    EventComparisonNode(Comparison comparison, const string& event);

    Comparison Comparison;
    string Value;

    bool Evaluate(const Date& date, const string& event) const override;
};

class LogicalOperationNode : public Node {
public:
    LogicalOperation Operation;
    shared_ptr<Node> Left;
    shared_ptr<Node> Right;

    LogicalOperationNode(LogicalOperation operation, shared_ptr<Node> left, shared_ptr<Node> right);

    bool Evaluate(const Date& date, const string& event) const override;
};