class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";

        vector<string> out;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (!cur) {
                out.push_back("null");
                continue;
            }
            out.push_back(to_string(cur->val));
            q.push(cur->left);
            q.push(cur->right);
        }

        // trim trailing nulls
        int i = out.size() - 1;
        while (i >= 0 && out[i] == "null") i--;
        out.resize(i + 1);

        string res = "[";
        for (int j = 0; j < out.size(); j++) {
            if (j) res += ",";
            res += out[j];
        }
        res += "]";
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "[]") return nullptr;

        // remove surrounding brackets
        data = data.substr(1, data.size() - 2);
        if (data.empty()) return nullptr;

        // split by commas
        vector<string> tokens;
        string cur;
        for (char c : data) {
            if (c == ',') {
                tokens.push_back(cur);
                cur.clear();
            } else {
                cur.push_back(c);
            }
        }
        tokens.push_back(cur);

        if (tokens[0] == "null") return nullptr;

        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int idx = 1;
        while (!q.empty() && idx < tokens.size()) {
            TreeNode* node = q.front(); q.pop();

            // left child
            if (idx < tokens.size() && tokens[idx] != "null") {
                node->left = new TreeNode(stoi(tokens[idx]));
                q.push(node->left);
            }
            idx++;

            // right child
            if (idx < tokens.size() && tokens[idx] != "null") {
                node->right = new TreeNode(stoi(tokens[idx]));
                q.push(node->right);
            }
            idx++;
        }

        return root;
    }
};
