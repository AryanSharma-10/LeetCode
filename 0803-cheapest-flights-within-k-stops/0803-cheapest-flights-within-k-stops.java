
class Pair {
    int node;
    int money;

    Pair(int node, int money)
    {
        this.node = node;
        this.money = money;
    }
}

class Tuple {
    int node;
    int dist;
    int money;

    Tuple(int node, int dist, int money)
    {
        this.node = node;
        this.dist = dist;
        this.money = money;
    }
}

class Solution {
    public int findCheapestPrice(int cities, int[][] flights, int src, int dst, int stops) {
        int m = flights.length;

        List<List<Pair>> adj = new ArrayList<>();

        for(int i = 0 ; i < cities ; i++)
            adj.add(new ArrayList<>());

        for(int i = 0 ; i < m ; i++)
        {
            int from = flights[i][0];
            int to = flights[i][1];
            int dist = flights[i][2];

            adj.get(from).add(new Pair(to, dist));
        }

        int [] nodeMoney = new int[cities];
        Arrays.fill(nodeMoney, (int)1e9);
        nodeMoney[src] = 0;

        Queue<Tuple> queue = new LinkedList<>();

        queue.add(new Tuple(src, 0, 0));

        int minPrice = Integer.MAX_VALUE;

        while(!queue.isEmpty())
        {   
            int node = queue.peek().node;
            int dist = queue.peek().dist;
            int money = queue.remove().money;

            // System.out.println("Exploring: "+node);

            if(node == dst)
            {
                // System.out.println("hi");
                minPrice = Math.min(minPrice, money);
            }
            else
            {
                for(Pair it : adj.get(node))
                {
                    int adjNode = it.node;
                    int nxtMoney = it.money;

                    if(dist <= stops && nxtMoney+money < nodeMoney[adjNode])
                    {   

                        // System.out.println("Adding: " + adjNode);
                        // System.out.println("Money: " + (nxtMoney+money));
                        nodeMoney[adjNode] = nxtMoney+money;
                        queue.add(new Tuple(adjNode, dist + 1, nxtMoney+money));
                    } 
                }
            
            }
        }
        
        if(minPrice == Integer.MAX_VALUE)
            return -1;

        return minPrice;
    }
}