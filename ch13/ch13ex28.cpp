#include <string>

//to make copies, I would basically have to write the entire class from scratch...
//not just do the constructors...
//so maybe come back to this when I know more about trees?
class TreeNode{
public:
    TreeNode(): value(), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode&);

    ~TreeNode();

private:
    std::string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};