#pragma once
#include <algorithm>

using namespace std;

template<class T, const size_t Size> class Stack {
private:
    T arr[Size];
    int top_i;

public:
    Stack() : arr(), top_i(-1) {}
    void push (T n) {
        arr[++top_i] = n;
    }
    void pop() {
        top_i--;
    }
    T top() {
        return arr[top_i];
    }
    T bottom() {
        return arr[0];
    }
    int size() {
        return top_i+1;
    }
};
template<class T, const size_t Size> class Queue {
private:
    T arr[Size];
    int start, end;

public:
    Queue() : arr(), start(0), end(0) {}
    void push (T n) {
        arr[end++] = n;
    }
    void pop() {
        start++;
    }
    T front() {
        return arr[start];
    }
    int size() {
        return end-start;
    }
};
template<class T, const size_t Size> class Priority_Q {
protected:
    T arr[Size];
    T min, max;

public:
    Priority_Q() : arr(), min(Size-1), max(0) {}
    virtual void push (T n) {
        min = (min<n) ? min : n;
        max = (max>n) ? max : n;
        arr[n]++;
    }
    virtual void pop_min() {
        if (--arr[min]) return;
        while (++min<=max&&!arr[min]);
        if (min>max) min = Size-1, max = 0;
    }
    virtual void pop_max() {
        if (--arr[max]) return;
        while (--max>=min&&!arr[max]);
        if (min>max) min = Size-1, max = 0;
    }
    virtual T top() const {
        return max;
    }
    virtual T bottom() const {
        return min;
    }
    bool empty() const {
        return min==Size-1&&max==0;
    }
};
template<class S, class T, const size_t Size, const int UnderSize = 5> 
class Pairority_Q : public Priority_Q<T, Size> {
protected:
    Stack<S, UnderSize> primary[Size];

public:
    using PQ = Priority_Q<T, Size>;

    Pairority_Q() : Priority_Q<T, Size>(), primary() {}
    void push (S m, T n) {
        primary[n].push(m);
        PQ::push(n);
    }
    void pop_min() {
        primary[PQ::min].pop();
        PQ::pop_min();
    }
    void pop_max() {
        primary[PQ::max].pop();
        PQ::pop_max();
    }
    pair<S, T> top_p() {
        return make_pair(primary[PQ::max].top(), PQ::max);
    }
    pair<S, T> bottom_p() {
        return make_pair(primary[PQ::min].top(), PQ::min);
    }

private:
    void push (T n) override {}
    T top() const override { return PQ::top(); }
    T bottom() const override { return PQ::bottom(); }
};