/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
    vector<vector<int>>dirs{{0,1},{1,0},{0,-1},{-1,0}};
public:
    void cleanRoom(Robot& robot) {
        unordered_set<string>visited;
        helper(robot,0,0,0,visited);
    }
    void helper(Robot& robot,int x,int y,int dir,unordered_set<string>&visited){
        robot.clean();
        visited.insert(to_string(x)+"_"+to_string(y));
        for(int i=0;i<4;i++){
            int cur=(i+dir)%4,nx=x+dirs[cur][0],ny=y+dirs[cur][1];
            if(!visited.count(to_string(nx)+"_"+to_string(ny)) && robot.move()){
                helper(robot,nx,ny,cur,visited);
                robot.turnLeft();
                robot.turnLeft();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
               robot.turnLeft();
        }
    }
};
