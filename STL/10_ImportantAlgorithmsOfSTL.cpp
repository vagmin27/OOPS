#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};
    vector<int> result(10);

    // copy() copies elements from one range to another.
    copy(v.begin(), v.end(), result.begin());

    // copy_if() copies only elements satisfying a condition.
    copy_if(v.begin(), v.end(), result.begin(), [](int x) {
        return x % 2 == 0;
    });

    // move() moves elements from one range to another.
    vector<int> moved(5);
    move(v.begin(), v.end(), moved.begin());

    // transform() applies a function to every element.
    transform(v.begin(), v.end(), v.begin(), [](int x) {
        return x * 2;
    });

    // transform() can also combine two ranges.
    transform(a.begin(), a.end(), b.begin(), result.begin(), [](int x, int y) {
        return x + y;
    });

    // remove() moves all elements equal to a value to the end.
    v.erase(remove(v.begin(), v.end(), 4), v.end());

    // remove_if() removes elements satisfying a condition.
    v.erase(remove_if(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    }), v.end());

    // replace_if() replaces elements satisfying a condition.
    replace_if(v.begin(), v.end(), [](int x) {
        return x > 3;
    }, 100);

    // partition() places elements satisfying a condition before the others.
    partition(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });

    // stable_partition() preserves the relative order within both groups.
    stable_partition(v.begin(), v.end(), [](int x) {
        return x % 2 == 0;
    });

    // is_sorted() checks whether a range is sorted.
    bool sorted = is_sorted(v.begin(), v.end());

    // is_sorted_until() returns the first position where sorting order breaks.
    auto position = is_sorted_until(v.begin(), v.end());

    // nth_element() places the element that would be at the given position if sorted.
    nth_element(v.begin(), v.begin() + 2, v.end());

    // partial_sort() sorts only a selected part of a range.
    partial_sort(v.begin(), v.begin() + 3, v.end());

    // partial_sort_copy() copies the smallest elements into another range.
    partial_sort_copy(v.begin(), v.end(), result.begin(), result.begin() + 3);

    // merge() merges two sorted ranges into another range.
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    merge(a.begin(), a.end(), b.begin(), b.end(), result.begin());

    // inplace_merge() merges two consecutive sorted parts of the same range.
    vector<int> m = {1, 3, 5, 2, 4, 6};
    inplace_merge(m.begin(), m.begin() + 3, m.end());

    // includes() checks whether one sorted range contains another.
    bool contains = includes(m.begin(), m.end(), a.begin(), a.end());

    // set_union() creates the union of two sorted ranges.
    vector<int> unionResult(10);
    auto unionEnd = set_union(a.begin(), a.end(), b.begin(), b.end(), unionResult.begin());

    // set_intersection() creates the common elements of two sorted ranges.
    vector<int> intersectionResult(10);
    auto intersectionEnd = set_intersection(a.begin(), a.end(), b.begin(), b.end(), intersectionResult.begin());

    // set_difference() finds elements present in the first range but not the second.
    vector<int> differenceResult(10);
    auto differenceEnd = set_difference(a.begin(), a.end(), b.begin(), b.end(), differenceResult.begin());

    // set_symmetric_difference() finds elements present in either range but not both.
    vector<int> symmetricResult(10);
    auto symmetricEnd = set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), symmetricResult.begin());

    // lexicographical_compare() compares two ranges lexicographically.
    bool smaller = lexicographical_compare(a.begin(), a.end(), b.begin(), b.end());

    // equal() checks whether two ranges contain equal elements.
    bool same = equal(a.begin(), a.end(), b.begin());

    // mismatch() finds the first position where two ranges differ.
    auto mismatchResult = mismatch(a.begin(), a.end(), b.begin());

    // adjacent_find() finds the first pair of equal adjacent elements.
    vector<int> duplicate = {1, 2, 2, 3, 4};
    auto adjacent = adjacent_find(duplicate.begin(), duplicate.end());

    // search() searches for one sequence inside another sequence.
    vector<int> pattern = {2, 3};
    auto foundSequence = search(duplicate.begin(), duplicate.end(), pattern.begin(), pattern.end());

    // search_n() searches for n consecutive occurrences of a value.
    vector<int> repeated = {1, 2, 2, 2, 3};
    auto repeatedPosition = search_n(repeated.begin(), repeated.end(), 3, 2);

    // shuffle() randomly rearranges elements.
    shuffle(v.begin(), v.end(), mt19937(random_device{}()));

    // is_permutation() checks whether two ranges contain the same elements with the same frequencies.
    bool permutation = is_permutation(a.begin(), a.end(), b.begin());

    // stable_sort() sorts while preserving the relative order of equivalent elements.
    stable_sort(v.begin(), v.end());

    // reverse_copy() reverses a range while copying it to another range.
    vector<int> reversed(5);
    reverse_copy(v.begin(), v.end(), reversed.begin());

    // rotate_copy() rotates a range while copying it to another range.
    vector<int> rotated(5);
    rotate_copy(v.begin(), v.begin() + 2, v.end(), rotated.begin());

    // replace_copy() copies a range while replacing matching values.
    vector<int> replaced(5);
    replace_copy(v.begin(), v.end(), replaced.begin(), 2, 100);

    // remove_copy() copies a range while skipping a specific value.
    vector<int> removed(5);
    remove_copy(v.begin(), v.end(), removed.begin(), 2);

    // remove_copy_if() copies elements that do not satisfy a condition.
    vector<int> removedIf(5);
    remove_copy_if(v.begin(), v.end(), removedIf.begin(), [](int x) {
        return x % 2 == 0;
    });

    // generate() generates values using a function.
    int counter = 1;
    generate(v.begin(), v.end(), [&counter]() {
        return counter++;
    });

    // generate_n() generates a specified number of values.
    generate_n(v.begin(), 3, []() {
        return 10;
    });

    // iota() fills a range with consecutive values.
    iota(v.begin(), v.end(), 1);

    // max_element() with a custom comparator.
    auto maximum = max_element(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });

    // min_element() with a custom comparator.
    auto minimum = min_element(v.begin(), v.end(), [](int a, int b) {
        return a < b;
    });

    // gcd() finds the greatest common divisor.
    int g = __gcd(24, 36);

    return 0;
}