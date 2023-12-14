int countLeafNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}


#include <iostream>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// a) Hàm tìm phần tử có khóa x trên cây
TreeNode* findElement(TreeNode* root, int x) {
    if (root == nullptr || root->value == x) {
        return root;
    }
    if (x < root->value) {
        return findElement(root->left, x);
    }
    return findElement(root->right, x);
}

// b) Hàm đếm số phần tử có khóa lớn hơn x
int countElementsGreaterThanX(TreeNode* root, int x) {
    if (root == nullptr) {
        return 0;
    }
    if (root->value > x) {
        return 1 + countElementsGreaterThanX(root->left, x) + countElementsGreaterThanX(root->right, x);
    }
    return countElementsGreaterThanX(root->right, x);
}

// c) Hàm kiểm tra cây đã cân bằng hay chưa (sử dụng hàm đệ quy)
bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
        return true;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
        return true;
    }
    return false;
}

int getHeight(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// d) Hàm xóa nút có khóa x trên cây
TreeNode* deleteNode(TreeNode* root, int x) {
    if (root == nullptr) {
        return root;
    }

    if (x < root->value) {
        root->left = deleteNode(root->left, x);
    } else if (x > root->value) {
        root->right = deleteNode(root->right, x);
    } else {
        // Nút có khóa x
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Nút có hai con: Tìm phần tử thay thế (nút nhỏ nhất trong cây con phải)
        TreeNode* temp = minValueNode(root->right);

        // Copy dữ liệu từ phần tử thay thế này vào nút hiện tại
        root->value = temp->value;

        // Xóa phần tử thay thế
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

TreeNode* minValueNode(TreeNode* node) {
    TreeNode* current = node;
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    int x = 3;
    TreeNode* foundNode = findElement(root, x);
    if (foundNode) {
        cout << "Phần tử có khóa " << x << " tồn tại trong cây." << endl;
    } else {
        cout << "Phần tử có khóa " << x << " không tồn tại trong cây." << endl;
    }

    int countGreater = countElementsGreaterThanX(root, x);
    cout << "Số phần tử có khóa lớn hơn " << x << " là: " << countGreater << endl;

    bool balanced = isBalanced(root);
    if (balanced) {
        cout << "Cây đã cân bằng." << endl;
    } else {
        cout << "Cây chưa cân bằng." << endl;
    }

    // Xóa nút 3 và cân bằng lại cây
    root = deleteNode(root, 3);
    balanced = isBalanced(root);
    if (balanced) {
        cout << "Cây đã cân bằng sau khi xóa nút 3." << endl;
    } else {
        cout << "Cây mất cân bằng sau khi xóa nút 3." << endl;
    }

    return 0;
}
