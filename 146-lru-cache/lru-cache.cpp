class Node {
  public:
  Node* next;
  Node* prev;
  int value;
  int key;

  Node(int key, int value){
    this->value = value;
    this->key = key;
  }
};
class LRUCache {
public:
  public:
  std::unordered_map<int, Node*> cacheMap;
  int capacity;
  Node* head;
  Node* tail;
  LRUCache(int capacity){
    this->capacity = capacity;
    head = new Node(-1, -1);
    tail = new Node(-1, -1);
    head->next = tail;
    tail->prev = head;
  }


  int get(int key){
    if(cacheMap.find(key) == cacheMap.end()){
      return -1;
    }

    Node* foundNode = cacheMap[key];
    int value = foundNode->value;

    remove(foundNode);
    add(foundNode);
    return value;
  }
  
  void put (int key, int value){
    if (cacheMap.find(key) != cacheMap.end()){
      Node* foundNode = cacheMap[key];
      remove(foundNode);
    }

    Node* newNode = new Node(key, value);
    add(newNode);
    cacheMap[key] = newNode;

    if (cacheMap.size() > capacity){
      Node* removeNode = tail->prev;
      remove(removeNode);
      cacheMap.erase(removeNode->key);
    }
  }

  void add(Node* n){
    n->next = head->next;
    head->next->prev = n;
    n->prev = head;
    head->next = n;
  }

  void remove(Node* n){
    n->prev->next = n->next;
    n->next->prev = n->prev;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */