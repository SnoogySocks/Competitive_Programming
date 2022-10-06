# https://leetcode.com/problems/course-schedule-ii/
# October 6, 2022

class Solution:
    def hasCycle (self, adj, vis, u):
        vis[u] = 1

        for v in adj[u]:
            # if already visited in current recursiveStack, then there's a cycle so return
            if vis[v]==1:
                return True

            # if unvisited, dfs through the node
            elif vis[v]==0:
                vis[v] = 1
                if self.hasCycle(adj, vis, v):
                    return True

        vis[u] = 2
        return False


    def dfs (self, adj, vis, u, output):
        if vis[u]:
            return

        vis[u] = True
        for v in adj[u]:
            self.dfs(adj, vis, v, output)
        output.append(u)


    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        # recieve input
        n = numCourses
        e = len(prerequisites)
        adj = [[] for _ in range(n)]
        for edge in prerequisites:
            adj[edge[0]].append(edge[1])

        # problem
        # if it has a cycle then it's invalid
        vis = [0]*(n)
        for s in range(n):
            if vis[s]==0 and self.hasCycle(adj, vis, s):
                return []

        # The onlly valid structure would be a tree
        # Can dfs to the root of a forest, print all the way down to the leaves
        roots = []
        vis = [False]*n
        for u in range(n):
            for v in adj[u]:
                vis[v] = True

        for u in range(len(vis)):
            if not vis[u]:
                roots.append(u)

        # dfs on each root and print all the way down
        vis = [False]*n
        output = []
        for r in roots:
            self.dfs(adj, vis, r, output)

        return output
