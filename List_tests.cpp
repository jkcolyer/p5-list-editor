#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here


TEST(test_list_empty_and_size) {
    List<int> list;
    ASSERT_TRUE(list.empty());
    ASSERT_EQUAL(list.size(), 0);
    list.push_front(1);
    ASSERT_FALSE(list.empty());
    ASSERT_EQUAL(list.size(), 1);
}

TEST(test_list_push_front_and_back) {
    List<int> list;
    list.push_back(2);
    list.push_front(1);
    list.push_back(3);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
    ASSERT_EQUAL(list.size(), 3);
}

TEST(test_list_pop_front_and_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    ASSERT_EQUAL(list.front(), 2);
    list.pop_back();
    ASSERT_EQUAL(list.back(), 2);
    ASSERT_EQUAL(list.size(), 1);
}

TEST(test_list_clear) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.clear();
    ASSERT_TRUE(list.empty());
}

TEST(test_iterator_copy_constructor) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    List<int> b(a);
    a.pop_front();
    ASSERT_EQUAL(b.size(), 2);
    ASSERT_EQUAL(b.front(), 1);
}

TEST(test_iterator_assignment_operator) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    List<int> b;
    b.push_back(10);
    b = a;
    ASSERT_EQUAL(b.size(), 2);
    ASSERT_EQUAL(b.front(), 1);
    ASSERT_EQUAL(b.back(), 2);
}

TEST(test_iterator_basic) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_TRUE(it == list.end());
}
// g
TEST(test_iterator_decrease) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.end();
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
}

TEST(test_iterator_insert) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    list.insert(it, 2);
    ASSERT_EQUAL(list.size(), 3);
    it = list.begin();
    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
}

TEST(test_iterator_erase) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    list.erase(it);
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 3);
}

TEST(test_list_copy_2) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    List<int> b;
    b = a;
    a.push_back(3);
    a.pop_front();
    ASSERT_EQUAL(b.size(), 2);
    ASSERT_EQUAL(b.front(), 1);
    ASSERT_EQUAL(b.back(), 2);
}

TEST(test_list_copy_3) {
    List<int> a;
    a.push_back(1);
    List<int> b;
    b.push_back(10);
    b.push_back(11);
    b.push_back(12);
    b = a;
    ASSERT_EQUAL(b.size(), 1);
    ASSERT_EQUAL(b.front(), 1);
    ASSERT_EQUAL(b.back(), 1);
}
// g
TEST(test_list_copy_empty) {
    List<int> a;
    List<int> b;
    b.push_back(1);
    b.push_back(2);
    b = a;
    ASSERT_TRUE(b.empty());
}

TEST(test_iterator_equality) {
    List<int>::Iterator a;
    List<int>::Iterator b;
    ASSERT_TRUE(a == b);
}

TEST(test_iterator_equality_2) {
    List<int> list;
    List<int>::Iterator def;
    ASSERT_FALSE(def == list.end());
    ASSERT_TRUE(def != list.end());
}

TEST(test_iterator_equality_3) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator a = list.begin();
    List<int>::Iterator b = list.begin();
    ASSERT_TRUE(a == b);
    ASSERT_FALSE(a != b);
}

TEST(test_iterator_equality_4) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator a = list.begin();
    List<int>::Iterator b = list.begin();
    ++b;
    ASSERT_FALSE(a == b);
    ASSERT_TRUE(a != b);
}

TEST(test_pop_front) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    list.push_front(0);
    ASSERT_EQUAL(list.front(), 0);
    ASSERT_EQUAL(list.size(), 3);
    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 0);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
}

TEST(test_pop_back) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    list.push_back(10);
    List<int>::Iterator it = list.end();
    --it;
    ASSERT_EQUAL(*it, 10);
    --it;
    ASSERT_EQUAL(*it, 2);
    --it;
    ASSERT_EQUAL(*it, 1);
}

