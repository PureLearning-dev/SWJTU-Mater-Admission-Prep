class LinkNode{
    constructor(val, next){
        this.val = val;
        this.next = next;
    }
}

class MyLinkedList{
    constructor(){
       this._size = 0;
       this._tail = null;
       this._head = null; 
    }

    /**
     * Get the value of the index-th node in the linked list. If the index is invalid, return -1. 
     * @param {number} index
     * @return {object}
     */
    getNode(index){
        if(index < 0 || index >= this._size){
            return null;
        }

        let cur = new LinkNode(0, this._head);

        while(index-- >= 0){
            cur = cur.next;
        }

        return cur;
    }
    
    get(index){
        if(index < 0 || index >= this._size){
            return -1;
        }
    
        return this.getNode(index);
    }

    addAtHead(val){
        const node = new LinkNode(val, this._head);
        this._head = node;
        this._size++;
        
        if(!this._tail){
            this._tail = node;
        }
    }

    addAtTail(val){
        const node = new LinkNode(val, null);
        this._size++;
        
        if(this._tail){
            this._tail.next = node;
            this._tail = node;
            return;
        }
        
        this._head = node;
        this._tail = node;
    }

    addAtIndex(index, val){
        if(index > this._size)  return ;
        
        if(index <= 0){
            this.addAtHead(val);
            return ;
        }

        const node = this.getNode(index - 1);
        node.next = new LinkNode(val, node.next);
        this._size++;
    }

    deleteAtIndex(index){
        if(index < 0 || index >= this._size)    return;
        
        // 如果在索引为0处
        if(index === 0){
            this._head = this._head.next;
            // 若链表中只有一个结点
            if(index === this._size - 1){
                this._tail = this._head;
            }
            this._size--;
            return ;
        }

        // 删除结点
        const node = this.getNode(index - 1);
        node.next = node.next.next;

        // 若删除的结点为最后一个结点，则修改 _tail
        if(index === this._size - 1){
            this._tail = node;
        }
        
        this._size--;
    }

}