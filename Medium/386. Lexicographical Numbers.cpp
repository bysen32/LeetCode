/*
�������1.��¼��ǰ����һ�οɽ��в�ֵ���±���С�
�������ʱ��vector�Ĳ�������ǳ���ʱ�� 
*/ 
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        deque<int> idxque1, idxque2;
        for ( int i=0; i<n && i<9; ++i ) {
            ret.insert(ret.begin()+i, i+1);
            idxque2.push_back(i);
        }
        int offset = 0;
        while ( ret.size()!=n ) {
            if (idxque1.empty()) {
                idxque1 = idxque2;
                idxque2.clear();
                offset = 0;
            }
            int idx = idxque1.front();
            idxque1.pop_front();
            int cur = ret[idx+offset];
            for ( int i=0; i<10 && ret.size()!=n; ++i ) {
                offset += 1;
                ret.insert(ret.begin()+idx+offset, cur * 10 + i);
                idxque2.push_back(idx+offset);
            }
        }
        return ret;
    }
};

/*
�������2.ʹ��dfs�� 
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        for (int i=1; i<10;i++) {
            dfs(i, n, ret);
        }
        return ret;
    }
    
    void dfs(int cur, int n, vector<int>& ret) {
        if (cur <= n) {
            ret.push_back(cur);
            for (int i=0; i<10; i++)
            {
                dfs(cur*10+i, n, ret);
            }
        }
    }
};

/*
�������3.�ҹ��ɡ� �����ⷨ�� 
*/ 

