// Created by Valdir de Souza Junior
// vsj@ic.ufal.br
// valdirjunior.contato@gmail.com
// https://www.hackerrank.com/challenges/red-knights-shortest-path


#include <bits/stdc++.h>
using namespace std;


enum move_t{ MOVE_UL=0, MOVE_UR, MOVE_R, MOVE_LR, MOVE_LL, MOVE_L, NONE};
string s[]={"UL","UR","R","LR","LL","L"};
typedef struct coordinate coordinate_t;
typedef struct node node_t;

struct node{
    pair<int, int> curr_xy;
    vector<enum move_t> previous_moves;
    vector<int> move_counter;
    enum move_t move;
};
vector<vector<int>> arr;
int n;
int x_start, x_end, y_start, y_end;


bool isValid(int x, int y){
    return (x>=0 && x<n && y>=0 && y< n);
}

void addQueue(queue<node_t>& q, map<pair<int,int>, bool>& visited, node_t& curr_node, enum move_t m){
    int curr_x = curr_node.curr_xy.first;
    int curr_y = curr_node.curr_xy.second;
    int i = 0, j= 0;
    switch(m){
        case MOVE_UL: {i = -2; j = -1;break;}
        case MOVE_UR: {i = -2; j = +1;break;}
        case MOVE_R: {i = 0; j = +2;break;}
        case MOVE_LR: {i = +2; j = +1;break;}
        case MOVE_LL: {i = +2; j = -1;break;}
        case MOVE_L: {i = 0; j = -2;break;}
        default: { return;}
    }
    if (!isValid(curr_x+i,curr_y+j)){
        return;
    }
    if (visited.count(make_pair(curr_x+i,curr_y+j)) >  0){
        return;
    }
    vector<enum move_t> moves = curr_node.previous_moves;
    moves.push_back(m);
    vector<int> new_move_counter = curr_node.move_counter;
    new_move_counter[m]++;
    q.push(node_t {make_pair(curr_x+i,curr_y+j), moves,  new_move_counter, .move= m});
}

void bfs() {
    map<pair<int,int>, bool> visited;
    queue<node_t> q;
    q.push(node_t {make_pair(x_start,y_start), vector<enum move_t> { NONE}, .move_counter= vector<int> {0,0,0,0,0,0}, .move= NONE});
    node_t curr_node ;
    while(!q.empty()){
        curr_node = q.front();
        int curr_x = curr_node.curr_xy.first;
        int curr_y = curr_node.curr_xy.second;
        if (curr_x==x_end && curr_y == y_end){
            int size = curr_node.previous_moves.size();
            printf("%d\n", size-1);
            for (int i = 1; i< size ; i++){
                cout<< s[curr_node.previous_moves[i]];
                if (i+1 == size){
                    printf("\n");
                }else{
                    printf(" ");
                }
            }
            //printa lista
            return;
        }
        if (visited.count(curr_node.curr_xy) > 0 ){
            q.pop();
            continue;
        }
        else{
            visited[curr_node.curr_xy] = true;
            addQueue(q, visited, curr_node, MOVE_UL);
            addQueue(q, visited, curr_node, MOVE_UR);
            addQueue(q, visited, curr_node, MOVE_R);
            addQueue(q, visited, curr_node, MOVE_LR);
            addQueue(q, visited, curr_node, MOVE_LL);
            addQueue(q, visited, curr_node, MOVE_L);
            q.pop();

        }


    }
    printf("Impossible\n");
}
int main() {
    scanf("%d", &n);
    arr.resize(n);
    scanf("%d %d %d %d", &x_start, &y_start, &x_end, &y_end);
    bfs();
    return 0;
}
