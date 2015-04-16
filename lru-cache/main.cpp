#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>

class LRUCache{
public:
    struct CacheItem {
        int key;
        int val;
        CacheItem* next;
        CacheItem* prev;
        CacheItem(int k=0, int v=0) : key(k), val(v), next(NULL), prev(NULL) {}
    };

    CacheItem *buffer;
    CacheItem *head;
    CacheItem *tail;
    CacheItem *free;

    CacheItem **item_idx;
    int len;
    int capacity;
    

    LRUCache(int capacity) {
        buffer = new CacheItem[capacity];
        item_idx = new CacheItem*[capacity];
        len = 0;
        this->capacity = capacity;
        head = NULL;
        tail = NULL;
        free = NULL;
        CacheItem **pNext = &free;
        for(int i=0; i<capacity; ++i) {
            *pNext = buffer+i;
            pNext = &(*pNext)->next;
        }
        *pNext = NULL;
    }
    
    int find_idx(int key) {
        int begin = 0;
        int end = len;
        while(begin<end) {
            int mid = (begin+end) / 2;
            if(item_idx[mid]->key==key) return mid;
            else if(item_idx[mid]->key<key) begin = mid + 1;
            else end = mid;
        }
        return -1;
    }

    int update_idx(CacheItem* item, int idx) {
        if(idx>=0) {
            memmove(item_idx+idx, item_idx+idx+1, sizeof(CacheItem*) * (len-idx-1));
            len -= 1;
        }

        // find upper bound
        int begin = 0;
        int end = len;
        while(begin < end) {
            int mid = (begin+end) / 2;
            if(item_idx[mid]->key <= item->key) begin = mid + 1;
            else end = mid;
        }
        assert(begin>=end || item_idx[begin]->key > item->key);
        memmove(item_idx+begin+1, item_idx+begin, sizeof(CacheItem*) * (len - begin));
        item_idx[begin] = item;
        len += 1;
        assert(len <= capacity);
    }
    int get(int key) {
        CacheItem *curr = NULL;
        int idx = find_idx(key);
        curr = idx<0 ? NULL : item_idx[idx];
        /*
        while(curr) {
            if(curr->key == key) {
                ret = curr->val;
                break;
            }
            curr = curr->next;
        };
        */

        if(curr && curr!=head) {
            curr->prev->next = curr->next;
            if(curr==tail) {
                tail = curr->prev;
            } else {
                curr->next->prev = curr->prev;
            }

            curr->next = head;
            curr->prev = NULL;
            head->prev = curr;
            head = curr;
        }
        return curr ? curr->val : -1;
    }
    
    void set(int key, int value) {
        CacheItem *curr = NULL;
        int idx = find_idx(key);
        curr = idx<0 ? NULL : item_idx[idx];
        /*
        while(curr) {
            if(curr->key == key) break;
            curr = curr->next;
        }
        */

        if(curr == NULL && free == NULL) {
            idx = find_idx(tail->key);
            assert(item_idx[idx]==tail);
            curr = tail;
        }
        if(curr!=NULL) {
            if(curr==head) {
                head = head->next;
            } else {
                curr->prev->next = curr->next;
            }
            if(curr==tail) {
                tail = curr->prev;
            } else {
                curr->next->prev = curr->prev;
            }
            curr->next = NULL;
            curr->prev = NULL;
        } else {
            curr = free;
            free = free->next;
        }

        curr->key = key;
        curr->val = value;

        curr->next = head;
        curr->prev = NULL;
        if(curr->next == NULL) {
            tail = curr;
        } else {
            head->prev = curr;
        }
        head = curr;
        update_idx(head, idx);
    }
};


int main(int argc, char** argv) {

    LRUCache cache(2);

    cache.set(1,1);
    assert(cache.get(1)==1);
    cache.set(2,2);
    assert(cache.get(2)==2);
    cache.set(3,3);
    assert(cache.get(1)==-1);
    assert(cache.get(2)==2);
    assert(cache.get(3)==3);
    cache.set(1,1);
    assert(cache.get(2)==-1);
    assert(cache.get(1)==1);

/*
    assert(cache.get(2)==-1);
    cache.set(2,6);
    cache.get(1);
    cache.set(1,5);
    cache.set(1,2);
    cache.get(1);
    cache.get(2);
*/

    return 0;
}
