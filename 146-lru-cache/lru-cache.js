class Node 
{
    constructor(key, value) 
    {
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class LRUCache {
    /**
     * @param {number} capacity
     */
    constructor(capacity) 
    {
        this.capacity = capacity;
        this.map = new Map();
        this.head = new Node(null, null);
        this.tail = new Node(null, null);
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    /**
     * @param {number} key
     * @return {number}
     */
    get(key) 
    {
        if (!this.map.has(key)) 
        {
            return -1;
        }
        
        const node = this.map.get(key);
        this._remove(node);
        this._add(node);
        
        return node.value;
    }

    /**
     * @param {number} key 
     * @param {number} value
     * @return {void}
     */
    put(key, value) 
    {
        if (this.map.has(key)) 
        {
            this._remove(this.map.get(key));
        }
        
        const newNode = new Node(key, value);
        this._add(newNode);
        this.map.set(key, newNode);

        if (this.map.size > this.capacity) 
        {
            const lru = this.head.next;
            this._remove(lru);
            this.map.delete(lru.key);
        }
    }

    _remove(node) 
    {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    _add(node) 
    {
        node.prev = this.tail.prev;
        node.next = this.tail;
        this.tail.prev.next = node;
        this.tail.prev = node;
    }
}

/** 
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */