#pragma once
#include <vector>
#include <cmath>
#include <cassert>
#include <iostream>
#include <algorithm>

class TritReference;

enum TritValue { False = -1, Unknown = 0, True = 1 };

class TritSet {
private:
    //PRIVATE MEMBERS
    int capacity;
    std::vector <unsigned int> set;
public:
    //CONSTRUCTOR
    TritSet() { capacity = 0; };
    explicit TritSet(int capacity);
    //SETTER
    void setTrit(int index, TritValue value);
    void setCapacity(int capacity);
    //GETTERS
    TritValue getTrit(int index) const;
    int getCapacity() const;
    //OPERATORS
    TritSet& operator = (const TritSet& trit);
    TritSet operator ! () const;
    TritSet operator & (const TritSet& trit);
    TritSet operator | (const TritSet& trit);
    TritReference operator [] (int index);    //setter
    TritValue operator [] (int index) const;  //getter
    //METHODS
    size_t cardinality(TritValue value);
    void trim(size_t lastIndex);
    void printTritSet();

};

class TritReference {
private:
    //PRIVATE MEMBERS
    int index;
    TritSet* set;
public:
    //CONSTRUCTOR
    TritReference(int index, TritSet* set);

    //SETTERS
    void setTritSet(TritSet* tritSet);
    void setIndex(int idx);

    //OPERATORS
    TritReference& operator = (TritValue value);
    TritReference& operator = (const TritReference& value);
    operator TritValue() const;
};





