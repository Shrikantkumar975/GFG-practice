class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        vector<int> jump(N + 1, 0);

        // Store ladders
        for(int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        // Store snakes
        for(int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        queue<int> q;
        vector<bool> visited(N + 1, false);

        q.push(1);
        visited[1] = true;

        int throws = 0;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int curr = q.front();
                q.pop();

                if(curr == N)
                    return throws;

                for(int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;

                    if(next > N)
                        break;

                    // Take snake or ladder
                    if(jump[next] != 0)
                        next = jump[next];

                    if(!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }

            throws++;
        }

        return -1;
    }
};