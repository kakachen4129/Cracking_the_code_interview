struct GraphNode{
    int val;
    vector<GraphNode*> next;
    int inDegree;
    GraphNode(int x) : val(x), inDegree(0){};    
};

class Solution {
public:
    int buildGraph(const vector<pair<int, int>>& prerequisites, unordered_map<int, GraphNode*> &map){
        int v_number = prerequisites.size();
        int n_number = 0;
        /*for (int i = 0; i < v_number; i++){
            int start = prerequisites[i].second;
            int end = prerequisites[i].first;
            if (map.find(start) == map.end()){
                GraphNode *newNode = new GraphNode(start);
                map[start] = newNode;
                n_number++;
            }
            if (map.find(end) == map.end()){
                GraphNode *newNode = new GraphNode(end);
                map[end] = newNode;
                n_number++;
            }
            map[start]->next.push_back(map[end]);
            map[end]->inDegree++;
        }*/
        for (const auto &p : prerequisites){
            int start = p.second;
            int end = p.first;
            if (map.find(start) == map.end()){
                map[start] = new GraphNode(start);
                n_number++;
            }
            if (map.find(end) == map.end()){
                map[end] = new GraphNode(end);
                n_number++;
            }
            map[start]->next.push_back(map[end]);
            map[end]->inDegree++;
        }
        return n_number;
    }
    void init_Q(queue<GraphNode*> &q, const unordered_map<int, GraphNode*> &map){
        /*unordered_map<int, GraphNode*>::iterator iter;
        for (iter = map.begin(); iter != map.end(); iter++){
            GraphNode *tmp = iter->second;
            if (tmp->inDegree == 0)
                q.push(tmp);
        }*/
        for (const auto &iter : map){
            GraphNode *tmp = iter.second;
            if (tmp->inDegree == 0)
                q.push(tmp);
        }
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, GraphNode*> map;
        int n_number = buildGraph(prerequisites, map);
        queue<GraphNode*> q;
        init_Q(q, map);
        int cnt = 0;
        while (q.empty() != true){
            GraphNode *tmp = q.front();
            q.pop();
            cnt++;
            /*for (int i = 0; i < tmp->next.size(); i++){
                GraphNode *next = tmp->next[i];
                next->inDegree--;
                if (next->inDegree == 0)
                    q.push(next);
            }*/
            for (const auto &next : tmp->next){
                next->inDegree--;
                if (next->inDegree == 0)
                    q.push(next);
            }
        }
        return cnt == n_number;
    }
};