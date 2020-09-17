//https://leetcode.com/problems/robot-bounded-in-circle/

class Solution {
public:
    class Robot {
    public:
        int x;
        int y;
        char direction;
        
        Robot() : x(0), y(0), direction('N') {}
        
        void rotate(char instruction) {
            if (instruction == 'L')
            {
                     if (direction == 'N') direction = 'W';
                else if (direction == 'W') direction = 'S';
                else if (direction == 'S') direction = 'E';
                else if (direction == 'E') direction = 'N';
            } 
            else if (instruction == 'R')
            {
                     if (direction == 'N') direction = 'E';
                else if (direction == 'E') direction = 'S';
                else if (direction == 'S') direction = 'W';
                else if (direction == 'W') direction = 'N';
            }
            else throw runtime_error("Wrong rotate instruction");
        }
        
        void move() {
                 if (direction == 'N') y += 1;
            else if (direction == 'W') x -= 1;
            else if (direction == 'S') y -= 1;
            else if (direction == 'E') x += 1;
        }
        
        void executeInstruction(char instruction) {
            if (instruction == 'G') move();
            else if (instruction == 'L' || instruction == 'R')
                rotate(instruction);
            else throw runtime_error("Wrong instruction");
        }
    };
    
    bool isRobotBounded(const string& instructions) {
        Robot robot;
        // first iteration
        for (char instruction : instructions) 
            robot.executeInstruction(instruction);
        if (robot.x == 0 && robot.y == 0)
            return true; // looped after one iteration
        // second iteration
        for (char instruction : instructions) 
            robot.executeInstruction(instruction);
        if (robot.x == 0 && robot.y == 0)
            return true; // looped after two iterations
        // Couldn't loop on third iteration, executing twice
        for (char instruction : instructions) 
            robot.executeInstruction(instruction);
        for (char instruction : instructions) 
            robot.executeInstruction(instruction);
        if (robot.x == 0 && robot.y == 0)
            return true; // looped after four iterations
        // will never loop
        return false; 
    }
};
