#include "node.h"

template<class T>
bool CompareValue(Comparison comparison, const T& left, const T& right) {
    bool result;
    if (comparison == Comparison::Less) {
        result = left < right;
    } else if (comparison == Comparison::LessOrEqual) {
        result = left <= right;
    } else if (comparison == Comparison::Greater) {
        result = left > right;
    } else if (comparison == Comparison::GreaterOrEqual) {
        result = left >= right;
    } else if (comparison == Comparison::Equal) {
        result = left == right;
    } else {
        result = left != right;
    }

    return result;
}

LogicalOperationNode::LogicalOperationNode(LogicalOperation op, shared_ptr<Node> left, shared_ptr<Node> right)
    : Operation(op), Left(left), Right(right) {}

bool LogicalOperationNode::Evaluate(const Date& date, const string& event) const {
    if (Operation == LogicalOperation::And) {
        return Right->Evaluate(date, event) && Left->Evaluate(date, event);
    } else {
        return Right->Evaluate(date, event) || Left->Evaluate(date, event);
    }
}

DateComparisonNode::DateComparisonNode(enum Comparison comparison, const Date& date)
    : Comparison(comparison), Value(date) {}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) const {
    return CompareValue(Comparison, date, Value);
}

EventComparisonNode::EventComparisonNode(enum Comparison comparison, const string& event)
    : Comparison(comparison), Value(event) {}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) const {
    return CompareValue(Comparison, event, Value);
}

bool EmptyNode::Evaluate(const Date& date, const string& event) const {
    return true;
}
