class Solution {
public:
int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    queue<string> q;
    unordered_set<string> visited;
    q.push(beginWord);
    visited.insert(beginWord);
    int cnt = 1;
    while (q.empty() != true){
        int n = q.size();
        for (int i = 0; i < n; i++){
            string cur = q.front();
            q.pop();
            for (int j = 0; j < cur.size(); j++){
                char ch = 'a';
                string cur_t = cur;
                while (ch <= 'z'){
                    if (ch != cur[j]){
                        cur_t[j] = ch;
                        if (cur_t == endWord)   return cnt + 1;
                        if (wordList.find(cur_t) != wordList.end() && visited.find(cur_t) == visited.end()){
                            q.push(cur_t);
                            visited.insert(cur_t);
                        }
                    }
                    ch++;
                }
            }
        }
        cnt++;
    }
    return 0;
}
};