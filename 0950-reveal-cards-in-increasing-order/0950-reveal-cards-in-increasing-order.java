class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int len = deck.length;
        Arrays.sort(deck);
        Deque <Integer> queue = new LinkedList();
        int [] result = new int[len];

        for(int i = 0 ; i < len ; i++)
            queue.add(i);

        int i = 0;
        while(!queue.isEmpty())
        {
            int idx = queue.poll();
            result[idx] = deck[i++];

            if(queue.isEmpty())
                break;

            queue.add(queue.poll());
        }

        return result;
    }
}