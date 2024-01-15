class Solution {
    public List<List<Integer>> findWinners(int[][] matches) {
        HashMap<Integer, Integer> winners = new HashMap<>();
        HashMap<Integer, Integer> losers = new HashMap<>();
        HashMap<Integer, Integer> losersOnce = new HashMap<>();

        List<List<Integer>> result = new ArrayList<>();

        for( int [] players : matches)
        {   

            if(!losers.containsKey(players[0]))
            {   
                if(!winners.containsKey(players[0]))
                {   
                    winners.put(players[0],1);
                }
            }

            Integer loss = losers.get( players[1] );
            Integer temp = winners.get( players[1] );

            if(temp != null)
            {
                winners.remove(players[1]);
                losers.put(players[1],1);
                losersOnce.put(players[1],1);
            }
            else if(loss == null)
            {
                losers.put(players[1],1);
                losersOnce.put(players[1],1);
            }
            else
            {
                losersOnce.remove(players[1]);
            }
        }

        List<Integer> temp1 = new ArrayList<Integer>( winners.keySet() );
        List<Integer> temp2 = new ArrayList<Integer>( losersOnce.keySet() );
        Collections.sort(temp1);
        Collections.sort(temp2);

        result.add(temp1);
        result.add(temp2);


        return result; 
    }
}