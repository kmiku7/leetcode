// Memory Limit Exceeded

#include <cstddef>
#include <cstring>

const int BUFFER_SIZE = 10240;

struct Item {
    int value;
    Item* stack_prev;
};

class MinStack {
    Item*  stack_tail;
    Item** item_index;  // descending
    size_t item_index_len;
    size_t item_index_cap;

private:
    void enlarge() {
        size_t new_cap = item_index_cap + BUFFER_SIZE;
        Item** new_buffer = new Item*[new_cap];
        memcpy(new_buffer, item_index, sizeof(Item*)*item_index_len);
        delete[] item_index;
        item_index = new_buffer;
        item_index_cap = new_cap;
    }

    size_t find_pos(Item* item) {
        size_t begin = 0;
        size_t end = item_index_len;
        size_t mid = ((end - begin) >> 1) + begin;

        while (begin < end) {
            if (item->value > item_index[mid]->value 
                || (item->value == item_index[mid]->value && item > item_index[mid]))  {
                end = mid;
            } else if (item == item_index[mid]) {
                break;
            } else {
                begin = mid + 1;
            }
            mid = ((end - begin) >> 1) + begin;
        }
        return mid;
    }

    void insert(Item* item) {
        if (item_index_len >= item_index_cap) {
            enlarge();
        }
        size_t pos = find_pos(item);
        memmove(&item_index[pos+1], &item_index[pos], sizeof(Item*) * (item_index_len - pos));
        item_index[pos] = item;
        ++item_index_len;
    }

    void remove(Item* item) {
        size_t pos = find_pos(item);
        memmove(&item_index[pos], &item_index[pos+1], sizeof(Item*) * (item_index_len - pos - 1));
        --item_index_len;
    }
public:
    MinStack() {
        stack_tail = NULL;
        item_index_cap = BUFFER_SIZE;
        item_index_len = 0;
        item_index = new Item*[item_index_cap];
    }

    void push(int x) {
        Item* item = new Item();
        item->value = x;
        item->stack_prev = stack_tail;
        stack_tail = item;
        insert(item);
    }

    void pop() {
        if (stack_tail == NULL) {
            return;
        }
        Item* top_item = stack_tail;
        stack_tail = top_item->stack_prev;
        top_item->stack_prev = NULL;

        remove(top_item);

        delete top_item;
    }

    int top() {
        if (stack_tail == NULL) {
            return -1;
        }
        return stack_tail->value;
    }

    int getMin() {
        if (item_index_len <= 0) {
            return -1;
        }
        return item_index[item_index_len-1]->value;
    }

};



