class RandomizedSet {
public:
    set<int>s;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) != s.end())
        {
            return false;
        }
        else
        {   
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end())
        {
            s.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int getRandom() {
        auto it = s.begin();
        int random = rand() % s.size();
        std::advance(it, random);
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */