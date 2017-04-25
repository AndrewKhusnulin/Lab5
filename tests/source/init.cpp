#include <Laboratory-work-5-sem2.hpp>
#include <catch.hpp>

SCENARIO("Add") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.Add(10, root);
    
    REQUIRE( rv == 15);
}
SCENARIO("print") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.print(11, root);
    
    REQUIRE( rv == 64);
}
SCENARIO("Search") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.Search(12, root);
    
    REQUIRE( rv == 1);
}
SCENARIO("Deletionh") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.Search(13, root);
    
    REQUIRE( rv == 0);
}
SCENARIO("FreeTree") {
    BinarySearchTree<unsigned int> r;
    BinarySearchTree<unsigned int>* root;
    int rv = r.Search(14, root);
    
    REQUIRE( rv == 228);
}

