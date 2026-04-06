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

TEST(test_list_copy_itself) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a = a;
    ASSERT_EQUAL(a.size(), 3);
    ASSERT_EQUAL(a.front(), 1);
    ASSERT_EQUAL(a.back(), 3);
}

TEST(test_list_copy_empty) {
    List<int> a;
    List<int> b;
    b.push_back(1);
    b.push_back(2);
    b = a;
    ASSERT_TRUE(b.empty());
}

TEST_MAIN()
