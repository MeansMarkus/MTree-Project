#include <iostream>
#include <vector>
using namespace std;

// Exception classes
class DuplicateInsertion {};
class NotFoundException {};

// Templated MTree class
template <classname DT>
class MTree {
protected:
    int M;  // Maximum number of children per node (M-way tree)
    vector<DT> values;  // Values stored in the node (M-1 values)
    vector<MTree*> children;  // Pointers to child MTrees (M children)

public:
    // Constructor
    MTree(int M) : M(M) {}

    // Destructor
    ~MTree() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }

    // Check if the node is a leaf
    bool is_leaf() const {
        return children.empty();
    }
    //Remove
    void remove(const DT& value) {
        
    }

    // Insert a value into the M-Tree
    void insert(const DT& value) {
       
    }

    // Split the node if it exceeds capacity
    void split_node() {
       
    }

    // Find the appropriate child to follow for insertion
   bool search(const DT& value) const {
 
    }




    // find_child method 
    MTree* find_child(const DT& value) {
   
    }
    // Collect all values from leaf nodes for rebuilding
   vector<DT>& collect_values(); 

    // Rebuild the tree from a sorted vector of values
    void buildTree(vector<DT>& input_values) {
    }
    
    bool find (DT& value){

    }
};

int main() {
        int n;
        int MValue;
        int numCommands;
        char command;
        int value;

    // Read number of initial elements
    cin >> n;
    vector<int> mySortedValues(n);
    for (int i = 0; i < n; i++) {
        cin >> mySortedValues[i];
    }

    // Get the M value
    cin >> MValue;
    MTree<int>* myTree = new MTree<int>(MValue);

    // Build the tree
    myTree->buildTree(mySortedValues);

    cin >> numCommands;  // Read the number of commands

    for (int i = 0; i < numCommands; i++) {
        cin >> command;

        switch (command) {
            case 'I':
                cin >> value;
                try {
                    (*myTree).insert(value);
                } catch (DuplicateInsertion& e) {
                    cout << "The value = " << value << " already in the tree." << endl;
                }
                break;
        
            case 'R':
                cin >> value;
                try {
                    (*myTree).remove(value);
                } catch (NotFoundException& e) {
                    cout << "The value = " << value << " not found." << endl;
                }
                break;
            
            case 'F':
                cin >> value;
                if (*myTree).find(value)
                    cout << "The element with value = " << value << " was found." << endl;
                else
                    cout << "The element with value = " << value << " not found." << endl;
                break;

            case 'B': {
                vector<int> myValues = (*myTree).collect_values();
                (*myTree).buildTree (myValues);
                break;
            }

            default:
                cout << "Invalid command!" << endl;
        }
    }

    delete myTree;
    return 0;
}
