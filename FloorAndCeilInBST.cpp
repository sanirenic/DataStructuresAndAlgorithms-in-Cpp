pair<int, int> floorCeilBST(Node* root, int key) {
    int floorVal = -1, ceilVal = -1;
    Node* curr = root;

    while (curr) {
        if (curr->data == key) {
            return {key, key};
        }
        else if (key < curr->data) {
            ceilVal = curr->data;
            curr = curr->left;
        }
        else {
            floorVal = curr->data;
            curr = curr->right;
        }
    }
    return {floorVal, ceilVal};
}
