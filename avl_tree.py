class AVLTree:
    """
    AVL Tree by Tamiji (Codon対応)
    リストに対し，「指定位置に値を挿入する」「指定位置の値を取得する」という2種類のクエリを，リストのサイズをnとして，それぞれO(log n)で処理する．
    insert(elem, pos) リストのpos番目にelemを挿入する．
    get(pos) リストのpos番目の値を取得する，
    """
    
    def __init__(self) -> None:
        self._elems = [0]
        self._l_child = [0]
        self._r_child = [0]
        self._parent = [0]
        self._rank = [-1]
        self._size = [0]
        self._new_id = 1
        self._init_id = 0
    
    def _pos_to_insert_id(self, pos) -> int:
        cur_id = self._init_id
        if cur_id == 0:
            return 0
        cur_pos = 0
        while True:
            l, r = self._l_child[cur_id], self._r_child[cur_id]
            new_pos = cur_pos + self._size[l] + 1
            if new_pos > pos:
                if l == 0:
                    return -cur_id
                cur_id = l
            else:
                if r == 0:
                    return cur_id
                cur_id = r
                cur_pos = new_pos
    
    def _pos_to_id(self, pos) -> int:
        cur_id = self._init_id
        cur_pos = 0
        while True:
            l, r = self._l_child[cur_id], self._r_child[cur_id]
            new_pos = cur_pos + self._size[l]
            if new_pos == pos:
                return cur_id
            if new_pos > pos:
                cur_id = l
            else:
                cur_id = r
                cur_pos = new_pos + 1
    
    def _l_rotate(self, a) -> int:
        p = self._parent[a]
        b = self._r_child[a]
        c, d, e = self._l_child[a], self._l_child[b], self._r_child[b]
        rc, rd, re = self._rank[c], self._rank[d], self._rank[e]
        sc, sd, se = self._size[c], self._size[d], self._size[e]
        if p == 0:
            self._init_id = b
        elif self._l_child[p] == a:
            self._l_child[p] = b
        else:
            self._r_child[p] = b
        self._r_child[a] = d
        self._l_child[b] = a
        self._parent[a] = b
        self._parent[b] = p
        self._parent[d] = a
        self._rank[a] = max(rc, rd) + 1
        self._rank[b] = max(self._rank[a], re) + 1
        self._size[a] = sc + sd + 1
        self._size[b] = self._size[a] + se + 1
        return b
    
    def _r_rotate(self, a) -> int:
        p = self._parent[a]
        b = self._l_child[a]
        c, d, e = self._l_child[b], self._r_child[b], self._r_child[a]
        rc, rd, re = self._rank[c], self._rank[d], self._rank[e]
        sc, sd, se = self._size[c], self._size[d], self._size[e]
        if p == 0:
            self._init_id = b
        elif self._l_child[p] == a:
            self._l_child[p] = b
        else:
            self._r_child[p] = b
        self._l_child[a] = d
        self._r_child[b] = a
        self._parent[a] = b
        self._parent[b] = p
        self._parent[d] = a
        self._rank[a] = max(rd, re) + 1
        self._rank[b] = max(rc, self._rank[a]) + 1
        self._size[a] = sd + se + 1
        self._size[b] = sc + self._size[a] + 1
        return b
    
    def _adjust(self, a) -> int:
        l, r = self._l_child[a], self._r_child[a]
        if self._rank[l] == self._rank[r] + 2:
            l2, r2 = self._l_child[l], self._r_child[l]
            if self._rank[l2] < self._rank[r2]:
                l = self._l_rotate(l)
            a = self._r_rotate(a)
        elif self._rank[r] == self._rank[l] + 2:
            l2, r2 = self._l_child[r], self._r_child[r]
            if self._rank[l2] > self._rank[r2]:
                r = self._r_rotate(r)
            a = self._l_rotate(a)
        return a
    
    def insert(self, elem, pos: int) -> None:
        insert_id = self._pos_to_insert_id(pos)
        if insert_id == 0:
            self._init_id = self._new_id
        elif insert_id > 0:
            self._r_child[insert_id] = self._new_id
        else:
            insert_id = -insert_id
            self._l_child[insert_id] = self._new_id
        self._elems.append(elem)
        self._l_child.append(0)
        self._r_child.append(0)
        self._parent.append(insert_id)
        self._rank.append(0)
        self._size.append(1)
        update_id = insert_id
        while update_id:
            l, r = self._l_child[update_id], self._r_child[update_id]
            self._rank[update_id] = max(self._rank[l], self._rank[r]) + 1
            self._size[update_id] = self._size[l] + self._size[r] + 1
            update_id = self._adjust(update_id)
            update_id = self._parent[update_id]
        self._new_id += 1
    
    def get(self, pos: int):
        return self._elems[self._pos_to_id(pos)]
