class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {

        vector<int> years(2051, 0);

        for(auto it: logs){
            int birth = it[0];
            int death = it[1];
            years[birth]+=1;
            years[death]-=1;
        }

        int max_population = 0;
        int earliest_year = 1950;
        int population = 0;
        for(int i=1950;i<=2050;i++){
            population += years[i];
            if(population > max_population){
                max_population = population;
                earliest_year = i;
            }
        }

        return earliest_year;
        
    }
};