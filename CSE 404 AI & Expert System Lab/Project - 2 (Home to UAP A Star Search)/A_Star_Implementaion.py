# A Star Implementation
import heapq
# Graph as adjacency list
graph = {
    "Home": [("Shre-e_bangla_road", 7), ("Mohammed_Pur", 18), ("Tenary_Mor", 9)],
    "Shre-e_bangla_road": [("Home", 7), ("Modhu_Bazar", 5)],
    "Modhu_Bazar": [("Shre-e_bangla_road", 5), ("Abahoni_Math", 12)],
    "Abahoni_Math": [("Modhu_Bazar", 12), ("32_No", 17), ("8_No_Bridge", 11)],
    "32_No": [("Abahoni_Math", 17), ("Panthopoth", 10)],
    "Panthopoth": [("32_No", 10), ("UAP", 4), ("Science_Lab", 13), ("Kola_Baghan", 9)],
    "UAP": [("Panthopoth", 4), ("Farm_Gate", 3)],
    "Mohammed_Pur": [("Home", 18), ("Khamar_Bari", 25)],
    "Khamar_Bari": [("Mohammed_Pur", 25), ("Farm_Gate", 12)],
    "Farm_Gate": [("Khamar_Bari", 12), ("UAP", 3)],
    "Tenary_Mor": [("Home", 9), ("Jhigatola", 9)],
    "Jhigatola": [("Tenary_Mor", 9), ("Science_Lab", 11), ("8_No_Bridge", 12)],
    "Science_Lab": [("Jhigatola", 11), ("Panthopoth", 13), ("Kola_Baghan", 8)],
    "Kola_Baghan": [("Science_Lab", 8), ("8_No_Bridge", 4), ("Panthopoth", 9)],
    "8_No_Bridge": [("Abahoni_Math", 11), ("Kola_Baghan", 4), ("Jhigatola", 12)],
}

# Heuristic values (Minimum Cost)
heuristic_estimates = {
    "UAP": 0,
    "Panthopoth": 4,
    "32_No": 14,
    "Abahoni_Math": 31,
    "Modhu_Bazar": 43,
    "Shre-e_bangla_road": 48,
    "Home": 46,
    "Mohammed_Pur": 40,
    "Khamar_Bari": 15,
    "Farm_Gate": 3,
    "Tenary_Mor": 37,
    "Jhigatola": 28,
    "Science_Lab": 17,
    "Kola_Baghan": 13,
    "8_No_Bridge": 17,
}


# Heuristic values (Straight Line Cost)
# heuristic_estimates = {
#     "UAP": 0,
#     "Panthopoth": 4,
#     "32_No": 13,
#     "Abahoni_Math": 20,
#     "Modhu_Bazar": 26,
#     "Shre-e_bangla_road": 28,
#     "Home": 33,
#     "Mohammed_Pur": 29,
#     "Khamar_Bari": 5,
#     "Farm_Gate": 3,
#     "Tenary_Mor": 19,
#     "Jhigatola": 28,
#     "Science_Lab": 17,
#     "Kola_Baghan": 11,
#     "8_No_Bridge": 15,
# }

def a_star(graph, h, start, goal):
    heap = [(h[start], 0, start, [])]  # (f = g + h, g, node, path)
    visited = set()
    while heap:
        f, g, node, path = heapq.heappop(heap)
        if node in visited:
            continue
        visited.add(node)
        path = path + [node]
        if node == goal:
            return g, path
        for neighbor, cost in graph[node]:
            if neighbor not in visited:
                g_new = g + cost
                f_new = g_new + h[neighbor]
                heapq.heappush(heap, (f_new, g_new, neighbor, path))
    return float('inf'), []

if __name__ == "__main__":
    total_cost, optimal_path = a_star(graph, heuristic_estimates, "Home", "UAP")
    print("A* Optimal path from Home to UAP:")
    print(" → ".join(optimal_path))
    print(f"Total Cost: {total_cost}")