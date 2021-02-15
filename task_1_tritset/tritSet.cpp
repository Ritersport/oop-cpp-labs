#include "tritSet.h"

//TritSet

//CONSTRUCTOR
TritSet::TritSet(int capacity) {
    this->capacity = capacity;
    int allocLength = ceil((capacity * 2) / 8.0);
    allocLength = ceil(allocLength / sizeof(unsigned int)) + 1;
    for (int i = 0; i < allocLength; i++) {
        this->set.push_back(0);
    }

}

//SETTER
void TritSet::setTrit(int index, TritValue value) {

    unsigned int bitOfVector = index * 2;
    unsigned int byteOfVector = bitOfVector / 8;
    unsigned int idxOfVector = byteOfVector / sizeof(unsigned int);
    unsigned int bitOfCell = bitOfVector % (8 * sizeof(unsigned int));


    //if size of the vector is less then we need
    //we pushback new cells or call return if value == Unknown
    if (index > this->capacity - 1) {
        if (value != Unknown) {
            int difference = idxOfVector - this->set.size() + 1;
            for (int i = 0; i < difference; i++) {
                this->set.push_back(0);
            }
            this->capacity = index + 1;
        }
        else
            return;
    }
    // Unknown == 00
    // True == 01
    // False == 11

    unsigned int mask = 0, mask1 = 0;

    switch (value) {
    case Unknown: {
        mask = UINT_MAX - 3; //11111..100
        for (auto i = 0; i < (8 * sizeof(unsigned int)) - 2 - bitOfCell; i++) {
            mask <<= 1;
            mask += 1;
        }
        this->set[idxOfVector] &= mask;
        return;
    }

    case True: {
        mask = 1; mask1 = UINT_MAX - 2; //mask = 0000..01 mask1 = 11111..101
        for (auto i = 0; i < (8 * sizeof(unsigned int)) - 2 - bitOfCell; i++) {
            mask <<= 1;
            mask1 <<= 1;
            mask1 += 1;
        }
        this->set[idxOfVector] &= mask1;
        this->set[idxOfVector] |= mask;
        return;
    }

    case False: {
        mask = 3; //0000..011
        for (auto i = 0; i < (8 * sizeof(unsigned int)) - 2 - bitOfCell; i++) {
            mask <<= 1;
            mask1 <<= 1;
        }
        this->set[idxOfVector] |= mask;
        return;
    }
    }

}

void TritSet::setCapacity(int capacity)
{
    this->capacity = capacity;
}

//GETTERS
TritValue TritSet::getTrit(int index) const {
    unsigned int bitOfVector = index * 2;
    unsigned int byteOfVector = bitOfVector / 8;
    unsigned int idxOfVector = byteOfVector / sizeof(unsigned int);
    unsigned int bitOfCell = bitOfVector % (8 * sizeof(unsigned int));


    if (idxOfVector > this->set.capacity() - 1)
        return Unknown;
    unsigned mask = 0;
    mask = mask | this->set[idxOfVector];
    for (int i = 0; i < (8 * sizeof(unsigned int)) - 2 - bitOfCell; i++) {
        mask >>= 1;
    }
    switch (mask % 4) {
    case 0: return Unknown;
    case 1: return True;
    case 3: return False;

    }
    return Unknown;
}

int TritSet::getCapacity() const {
    return this->capacity;
}


//OPERATORS
TritSet& TritSet::operator= (const TritSet& trit) {
    if (this == &trit)
        return *this;
    capacity = trit.capacity;
    set = trit.set;
    return *this;
}

TritSet TritSet::operator!() const {
    TritSet newTritSet(this->capacity);
    for (auto i = 0; i < this->capacity; i++) {
        switch (this->getTrit(i)) {

        case False:
            newTritSet.setTrit(i, True);
            break;
        case True:
            newTritSet.setTrit(i, False);
            break;
        case Unknown:
            break;
        }
    }
    return newTritSet;
}

TritSet TritSet::operator&(const TritSet& trit) {
    TritSet firstTrit = *this;
    TritSet secondTrit = trit;
    TritSet newTrit = TritSet((firstTrit.capacity > secondTrit.capacity) ? firstTrit.capacity : secondTrit.capacity);


    for (auto i = 0; i < newTrit.capacity; i++) {
        switch (firstTrit.getTrit(i)) {
        case False:
            newTrit.setTrit(i, False);
            break;
        case Unknown:
            if (secondTrit.getTrit(i) == True)
                newTrit.setTrit(i, Unknown);
            else
                newTrit.setTrit(i, secondTrit.getTrit(i));
            break;
        case True:
            newTrit.setTrit(i, secondTrit.getTrit(i));
            break;
        }
    }

    return newTrit;
}

TritSet TritSet::operator|(const TritSet& trit) {
    TritSet firstTrit = *this;
    TritSet secondTrit = trit;
    TritSet newTrit = TritSet((firstTrit.capacity > secondTrit.capacity) ? firstTrit.capacity : secondTrit.capacity);


    for (auto i = 0; i < newTrit.capacity; i++) {
        switch (firstTrit.getTrit(i)) {
        case True:
            newTrit.setTrit(i, True);
            break;
        case Unknown:
            if (secondTrit.getTrit(i) == True)
                newTrit.setTrit(i, True);
            else
                newTrit.setTrit(i, Unknown);
            break;
        case False:
            newTrit.setTrit(i, secondTrit.getTrit(i));
            break;
        }
    }
    return newTrit;
}

TritValue TritSet::operator[](const int index) const {
    //getter

    return this->getTrit(index);
}

TritReference TritSet::operator [](const int index) {
    //setter

    TritReference ref(index, this);
    return ref;
}

// METHODS

size_t TritSet::cardinality(TritValue value) {
    int counter = 0;
    for (int i = 0; i < this->capacity; i++) {
        if (this->getTrit(i) == value)
            counter++;
    }

    return counter;
}

void TritSet::trim(size_t lastIndex) {
    unsigned int bitOfVector = lastIndex * 2;
    unsigned int byteOfVector = bitOfVector / 8;
    unsigned int idxOfVector = byteOfVector / sizeof(unsigned int);


    for (unsigned i = idxOfVector + 1; i < this->set.size(); i++) {
        this->set.pop_back();
    }
    for (int i = lastIndex; i < 8 * sizeof(unsigned) * (idxOfVector + 1); i++)
        this->setTrit(i, Unknown);
    this->capacity = lastIndex;
    while (this->getTrit(this->capacity - 1) == Unknown)
        this->capacity--;
}

void TritSet::printTritSet() {
    for (int i = 0; i < this->capacity; i++)
        std::cout << this->getTrit(i) << " ";
    std::cout << std::endl;
}



/////////////////

//TritReference

//CONSTRUCTOR
TritReference::TritReference(int index, TritSet* set) {
    this->index = index;
    this->set = set;
}

//SETTERS
void TritReference::setTritSet(TritSet* tritSet) {
    this->set = tritSet;
}

void TritReference::setIndex(int idx) {
    this->index = idx;
}

//OPERATORS
TritReference& TritReference::operator = (TritValue value) {
    this->set->setTrit(this->index, value);
    return *this;
}


TritReference& TritReference::operator = (const TritReference& value) {
    this->set->setTrit(this->index, (TritValue)value);

    return *this;
}

TritReference::operator TritValue() const {
    return this->set->getTrit(this->index);;
}

