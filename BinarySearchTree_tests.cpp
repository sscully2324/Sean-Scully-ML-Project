// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"


TEST(test_stub) {
    // Add your tests here
    ASSERT_TRUE(true);
}

TEST(size_one){
  BinarySearchTree<int> tree;
  ASSERT_TRUE(tree.size() == 0);
  ASSERT_TRUE(tree.height() == 0);
}

///////////////need more size tests once create insert
TEST(insert_one){
    BinarySearchTree<int> tree;
    tree.insert(5);
  ASSERT_TRUE(tree.size() == 1);
  ASSERT_TRUE(tree.height() == 1);
}

TEST(insert_two){
     BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    ASSERT_TRUE(tree.size() == 3);
    ASSERT_TRUE(tree.height() == 2);
}

//TEST(insert_three){
   //BinarySearchTree<int> tree;
    //tree.insert(5);
    //tree.insert(5);
    //ASSERT_TRUE(tree.size() == 1);
//}

TEST(empty_one){
    BinarySearchTree<int> tree;
    ASSERT_TRUE(tree.empty() == 1);
     tree.insert(5);
     ASSERT_TRUE(tree.empty() == 0);
    }
TEST(empty_height_two){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(2);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_TRUE(tree.height() == 3);
    ASSERT_TRUE(tree.size() == 4);
}


TEST(height_one){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(2);
    tree.insert(3);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_EQUAL(tree.height(), 4);
    ASSERT_TRUE(tree.size() == 5);
}

TEST(height_two){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(2);
    tree.insert(3);
    tree.insert(7);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_TRUE(tree.height() == 4);
    ASSERT_TRUE(tree.size() == 6);
}

TEST(height_three){
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(13);
    tree.insert(2);
    tree.insert(3);
    tree.insert(14);
    tree.insert(12);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_EQUAL(tree.height(), 4);
    ASSERT_TRUE(tree.size() == 7);
}

TEST(height_four){
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(13);
    tree.insert(2);
    tree.insert(3);
    tree.insert(14);
    tree.insert(12);
    tree.insert(15);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_TRUE(tree.height() == 4);
    ASSERT_TRUE(tree.size() == 8);
}

TEST(heigh_five){
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(4);
    tree.insert(13);
    tree.insert(2);
    tree.insert(3);
    tree.insert(15);
    tree.insert(12);
    tree.insert(14);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_TRUE(tree.height() == 4);
    ASSERT_TRUE(tree.size() == 8);
}

TEST(height_six){
     BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(13);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(15);
    tree.insert(12);
    tree.insert(14);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_TRUE(tree.height() == 5);
    ASSERT_TRUE(tree.size() == 9);
}

TEST(doubles){
    BinarySearchTree<double> tree;
    tree.insert(10.5);
    tree.insert(10.2);
    tree.insert(10.7);
    tree.insert(10.15);
    tree.insert(10.17);
    tree.insert(10.18);
    tree.insert(10.8);
    tree.insert(10.55);
    tree.insert(10.6);
    ASSERT_TRUE(tree.empty() == 0);
    ASSERT_TRUE(tree.height() == 5);
    ASSERT_TRUE(tree.size() == 9);
}

TEST(find_one){
     BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
   auto it = tree.begin();
ASSERT_EQUAL(*tree.find(4),*it);
}

TEST(find_two){
    BinarySearchTree<int> tree;
    tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   auto it = tree.begin();
   ASSERT_EQUAL(*tree.find(4),*it);
}

TEST(find_three){
    BinarySearchTree<int> tree;
    tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   auto it = tree.begin();
   ++it;
   ++it;
   ASSERT_EQUAL(*tree.find(6),*it);
}

TEST(find_four){
    BinarySearchTree<int> tree;
    ASSERT_EQUAL(tree.find(4), tree.end());
}
TEST(find_five){
    BinarySearchTree<int> tree;
    tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   tree.insert(3);
   tree.insert(7);
    ASSERT_EQUAL(tree.find(10), tree.end());
}
TEST(find_six){
    BinarySearchTree<int> tree;
    tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   tree.insert(3);
   tree.insert(7);
   auto it = tree.begin();
   ++it;
   ++it;
   ++it;
   ++it;
   ASSERT_EQUAL(*tree.find(7),*it);
}
TEST(find_seven){
   BinarySearchTree<int> tree;
   tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   tree.insert(3);
   tree.insert(7);
   tree.insert(1);
   auto it = tree.begin();
   ASSERT_EQUAL(*tree.find(1),*it);
}
TEST(find_eight){
     BinarySearchTree<int> tree;
   tree.insert(5);
    tree.insert(3);
   tree.insert(7);
   tree.insert(1);
   ASSERT_EQUAL(tree.end(),tree.find(4));
}

TEST(min_element){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    ASSERT_EQUAL(*tree.min_element(), 4);
}

TEST(max_element){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    auto it = tree.begin();
    ++it;
    ++it;
    ASSERT_EQUAL(tree.max_element(),it);
}
TEST(check_invariant_one){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    auto it = tree.begin();
    it++;
    it++;
    *it = 3;
    ASSERT_TRUE(!tree.check_sorting_invariant());
    

}

TEST(check_invariant_two){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    auto it = tree.begin();
    *it = 7;
    ASSERT_FALSE(tree.check_sorting_invariant());
}

TEST(check_invariant_three){
     BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
  
    ASSERT_TRUE(tree.check_sorting_invariant());
}
TEST(min_greater_than_one){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    auto it = tree.begin();
    ++it;
    ++it;

    ASSERT_EQUAL(*tree.min_greater_than(5),*it);
}

TEST(min_greater_than_two){
    BinarySearchTree<int> tree;
   tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   tree.insert(3);
   tree.insert(7);
   tree.insert(1);
   auto it = tree.begin();
   ++it;
   ASSERT_EQUAL(*tree.min_greater_than(2),*it);
}
TEST(min_greater_than_three){
    BinarySearchTree<int> tree;
   tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   tree.insert(3);
   tree.insert(7);
   tree.insert(1);
   auto it = tree.begin();
   ++it;
   ASSERT_EQUAL(*tree.min_greater_than(2),*it);
}

TEST(min_greater_than_four){
    BinarySearchTree<int> tree;
   
   ASSERT_EQUAL(tree.min_greater_than(2),tree.end());
}

TEST(min_greater_than_five){
    BinarySearchTree<int> tree;
   tree.insert(5);
   tree.insert(4);
   tree.insert(6);
   tree.insert(3);
   tree.insert(7);
   tree.insert(1);
   ASSERT_EQUAL(tree.min_greater_than(8),tree.end());
}

TEST(inorder){
   
    BinarySearchTree<int> tree;
   
    tree.insert(5);
    
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
   
    
    std::ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "2 3 4 5 ");
}

TEST(inorder_one){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(10);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    
    std::ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "2 3 4 5 10 ");
}

TEST(inorder_two){
    BinarySearchTree<int> tree;
    
    
    std::ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    ASSERT_FALSE(oss_inorder.str() == " ");
}

TEST(pre_order){
    BinarySearchTree<int> tree;
    tree.insert(5);
    tree.insert(10);
    tree.insert(2);
    tree.insert(3);
    tree.insert(14);
     std::ostringstream oss_inorder;
    tree.traverse_inorder(oss_inorder);
    ASSERT_TRUE(oss_inorder.str() == "2 3 5 10 14 ");
}


TEST_MAIN()










