/**
 * // Definition for a _Node.
 * function _Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {_Node} head
 * @return {_Node}
 */
var copyRandomList = function(head) 
{
    if (!head)
    {
        return null;
    }

    let current = head;
    while (current)
    {
        let copy = new _Node(current.val, current.next, null);
        current.next = copy;
        current = copy.next;
    }

    current = head;
    while (current)
    {
        if (current.random)
        {
            current.next.random = current.random.next;
        }

        current = current.next.next;
    }

    current = head;
    let copyHead = head.next;
    while (current)
    {
        let copy = current.next;
        current.next = copy.next;
        if (copy.next)
        {
            copy.next = copy.next.next;
        }

        current = current.next;
    }

    return copyHead;
};