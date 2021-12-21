from typing import List

def dungeon_game(dungeon: List[List[int]]) -> int:
    m, n = len(dungeon), len(dungeon[0])

    # cache the states
    def dp(x, y):

        # FOR BASE CASE:
        if x == m-1 and y == n-1:
            # if last element is negative, then i've to be one more than its abs value
            # else if its positive, i've to be 1 because that's the least health i can have
            return max(1, -dungeon[x][y] + 1)

        # FOR THE CURRENT STATE I'M IN i.e., (x,y):

        # initially set answer to infinity for the (x,y) state that we'll find out
        ans = float("inf")

        # there are two moves possible,
        # so get answers from both the directions i.e., left and down
        # take the minimum answer from both of them in each direction

        # DOWN:
        if x+1 < m:
            ans = min(ans, dp(x+1, y))
        # LEFT:
        if y+1 < n:
            ans = min(ans, dp(x, y+1))

        ans += -dungeon[x][y]

        # again if your ans is +ve, then it means you'd need atleast ans health to enter
        # this current point
        # else if its negative, then it means you actually need no health to even enter because
        # of the positive orbs in the subsequent points.
        # so since i added the negative, i need to return the max of 1 and the ans at the end
        return max(1, ans)

    # start the recursion from top
    return dp(0, 0)
    pwo.put_buttons(['Home Page'], onclick = [home_page])