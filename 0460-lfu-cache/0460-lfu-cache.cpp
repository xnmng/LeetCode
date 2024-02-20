// https://leetcode.com/problems/lfu-cache/discuss/3111409/Day-29-oror-C++-Easiest-Beginner-Friendly-Sol-oror-HashMap-and-Doubly-Linked-List

// question requirements:
// - put and get run in O(1) time -> hints we probably need a hashmap (i.e. unordered_map in c++)
// - put evicts least frequency key. if there are multiple, we need to evict LRU of all given least frequency keys
// - hints that we probably need to maintain some sort of LRU cache for each frequency
// - we need to track the minimum frequency
// - we need to store (value, frequency) for each given key
//
// - similar to LRU solution which runs in O(1) time, 
//      we would have a DLL of keys and a unordered_map to each node in the DLL 
//      (recall std::list is a doubly linked list)
// - however in this case, (instead of only 1 LRU cache) 
//      we need to have an unordered_map of freq to DLL (i.e. a LRU cache for each freq f)
//
// this gives rise to the metadata our LFUCache needs to store (see below)
//
// get(key) pseudocode:
// - if key doesnt exist, return -1
// - if it does, update metadata (i.e. increment key freq, etc) and return key
//
// put(key, val) pseudocode:
//      3 cases:
//          - key exists
//              update metadata, assign new value
//          - key doesnt exist
//              (optionally evict key)
//              add new kv pair and update metadata
//              set minFreq to 1 (regardless of eviction, this holds true)
//
// we notice we need to update metadata for both get and put; implement this logic using a helper function
//
// all this gives rise to the following implementation below
class LFUCache {
        // maxiumum number of kv pairs we can store in cache
    int capacity;
        // LFU key(s)' frequency (used for eviction)
    int minFreq;
        // maps key to its <stored value, frequency>
    unordered_map<int,pair<int,int>> keyValMap;
        // maps a given freq to a list of keys (in LRU order)
        // (note: this is a list; we can have >1 key with same used frequency)
    unordered_map<int,list<int>> freqKeysMap;
        // because each freq can have >1 key, 
        // we need some sort of way to access the key inside the list
        // to update a key's used freq in O(1) time (qn requirement)
        //
        // we can do this either by storing some sort of index into a given list
        // or (easier) store an iterator into the list
    unordered_map<int, list<int>::iterator> keyListIteratorMap;

        // we dont need to store size because we can check keyValMap.size()
public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
    // helper function to help us update our metadata (per get/put call)
    // assumes key already exists in our cache
    // (we could also remove the assumption by checking inside the helper function)
    void incrKeyUsage(int key) {
        // update our key's:
        // - freq 
        // - the list it is stored in inside freqKeysMap
        // - iterator to the list element
        // also optionally update minFreq
        auto itr = keyListIteratorMap[key];
        int freq = keyValMap[key].second;
        freqKeysMap[freq].erase(itr);
        
        ++keyValMap[key].second;
        ++freq;
        // assume front of list is LRU (for a given freq)
        freqKeysMap[freq].push_back(key); 
        keyListIteratorMap[key] = --freqKeysMap[freq].end(); // back of list contains our just inserted key
        
        // we are utilizing the property that minFreq will increase by max of 1 after call
        if (freqKeysMap[minFreq].empty()) ++minFreq;
    }
    
    int get(int key) {
        // could also have just checked keyListIteratorMap
        if (keyValMap.find(key) == keyValMap.end()) return -1;
        
        // here, we know that the key exists in our cache
        // update metadata and return value
        incrKeyUsage(key);
        
        return keyValMap[key].first;
    }
    
    // 3 cases:
    // key exists
    // key does not exist, need evict
    // key does not exist, no need evict
    void put(int key, int value) {
        // key exists
        if (keyValMap.find(key) != keyValMap.end()) {
            incrKeyUsage(key);
            keyValMap[key].first = value;
            return;
        }
        
        // key does not exist
        // perform optional evict
        if (keyValMap.size() == capacity) {
            // need to evict a key
            // assume front of list is LRU (for a given freq)
            int lruKey = *freqKeysMap[minFreq].begin();
            freqKeysMap[minFreq].pop_front();
            keyValMap.erase(lruKey);
            keyListIteratorMap.erase(lruKey);
        }

        // insert this key
        keyValMap[key] = {value, 1};
        freqKeysMap[1].push_back(key);
        keyListIteratorMap[key] = --freqKeysMap[1].end();
        minFreq = 1; // new lowest minFreq (regardless of eviction)
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */