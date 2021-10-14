#include "pch.h"

#include "pch.h"
#include "../task_1_tritset/tritSet.h"

class TritSetTest : public ::testing::Test {
protected:
    void SetUp() {

        tritSet1 = new TritSet(10);     
        tritSet2 = new TritSet(9);
        tritSet3 = new TritSet(50000);       
    }
    void TearDown() {

        delete tritSet1;
        delete tritSet2;
        delete tritSet3;
    }
    TritSet* tritSet1, *tritSet2, *tritSet3;
};

TEST_F(TritSetTest, testCopyConstructor) {

    tritSet1->setTrit(5, True);
    TritSet newSet(*tritSet1);
    ASSERT_EQ(tritSet1->getCapacity(), newSet.getCapacity());
    for (int i = 0; i < tritSet1->getCapacity(); i++)
        ASSERT_EQ((*tritSet1)[i], newSet[i]);
}

TEST_F(TritSetTest, testTritSetter) {

    tritSet1->setTrit(1, False);
    tritSet1->setTrit(18, True);
    ASSERT_EQ((*tritSet1)[0], Unknown);
    ASSERT_EQ((*tritSet1)[1], False);
    ASSERT_EQ((*tritSet1)[18], True);
}

TEST_F(TritSetTest, testCapacitySetterAndGetter) {

    tritSet1->setCapacity(78);
    ASSERT_EQ(tritSet1->getCapacity(), 78);
    tritSet1->setCapacity(4);
    ASSERT_EQ(tritSet1->getCapacity(), 4);
}

TEST_F(TritSetTest, testTritGetter) {

    ASSERT_EQ(tritSet2->getTrit(10), Unknown);
    (*tritSet1)[18] = True;
    ASSERT_EQ(tritSet1->getTrit(18), True);
}

TEST_F(TritSetTest, testOperatorEq) {

    (*tritSet3) = (*tritSet2); 
    ASSERT_EQ(tritSet2->getCapacity(), tritSet3->getCapacity());
    for (int i = 0; i < tritSet2->getCapacity(); i++)
        ASSERT_EQ((*tritSet2)[i], (*tritSet3)[i]);
}

TEST_F(TritSetTest, testOperatorNot) {

    (*tritSet1)[56] = True;
    (*tritSet1)[0] = False;
    (*tritSet1)[18] = True;
    TritSet newSet = !(*tritSet1);

    for (int i = 0; i < newSet.getCapacity(); i++)
        ASSERT_EQ(newSet[i], -((*tritSet1)[i]));
}

TEST_F(TritSetTest, testOperatorAnd) {

    TritSet first(50), second(60), expect(60);
    first[0] = True;
    first[17] = False;
    first[20] = False;
    second[0] = True;
    second[17] = True;
    second[20] = False;
    second[49] = False;
    second[59] = True;
    expect[0] = True;
    expect[17] = False;
    expect[20] = False;
    expect[49] = False;
    expect[59] = Unknown;
    TritSet result = first & second;

    ASSERT_EQ(result.getCapacity(), 60);
    for (int i = 0; i < 60; i++) 
        ASSERT_EQ(result[i], expect[i]);  
}

TEST_F(TritSetTest, testOperatorOr) {

    TritSet first(50), second(60), expect(60);
    first[0] = True;
    first[17] = False;
    first[20] = False;
    second[0] = True;
    second[17] = True;
    second[20] = False;
    second[49] = False;
    second[59] = True;
    expect[0] = True;
    expect[17] = True;
    expect[20] = False;
    expect[49] = Unknown;
    expect[59] = True;
    TritSet result = first | second;

    ASSERT_EQ(result.getCapacity(), 60);
    for (int i = 0; i < 60; i++)
        ASSERT_EQ(result[i], expect[i]);
}

TEST_F(TritSetTest, testCardinality) {

    (*tritSet1)[56] = True;
    (*tritSet1)[0] = False;
    (*tritSet1)[18] = True;
    
    ASSERT_EQ(tritSet1->cardinality(True), 2);
    ASSERT_EQ(tritSet1->cardinality(False), 1);
    ASSERT_EQ(tritSet1->cardinality(Unknown), 54);
}

TEST_F(TritSetTest, testTrim) {

    (*tritSet1)[56] = True;
    (*tritSet1)[0] = False;
    (*tritSet1)[18] = True;
    tritSet1->trim(30);

    ASSERT_EQ(tritSet1->getCapacity(), 31);
}




