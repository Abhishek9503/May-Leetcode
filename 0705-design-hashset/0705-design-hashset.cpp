class MyHashSet {
public:
    /** Initialize your data structure here. */
    vector<bool> vec;
    MyHashSet() {
        vec.resize(1000001, false);
    }
    
    void add(int key) {
        vec[key] = true;
    }
    
    void remove(int key) {
        vec[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return vec[key] == true;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */