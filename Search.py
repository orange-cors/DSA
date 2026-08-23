#DFS
graph = {
    'A': ['B', 'C', 'D'],
    'B': ['M', 'N'],
    'C': ['L'],
    'D': ['O', 'P'],
    'M': ['X', 'Y'],
    'N': ['U', 'V'],
    'L': [],
    'O': ['I', 'J'],
    'P': [],
    'X': [],
    'Y': ['R', 'S'],
    'U': [],
    'V': ['G', 'H'],
    'I': [],
    'J': [],
    'R': [],
    'S': [],
    'G': [],
    'H': []
}

def DFS_search(graph, start, goal):
    # Stack lưu trữ các đường đi đang xét
    stack = [[start]]
    visited = set()

    while stack:
        # Lấy đường đi ở đỉnh ngăn xếp (Vào sau - Ra trước)
        path = stack.pop()
        current_node = path[-1]

        if current_node == goal:
            return path

        if current_node not in visited:
            visited.add(current_node)
            
            # Đảo ngược danh sách các đỉnh kề để đảm bảo nhánh bên trái 
            # được đưa vào sau cùng và sẽ được pop ra duyệt trước
            for neighbor in reversed(graph.get(current_node, [])):
                if neighbor not in visited:
                    new_path = list(path)
                    new_path.append(neighbor)
                    stack.append(new_path)

    return None

# 2. Chạy thuật toán
start_node = 'A'
goal_node = 'R'
path = DFS_search(graph, start_node, goal_node)

# 3. In kết quả
if path:
    print(f"Đường đi tìm thấy bằng DFS: {' -> '.join(path)}")
else:
    print("Không tìm thấy đường đi tới đích.")
    
#BFS
graph = {
    'A': ['B', 'C', 'D'],
    'B': ['H', 'I'],
    'C': ['E', 'F'],
    'D': ['G'],
    'E': [],
    'F': ['J', 'K'],
    'G': [],
    'H': [],
    'I': [],
    'J': [],
    'K': []
}

def BFS_search(graph, start, goals):
    # Hàng đợi lưu trữ các đường đi, hoạt động theo cơ chế FIFO
    queue = [[start]]
    
    # Tập hợp lưu các đỉnh đã duyệt qua để tránh lặp (vòng lặp vô hạn)
    visited = {start}

    while queue:
        # Lấy đường đi đầu tiên ra khỏi hàng đợi (Vào trước ra trước)
        path = queue.pop(0)
        
        # Lấy đỉnh hiện tại (đỉnh cuối cùng trong đường đi)
        current_node = path[-1]

        # Kiểm tra xem đỉnh hiện tại có thuộc tập đích (Goal) không
        if current_node in goals:
            return path

        # Duyệt các đỉnh kề của đỉnh hiện tại
        for neighbor in graph.get(current_node, []):
            if neighbor not in visited:
                visited.add(neighbor)
                
                # Tạo đường đi mới bằng cách sao chép đường đi cũ và thêm đỉnh kề
                new_path = list(path)
                new_path.append(neighbor)
                
                # Đẩy đường đi mới vào cuối hàng đợi
                queue.append(new_path)

    return None

# 2. Chạy thuật toán
start_node = 'A'
goal_nodes = {'I', 'G', 'K'}
path = BFS_search(graph, start_node, goal_nodes)

# 3. In kết quả
if path:
    print(f"Đường đi tìm thấy bằng BFS: {' -> '.join(path)}")
else:
    print("Không tìm thấy đường đi tới đích.")
    
#AT
import heapq
graph = {
'S': {'A': 2, 'M': 5, 'K': 8},
'A': {'H': 10, 'I' : 9},
'M': {},
'K': {'D': 7, 'E' : 1},
'H': {},
'I': {},
'D': {'F': 4},
'E': {'C': 6, 'G': 3},
'F': {},
'C': {},
'G': {}
}

def A_T_search(graph, start, goal):
    # MO đóng vai trò là hàng đợi ưu tiên. 
    # Mỗi phần tử là một tuple: (tổng chi phí g(n), đỉnh n hiện tại, đường đi path)
    MO = [(0, start, [start])]
    
    # DONG lưu các đỉnh đã được phát triển xong
    DONG = set()
    
    # g_costs dùng để theo dõi chi phí rẻ nhất tìm được cho mỗi đỉnh tính đến hiện tại
    g_costs = {start: 0}

    while MO:
        # Lấy đỉnh n có chi phí g(n) nhỏ nhất ra khỏi MO
        current_cost, n, path = heapq.heappop(MO)

        # Nếu n đã thuộc tập DONG thì bỏ qua (vì đã được duyệt trước đó với chi phí tối ưu hơn)
        if n in DONG:
            continue

        # Nếu n là đích (TG)
        if n == goal:
            return path, current_cost

        # Đưa n vào tập DONG
        DONG.add(n)

        # Xét các đỉnh kề m của n
        for m, cost_n_m in graph.get(n, {}).items():
            new_cost = current_cost + cost_n_m

            # Chỉ đưa vào MO nếu m chưa nằm trong tập DONG
            if m not in DONG:
                # Nếu m chưa từng được duyệt, hoặc tìm thấy đường mới đến m có chi phí rẻ hơn đường cũ
                if m not in g_costs or new_cost < g_costs[m]:
                    g_costs[m] = new_cost
                    # Cập nhật m vào MO cùng với đường đi mới
                    heapq.heappush(MO, (new_cost, m, path + [m]))

    # Trả về None nếu không tìm thấy đường đi (MO rỗng)
    return None, -1

# 2. Chạy thuật toán
start_node = 'S'
goal_node = 'G'
path, total_cost = A_T_search(graph, start_node, goal_node)

# 3. In kết quả
if path:
    print(f"Đường đi tối ưu từ {start_node} đến {goal_node}: {' -> '.join(path)}")
    print(f"Tổng chi phí: {total_cost}")
else:
    print(f"Không tìm thấy đường đi từ {start_node} đến {goal_node}.")
    
#A-star
import heapq

# 1. Khai báo đồ thị gồm chi phí cạnh g(n) và giá trị heuristic h(n)
# Cấu trúc: 'Đỉnh': {'edges': {Đỉnh kề: chi phí}, 'h': giá trị heuristic}
graph = {
    'B': {'edges': {'J': 2, 'C': 12, 'E': 2}, 'h': 12},
    'J': {'edges': {'I': 2, 'H': 6}, 'h': 1},
    'C': {'edges': {'D': 2, 'F': 3}, 'h': 8},
    'E': {'edges': {'G': 3}, 'h': 2},
    'I': {'edges': {}, 'h': 3},
    'H': {'edges': {}, 'h': 2},
    'D': {'edges': {}, 'h': 7},
    'F': {'edges': {'A': 6, 'K': 3}, 'h': 4},
    'G': {'edges': {}, 'h': 3},
    'A': {'edges': {}, 'h': 0},
    'K': {'edges': {}, 'h': 6}
}

def A_star_search(graph, start, goal):
    # Hàng đợi ưu tiên MO lưu trữ: (f_cost, g_cost, đỉnh_hiện_tại, đường_đi)
    # f_cost được đặt lên đầu để heapq luôn lấy đỉnh có f(n) nhỏ nhất
    start_f_cost = graph[start]['h']
    MO = [(start_f_cost, 0, start, [start])]
    
    DONG = set()
    g_costs = {start: 0}

    while MO:
        # Rút đỉnh có f(n) nhỏ nhất ra khỏi tập MỞ
        current_f, current_g, n, path = heapq.heappop(MO)

        # Bỏ qua nếu đỉnh đã được duyệt (đã đưa vào tập ĐÓNG)
        if n in DONG:
            continue

        # Nếu đạt tới đích
        if n == goal:
            return path, current_g

        DONG.add(n)

        # Xét các đỉnh kề của n
        for m, cost_n_m in graph[n]['edges'].items():
            new_g = current_g + cost_n_m
            new_f = new_g + graph[m]['h']

            # Nếu m chưa đóng, hoặc tìm được đường g(n) ngắn hơn tới m
            if m not in DONG:
                if m not in g_costs or new_g < g_costs[m]:
                    g_costs[m] = new_g
                    heapq.heappush(MO, (new_f, new_g, m, path + [m]))

    return None, -1

# 2. Chạy chương trình
start_node = 'B'
goal_node = 'A'
path, total_cost = A_star_search(graph, start_node, goal_node)

# 3. In kết quả
if path:
    print(f"Đường đi tìm thấy bằng thuật toán A*: {' -> '.join(path)}")
    print(f"Tổng chi phí thực tế g(n): {total_cost}")
else:
    print("Không tìm thấy đường đi.")