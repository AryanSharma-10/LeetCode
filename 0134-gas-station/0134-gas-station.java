class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n = gas.length;
        int total_fuel = 0;
        int fuel = 0;
        int index = 0;
        
        for(int i = 0; i < n; i++){
            total_fuel += gas[i] - cost[i];
            fuel += gas[i] - cost[i];
            if(fuel < 0){
                fuel = 0;
                index = i + 1;
            }
        }
        return (total_fuel < 0) ? -1 : index;
    }
}