TEST(test_insert_double_link) {
    List<int> list;
    list.push_back(1);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    list.insert(it, 2);
    List<int>::Iterator fwd = list.begin();
    ASSERT_EQUAL(*fwd, 1);
    ++fwd;
    ASSERT_EQUAL(*fwd, 2);
    ++fwd;
    ASSERT_EQUAL(*fwd, 3);
    List<int>::Iterator bwd = list.end();
    --bwd;
    ASSERT_EQUAL(*bwd, 3);
    --bwd;
    ASSERT_EQUAL(*bwd, 2);
    --bwd;
    ASSERT_EQUAL(*bwd, 1);
}

TEST(test_erase_double_link) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.begin();
    ++it;
    list.erase(it);
    List<int>::Iterator fwd = list.begin();
    ASSERT_EQUAL(*fwd, 1);
    ++fwd;
    ASSERT_EQUAL(*fwd, 3);
    List<int>::Iterator bwd = list.end();
    --bwd;
    ASSERT_EQUAL(*bwd, 3);
    --bwd;
    ASSERT_EQUAL(*bwd, 1);
}

TEST(test_insert_2) {
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    List<int>::Iterator it = list.insert(list.begin(), 1);
    ASSERT_TRUE(it == list.begin());
    ASSERT_EQUAL(*it, 1);
}

TEST(test_insert_3) {
    List<int> list;
    list.insert(list.end(), 1);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 1);
    ASSERT_EQUAL(list.back(), 1);
}

TEST(test_erase_2) {
    List<int> list;
    list.push_back(42);
    List<int>::Iterator it = list.erase(list.begin());
    ASSERT_TRUE(list.empty());
    ASSERT_TRUE(it == list.end());
    list.push_back(1);
    ASSERT_EQUAL(list.front(), 1);
}

TEST(test_iterator_2) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    List<int>::Iterator it = list.begin();
    List<int>::Iterator old = it++;
    ASSERT_EQUAL(*old, 1);
    ASSERT_EQUAL(*it, 2);
}

TEST(test_list_copy_4) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    List<int> &ref = a;
    a = ref;
    ASSERT_EQUAL(a.size(), 3);
    ASSERT_EQUAL(a.front(), 1);
    ASSERT_EQUAL(a.back(), 3);
}

TEST(test_list_copy_5) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    List<int> b;
    List<int> c;
    c = b = a;
    ASSERT_EQUAL(b.size(), 2);
    ASSERT_EQUAL(c.size(), 2);
    ASSERT_EQUAL(c.front(), 1);
    ASSERT_EQUAL(c.back(), 2);
}

TEST(test_list_assignment) {
    List<int> a;
    for (int i = 0; i < 4; ++i) {
        a.push_back(i);
    }
    List<int> b;
    b.push_back(10);
    b = a;
    ASSERT_EQUAL(b.size(), 4);
    int j = 0;
    for (List<int>::Iterator it = b.begin(); it != b.end(); ++it, ++j) {
        ASSERT_EQUAL(*it, j);
    }
    List<int>::Iterator bwd = b.end();
    --bwd;
    ASSERT_EQUAL(*bwd, 3);
    --bwd;
    ASSERT_EQUAL(*bwd, 2);
}

TEST(test_list_assignment_2) {
    List<int> a;
    a.push_back(10);
    List<int> b;
    b.push_back(1);
    b.push_back(2);
    b = a;
    ASSERT_EQUAL(b.size(), 1);
    ASSERT_EQUAL(b.front(), 10);
    ASSERT_EQUAL(b.back(), 10);
    List<int>::Iterator it = b.begin();
    ASSERT_EQUAL(*it, 10);
    ++it;
    ASSERT_TRUE(it == b.end());
}

TEST(test_erase_3) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.erase(list.begin());
    ASSERT_EQUAL(list.size(), 2);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 3);

    List<int>::Iterator it = list.begin();
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_TRUE(it == list.end());

    List<int>::Iterator last = list.end();
    --last;
    list.erase(last);
    ASSERT_EQUAL(list.size(), 1);
    ASSERT_EQUAL(list.front(), 2);
    ASSERT_EQUAL(list.back(), 2);

    List<int>::Iterator bwd = list.end();
    --bwd;
    ASSERT_EQUAL(*bwd, 2);
    ASSERT_TRUE(bwd == list.begin());
}

TEST_MAIN()
