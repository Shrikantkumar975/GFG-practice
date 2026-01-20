class Solution {
  private:
    stack<char> undoStack;
    stack<char> redoStack;

  public:
    void append(char x) {
        undoStack.push(x);
        
        // clear redo stack on new append
        while (!redoStack.empty())
            redoStack.pop();
    }

    void undo() {
        if (!undoStack.empty()) {
            char ch = undoStack.top();
            undoStack.pop();
            redoStack.push(ch);
        }
    }

    void redo() {
        if (!redoStack.empty()) {
            char ch = redoStack.top();
            redoStack.pop();
            undoStack.push(ch);
        }
    }

    string read() {
        string result = "";
        stack<char> temp = undoStack;

        // stack stores characters in reverse order
        while (!temp.empty()) {
            result.push_back(temp.top());
            temp.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
