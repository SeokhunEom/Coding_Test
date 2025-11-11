struct DoublyListNode {
    int val;
    DoublyListNode *prev;
    DoublyListNode *next;
    DoublyListNode(int x) : val(x), prev(NULL), next(NULL) {}
};

class MyLinkedList {
private:
    DoublyListNode* head;
    DoublyListNode* tail;
    int size;

public:
    MyLinkedList() {
        this->head = new DoublyListNode(0);
        this->tail = new DoublyListNode(0);
        this->size = 0;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }
    
    int get(int index) {
        if (index < 0 || index >= this->size) {
            return -1;
        }

        DoublyListNode* curr;
        if (index + 1 < this->size - index) {
            curr = this->head;
            for (int i = 0; i <= index; i++) {
                curr = curr->next;
            }
        } else {
            curr = this->tail;
            for (int i = 0; i < this->size - index; i++) {
                curr = curr->prev;
            }
        }

        return curr->val;
    }
    
    void addAtHead(int val) {
        DoublyListNode* newNode = new DoublyListNode(val);
        newNode->next = this->head->next;
        newNode->prev = this->head;
        this->head->next->prev = newNode;
        this->head->next = newNode;
        this->size++;
    }
    
    void addAtTail(int val) {
        DoublyListNode* newNode = new DoublyListNode(val);
        newNode->next = this->tail;
        newNode->prev = this->tail->prev;
        this->tail->prev->next = newNode;
        this->tail->prev = newNode;
        this->size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > this->size) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == this->size) {
            addAtTail(val);
            return;
        }

        DoublyListNode* newNode = new DoublyListNode(val);
        DoublyListNode* prevNode;
        DoublyListNode* nextNode;
        DoublyListNode* curr;
        if (index < this->size - index) {
            curr = this->head;
            for (int i = 0; i < index; i++) {
                curr = curr->next;
            }
            prevNode = curr;
            nextNode = curr->next;
        } else {
            curr = this->tail;
            for (int i = 0; i < this->size - index; i++) {
                curr = curr->prev;
            }
            nextNode = curr;
            prevNode = curr->prev;
        }
        prevNode->next = newNode;
        newNode->prev = prevNode;
        newNode->next = nextNode;
        nextNode->prev = newNode;
        this->size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= this->size) {
            return;
        }
        if (index == 0) {
            DoublyListNode* delNode = this->head->next;
            this->head->next = delNode->next;
            delNode->next->prev = this->head;
            delete delNode;
            this->size--;
            return;
        }
        if (index == this->size - 1) {
            DoublyListNode* delNode = this->tail->prev;
            delNode->prev->next = this->tail;
            this->tail->prev = delNode->prev;
            delete delNode;
            this->size--;
            return;
        }

        DoublyListNode* curr;
        if (index < this->size - index) {
            curr = this->head;
            for (int i = 0; i <= index; i++) {
                curr = curr->next;
            }
        } else {
            curr = this->tail;
            for (int i = 0; i < this->size - index; i++) {
                curr = curr->prev;
            }
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        this->size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */